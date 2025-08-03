# Problema G - Paintball

A un grupo de amigos les gusta organizar actividades divertidas los fines de
semana. Este fin de semana quieren organizar una partida de paintball, esa
divertida actividad en la que los participantes se disparan pintura unos a
otros. Para ello, tienen que montar dos equipos: el equipo rojo y el equipo
azul. Y enseguida surgen los piques:

- María, tenemos que ir en equipos distintos porque ese tiro por la espalda de
  la otra vez te lo tengo que devolver.
- Vale. Y yo tengo una deuda pendiente con Juan...

En suma, el problema es el siguiente: en este grupo existen ciertas rivalidades
(amistosas, por supuesto). Cuando dos personas son rivales, quieren ir en
equipos distintos para poder dispararse a placer. Tu objetivo es, dada una
serie de rivalidades, determinar si es posible formar equipos que cumplan con
esta restricción. Es importante tener en cuenta que los equipos no tienen por
qué estar equilibrados en número (si un equipo es más pequeño que otro, siempre
se puede compensar dándoles mejor posición o más munición).

Por ejemplo, supongamos que los amigos son cuatro (Lucía, María, Juan y Pablo).
Lucía es rival de María, María es rival de Juan y Juan es rival de Pablo.
Entonces, la asignación es posible (por ejemplo, podríamos poner a Lucía y Juan
en el equipo rojo, y a María y Pablo en el azul. En este ejemplo los dos
equipos tienen el mismo número de integrantes, pero no tiene por qué ser
necesariamente así.  También puede haber otras asignaciones que sean igualmente
válidas, pero en este problema basta con saber si existe o no alguna). En
cambio, si resulta que Lucía es rival de María, María es rival de Juan y Juan
es rival de Lucía, no hay asignación posible que no ponga a dos rivales en el
mismo equipo.

## Entrada

La primera línea de la entrada contendrá un valor entero entre 1 y 1000,
correspondiente al número de casos de prueba.

Cada caso de prueba tendrá una primera línea con dos valores enteros $n > 0$ y
$m > 0$, separados por espacios. $n$ es el número de amigos, y $m$ el número de
rivalidades. Los amigos se numeran del 1 al $n$.

Las siguientes $m$ líneas contendrán, cada una de ellas, dos valores enteros
positivos representando una rivalidad. Si una línea contiene los valores $i$
$j$, quiere decir que el $i$-ésimo amigo del grupo es rival del $j$-ésimo.
Supondremos que nadie es rival de sí mismo (todos están mentalmente sanos).

Después de terminar cada caso de prueba, el siguiente (si es que hay más, según
la primera línea) empezaría en la línea siguiente.

## Salida

La salida será una línea con la cadena "Que comience la batalla", si existe una
asignación de equipos que cumple las restricciones, o "Mejor nos vamos de cena
o algo", en caso contrario.

## Ejemplos de Entrada y Salida

### Entrada de ejemplo
```
2
4 3
1 2
2 3
3 4
3 3
1 2
2 3
3 1
```

### Salida de ejemplo
```
Que comience la batalla
Mejor nos vamos de cena o algo
```

### Entrada de ejemplo
```
1
10 10
1 2
2 3
3 4
4 1
4 5
5 6
6 7
7 4
8 9
9 1
```

### Salida de ejemplo
```
Que comience la batalla
```
