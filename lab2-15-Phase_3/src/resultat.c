
#include "../includes/resultat.h"

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
    //HLR15
    double averageRating;
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

    resultat = (t_resultat)malloc(sizeof(struct resultat));
    
    // Si on a plus de nombre de nombre de titres
    /*if (resultat == NULL) {
        resultat->titre = (t_titre *) realloc(resultat->titre,(resultat->nb_titre+1)*sizeof(t_titre));
    }*/
    resultat->titre = NULL;
    resultat->nb_titre = 0;

    return resultat;
}

// Mutateurs
void add_titre(t_resultat resultat, t_titre titre) {

t_titre Temporaire = creer_titre();
resultat->nb_titre++;
resultat->titre= (t_titre *) realloc(resultat->titre,(resultat->nb_titre)*sizeof(t_titre));

strcpy(&Temporaire->tconst,&titre->tconst);
  
strcpy(&Temporaire->primaryTitle, &titre->primaryTitle);
Temporaire->startYear = titre->startYear;
strcpy(&Temporaire->genres, &titre->genres);
strcpy(&Temporaire->titleType ,&titre->titleType);

    resultat->titre=&Temporaire;
 //  resultat->titre[resultat->nb_titre-1]=Temporaire;
    free(Temporaire);
}
/*HLR16*/
void add_cote(t_titre titre, double note, int nb_votes) {
    titre->averageRating = note;
    titre->numVotes = nb_votes;
}

// Observateurs
t_titre *get_titres(t_resultat resultat) {
    return resultat->titre;
}
int get_i_eme_titre(int i, t_resultat resultat) {
    for (int i = 0; i < resultat->nb_titre; i++)
        if (i == resultat->nb_titre)
            return resultat->nb_titre;
}
int get_nb_titre(t_resultat resultat) {
    return resultat->nb_titre;
}

char* get_tconst(t_titre titre) {
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
double get_averageRating(t_titre titre){
    return titre->averageRating;
};

int* get_numVotes(t_titre titre){
    return titre->numVotes;
}

char* get_resultat_tconst(t_resultat resultat, int nb_resultat)
{
return get_tconst(resultat->titre[nb_resultat]);

}
int get_resultat_nb_titre(t_resultat resultat){
return resultat->nb_titre;
}

void set_primaryTitle(t_titre critere, char *titre) {
    critere->primaryTitle= titre;
}

void set_genres(t_titre critere, char *genre) {
    critere->genres = genre;
}

void set_startYear(t_titre critere, int annee) {
    critere->startYear = annee;
}
void set_tconst(t_titre critere, char *tconst) {
    critere->tconst = tconst;
}
void set_titleType(t_titre critere, char *titleType) {
    critere->titleType= titleType;
}
void detruire_titre(t_titre titre) {
    free(titre);
}
void set_averageRating(t_titre critere, double averageRating) {
    critere->averageRating = averageRating;
}
void set_numVotes(t_titre critere, int *numVotes) {
    critere->numVotes = numVotes;
}
void t_resultat_ecrire(t_resultat resultat_ptr, const char* nom_fichier)
{
    char* titre = get_titres(resultat_ptr);
    int nb_titre = get_nb_titre(resultat_ptr);
    
    /* Ouvrir le fichier */
	FILE* fichier_ptr = fopen(nom_fichier, "w");

	/* Valider */
	if (fichier_ptr == NULL)
	{
		printf("Impossible d'ouvrir le fichier\n");
		EXIT_FAILURE;
	}

	/* Sauvegarde les composants d'un resultat */
	fprintf(fichier_ptr, "%s\n", titre);
	fprintf(fichier_ptr, "%i\n", nb_titre);

	/* Fermer le fichier */
	fclose(fichier_ptr);

}