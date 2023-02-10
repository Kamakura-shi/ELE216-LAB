
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "imdb.h"
#include "recherche.h"
#include "resultat.h"
int maine(void)
{
/*
Ce teste permet de tester le fonctionnement des set et des get pour la structure
critere. Ensuite, on affiche les resultats. Il permet aussi de creer une structure critere
*/
//Test_Mutateur();




}

void Test_Mutateur(void){
    //creation de critere
t_critere critere = creer_critere();
//utilisation des mutateur
set_titre(critere,"Matrix");
set_genre(critere,"science,fi");
set_categorie(critere,"Short");
set_annee_parution_min(critere,1990);
set_annee_parution_max(critere,2000);
//utilisation des get
printf("Titre: %s\n", get_titre(critere));
printf("genre: %s\n", get_genre(critere));
printf("Categorie: %s\n", get_categorie(critere));
printf("Annee:  %d to %d\n", get_annee_parution_min(critere),get_annee_parution_max(critere));
//liberation de memoire
detruire_critere(critere);

}


void Test_Mutateur2(void){
    //creation de critere
t_critere critere = creer_critere();
//utilisation des mutateur

set_genre(critere,"science,fi");
set_categorie(critere,"Short");
set_annee_parution_min(critere,1990);
set_annee_parution_max(critere,2000);
//utilisation des get
if(get_titre(critere)== NULL)

{printf("Titre vide");}


//liberation de memoire
detruire_critere(critere);

}
void Test_Get_critere(){
t_resultat resultat = creer_resultat();
t_critere critere = creer_titre();

set_titre(critere,"Carmencita");
set_genre(critere,"Documentary,Short");
set_annee_parution_min(critere,1990);
set_annee_parution_max(critere,2000);


get_critere(resultat,critere);
printf("Titre: %s\n", get_titre(critere));
printf("genre: %s\n", get_genre(critere));
printf("Categorie: %s\n", get_categorie(critere));
printf("Annee:  %d %d\n", get_annee_parution_min(critere),get_annee_parution_min(critere));
free(resultat);
free(critere);
}
void Test_decomposition()
{
char store[1024];
t_critere critere = creer_titre();

	/* Ouvrir le fichier */
	FILE* fichier_ptr ;
	fichier_ptr = fopen("../data/title_basics.tsv", "r");
	
/*passer la premiere ligne*/
//fgets(store,1000,fichier_ptr);
/* Lecture de chaque titre */
fgets(store,sizeof(store),fichier_ptr);
decomposition_titre(critere,store);
set_titre(critere,"Carmencita");
set_genre(critere,"Documentary,Short");
set_annee_parution_min(critere,1990);
set_annee_parution_max(critere,2000);
}
