#include "imdb.h"

void comparer_titre_critere(t_critere critere, t_titre titre, t_resultat resultat) {
    // La fonction compare le titre donné avec l'argument -t
    // et le titre du champ primaryTitle d'une ligne du
    // fichier de base de données
    for (int i = 1; i < argc; i++) {
        // Option de titre
        if (strcmp(argv[i], "-t") == 0) {
            // On passe a l'argument qui vient après l'option
            i++;
            titre = argv[i];
        }
    }

    // S'ils concordent
    if(critere==titre) {
        // L'entrée est conservée dans les résultats
        add_titre(resultat, titre);
    }
    // Si un genre, une catégorie de titre et/ou des années de parution sont présents dans les critères de recherches
    if() {
        // Ils doivent être utilisés pour filtrer les résultats retenus
    }
}

void recherche_titre_creation_resultat(t_critere critere, t_titre titre, t_resultat resultat)
{
    // Lire chaque ligne : HLR10 (fopen, r)

    // Pour chaque ligne lue, décomposer la ligne de titre : HLR12 (strtok)

    // Comparer cette ligne décomposée avec les critères de recherche : HLR13 (strcmp)
    comparer_titre_critere(critere, titre);

    // Ajouter le titre de la base de données aux résultats (HLR08)
    add_titre(resultat, titre);

    // La structure de résultats est maintenantremplie de titres qui répondent aux critères de
    // recherche

    // La fonction retourne un pointeur vers la structure résultat
    return resultat;
}