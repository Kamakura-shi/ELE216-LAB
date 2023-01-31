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

        
    // ...
    // À COMPLÉTER 
    // ...
    
    // Libérer la mémoire
    detruire_critere(critere);

    return 0;
}
