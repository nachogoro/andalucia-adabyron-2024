# Introducción a la solución

Queremos saber cuántas cabañas podemos montar como mínimo cumpliendo que si
alguien se encuentra dentro de la cabaña debe cumplirse que:
- Todos sus amigos están dentro de la cabaña.
- Tiene al menos un amigo dentro de la cabaña.

Aunque la amistad no se defina como transitiva en el enunciado, estas
condiciones tienen un efecto similar: si $a$ es amigo de $b$, $a$ y $b$ tienen
que estar juntos en la misma cabaña. Si a su vez $b$ es amigo de $c$ pero $a$
no lo es, para que $b$ pueda estar en la cabaña también debe estarlo $c$, luego
$a$ y $c$ acaban en la misma cabaña en virtud de tener un amigo común aunque no
sean directamente amigos. A efectos prácticos, desde el punto de vista de $a$,
la pertenencia de $c$ está determinada de la misma forma que si la amistad
fuese transitiva.

Podemos modelar el campamento como un grafo bidireccional en el que cada
adolescente es un nodo y cada arista entre dos nodos representa una relación de
amistad. Así, si tratamos la amistad como una propiedad transitiva (por lo
expuesto anteriormente), en la cabaña del nodo $a$ deben ir todos los nodos
alcanzables desde $a$ y ningún nodo no alcanzable desde éste.

Por lo tanto, harán falta tantas cabañas como componentes conexas tenga el
grafo. Podemos encontrar las componentes conexas del grafo de forma sencilla:
- Inicialmente, ningún nodo está asignado a ninguna componente.
- Iteramos nodo a nodo, y cuando encontremos un nodo $i$ no asignado a una
  componente, lanzamos un recorrido (en profundidad o en anchura) comenzando
desde el nodo $i$, en el que asignamos a cada nodo encontrado a una nueva
componente conexa.

En el proceso de coloreado del grafo para asignar cada nodo a una componente
conexa, podemos llevar la cuenta de cuántas componentes conexas hay y cuántos
nodos pertenecen a cada una de ellas.

Una vez tenemos el número de cabañas $k$, con $s$ adolescentes en cada una:
$(s_0, s_1, \dots, s_k)$, el número de combinaciones de delegados posibles es
simplemente:
```math
\prod_{i=0}^{k}{s_i}
```

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [C.cpp](src/C.cpp) | :x:          |
