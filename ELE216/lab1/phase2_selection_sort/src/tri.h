#include <stdio.h>
#include <stdlib.h>

#define PERMUTER(a, b) { unsigned int t = a; a = b; b = t; }

void tri_selection(unsigned int* tableau, const unsigned int taille);
