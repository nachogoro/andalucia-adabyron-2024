# Introducción a la solución
El problema consiste en decidir si es posible dividir a los participantes en
dos grupos, de tal forma que no haya dos rivales en el mismo equipo.

Podemos modelar el problema como un grafo, en el que cada participante es un
nodo, y una relación de rivalidad entre dos personas se representa como una
arista que conecta ambos nodos. De esta forma, el problema se reduce a
comprobar si el grafo es bipartito o no (es decir, si podemos colorearlo usando
dos colores, de tal forma que no existan nodos adyacentes con el mismo color).

Podemos hacer esto de forma sencilla mediante un recorrido en profundidad o en
anchura. Originalmente, todos los nodos del grafo estarán sin colorear.
Elegimos un nodo sin colorear cualquiera y le asignamos un color arbitrario
$c_1$, y a continuación pintamos a sus nodos inmediatamente adyacentes del
color contrario $c_2$; y a los nodos adyacentes a estos (a dos aristas del
original) de nuevo de $c_1$, etc. Si en algún momento nos encontramos que hemos
de colorear un nodo ya coloreado de un color distinto al que tiene, quiere
decir que el grafo no es bipartito.

Es posible que existan varias componentes independientes en el grafo ("islas"
de nodos, no conectadas entre ellas por aristas), por lo que debemos comprobar
que cada una de ellas es bipartita. El grafo total será bipartito si y solo si
cada una de sus componentes independientes lo son.


# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [G.cpp](src/G.cpp) | :x:          |
