# Problema C - Campamento de Verano

Tenemos que organizar el campamento de verano de la Xunta de Galicia. Se trata
de una instalación en la naturaleza donde vamos a colocar tiendas de campaña.
El campamento debe alojar $N$ adolescentes, y el organizador debe decidir
cuántas tiendas de campaña se van a montar.

Para tomar esa decisión, cada campista entrega al organizador una lista de
amigos con los que quiere que se le aloje en la misma tienda. La amistad es
mutua, si un campista $i$ es amigo de un campista $j$, entonces $j$ también es
amigo de $i$. Sin embargo, la amistad NO es transitiva, si $i$ es amigo de $j$,
y $j$ es amigo de $k$, eso no quiere decir que necesariamente $i$ sea amigo de
$k$.

Todos los amigos hay que asignarlos a la misma tienda. Asumimos que las tiendas
son lo suficientemente grandes para alojar a todos los amigos. Pero el
organizador debe minimizar la presencia de adolescentes que no son amigos en la
misma tienda. Esto es, dado el número de campistas y la lista de amistades, el
programa debe proporcionar el número máximo de tiendas, manteniendo a las
personas que son amigas juntas y sin incluir a personas que no sean amigas de
nadie en la misma tienda.

En cada tienda, el organizador debe escoger una de las personas que se van a
alojar allí como el delegado de la tienda. El delegado será la persona de la
tienda contacto del director del campo, y responsable de que la tienda esté
ordenada y limpia. El programa debe proporcionar el número de posibilidades de
selección de delegados de tienda. Por ejemplo, si tenemos tres tiendas, con
campistas $t_1(1,2)$, $t_2(3,4)$, y $t_3(5)$, hay cuatro posibilidades de
elección de delegados $(1,3,5)$, $(1,4,5)$, $(2,3,5)$ y $(2,4,5)$.

Dado que el número de posibilidades de elección de delegados puede ser muy
grande, muestra este valor módulo $10^9 + 7$.

## Entrada

La primera línea de la entrada contiene un único número entero T $(1 < T < 5)$
que indica el número de casos de prueba. A continuación, se describen los casos
de prueba.

La primera línea de cada caso de prueba contiene dos números enteros separados
por espacios $N$ y $M$, que denotan el número de campistas $(1 < N < 10)$ y el
número de relaciones de amistad $(0 < M < 10^5)$, respectivamente.

Cada una de las siguientes $M$ líneas contiene dos números enteros $i$ y $j$
$(1 \leq i,j \leq N, i eq j)$ separados por espacios, lo que indica que el
campista $i$ y el campista $j$ son amigos. Para cualquier par de campistas $i$
y $j$ tal que $1 \leq i,j \leq N$, como mucho existe un par de entre $(i,j)$ y
$(j,i)$ en la entrada.

## Salida

Para cada caso de prueba, muestra una sola línea que contenga dos números
enteros separados por un espacio, el primero indica el número máximo de tiendas
de campaña manteniendo a los amigos juntos y el segundo indica el número de
opciones de seleccionar los delegados módulo $10^9 + 7$.

## Ejemplos de Entrada y Salida

### Entrada de ejemplo
```
3
4 2
1 2
2 3
5 3
1 2
2 3
1 3
6 3
1 2
3 4
5 6
```

### Salida de ejemplo
```
2 3
3 3
3 8
```
