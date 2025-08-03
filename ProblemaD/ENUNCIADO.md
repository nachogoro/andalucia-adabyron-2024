# Problema D - Cromos

Tiago es un niño que tiene una única pasión en la vida: coleccionar cromos para
completar sus álbumes favoritos. El último álbum que Tiago logró completar fue
el de los Fantasy Riders.

Para completar los álbumes Tiago debe comprar sobres con cromos. Cada uno de
los cuales contiene 5 cromos, pero Tiago no sabe qué cromos le saldrán antes de
comprarlos. Es por esto que siempre debe comprar muchos sobres extras, pues es
muy probable que al comprarlos le salgan cromos que ya tenía (también conocidos
en la jerga de los coleccionistas como *repes*).

Después de completar su último álbum, el de los Fantasy Riders, Tiago se enteró
que también era posible comprar cromos sueltos escogiendo los que quisiera a
través de la tienda online. Si Tiago se hubiese enterado antes de esto no
habría acumulado tantos cromos repetidos, pues simplemente podría haber
comprado los cromos que le faltaban.

Tiago además se pregunta si comprando cromos sueltos se podría haber gastado
menos dinero. En realidad, él cree que hubiese sido mejor idea comprar sobres
hasta cierto punto y después de eso comprar sueltos todos los cromos que le
faltaban y que no habían salido en los sobres. Por suerte Tiago es un niño muy
ordenado y anotó los cromos que le salieron en cada uno de los sobres que
compró. ¿Podéis ayudarlo?

El álbum consiste en $N$ cromos y por simplicidad nos referiremos a ellos con
los números del $1$ al $N$.  Cada sobre tiene un precio $P$ y contiene $5$
cromos. Además se conoce el precio asociado a la compra de cada cromo suelto.

Vuestra tarea será la de encontrar la mínima cantidad de dinero que Tiago
podría haber gastado para completar toda la colección si hubiese dejado de
comprar sobres en algún punto y luego hubiese comprado cromos sueltos.

## Entrada

La primera línea de la entrada contiene tres enteros positivos separados por un
espacio. Estos se corresponden respectivamente con la cantidad de cromos del
álbum ($N$), la cantidad de sobres comprados por Tiago ($S$) y el precio de
cada sobre ($P$). Debemos tener en cuenta que: $0 < N < 50000$, $0 < S <
50000$, $0 < P < 1000$.

La segunda línea contiene $N$ enteros positivos separados por espacios
correspondientes a los precios de cada cromo. El primer entero al precio del
cromo $1$, el segundo al precio del cromo $2$, etc. El precio de cada cromo
será mayor o igual que $1$ y menor o igual que $5000$.

Las siguientes $S$ líneas contienen la descripción de cada sobre que compró
Tiago. Cada una de estas líneas contiene $5$ enteros entre $1$ y $N$
describiendo los cromos que salieron en el sobre.

Debes asumir que considerando todos los sobres es posible juntar los $N$
cromos. Además Tiago no compró sobres extras, es decir, en el último sobre
obtuvo los últimos cromos que le faltaban.

## Salida

Debes imprimir un solo entero correspondiente a la mínima cantidad de dinero
que podría haber gastado Tiago si solo hubiese comprado sobres hasta cierto
punto y luego hubiese comprado el resto de los cromos sueltos.

## Ejemplos de Entrada y Salida

### Entrada de ejemplo
```
7 4 5
5 4 1 1 1 1 10
3 4 5 6 5
5 4 3 7 3
1 3 3 4 6
2 3 7 4 6
```

### Salida de ejemplo
```
19
```

En el primer ejemplo, el álbum está compuesto por 7 cromos. Tiago compró 4
sobres y cada uno costó 5 euros. En este caso a Tiago le hubiese convenido
comprar solo hasta el segundo sobre. De esta forma Tiago hubiese conseguido los
cromos 3, 4, 5, 6 y 7 gastando 10 euros en sobres. Luego podría haber comprado
los cromos 1 y 2 por 5 y 4 euros respectivamente para un total de 19 euros
sumando a lo que había gastado en sobres. Si os fijáis, Tiago podría haber
gastado la misma cantidad de dinero si hubiese comprado hasta el tercer sobre y
luego el cromo 2 suelto.

### Entrada de ejemplo
```
7 4 5
5 4 1 1 1 1 10
3 4 5 6 5
5 4 3 6 3
1 2 3 4 6
2 3 7 4 6
```

### Salida de ejemplo
```
20
```

En el segundo ejemplo comprar cromos sueltos no hubiese ayudado a Tiago y lo
óptimo hubiese sido comprar todos los sobres por 5 euros cada uno para un total
de 20 euros.
