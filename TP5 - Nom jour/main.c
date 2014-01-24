//
//  main.c
//  Nom Jour-TP5
//
//  Created by Med Ayoub on 09/12/2013.
//  Copyright (c) 2013 Med Ayoub. All rights reserved.
//

//Declaration des librairies

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaration des variables locales

#define REP_ANNEE 1901
#define REP_MOIS 1
#define REP_JOUR 1

//Declaration des fonctions


/* Nom fonction: jours_annee
 * Entrees: un entier qui represente l'annee
 * Sorties: un entier qui represente le nombre de jours de l'annee
 * Description: Cette fonction nous permet de calculer le nombre de jours
 *             contenus dans une annee, sans oublier les jours des annees bisecstiles
 */

int jours_annee(int annee)
{
    return (annee - REP_ANNEE) * 365 +   (annee - REP_ANNEE)/4;//le nombre de jours des annees entieres, plus un
}                                                            //jour par chaque 4 annees*/


/* Nom fonction: jours_mois
 * Entrees: un entier qui represente l'annee
 *          un entier qui represente le mois
 * Sorties: un entier qui represente le nombre de jours des mois
 * Description: Cette fonction nous permet de calculer le nombre de jours
 *             contenus dans les mois a partir de janvier jusqu'au mois actuel
 */

int jours_mois(short int mois, int annee)
{
    int nbrJours = 0;
    switch (mois-1)
    {
        case 11: nbrJours += 30;
        case 10: nbrJours += 31;
        case 9: nbrJours += 30;
        case 8: nbrJours += 31;
        case 7: nbrJours += 31;
        case 6: nbrJours += 30;
        case 5: nbrJours += 31;
        case 4: nbrJours += 30;
        case 3: nbrJours += 31;
        case 2: nbrJours += (annee % 4 == 0)? 29 : 28; //si l'annee est bisecstile on ajoute un jour
        case 1: nbrJours += 31;
    }
    return nbrJours;
}

/* Nom fonction: jours_date
 * Entrees: un entier qui represente l'annee
 *          un entier qui represente le mois
 *          un entier qui represente le jour
 * Sorties: un entier qui represente le nombre de jours de la date
 * Description: Cette fonction nous permet de calculer le nombre de jours
 *             a partir de la date 1/1/1901 jusqu'a l'annee en cours
 */


unsigned int jours_date(int annee, int mois, int jour)
{
    return (jours_annee(annee) + jours_mois(mois, annee) + jour - 1);
}

/* Nom fonction: nom_jour
 * Entrees: un entier qui represente l'indice
 * Sorties: une chaine de caractere qui est le nom du jour
 * Description: Cette fonction nous permet de determiner le nom du jour auquel
 *              correspond la date donnee
 */


char* nom_jour(short int indice)
{
    switch(indice)
    {
        case 0: return "Mardi";
        case 1: return "Mercredi";
        case 2: return "Jeudi";
        case 3: return "Vendredi";
        case 4: return "Samedi";
        case 5: return "Dimanche";
        default: return "Lundi";
    }
}


/* Nom fonction: verifie_date
 * Entrees: un entier qui represente l'annee
 *          un entier qui represente le mois
 *          un entier qui represente le jour
 * Sorties: une variable booleenne
 * Description: Cette fonction nous permet de verifier la validite d'une date
 *              entree par l'utilisateur
 */

int verifie_date(short int jour, short int mois, int annee)
{
    // Test jour
    if( (jour < 1) || (jour > 31) ) return 0;
    switch (mois) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if(jour > 30) return 0;
        case 4: case 6: case 9: case 11:
            if(jour > 31) return 0;
        case 2:
            if(
               ( ((annee % 4) == 0) && (jour > 29)) ||
               ( ((annee % 4) != 0) && jour > 28)
              )  return 0;
    }
    
    // Test mois
    if( (mois < 1 )|| (mois > 12) ) return 0;
    
    // Test annee
    if( (annee < 1901) || (annee > 2099) ) return 0;
    
    return 1;
}


//Programme principal

int main()
{
    int jour, mois, annee;
    printf("--------------Saisie de la date:--------------\n");
    printf("Entrez une date (jj/mm/aaaa) : ");//saisie de la date
    scanf("%d/%d/%d", &jour, &mois, &annee);
    
    if(verifie_date(jour, mois, annee))//verification de la validite de la date saisie
    {
        short int indice = jours_date(annee, mois, jour) % 7;//calcul de l'indice qui n'est que le reste de la
        printf("Le %d/%d/%d est un %s\n", jour, mois, annee, nom_jour(indice));//division sur 7
    }
    else printf("Date invalide\n");
    
    return 0;
}



