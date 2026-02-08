# Introducción a la solución

Podemos transformar el problema en una variante del clásico problema de la
mochila 0-1: para una capacidad fija (en este caso, la cantidad de masa
disponible), se desea elegir un subconjunto de posibles objetos (bollos) que
maximice el valor total (dinero obtenido).

En este problema:

- El valor de cada bollo preñado es $d_i$.
- El "peso" (lo que consume de masa) es $c_i$.
- La cantidad máxima que podemos fabricar está limitada por $\frac{a_i}{b_i}$
  (número de bollos posibles del tipo $i$, dado el chorizo disponible) y por
$\frac{n}{c_i}$ (número de bollos posibles de tipo $i$, dada la masa
disponible). Podremos hacer como mucho $\min(\frac{a_i}{b_i},\frac{n}{c_i})$
- Los bollos sin chorizo también hay que considerarlos, ya que pueden
  producirse en cualquier cantidad limitada solo por la masa: $\frac{n}{c_y}$.

El desafío está en manejar eficientemente los límites superiores en las
cantidades de cada tipo de bollo.

## Descomposición binaria

Una solución ingenua sería considerar todos los bollos posibles como objetos
individuales (es decir, si podemos realizar $k$ bollos de un cierto tipo $i$,
tratar cada uno de esos bollos como un objeto individual, de coste $c_i$ y
beneficio $d_i$), pero sería muy ineficiente en tiempo y espacio. En lugar de
eso, usamos **descomposición binaria**, una técnica que permite reducir el
número de objetos a considerar de forma eficiente.

Supongamos que podemos hacer hasta $14$ bollos de cierto tipo. En lugar de
generar $14$ objetos con el mismo peso y valor, descomponemos esa cantidad en
la medida de lo posible como suma de potencias de dos:

```math
14 = 1 + 2 + 4 + 7
```

Esto nos permite representar cualquier cantidad entre 0 y 14 usando solo 4 objetos:

- Objeto 1: peso = `1 * c_i`, valor = `1 * d_i`
- Objeto 2: peso = `2 * c_i`, valor = `2 * d_i`
- Objeto 3: peso = `4 * c_i`, valor = `4 * d_i`
- Objeto 4: peso = `7 * c_i`, valor = `7 * d_i`

Así, la cantidad de objetos utilizados se reduce de $k$ a $\log2(k)$.

## Resolución detallada

1. Para cada tipo de bollo preñado:
   - Calculamos cuántos podemos hacer con el chorizo y masa disponibles para
     cada tipo $i$:
   
   $$k_i = \min(\frac{a_i}{b_i},\frac{n}{c_i})$$

   - Usamos descomposición binaria para crear $\log2(k_i)$ subobjetos
     equivalentes.

3. Para el tipo de bollo sin chorizo:
    - Calculamos cuántos podemos hacer con la masa disponible:
    
    $$k_y = \frac{n}{c_y}$$
   
   - Usamos descomposición binaria para crear $\log2(k_y)$ subobjetos
     equivalentes.
   - Lo tratamos como un tipo de bollo más.

5. Aplicamos el algoritmo clásico de la mochila 0-1:
   - Mantenemos un array bidimensional $dp$ de tamaño $\text{\\# objetos a
     considerar} \times (n+1)$.
   - Para un orden arbitrario de los objetos, para cada objeto $j$ con peso
     $w_j$ y beneficio $v_j$, y cantidad de masa $m' < m$ calculamos el valor
máximo obtenible con $m'$ gramos de masa si sólo usamos objetos que preceden al
objeto $j$ y potencialmente el objeto $j$ como:

    $$dp[j][m'] = \max(v_j + dp[j-1][m'-w_j], dp[j-1][m'])$$

6. El valor $dp[\text{\\# objetos a considerar}][n]$ es el valor buscado.

### Optimización de espacio
Podemos utilizar un array unidimensional en lugar de uno bidimensional si para
cada objeto $j$ iteramos sobre las cantidades de masa posible en orden
decreciente:
```math
dp[m'] = \max(dp[m'], v_j + dp[m' - w_j])
```

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [A.cpp](src/A.cpp) | :x:          |

