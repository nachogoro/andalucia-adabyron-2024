# Introducción a la solución

Queremos determinar el mínimo gasto posible que habría hecho Tiago si, en lugar
de comprar todos los sobres, hubiera optado por:

- Comprar algunos sobres (empezando desde el primero).
- Y luego completar los cromos que aún le faltaban comprándolos individualmente.

Para ello, vamos a simular paso a paso la compra de sobres. Después de cada
sobre $i$, nos preguntamos:

- ¿Cuánto ha gastado Tiago hasta ahora solo en sobres? Lo llamamos $d_i$.
- ¿Cuánto costaría comprar los cromos que aún le faltan por separado? Lo
  llamamos $r_i$.

La suma $d_i + r_i$ representa el coste total si Tiago hubiera parado justo
después del sobre $i$ y hubiera comprado el resto de los cromos
individualmente.

Al final, elegiremos el mínimo de todos esos valores:
```math
\min_{i=0}^{S}(d_i+r_i)
```
donde $S$ es el número total de sobres.

Para que esta simulación sea eficiente:

- Mantenemos un conjunto de los cromos que aún faltan.
- Inicialmente, Tiago no ha comprado sobres, así que el coste total es
  simplemente la suma de los precios de todos los cromos ($r_0$).
- A medida que compramos sobres, aumentamos $d_i$ sumando el precio del sobre
  $P$.
- Por cada nuevo cromo no repetido que aparece en un sobre, restamos su precio
  de $r_i$ (porque ya no lo tenemos que comprar suelto).

Este proceso se puede hacer en tiempo lineal en el número total de cromos y
sobres, si usamos un array de booleanos para marcar los cromos obtenidos.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [D.cpp](src/D.cpp) | :x:          |
