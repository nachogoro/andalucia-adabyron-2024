# Problema A - Bollos preñados

Estache Bo, un reconocido cocinero gallego, va a hacer bollos preñados para
vender.

Estache Bo tiene $n$ gramos de masa y $m$ tipos de chorizos diferentes. Los
tipos de chorizos están numerados del $1$ al $m$. Estache Bo sabe que le quedan
$a_i$ gramos del $i$-ésimo tipo de chorizo. Se necesitan exactamente $b_i$
gramos del tipo de chorizo $i$ y $c_i$ gramos de masa para cocinar un bollo
preñado con el $i$-ésimo tipo de chorizo. Ese bollo puede venderse por $d_i$
euros.

También puede hacer bollos sin relleno. Cada uno de estos bollos requiere $c_y$
gramos de masa y puede venderse por $d_y$ euros. Así pues, Estache Bo puede
hacer cualquier número de bollos con diferentes tipos de chorizos o sin ellos,
a menos que se le acabe la masa y los chorizos. Estache Bo tira todo el
material sobrante que quede después de hornear.

Halla el número máximo de euros que puede ganar Estache Bo.

## Entrada

La primera línea contiene 4 enteros $n$, $m$, $c_y$ y $d_y$:

```math
1 \leq n < 1000,\quad 1 \leq m < 50,\quad 1 \leq c_y, d_y < 100
```

Cada una de las $m$ líneas siguientes contiene 4 enteros. La $i$-ésima línea
contiene los números $a_i$, $b_i$, $c_i$ y $d_i$:

```math
1 \leq a_i, b_i, c_i, d_i < 100
```

## Salida

El número máximo de euros que puede ganar Estache Bo.

## Ejemplos de Entrada y Salida

### Entrada
```
10 2 2 1
7 3 2 100
12 3 1 10
```

### Salida
```
241
```

### Entrada
```
100 1 25 50
15 5 20 10
```

### Salida
```
200
```
