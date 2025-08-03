# Problema K - Juego de Letras

Tras ver el famoso programa de televisión "Cifras y Letras" nos hemos dado
cuenta de que no ganaríamos casi nada en la parte de letras. El juego consiste
en, dado un conjunto de vocales y consonantes, intentar conseguir la palabra
más larga posible que aparezca en el Diccionario de la lengua española de la
Real Academia Española. Hemos decidido hacer una aproximación al juego, de modo
que como entrada recibiremos un conjunto de letras que pueden estar repetidas,
vocales sin acentuar y consonantes (todas minúsculas), y a continuación una
serie de palabras del diccionario. El objetivo es devolver, si es posible, la
palabra más larga de las suministradas, que puede formarse utilizando letras
del multiconjunto de letras proporcionado. Cada letra del multiconjunto puede
utilizarse como mucho una vez para formar una de las palabras del diccionario.

## Entrada

La entrada tiene $N + 2$ líneas. La primera línea de la entrada contiene la
secuencia de letras. La siguiente línea contiene el número de palabras que se
quieren comprobar ($N$). Las siguientes $N$ líneas contienen palabras del
diccionario.

Consideramos que $1 \leq N \leq 8 * 10^4$ . Cada palabra, así como la primera
línea, tendrá un máximo de 26 letras. Se garantiza que las palabras no
contienen tildes.

## Salida

La salida debe contener una única línea con el mensaje `No es posible` si no
hemos podido formar ninguna de las palabras suministradas. En otro caso, se
devolverá la palabra del diccionario de la máxima longitud que hayamos
conseguido crear. Si hubiese más de una con la misma longitud se devolvería la
primera en orden lexicográfico.

## Ejemplos de Entrada y Salida

### Entrada de ejemplo
```
aaeoollgg
7
gallega
galleta
argolla
gazapo
anilla
geotermia
gallego
```

### Salida de ejemplo
```
gallega
```
