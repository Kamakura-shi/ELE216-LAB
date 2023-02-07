/**
 * Module resultat - imdb.h
 *
 * Par : Hani OUali
 * Date : Janvier 2023
 * Le module imdb est responsable de gérer les resultats
 * de la recherche effectuee à l'aide de structures encapsulees de données
 */

#ifndef IMDB_H
#define IMDB_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "recherche.h"
#include "resultat.h"

#define SUCCESS 1
#define ECHEC 0

/**
 * Permet de comparer un titre du fichier title_basics.tsv aux critères de recherches (HLR13).
 *
 * critere : la structure à modifier
 * titre : chaine de caractères constituant le titre à ajouter
 */
int comparer_titre_critere(t_critere critere, t_titre* titre);

/**
 * Permet de comparer une ligne de cote du fichier title_ratings.tsv aux résultats de titres retenus (HLR21).
 *
 * tconst_cote : identifiant unique de la cote
 * tconst_titre : identifiant unique des titres retenus
 * titre : chaine de caractères constituant le titre à ajouter
 */
int comparer_cote_titre(char* tconst_cote, char* tconst_titre, t_titre* titre);

/**
 * Constructeur de resultat (HLR14)
 *
 * Permet de comparer un titre du fichier title_basics.tsv aux critères de recherches et
 * d'ajouter une donnée de titre à la structure resultat.
 *
 * critere : la structure à modifier
 * titre : chaine de caractères constituant le titre à ajouter
 * resultat : la structure à modifier
 * 
 * Retour : pointeur vers la structure allouée
 */
t_resultat recherche_titre_creation_resultat(t_critere critere, t_titre titre);

#endif