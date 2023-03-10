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
    double averageRating;
    int numVotes;
};

/**
 * Structure de données représentant les résultats de recherche
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

// Destructeurs
void detruire_titre(t_titre titre) {
    free(titre);
}

// Mutateurs
void set_primaryTitle(t_titre critere, char *titre) {
    critere->primaryTitle= titre;
}

void set_genres(t_titre critere, char *genre) {
    critere->genres = genre;
}

void set_annee_parution_mins(t_titre critere, int annee) {
    critere->startYear = annee;
}
void set_tconst(t_titre critere, char *tconst) {
    critere->tconst = tconst;
}
void set_titleType(t_titre critere, char* titleType) {
    critere->titleType= titleType;
}
// void set_titleType(t_titre critere, char* titleType) {
//     char* string = (char*)malloc(strlen(titleType));
//     strcpy(string, titleType);
//     critere->titleType= titleType;
// }
/*
    char* une_chaine;
    strcpy(une_chaine, "ma ma chaine");
    set_titleType(critere,une_chaine (987678667)); //adresse
    get_titleType(critere);      //donne ma chaine
    strcpy(une_chaine, "lHsUf");
    get_titleType(critere);          //donne une erreur: lHsUf
*/
void add_titre(t_resultat resultat, t_titre titre) {
    char *tconst = get_tconst(titre);
    char *primaryTitle = get_primaryTitle(titre);
    int startYear = get_startYear(titre);
    char *genres = get_genres(titre);
    char *titleType = get_titleType(titre);

    resultat->titre = strdup(tconst);
    resultat->titre = strdup(primaryTitle);
    resultat->titre = strdup(startYear);
    resultat->titre = strdup(genres);
    resultat->titre = strdup(titleType);
}

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

double get_averageRating(t_titre titre) {
    return titre->averageRating;
}

int get_numVotes(t_titre titre) {
    return titre->numVotes;
}