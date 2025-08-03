# Problema I - Tendencias

La empresa textil Eurotex está interesada en analizar los datos de las últimas
ventas realizadas en sus establecimientos para identificar tendencias o valores
atípicos y así tomar decisiones para mejorar o definir nuevas estrategias de
negocio que le ayuden a alcanzar nuevos objetivos.

Para ello, a partir de los datos diarios del número de ventas que tuvieron
lugar en sus establecimientos, ha decidido calcular el Análisis de Riesgo
Estándar (ARE) que consiste en obtener, para cada día, cuántos días anteriores
consecutivos, incluido el día actual, el número de ventas ha sido menor o igual
a las ventas del día actual.

Por ejemplo, si el número de ventas que tuvieron lugar durante 7 días fue:

```
100, 80, 60, 70, 60, 75, 85
```

el ARE correspondiente sería:

```
1 1 1 2 1 4 6
```

## Entrada

La entrada consta de una serie de casos de prueba.

Cada caso se compone de 2 líneas. La primera línea contiene el número de días a
analizar, $N$, siendo $0 < N \leq 500000$.

Además, se garantiza que el número total de días entre todos los casos de
prueba también es menor o igual a 500000. La segunda línea representa el número
de artículos vendidos diariamente, separados por espacio. El número de ventas
diarias será un valor entero entre 1 y 10000.

El final de la entrada se reconoce como $N = 0$.

## Salida

Para cada caso de prueba la salida es una línea con el ARE para cada día.

## Ejemplos de Entrada y Salida

### Entrada de ejemplo
```
7
100 80 60 70 60 75 85
10
25 530 120 910 330 50 50 102 55 75
15
56 67 45 2 46 57 68 79 80 90 189 200 398 560 72
0
```

### Salida de ejemplo
```
1 1 1 2 1 4 6
1 2 1 4 1 1 2 3 1 2
1 2 1 1 3 4 7 8 9 10 11 12 13 14 1
```
