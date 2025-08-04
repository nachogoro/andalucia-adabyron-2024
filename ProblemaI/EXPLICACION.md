# Introducción a la solución

Queremos calcular el Análisis de Riesgo Estándar (ARE) para cada día a partir
de la serie de ventas diarias. El ARE de un día $i$ es el número de días
anteriores consecutivos (incluyendo el actual) en los que el número de ventas
fue **menor o igual** al del día $i$.

Una solución naïf revisaría para cada posición $i$ las ventas de días
anteriores uno a uno, hasta encontrar un día con ventas mayores. En el caso
peor (ventas crecientes), cada día se revisarían todos los días anteriores,
obteniendo un coste $O(n^2)$, demasiado costoso.

Existen dos alternativas más eficientes para resolver este problema: utilizando
una pila o utilizando saltos mediante un array de programación dinámica. La
idea fundamental en ambas aproximaciones es la misma: dado un día $i$, todos
los días anteriores con ventas inferiores a las del día $i$ dejan de ser
relevantes para el futuro: si para un $j > i$ su racha no muere en $i$ (porque
en $i$ se vendió menos que en $j$), tampoco morirá en ningún día anterior a $i$
que vendiese menos que $i$.

## Solución 1: Pila Monótona

La pila nos ayuda a encontrar el índice más reciente anterior al día actual
donde la venta fue **mayor** que la actual. Todo lo que esté encima en la pila
y tenga ventas **menores o iguales** ya no es útil.

### Algoritmo paso a paso

1. Inicializa una pila vacía (guardará índices).
2. Recorre el array `ventas` de izquierda a derecha:
   - Mientras la pila **no esté vacía** y `ventas[stack.top()] <= ventas[i]`,
     hacemos `stack.pop()` (eliminamos de la pila los días anteriores al
nuestro con ventas menores que las nuestras).
   - Si la pila queda vacía, entonces todas las ventas anteriores eran menores
     o iguales → `ARE[i] = i + 1`.
   - Si no, el elemento en la cima es el **último día con ventas mayores**, así
     que:
     ```
     ARE[i] = i - stack.top()
     ```
   - Finalmente, añadimos el índice actual a la pila: `stack.push(i)`.

### Complejidad

- Cada índice entra y sale de la pila **una sola vez**.
- Complejidad total: $O(N)$.

## Solución 2: Saltos hacia atrás (con DP)

Esta solución evita el uso de una pila haciendo uso del array de solución
parcialmente construido (al que llamaremos $dp$). $dp[i]$ representa cuántos
días consecutivos anteriores (incluyéndose) han tenido ventas menores o iguales
a las del día $i$.

La idea es que, en lugar de recorrer día por día hacia atrás, podemos saltar
directamente al final de la última racha conocida, ahorrando tiempo y evitando
trabajo repetido:

- Si $ventas[i - 1] > ventas[i]$, el día anterior rompe la racha y el único día
  que cuenta es el actual: $dp[i] = 1$.
- En cambio, si $ventas[i-1] \leq ventas[i]$, existe una racha anterior que
  podría extenderse.
Sabemos que $dp[i-1]$ nos indica hasta cuántos días atrás (desde $i-1$) se
extiende esa racha. Esto nos lleva al índice:
```math
    p=(i−1)−dp[i−1]
```
Pero aún no sabemos si $ventas[p]$ rompe o no la racha del día $i$. Si
$ventas[p] \leq ventas[i]$, entonces el día $p$ también puede incluirse en la
racha de $i$, y todos los días consecutivos inmediatamente anteriores a $p$ y
con ventas menores que $ventas[p]$ (es decir, $dp[p]$ elementos empezando a
contar en $p$). En ese caso, repetimos el proceso: saltamos hacia atrás desde
$p$ usando $dp[p]$.

- Repetimos el proceso en bucle hasta encontrar un día $k$ tal que $ventas[k] >
  ventas[i]$ (ese día rompe la racha), o hasta que no quede ninguno (es decir,
hemos llegado al inicio y $ventas[i]$ ha sido mayor o igual a todas las
anteriores).
    - Si encontramos un $k < i$ tal que $ventas[k] > ventas[i]$, la racha se
      extiende desde $k+1$ hasta $i$, así que:
```math
dp[i]=i−k
```
    - Si no hay tal $k$ (porque todos los días previos tienen ventas menores o
      iguales), entonces $dp[i] = i + 1$.

### Complejidad

Aunque contiene un `while`, cada posición `ptr` se visita **una sola vez**
gracias a los saltos por `dp[ptr]`, por lo tanto la complejidad total sigue
siendo $O(N)$ amortizado.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [I.cpp](src/I.cpp) | :x:          |
