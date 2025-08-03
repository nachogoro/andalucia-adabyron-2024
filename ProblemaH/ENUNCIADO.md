# Problema H - Scalextric

Estás algo aburrido y, para entretenerte, encuentras un juego de rompecabezas
llamado "Scalextric" y juegas un rato. No has sido capaz de encontrar una
solución a mano para un circuito, y piensas que no es posible. Por esta razón,
decides escribir un programa que te diga si es así.

El juego se desarrolla en una cuadrícula con $R$ filas y $C$ columnas que
contiene piezas para formar un circuito ($R \times C$ piezas). Cada pieza del
circuito contiene un punto negro en el centro y líneas negras en la dirección
de algunas, ninguna o todas sus piezas vecinas al norte ($N$), este ($E$), sur
($S$) y oeste ($W$), con la siguiente restricción: si dos direcciones opuestas
tienen líneas, al menos una de las otras dos direcciones también tiene una
línea. En otras palabras, está prohibido que una pieza consista solo en una
línea recta.

El objetivo del juego es crear un circuito válido girando las diferentes piezas
tantas veces como se quiera. En un circuito válido si una pieza tiene una línea
que va en una dirección de la brújula (es decir, norte, este, sur u oeste),
entonces tiene una pieza vecina en esa dirección de la brújula y esa pieza
vecina tiene una línea que va en la dirección opuesta de la brújula. En otras
palabras, cada conexión entre piezas del circuito debe tener una línea en ambos
lados o en ninguno. Debemos tener en cuenta que cada uno de los giros que se le
aplique a una pieza será de 90°. Así, podremos girar cada pieza 90°, 180° o
270°. Para que la solución sea correcta, toda línea debe conectar con la línea
de una pieza vecina.

Tu tarea consiste en determinar si un circuito dado tiene solución.

## Entrada

La entrada consta de varios casos de prueba.

La primera línea de cada caso de prueba contiene los dos números enteros $R$ y
$C$, separados por espacios, con $1 \leq R, C < 12$.

Las siguientes $R$ líneas de entrada contienen cada una la descripción de una
fila de la cuadrícula para formar un circuito, de norte a sur. Cada una de
estas filas contiene exactamente $C$ cadenas de letras, separadas por espacios,
que corresponden a piezas del circuito, de oeste a este. Su formato es el
siguiente:

- Si la cadena es el único carácter `x`, la pieza no contiene ninguna línea con
  ninguno de sus vecinos.
- En caso contrario, la cadena contiene uno o más de los caracteres $N$, $E$,
  $S$, $W$, que indican que una línea negra se extiende desde el centro de
dicha pieza en dirección a su vecino norte, este, sur u oeste, respectivamente.
Ningún carácter aparecerá en la cadena más de una vez.

La entrada se termina con una línea que contiene `0 0`. Estos ceros no son un
caso de prueba y no deben procesarse.

## Salida

Para cada caso de prueba, la salida es `SOLUCIONABLE` si hay una solución al
rompecabezas, y `NOSOLUCIONABLE` en caso contrario.

## Ejemplos de Entrada y Salida

### Entrada de ejemplo
```
3 3
NW NW x
NES NESW W
E W x
2 2
ES x
x N
1 2
NE N
2 2
N N
N N
O O
```

### Salida de ejemplo
```
SOLUCIONABLE
NOSOLUCIONABLE
NOSOLUCIONABLE
SOLUCIONABLE
```
