#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "donnees.h"
#include "tri.h"

int main(void)
{
	
	unsigned int* tableau;
	
	tableau = generer_n_nombres_aleatoires(10, 0, 100);

	for (unsigned int i = 0; i < 10; i++)
		{
			printf("%3u ", tableau[i]);
		}
		printf("\n");

	
	tri_selection(tableau, 10);

	for (unsigned int i = 0; i < 10; i++)
		{
			printf("%3u ", tableau[i]);
		}
		printf("\n");

}
