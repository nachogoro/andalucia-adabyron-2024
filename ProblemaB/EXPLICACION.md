# Introducción a la solución

Queremos determinar si es posible bloquear a todos los villanos usando prefijos
que no bloqueen a ningún héroe. Para ello, se busca el conjunto mínimo de
prefijos tal que:

- Cada villano tiene al menos un prefijo que coincide con el inicio de su nombre.
- Ningún héroe tiene como prefijo alguno de los seleccionados.

De aquí se deduce que si algún villano es prefijo de algún héroe, entonces no
podrá haber solución (porque cualquier prefijo que bloquee al villano bloqueará
también al héroe).

Se puede construir una estructura tipo *trie* (árbol de prefijos) para
representar los nombres. En cada nodo podemos almacenar cuántos héroes y
villanos pasan por él, y si el nodo representa el final de un héroe o de un
villano.

## Recorrido del Trie

Una vez hemos construido el árbol de prefijos, podemos hacer un recorrido
recursivo, descendiendo por todas las ramas aún no bloqueadas en las que sigan
existiendo villanos (si en una rama no existen villanos, no será necesario
bloquearla y podemos ignorarla):

- Si de un nodo cuelga al menos un villano pero ningún héroe, entonces es un
  prefijo válido: todos los villanos que pasen por este nodo o estén más abajo
pueden bloquearse con él sin afectar a ningún héroe. Si bloqueamos en este
instante, estaremos utilizando el prefijo más corto para bloquear a estos
villanos.
- Si un nodo marca el final de un villano y además tiene héroes colgando de él,
  ese villano es prefijo de un héroe. En tal caso, no existe solución válida.

Este recorrido garantiza que se eligen prefijos lo más altos posibles en el
árbol de prefijos, lo cual minimiza su longitud y número.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [B.cpp](src/B.cpp) | :x:          |
