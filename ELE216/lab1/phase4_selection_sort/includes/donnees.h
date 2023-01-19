#include <stdlib.h>
#include <stdio.h>

/* Genere un nombre aleatoire entre a et b */
#define RANDBETWEEN(a,b) (a + (int)(rand() % (b - a)))

unsigned int* generer_n_nombres_aleatoires(unsigned n, unsigned min, unsigned max);
