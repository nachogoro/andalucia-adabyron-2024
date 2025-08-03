# Problema J - Voluntarios

Este año la plataforma Voluntarios Sin Fronteras vuelve a recaudar dinero, en
esta ocasión, para ayudar a niños y niñas que viven las consecuencias de
conflictos armados. La donación a la plataforma se puede realizar como siempre,
llamando gratis al teléfono 900 30 20 10 o bien a través de Bizum al número
11013 (la cantidad máxima que se puede donar es de 500 euros).

A lo largo de estos años las donaciones han sido muy variadas, pero
habitualmente hay ciertas cantidades de dinero que se suelen repetir entre los
donantes. Este año se ha decidido analizar más en detalle las donaciones para
determinar con exactitud cuál es la cantidad de dinero que más se repite en
cada campaña.

## Entrada

La entrada consta de una serie de casos de prueba.

Cada caso se compone de 2 líneas. La primera línea contiene el número de
donaciones realizadas, $N$, siendo $0 < N \leq 1.000.000$.

La segunda línea representa cada una de las donaciones realizadas en euros,
separadas por espacio.

No se admiten donaciones con valores decimales.

El final de entrada se reconoce como $N = 0$.

## Salida

Para cada caso la salida es la donación que más se repite. En caso de que haya
empate, se debe devolver la donación de menor valor.

## Ejemplos de Entrada y Salida

### Entrada de ejemplo
```
10
25 50 100 25 30 25 35 5 100 5
12
8 75 30 4 50 10 10 50 10 10 60 10
7
250 50 80 50 250 70 100
0
```

### Salida de ejemplo
```
25
10
50
```
