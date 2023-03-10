#include "imdb.h"

int comparer_titre_critere(t_critere critere, t_titre *titre)
{
    char *genre = get_genre(critere), *categorie = get_categorie(critere);
    int annee_parution_min = get_annee_parution_min(critere), annee_parution_max = get_annee_parution_max(critere), valide = SUCCES;

    /* Validation */
    if (genre == 0)
        return ECHEC;
    if (categorie == 0)
        return ECHEC;
    if (annee_parution_min == -1)
        return ECHEC;
    if (annee_parution_max == -1)
        return ECHEC;

    critere = get_titre(critere);
    titre = get_primaryTitle(titre);

    // La fonction compare : le titre donné; avec : l'argument -t et le titre du champ primaryTitle d'une ligne du
    // fichier de base de données. Le -t indique des titres (primaryTitle).
    // Si le titre donné et celui du champ ne concordent pas, l'entrée n'est pas conservée dans les résultats
    if (strcmp(critere, titre) != 0)
        return ECHEC;

    // Si un genre, une catégorie de titre et/ou des années de parution sont présents dans les critères de recherches
    // Ils doivent être utilisés pour filtrer les résultats retenus
    if (strstr(genre, titre) != 0)
        return ECHEC;
    if (strstr(categorie, titre) != 0)
        return ECHEC;
    if (strstr(annee_parution_min, titre) != 0)
        return ECHEC;
    if (strstr(annee_parution_max, titre) != 0)
        return ECHEC;

    // L'entrée est conservée dans les résultats
    return SUCCES;
}

int comparer_cote_titre(const char *tconst_cote, t_resultat *resultat)
{
    t_titre *titre;

    // /* Validation */
    // if (averageRating == -1)
    //     return ECHEC;
    // if (numVotes == -1)
    //     return ECHEC;

    char *tconst_titre;
    for (int i = 0; i < get_nb_titre(resultat); i++)
    {
        titre = get_i_eme_titre(i, resultat);

        tconst_titre = get_tconst(titre); //get tconst du ieme titre

        // Si l'identifiant unique de la cote n'est pas identique à ceux des titres retenus, on retourne un code d'echec
        if (strcmp(tconst_cote, tconst_titre) != 0)
            return ECHEC;
        
        // On ajoute le classement au titre
        int numVotes = get_numVotes(titre);
        double averageRating = get_averageRating(titre);
        
        // Il faut que les données de la cote soient ajoutées à la structure de titre qui lui correspond
        add_cote(titre, averageRating, numVotes);
    }
    // L'entrée est conservée dans les résultats
    return SUCCES;
}

t_resultat recherche_titre_creation_resultat(t_critere critere, t_titre titre)
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