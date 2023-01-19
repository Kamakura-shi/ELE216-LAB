#include "donnees.h"

/* Genere un tableau de taille n et le remplit de nombres aleatoiress */
unsigned int* generer_n_nombres_aleatoires(unsigned n, unsigned min, unsigned max)
{

	/*  Allocation de memoire */
	unsigned int* tableau = (unsigned int*)malloc(n * sizeof(int));

	/* Verification */
	if (tableau == NULL)
	{
		return NULL;
	}

	/* Inserer les nombres aleatoires */
	for (unsigned i = 0; i < n; i++)
	{

		tableau[i] = RANDBETWEEN(min,max);

	}

	return tableau;

}
