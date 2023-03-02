/**
 * Programme principal - main.c
 *
 * Par : Samuel Yactayo-Goulet
 * Date : Janvier 2023
 *
 * Le programme main permet à un utilisateur de rentrer manuellement des 
 * parametre de recherche. Il permet aussi de tester des fonctions.
 *
 * Exemple d'exécution:
 *  ./a.out -t "The Matrix" -c "movie" -a "1990:2000"
 */

#include "recherche.h"
#include "resultat.h"
#include "imdb.h"
#include "Test.c"

int main(int argc, char *argv[]) {
    char *titre = NULL, *genre = NULL, *annees = NULL, *categorie = NULL, *evaluation = NULL;
    
    //Test_Mutateur();
    Test_Mutateur2();
    t_critere critere1 = creer_critere();
    t_resultat resultat_rechercher = creer_resultat();
    t_resultat resultat_rechercher1 = creer_resultat();
    t_resultat resultat_rechercher2 = creer_resultat();
    set_titre(critere1,"The Matrix");

    resultat_rechercher1 = get_critere(critere1,resultat_rechercher);
    get_cote(resultat_rechercher2);
    
    // Lab2-HLR01 - Arguments provenant du terminal
    // Si aucun argument n'est donné, le programme s'arrête
    if (argc < 2) {
       printf("Invalide! Pas assez de paramètres!\n");
       return -1;
    }

    #include <unistd.h>

    // Lab2-HLR02 - Arguments possibles
    for (int i = 1; i < argc; i++) {
        // Option de titre
        if (getopt(argc, argv[i], "-t")) {
            // On passe a l'argument qui vient après l'option
            i++;
            titre = argv[i];
        }
        if (getopt(argc, argv[i], "-c")) {
            // On passe a l'argument qui vient après l'option
            i++;
            categorie = argv[i];
        }
        if (getopt(argc, argv[i], "-a")) {
            // On passe a l'argument qui vient après l'option
            i++;
             annees = argv[i];
        }
        if (getopt(argc, argv[i], "-g")) {
            // On passe a l'argument qui vient après l'option
            i++;
            genre = argv[i];
        }
        if (getopt(argc, argv[i], "-v")) {
            // On passe a l'argument qui vient après l'option
            i++;
            evaluation = argv[i];
        }
    
    }

    

    // Lab2-HLR03 - Argument obligatoire
    if (titre == NULL) {
        printf("Commande invalide");
        return 0;
        
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
    t_resultat resultat = creer_resultat();


    //t_resultat resultat_1 = creer_resultat();
    t_resultat resultat_2 = creer_resultat();

    set_primaryTitle(un_titre,"The Matrix");
    set_genres(un_titre,"Action,Sci-Fi");


    printf("Titre :  %s\n", get_titre(critere));
    printf("Categorie :  %s \n", get_categorie(critere));
    printf("Annees :  %d:%d\n", get_annee_parution_min(critere), get_annee_parution_max(critere));

    // ./Debug/client
    // ./Debug/client -t "The Matrix" -c "Action,Sci-Fi" -a "1990:2000"
    // tconst : tt0133093
    // titleType : movie
    // primaryTitle : The Matrix
    // originalTitle : The Matrix
    // isAdult : 0
    // startYear : 1998
    // endYear : \N 
    // runtimeMinutes : 136
    // genres : Action,Sci-Fi

    // Lab2-HLR17 - Visualisation des résultats - ajout de cotes

    // La fonction définie au HLR09 doit écrire dans un deuxième fichier TSV tous les résultats de cotes
    // t_resultat_ecrire(resultat, "title_ratings.tsv");

    // Lab2-HLR23 - Spécification concernant la base de données

    // Les noms de la base de données doivent absolument être : title.basics.tsv et title.ratings.tsv.

    // Lab2-HLR24 - Exploration de la base de données

    // Le programme principal doit explorer les deux fichiers de base de données en utilisant les fonctions du module imdb
    get_critere(critere, resultat_rechercher);
    get_cote(resultat);
    
    // Lab2-HLR25 - Retour des résultats à l'utilisateur
    int taille = get_nb_titre(resultat);
    
    printf("Vos résultats de recherche :\n\n");
    for (int i = 0; i < taille; i++)
    {
        printf("Titre :  %s\n", get_titre(critere));
        printf("Categorie :  %s \n", get_categorie(critere));
        printf("Annees :  %d:%d\n\n", get_annee_parution_min(critere), get_annee_parution_max(critere));
    }

    // Lab2-HLR26 - Gestion de mémoire

    detruire_critere(critere);
    detruire_critere(titre);
    detruire_critere(resultat);
    detruire_critere(resultat_2);
    detruire_critere(resultat_rechercher);

    return 0;
}

