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

#define _CRT_SECURE_NO_WARNINGS

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
/* Permet d'écrire dans un fichier TSV tous les résultats (HLR09)
*
* resultat_ptr : la structure à visualiser
* nom_fichier : fichier à ecrire
*/
int t_resultat_ecrire(t_resultat resultat_ptr, const char* nom_fichier);

#endif
