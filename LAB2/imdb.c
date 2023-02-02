#include "imdb.h"

void comparer_titre_critere(t_critere critere, t_titre titre) {
    char* genre = get_genre(critere), * categorie = get_categorie(critere);
    int annee_parution_min = get_annee_parution_min(critere), annee_parution_max = get_annee_parution_max(critere), valide = SUCCESS;
    // La fonction compare le titre donné avec l'argument -t et le titre du champ primaryTitle d'une ligne du
    // fichier de base de données. Le -t indique des titres (primaryTitle).
    // Si un genre, une catégorie de titre et/ou des années de parution sont présents dans les critères de recherches
    // Ils doivent être utilisés pour filtrer les résultats retenus

    /* Validation */
    if (genre == -1)
        return valide = ECHEC;
    if (categorie == -1)
        return valide = ECHEC;
    if (annee_parution_min == -1)
        return valide = ECHEC;
    if (annee_parution_max == -1)
        return valide = ECHEC;
    // S'ils ne concordent pas, l'entrée n'est pas conservée dans les résultats
    if (strcmp(titre, "-t") != 0)
        return valide = ECHEC;
    return valide;
}

void recherche_titre_creation_resultat(t_critere critere, t_titre titre)
{
    // Lire chaque ligne : HLR10 (fopen, r)

    // Pour chaque ligne lue, décomposer la ligne de titre : HLR12 (strsep)

    // Comparer cette ligne décomposée avec les critères de recherche : HLR13 (strcmp)
    comparer_titre_critere(critere, titre);

    t_resultat resultat = creer_resultat();

    // Ajouter le titre de la base de données aux résultats (HLR08)
    add_titre(resultat, titre);

    // La structure de résultats est maintenantremplie de titres qui répondent aux critères de
    // recherche

    // La fonction retourne un pointeur vers la structure résultat
    return resultat;
}