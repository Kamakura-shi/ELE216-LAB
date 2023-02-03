/**
 * Module resultat - resultat.h
 *
 * Par : Hani OUali
 * Date : Janvier 2023
 * Le module resultat est responsable de gérer les resultats
 * de la recherche effectuee à l'aide de structures encapsulees de données
 */

#ifndef RESULTAT_H
#define RESULTAT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Encapsulation de la structure titre (HLR04)
 * Les champs sont accessibles seulement à l'intérieur du module resultat.c
 */
typedef struct titre* t_titre;

/**
 * Encapsulation de la structure resultat (HLR06)
 * Les champs sont accessibles seulement à l'intérieur du module resultat.c
 */
typedef struct resultat* t_resultat;

/**
 * Constructeur de titre (HLR05)
 *
 * Cette fonction publique permet d'allouer dynamiquement une structure de titre.
 * Elle place des valeurs par défaut dans les membres de celle-ci.
 *
 * Retour : pointeur vers la structure allouée
 */
t_titre creer_titre(void);

/**
 * Constructeur de resultat (HLR07)
 *
 * Cette fonction publique permet d'allouer dynamiquement une structure de resultat.
 * Elle place des valeurs par défaut dans les membres de celle-ci.
 *
 * Retour : pointeur vers la structure allouée
 */
t_resultat creer_resultat(void);


/* MUTATEURS DES CRITÈRES */

/**
 * Mutateur de titre (HLR08)
 *
 * Permet d'ajouter une donnée de titre à la structure resultat.
 *
 * resultat : la structure à modifier
 * titre : chaine de caractères constituant le titre à ajouter
 */
void add_titre(t_resultat resultat, t_titre titre);

/**
 * Mutateur de titre (HLR15)
 *
 * Permet d'ajouter une donnée de titre à la structure titre.
 *
 * resultat : la structure à modifier
 * titre : chaine de caractères constituant le titre à ajouter
 */
void add_cote(t_titre titre, int averageRating, int numVotes);


/* OBSERVATEURS DES TITRES */

/**
 * Observateur de constante d'identification
 *
 * Permet d'obtenir la constante d'identification de la structure titre
 *
 * titre : la structure à observer
 *
 * Retour : chaine de caractères constituant la constante d'identification de la structure donnée
 *          en paramètre
 */
int get_tconst(t_titre titre);

/**
 * Observateur de titre principal
 *
 * Permet d'obtenir le titre principal de la structure titre
 *
 * titre : la structure à observer
 *
 * Retour : chaine de caractères constituant le titre principal de la structure donnée
 *          en paramètre
 */
char* get_primaryTitle(t_titre titre);

/**
 * Observateur de d'année de début
 *
 * Permet d'obtenir l'année de début de la structure titre
 *
 * titre : la structure à observer
 *
 * Retour : l'année constituant le début de l'intervalle de la structure donnée
 *          en paramètre
 */
int get_startYear(t_titre titre);

/**
 * Observateurs de genres
 *
 * Permet d'obtenir les genres de la structure titre
 *
 * titre : la structure à observer
 *
 * Retour : chaine de caractères constituant les genres de la structure donnée
 *          en paramètre
 */
char* get_genres(t_titre titre);

/**
 * Observateurs de type de titre
 *
 * Permet d'obtenir le type de titre de la structure titre
 *
 * titre : la structure à observer
 *
 * Retour : chaine de caractères constituant le type de titre de la structure donnée
 *          en paramètre
 */
char* get_titleType(t_titre titre);


/**
/* Permet d'écrire dans un fichier TSV tous les résultats (HLR09)
*
* resultat_ptr : la structure à visualiser
* nom_fichier : fichier à ecrire
*/
int t_resultat_ecrire(t_resultat resultat_ptr, const char* nom_fichier);

#endif
