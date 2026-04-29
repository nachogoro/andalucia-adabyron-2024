# Introducción a la solución
Para saber si una palabra $s$ se puede formar con un conjunto de letras $C$,
basta con contar la frecuencia de aparición $f_i$ de cada letra $c_i$ en $s$, y
comprobar si la letra $c_i$ aparece al menos $f_i$ veces en $C$.

Para ello, podemos convertir tanto el conjunto de letras $C$ como cada palabra
candidata $s_i$ en un diccionario clave-valor que mapea cada letra a su
frecuencia, y compara dichos diccionarios para saber si $s_i$ puede formarse
con un subconjunto de $C$.


# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [K.cpp](src/K.cpp) | :white_check_mark:          |
