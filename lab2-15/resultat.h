/**
 * Module recherche - resultat.h
 *
 * Par : Hani OUali
 * Date : Janvier 2023
 *
 * Le module resultat est responsable de gérer les resultats de la recherche effectuee la 	   *a laide de structures encapsulees de données
 */

#ifndef RESULTAT_H
#define RESULTAT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Encapsulation de la structure critere
 * Les champs sont accessibles seulement à l'intérieur du module recherche.c
 */
typedef struct critere* t_critere;

/**
 * Constructeur de critères
 *
 * Cette fonction publique permet d'allouer dynamiquement une structure de critères.
 * Elle place des valeurs par défaut dans les membres de celle-ci.
 *
 * Retour : pointeur vers la structure allouée
 */
t_critere creer_critere(void);

#endif
