/**
 * Module resultat - resultat.h
 *
 * Par :Samuel Yactayo-Goulet et Hani OUali
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


/* MUTATEURS DES TITRES */

/**
 * Mutateur de titre (HLR08)
 *
 * Permet d'ajouter une donnée de titre à la structure resultat.
 *
 * resultat : la structure à modifier
 * titre : chaine de caractères constituant le titre à ajouter
 */
void add_titre(t_resultat resultat, t_titre titre);

/* OBSERVATEURS DES RÉSULTATS */

/**
 * Observateur de nombre de titres
 *
 * Permet d'obtenir le nombre de titres de la structure résultat
 *
 * resultat : la structure à observer
 *
 * Retour : strucutre constituant les titres de la structure donnée
 *          en paramètre
 */
int get_nb_titre(t_resultat resultat);

/**
 * Observateur de titres
 *
 * Permet d'obtenir les titres de la structure résultat
 *
 * resultat : la structure à observer
 *
 * Retour : nombre constituant le nombre de titres de la structure donnée
 *          en paramètre
 */
t_titre *get_titres(t_resultat resultat);

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
char* get_tconst(t_titre titre);

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
 * Observateur d'année de début
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


/* MUTATEURS DES TITRES */

/**
* Mutateur de titre principal
*
* Permet d'ajouter le titre principal
*
* critere : la structure a modifier
* titre : chaine de caractères constituant le titre principal à ajouter
*/
void set_primaryTitle(t_titre critere, char *titre);

/**
* Mutateur de genres
*
* Permet d'ajouter les genres
*
* titre : la structure a modifier
* genre : chaine de caractères constituant le genre à ajouter
*/
void set_genres(t_titre critere, char *genre);

/**
* Mutateur d'année de début
*
* Permet d'ajouter l'année de début
*
* critere : la structure a modifier
* annee :  l'année de début à ajouter
*/
void set_startYear(t_titre critere, int annee);

/**
* Mutateur de constante d'identification
*
* Permet d'ajouter la constante d'identification de la structure titre
*
* critere : la structure à modifier
* titre :  la constante d'identification à modifier
*/
void set_tconst(t_titre critere, char *tconst);

/**
* Destructeur de titre
*
* Cette fonction publique permet de libérer une structure titre de la mémoire
*
* titre : la structure a libérer
*/
void detruire_titre(t_titre titre);

/**
* Permet d'écrire dans un fichier.tsv
*
* Reslultat_ptr : pointeur vers la structure
* nom_fichier :  Le nom du fichier a écrire a l'intérieur
*/

#endif