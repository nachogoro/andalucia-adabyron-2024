# Problema E - Lazarillo

En la cafetería de una facultad atiende un camarero peculiar llamado Lazarillo,
el cual es conocido por sus famosas frases y su buen trato con el alumnado. Con
el motivo de este concurso está algo estresado, ya que aún le queda trabajo por
hacer y muchas ganas de llegar a casa. Uno de esos trabajos es recoger los
vasos sucios que están repartidos por distintas mesas. Como Lazarillo tiene
prisa, te pide que le ayudes a identificar el área de la cafetería donde se
encuentra el mayor número de vasos.

Para ello, Lazarillo divide la cafetería en una matriz formada por $R$ filas y
$C$ columnas, donde cada celda nos indica el número de vasos que contiene la
mesa que corresponde a dicha celda. Además, te indica las $Q$ áreas de la
cafetería a consultar para saber el número de vasos que hay en cada una de
ellas. Tu objetivo es identificar el área que contiene más vasos y especificar
el número de vasos que contiene.

## Entrada

La primera línea del input contiene dos enteros positivos separados por un
espacio, que se corresponden con los valores de $R$ y $C$. Las siguientes $R$
líneas están compuestas por $C$ enteros positivos separados por espacios, con
los valores de cada una de las celdas. La primera línea corresponde con la
primera fila, la segunda línea con la segunda fila, y así sucesivamente. El
valor de cada celda está en el rango $[0, 99]$, es decir, el mínimo número de
vasos por celda es $0$ y el máximo es $99$.

La siguiente línea contiene el entero $Q$, indicando el número de consultas a
realizar. Las siguientes $Q$ líneas contienen cinco enteros $id$, $r_1$, $c_1$,
$r_2$, $c_2$ separados por espacios, donde $1 \leq r_1 \leq r_2 \leq R$ y $1
\leq c_1 \leq c_2 \leq C$. El valor id es el identificador y los otros valores
definen las esquinas superior izquierda $(r_1, c_1)$ e inferior derecha $(r_2,
c_2)$ del área de la cafetería a consultar.

## Salida

La salida debe contener una línea que contiene el *id* del área con más vasos y
el número de vasos, separados por un espacio. En caso de dos áreas con el mismo
número máximo de vasos, se muestra el área con el id menor.

## Restricciones

- $1 \leq R, C \leq 1000$
- $1 \leq Q \leq 50000$
- $1 \leq r_1 \leq r_2 \leq R$
- $1 \leq c_1 \leq c_2 \leq C$

## Ejemplos de Entrada y Salida

### Entrada de ejemplo
```
5 7
1 2 4 1 1 0 1
0 1 0 3 1 3 1
1 0 0 1 0 0 0
0 1 5 0 0 3 0
1 6 0 0 5 2 1
3
1 1 2 3 5
2 2 4 4 6
3 4 1 5 7
```

### Salida de ejemplo
```
3 24
```

Explicación:

En este ejemplo, con $R = 5$ y $C = 7$, se consultan tres áreas con *ids*: $1$,
$2$ y $3$. El resultado de este ejemplo es $3 24$, ya que el área con *id* =
$3$ contiene $24$ vasos, el área con *id* = $1$ contiene $14$ y el área con
*id* = $2$ contiene $11$ vasos.
