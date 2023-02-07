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

/**
 * Destructeur de titre
 *
 * Cette fonction publique permet de libérer une structure titre de la mémoire
 *
 * titre : la structure à libérer
 */
void detruire_titre(t_titre titre);


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
void add_cote(t_titre titre, double averageRating, int numVotes);

/**
/* Permet de definir le titre
*
* critere : la structure a modifier
* titre :  titre a ecrire
*/
void set_primaryTitle(t_titre critere, char *titre);
/**
/* Permet de definir le genre
*
* critere : la structure a modifier
* titre :  le genre a ecrire
*/
void set_genres(t_titre critere, char *genre) ;
/**
/* Permet de definir l anner de parution min
*
* critere : la structure a modifier
* titre :  le anner de parution min a ecrire
*/
void set_annee_parution_mins(t_titre critere, int annee) ;
/**
/* Permet de definir le Tcons
*
* critere : la structure a modifier
* titre :  le Tconst a ecrire
*/
void set_tconst(t_titre critere, char *tconst);
/**
/* Permet de detruire une structure titre
*
* titre : la structure a modifier
*
*/
void set_averageRating(t_titre critere, double averageRating);
/**
/* Permet de definir le nombre de vote
*
* critere : la structure a modifier
* titre :  le nombre de vote a ecrire
*/
void set_numVotes(t_titre critere, int *numVotes);


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
t_titre *get_titres(t_resultat resultat);

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
int get_nb_titre(t_resultat resultat);

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
 * Observateur de note moyenne
 *
 * Permet d'obtenir la note moyenne de la structure titre
 *
 * titre : la structure à observer
 *
 * Retour : la note moyenne de la structure donnée
 *          en paramètre
 */
double get_averageRating(t_titre titre);

/**
 * Observateur de nombre de votes
 *
 * Permet d'obtenir le nombre de votes de la structure titre
 *
 * titre : la structure à observer
 *
 * Retour : le nombre de votes de la structure donnée
 *          en paramètre
 */
int get_numVotes(t_titre titre);

#endif
