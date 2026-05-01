# Introducción a la solución

Tenemos una cuadrícula de $R \times C$ piezas (con $R, C < 12$), donde cada
pieza es un conjunto de líneas que salen de su centro hacia algunos de sus
cuatro vecinos ortogonales. Podemos girar cada pieza $0°$, $90°$, $180°$ o
$270°$, y queremos saber si existe alguna combinación de giros en la que cada
línea de cada pieza encaje con la línea de su pieza vecina (es decir, en cada
arista entre dos piezas vecinas las dos piezas tienen línea, o ninguna de las
dos la tiene).

A primera vista parece un problema de búsqueda sobre $4^{R \cdot C}$
posibilidades. Para una cuadrícula $11 \times 11$ esto da $4^{121} \approx
10^{73}$ configuraciones, claramente intratable por fuerza bruta. La idea clave
para hacerlo eficiente es darse cuenta de que, si recorremos la cuadrícula en
un orden fijo (por ejemplo, fila a fila, de oeste a este) y vamos colocando una
pieza tras otra, en cada momento las únicas restricciones pendientes con el
"futuro" son una franja muy estrecha de bits: el lado sur de la fila
parcialmente colocada, y el lado este de la última pieza puesta. Eso es lo que
en programación dinámica se conoce como **DP de perfil roto** (*broken profile
DP*, también llamada *plug DP* o *profile DP*).

## Codificación de las piezas

Cada pieza se representa como una máscara de bits de 4 bits, donde:

- Bit $0$ ($N$): hay línea hacia el norte.
- Bit $1$ ($E$): hay línea hacia el este.
- Bit $2$ ($S$): hay línea hacia el sur.
- Bit $3$ ($W$): hay línea hacia el oeste.

Una rotación de $90°$ en sentido horario aplica la permutación $N \to E$, $E
\to S$, $S \to W$, $W \to N$. Para cada pieza generamos sus rotaciones
distintas (entre $1$ y $4$, según las simetrías de la pieza original); por
ejemplo, una pieza vacía (`x`) o una pieza con las cuatro direcciones
(`NESW`) tiene una sola rotación distinta, mientras que una pieza en "L" tiene
cuatro.

La restricción de la pieza recta (si una pieza tiene dos direcciones opuestas
debe tener al menos otra) ya viene garantizada por el enunciado en cada pieza
de entrada, y se conserva al rotar, por lo que no hay que comprobarla
explícitamente en el algoritmo.

## ¿Qué información necesita arrastrar el algoritmo?

Imaginemos que recorremos la cuadrícula en orden de lectura (fila a fila, y
dentro de cada fila de izquierda a derecha) y vamos eligiendo una rotación
para cada pieza. Cuando lleguemos a colocar la pieza en la posición $(r, c)$
debemos respetar dos restricciones de adyacencia con piezas ya colocadas:

- La línea **norte** de $(r, c)$ debe coincidir con la línea **sur** de la
  pieza $(r-1, c)$ ya colocada (o ser $0$ si $r = 0$).
- La línea **oeste** de $(r, c)$ debe coincidir con la línea **este** de la
  pieza $(r, c-1)$ ya colocada (o ser $0$ si $c = 0$).

Las líneas **este** y **sur** de $(r, c)$ no se pueden validar todavía: lo
harán las piezas que se coloquen después en $(r, c+1)$ y $(r+1, c)$.

Es decir, para decidir si una pieza colocada lleva a una solución, no hace
falta recordar todo el pasado: basta con saber qué lados están "salientes"
hacia las celdas aún no procesadas. A esa frontera se le llama el **perfil**.

## El perfil

Definimos:

- `profile`: una máscara de $C$ bits, una por columna. El bit en la posición
  $c'$ representa la línea sur del último vecino que ya hemos puesto encima
  de la columna $c'$, es decir, justo lo que la siguiente pieza colocada en la
  columna $c'$ tendrá que respetar como su línea norte. Concretamente,
  - para columnas $c' \geq c$, ese "vecino superior" es la pieza
    $(r-1, c')$ (la pieza inmediatamente encima de la celda $(r, c')$ todavía
    sin colocar).
  - para columnas $c' < c$, ya hemos avanzado en la fila $r$ y el vecino
    superior es la pieza $(r, c')$ (la cual restringirá el norte de
    $(r+1, c')$).

  De esta manera, el perfil siempre contiene exactamente la información
  necesaria sobre la línea norte de la próxima pieza a colocar en cada
  columna.

- `h`: un único bit con la línea este de la pieza $(r, c-1)$, esto es, lo que
  la siguiente pieza $(r, c)$ tendrá que respetar como su línea oeste. Este
  bit se reinicia a $0$ al comienzo de cada fila (en la primera columna no hay
  vecino oeste).

Con estos $C + 1$ bits de información sobre la frontera, junto con la
posición actual $(r, c)$, ya podemos decidir todas las restricciones
pendientes con piezas todavía sin colocar.

## Transición

Estamos en el estado $(r, c, \texttt{profile}, h)$ y queremos colocar una
rotación de la pieza $(r, c)$. Para cada rotación candidata con bits
$(n, e, s, w)$:

1. **Restricción norte**: $n$ debe ser igual a `(profile >> c) & 1`.
2. **Restricción oeste**: $w$ debe ser igual a $h$.
3. **Borde inferior**: si $r = R - 1$, se rechaza la rotación si $s = 1$
   (no hay pieza debajo a la que conectar).
4. **Borde derecho**: si $c = C - 1$, se rechaza la rotación si $e = 1$
   (no hay pieza a la derecha a la que conectar).

Si la rotación pasa los filtros, calculamos el nuevo perfil:

```math
\texttt{newProfile} = (\texttt{profile} \text{ con el bit } c \text{ borrado}) \;|\; (s \ll c)
```

es decir, sustituimos el bit de la columna $c$ por la línea sur de la
rotación recién colocada. Esto refleja que ya no es relevante "lo que venía de
arriba" para la columna $c$ (acabamos de cubrirlo); lo que pasa a importar es
qué saca la pieza $(r, c)$ por su sur, que será la restricción norte de
$(r+1, c)$.

El nuevo bit horizontal es `newH = e`, y avanzamos a la siguiente celda en
orden de lectura: $(r, c+1)$ si $c+1 < C$, o si no $(r+1, 0)$ con
`newH = 0`.

Si al recurrir sobre el nuevo estado encontramos solución, el estado actual
también tiene solución; si ninguna rotación lleva a solución, el estado actual
no tiene solución.

## Condiciones de contorno

Las cuatro condiciones de contorno se manejan automáticamente con esta
formulación:

- La fila superior. Inicializamos `profile = 0`. Como en la primera fila $r =
  0$ todavía no hay piezas encima, las restricciones norte que se leen del
  perfil son todas $0$, lo que obliga a que la primera fila no tenga líneas
  hacia el norte (no hay nada al norte con lo que conectar).
- La columna izquierda. Al iniciar cada fila ponemos $h = 0$, lo que obliga a
  que la primera columna no tenga líneas hacia el oeste.
- La fila inferior y la columna derecha. Se filtran explícitamente con las
  reglas 3 y 4 de la transición.

Cuando $r = R$ se han colocado todas las piezas, y el algoritmo devuelve
`true`. Es importante notar que en ese momento `profile` es $0$ por
construcción, ya que los bits de la última fila se han ido filtrando uno a uno
con la condición "borde inferior $\Rightarrow s = 0$".

## Memoización

Sin memoización el número de estados visitados puede crecer exponencialmente
porque distintas secuencias de rotaciones pueden llevar al mismo
$(r, c, \texttt{profile}, h)$. Memoizando el resultado (resoluble o no) de
cada estado, cada estado se evalúa una sola vez.

El número total de estados está acotado por:
```math
R \cdot C \cdot 2^C \cdot 2 \leq 11 \cdot 11 \cdot 2^{11} \cdot 2 = 495\,616
```
y cada estado examina como mucho $4$ rotaciones, por lo que el algoritmo
realiza a lo sumo del orden de $2 \cdot 10^6$ operaciones por caso de prueba,
muy holgado para los límites del problema.

## Indexación del estado en el array de memoización

Para memoizar el resultado, codificamos el estado como un único entero. Si
`profileShift = C + 1`:

```math
\texttt{idx} = ((r \cdot C + c) \ll \texttt{profileShift}) \;|\; (\texttt{profile} \ll 1) \;|\; h
```

Esto reserva $1$ bit para $h$, $C$ bits para `profile` y el resto para la
posición lineal $r \cdot C + c$. El array `memo` se inicializa a $-1$ (estado
no calculado), y guarda $0$ o $1$ una vez resuelto el estado.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [H.cpp](src/H.cpp) | :white_check_mark: |
