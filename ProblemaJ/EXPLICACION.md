# Introducción a la solución

Para calcular el número más frecuente de una secuencia de números podemos
almacenar en un diccionario/mapa clave-valor el número de ocurrencias hasta
ahora de cada número.

Al finalizar, podríamos iterar sobre todas las claves almacenadas (números que
han aparecido) cuál tiene el valor (frecuencia de aparición) mayor. Para mayor
eficiencia, podemos llevar la cuenta de cuál es el número más frecuente a
medida que procesamos la lista de números: tras actualizar la frecuencia de
aparición de un número, vemos si ahora es mayor que la frecuencia de aparición
del más común hasta ahora (o, si es idéntica, si el número actual es menor que
el más frecuente hasta ahora), y en ese caso nuestro número pasa a ser el más
frecuente.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [J.cpp](src/J.cpp) | :x:          |
