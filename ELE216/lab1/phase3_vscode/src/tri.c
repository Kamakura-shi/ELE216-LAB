#include "donnees.h"

/* Tri par selection */
void tri_selection(unsigned int* tableau, const unsigned int taille)
{

	unsigned int i_min;

	for (unsigned int i = 0; i < taille - 1; i++)
	{

		/* Assumer que le min est la valeur de gauche */
		i_min = i;

		/* Parcourir la sequence de droite */
		for (unsigned int j = i + 1; j < taille; j++)
		{

			/* Si la valeur courante est plus petite que la reference, je permute */
			if (tableau[j] < tableau[i_min])
			{
				i_min = j;
			}

		}

		/* Permuter la valeur a gauche completement avec la plus petite trouvee */
		PERMUTER(tableau[i], tableau[i_min]);

	}

}
