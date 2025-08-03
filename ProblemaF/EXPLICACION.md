# Introducción a la solución

Para un número $n$, podemos calcular el número de dígitos en base 10 como
$\lfloor \log10(n+1) \rfloor$.

Puesto que la suma es conmutativa, podemos iterar sobre los dígitos de $n$ en
cualquier orden. Para iterar por los dígitos de un número podemos transformarlo
en una cadena de texto e iterar por sus caracteres, convirtiéndolos de nuevo a
entero; o podemos iterativamente obtener el último dígito de un número como $n
\mod 10$, y descartarlo mediante $n / 10$, hasta que el número sea 0.


# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [A.cpp](src/A.cpp) | :x:          |
