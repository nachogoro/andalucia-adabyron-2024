# Problema B - Buenos y Malos

El cine y la literatura se han empeñado en enseñarnos que el mundo está lleno
de buenos y malos.

Tomemos como ejemplo los universos de Marvel y DC. Todo el mundo sabe que
Superman, Thor, Green Lantern y Wonder Woman son héroes, mientras que Venom,
Deadpool, Rorschach y Batman son antihéroes. Bueno, quizás no todo el mundo
esté de acuerdo en esta clasificación, pero el objetivo del problema no es
abrir un debate al respecto.

En este problema os proponemos un juego llamado Buenos y Malos. Se os
proporcionará una lista de $N$ nombres y, por cada uno, se indicará si es bueno
o malo. Estos nombres estarán escritos utilizando letras minúsculas.

Vuestro objetivo, como siempre, es ayudar a los buenos a derrotar a los malos.
Para eso, vuestros superpoderes particulares son la programación y la
algoritmia. Sabemos que existen una serie de bloqueadores capaces de derrotar a
un personaje. Un bloqueador, en nuestro universo particular, es una cadena de
caracteres, de longitud mayor o igual a 1, que es prefijo de algún personaje.
En este problema debéis encontrar un conjunto de bloqueadores cuya suma de
longitudes sea mínima y de tal forma que todos los personajes malos sean
derrotados (es decir, para cada uno existe un bloqueador en el conjunto que es
prefijo de su nombre) y ningún personaje bueno sea derrotado (es decir, ninguno
de los bloqueadores propuestos es prefijo de su nombre).

## Entrada

La primera línea de la entrada contiene un entero $N$ indicando el número de
personajes en la simulación.

A continuación, $N$ líneas describiendo a cada personaje. Cada línea empieza
con un carácter $C$. Si el personaje es bueno, entonces $C$ es '+', mientras
que si el personaje es malo, entonces $C$ es '-'. A continuación, y SIN estar
separado por espacio, el nombre del personaje cuya longitud es al menos 1
carácter.

## Salida

Si no es posible encontrar un conjunto de bloqueadores que derroten a todos los
malos manteniendo a salvo a todos los buenos, se deberá imprimir una única
línea con el entero -1.

En caso contrario, en la primera línea se debe imprimir el número de
bloqueadores $X$. Después $X$ líneas, cada una imprimiendo un bloqueador. Los
bloqueadores deben ser mostrados en orden lexicográfico. Además, se garantiza
que la respuesta será única para todos los casos de prueba.

## Restricciones

- $1 < N < 2 \times 10^5$
- La suma de las longitudes de los nombres de los personajes no excederá el
  valor $2 \times 10^5$

## Ejemplos de Entrada y Salida

### Entrada de ejemplo
```
4
-angela
+antonia
-nico
+olga
```

### Salida de ejemplo
```
2
ang
n
```

**Explicación:** fíjate que "ang" es un prefijo del personaje malo "angela", pero
no es prefijo de ningún personaje bueno. De forma similar, "n" es un prefijo
del personaje malo "nico", pero no es prefijo de ningún personaje bueno. Por
tanto, existe un bloqueador para cada personaje malo y ningún bloqueador para
los personajes buenos. Por último, no existen bloqueadores más cortos que
cumplan las restricciones del problema, por ejemplo, "an" también sería un
bloqueador válido para "angela", pero bloquearía al personaje bueno "antonia".

### Entrada de ejemplo
```
3
-ana
+anabella
+anahi
```

### Salida de ejemplo
```
-1
```

**Explicación:** cualquier prefijo del personaje malo "ana" es también prefijo
de los personajes buenos "anabella" y "anahi", por lo que no se puede bloquear
a "ana" sin bloquear también a los personajes buenos.

### Entrada de ejemplo
```
2
+anabel
-anabela
```

### Salida de ejemplo
```
1
anabela
```

**Explicación:** Fíjate que un nombre completo también es un prefijo válido de
ese nombre.
