# Problema F - Número Seguro

Cuando las personas usuarias del banco CaixaGalega solicitan una tarjeta de
crédito a la entidad bancaria esta es enviada a las personas interesadas por
correo postal, pero para activarla les piden generar una contraseña numérica
segura, que cumpla una determinada propiedad matemática. Para CaixaGalega un
número seguro es aquel que es igual a la suma de sus dígitos elevados a la
potencia de su número de cifras.

Por ejemplo, el número 371 es un número seguro, ya que:

```math
371 = 3^3 + 7^3 + 1^3 = 27 + 343 + 1 = 371
```

Dada la dificultad que supone para César, cliente de CaixaGalega, determinar si
su contraseña es un número seguro, este solicitó a un amigo que desarrollara un
programa que determine si su propuesta de contraseña es número seguro o no.

## Entrada

La entrada consta de una serie de casos de prueba. Cada caso es un número
entero positivo $n$, siendo $0 < n < 100000$.

El final de la entrada se reconoce por el entero 0.

## Salida

Para cada caso de prueba, la salida es `SEGURO` si el número es seguro e
`INSEGURO` en caso contrario.

## Ejemplos de Entrada y Salida

### Entrada de ejemplo
```
8
372
1634
154
0
```

### Salida de ejemplo
```
SEGURO
INSEGURO
SEGURO
INSEGURO
```
