/**
 * Programme principal - main.c
 *
 * Par :
 * Date : 
 *
 * À compléter...
 *
 * Exemple d'exécution:
 *  ./a.out -t "The Matrix" -c "movie" -a "1990:2000"
 */

#include "recherche.h"
#include "resultat.h"
#include "imdb.h"

/**
/* Permet d'écrire dans un fichier TSV tous les résultats (HLR09)
*
* resultat_ptr : la structure à visualiser
* nom_fichier : fichier à ecrire
*/
void t_resultat_ecrire(t_resultat resultat_ptr, const char* nom_fichier);

int main(int argc, char *argv[]) {
    char *titre = NULL, *genre = NULL, *annees = NULL, *categorie = NULL;
    
    // Lab2-HLR01 - Arguments provenant du terminal
    // Si aucun argument n'est donné, le programme s'arrête
    if (argc < 2) {
        printf("Invalide! Pas assez de paramètres!\n");
        return -1;
        // ...
        // À COMPLÉTER
        // ...
    }

    // Lab2-HLR02 - Arguments possibles
    for (int i = 1; i < argc; i++) {
        // Option de titre
        if (strcmp(argv[i], "-t") == 0) {
            // On passe a l'argument qui vient après l'option
            i++;
            titre = argv[i];
        }
        if (strcmp(argv[i], "-c") == 0) {
            // On passe a l'argument qui vient après l'option
            i++;
            categorie = argv[i];
        }
        if (strcmp(argv[i], "-a") == 0) {
            // On passe a l'argument qui vient après l'option
            i++;
             annees = argv[i];
        }
        if (strcmp(argv[i], "-g") == 0) {
            // On passe a l'argument qui vient après l'option
            i++;
            genre = argv[i];
        }
        // ...
        // À COMPLÉTER pour les autres options possibles.
        // ...
    }

    // Lab2-HLR03 - Argument obligatoire
    if (titre == NULL) {

        return 0;
        // ...
        // À COMPLÉTER
        // ...
    }

    // Création de la structure critere et stockage des arguments reçus
    t_critere critere = creer_critere();

    set_titre(critere, titre);
    if (categorie) 
        set_categorie(critere, categorie);
    if (genre) 
        set_genre(critere, genre);
    if (annees) 
        set_intervalle_annees(critere, annees);

    // Lab2-HLR04 à HLR09

    // Création de la structure titre
    t_titre un_titre = creer_titre();

    // Création de la structure résultat
    t_resultat un_resultat = creer_resultat();

    // Ajout à la structure résultat
    add_titre(un_resultat, un_titre);

    // Extraction des résultats dans un fichier TSV
    t_resultat_ecrire(un_resultat, "résultats.tsv");

    // tconst : titre-­>tconst = "The Matrix" : tt0133093

    t_titre titres = creer_titre();

    t_resultat resultat = creer_resultat();

    set_titre(titres,"The Matrix");
    set_genres(titres,"Action,Sci-Fi");

    add_titre(resultat,titres);

    printf("Titre : %s\n", get_titre(critere));
    printf("Catégorie : %s \n", get_categorie(critere));
    printf("Années : %d:%d\n", get_annee_parution_min(critere), get_annee_parution_max(critere));

    // ./Debug/main -t "The Matrix" -c "Action,Sci-Fi" -a "1990:2000"

    // Lab2-HLR17 - Visualisation des résultats - ajout de cotes

    // La fonction définie au HLR09 doit écrire dans un deuxième fichier TSV tous les résultats de cotes
    t_resultat_ecrire(resultat, "résultats_cotes.tsv");

    // Lab2-HLR23 - Spécification concernant la base de données

    // Les noms de la base de données doivent absolument être : title.basics.tsv et title.ratings.tsv.

    // Lab2-HLR24 - Exploration de la base de données

    // Le programme principal doit explorer les deux fichiers de base de données en utilisant les fonctions du module imdb
    // get_critere(critere, "title.basics.tsv");
    // get_cote(resultat, "title.ratings.tsv");
    
    // Lab2-HLR25 - Retour des résultats à l'utilisateur

    // Création de la structure résultat
    t_resultat resultats = creer_resultat();

    // Interaction avec la base de données

    // ...
    // À COMPLÉTER 
    // ...
    
    // Lab2-HLR26 - Gestion de mémoire

    // Toute mémoire allouée se doit d'être désallouée correctement avant de quitter le programme
    
    // Libérer la mémoire
    detruire_critere(critere);

    return 0;
}

void t_resultat_ecrire(t_resultat resultat_ptr, const char* nom_fichier)
{
    /* Ouvrir le fichier */
	FILE* fichier_ptr = fopen(nom_fichier, "w");

	/* Valider */
	if (fichier_ptr == NULL)
	{
		printf("Impossible d'ouvrir le fichier\n");
		EXIT_FAILURE;
	}

	/* Sauvegarde les composants d'un resultat */
	fprintf(fichier_ptr, "%s\n", resultat_ptr);

	/* Fermer le fichier */
	fclose(fichier_ptr);
}
