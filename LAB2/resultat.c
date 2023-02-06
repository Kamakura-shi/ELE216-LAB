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
    int startYear;
    char *genres; 
    char *titleType;
    int averageRating;
    int numVotes;
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
        titre->startYear = -1;
        titre->genres = NULL;
        titre->titleType = NULL;
        titre->averageRating = -1;
        titre->numVotes = -1;
    }
    
    return titre;
}

t_resultat creer_resultat(void) {
    t_resultat resultat;

    resultat = (t_resultat) malloc(sizeof(struct resultat));
    
    // Si on a plus de nombre de nombre de titres
    if (resultat == NULL) {
        resultat->titre = (t_titre *) realloc(resultat->titre,(resultat->nb_titre+1)*sizeof(t_titre));
    }
    
    resultat->nb_titre = 0;

    return resultat;
}

// Mutateurs
void add_titre(t_resultat resultat, t_titre titre) {
    resultat->titre = titre;
}

void add_cote(t_titre titre, int note, int nb_votes) {
    titre->averageRating = note;
    titre->numVotes = nb_votes;
}

// Observateurs
char *get_tconst(t_titre titre) {
    return titre->tconst;
}

char* get_primaryTitle(t_titre titre) {
    return titre->primaryTitle;
}

int get_startYear(t_titre titre) {
    return titre->startYear;
}

char* get_genres(t_titre titre) {
    return titre->genres;
}

char* get_titleType(t_titre titre) {
    return titre->titleType;
}

int get_averageRating(t_titre titre) {
    return titre->averageRating;
}

int get_numVotes(t_titre titre) {
    return titre->numVotes;
}

int t_resultat_ecrire(t_resultat resultat_ptr, const char* nom_fichier)
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
	fprintf(fichier_ptr, "%i\n", resultat_ptr->titre);
	fprintf(fichier_ptr, "%i\n", resultat_ptr->nb_titre);

	/* Fermer le fichier */
	fclose(fichier_ptr);

	return EXIT_SUCCESS;

}