#include "resultat.h"

/**
 * Structure de données représentant les champs d'une entrée de titre du fichier title_basics.tsv
 *
 * tconst: identifiant unique du film
 * primaryTitle: titre du film
 * startYear: année de parution
 * genres: catégorie du titre
 * titleType: catégorie du titre
 */
struct titre {
    char *tconst;
    char *primaryTitle;
    char *startYear;
    int genres; 
    int titleType;
};

/**
 * Structure de données représentant les les résultats de recherche
 *
 * t_titre: liste des titres retenus
 * nb_titre: nombre de titres retenus
 */
struct resultat {
    t_titre* titre;
    int nb_titre;
};

// Constructeur
t_titre creer_titre(void) {
    t_titre titre;

    titre = (t_titre) malloc(sizeof(struct titre));
    
    if (titre) {
        titre->tconst = NULL;
        titre->primaryTitle = NULL;
        titre->startYear = NULL;
        titre->genres = -1;
        titre->titleType = -1;
    }
    
    return titre;
}

t_resultat creer_resultat(void) {
    t_resultat resultat;

    resultat = (t_resultat) malloc(sizeof(struct resultat));
    
    //Si + de films
    if (resultat) {
        *resultat->titre = (t_titre *) realloc(resultat->titre,(resultat->nb_titre+1)*sizeof(t_titre));
    }
    
    resultat->nb_titre = 0;

    return resultat;
}

// Mutateurs
void add_titre(t_resultat resultat, t_titre titre) {
    resultat->titre = titre;
}

int t_fichier_ecrire(t_resultat resultat_ptr, const char* nom_fichier)
{

	/* Ouvrir le fichier */
	FILE* fichier_ptr = fopen(nom_fichier, "w");

	/* Valider */
	if (fichier_ptr == NULL)
	{
		printf("Impossible d'ouvrir le fichier\n");
		return EXIT_FAILURE;
	}

	/* Sauvegarde les composants d'un resultat */
	fprintf(fichier_ptr, "%f\n", resultat_ptr->titre);
	fprintf(fichier_ptr, "%f\n", resultat_ptr->nb_titre);

	/* Fermer le fichier */
	fclose(fichier_ptr);

	return EXIT_SUCCESS;

}
