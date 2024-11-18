H!!!!!!!!

#ifndef FONCTION_H
#define FONCTION_H
#include <windows.h>
#define TAILLE 9
typedef struct
{
    char nom[50];char pion;int x;int y;
}Joueur;
void choixNom(char nom[10]);
void lancerNouvellePartie();
void reprendrePartieSauvegardee();
void afficherScores();
void afficherMenu();
void pion(Joueur joueurs[],int nbr,char plateau[TAILLE][TAILLE]);
void color(int,int);
void CréationDuPlateau(char plateau[TAILLE][TAILLE]);
void Plateau(char plateau[TAILLE][TAILLE]);
void deplacementDuPion(char plateau[TAILLE][TAILLE],int*x,int*y,int X, int Y);

#endif //FONCTION_H
-----------------------------------------------------------------------------------------------------------
C!!!!!!!!!!!!!!
  


#include "fct.h"

#include <math.h>
#include <stdio.h>
#include<windows.h>
#define TAILLE 9


void lancerNouvellePartie() {
    printf("Lancement d'une nouvelle partie...\n\n");
    printf("On vous souhaite une bonne partie\n");
    printf("------------------------------------\n");
}
void reprendrePartieSauvegardee() {
    printf("Reprise d'une partie sauvegardée...\n");
}
void afficherScores() {
    printf("Affichage des scores des joueurs...\n");
}
void afficherMenu() {
    printf("-----!! Menu du Jeu Quoridor !!-----\n");
    printf("1. Lancer une nouvelle partie\n");
    printf("2. Reprendre une partie sauvegardee\n");
    printf("3. Afficher les scores des joueurs\n");
    printf("4. Quitter le jeu\n");
    printf("\n");
    printf("Veuillez choisir une option (entre 1 et 4) :\n ");
}
void pion( Joueur joueurs[],int nbr,char plateau[TAILLE][TAILLE])
{
    char different_pion[]={3,4,5,6};

    for(int i = 0; i < nbr; i++)
    {
        printf("Entrer le nom du joueur %d\n",i+1);
        scanf("%s",&joueurs[i].nom);
        joueurs[i].pion=different_pion[i];
        if (i==0)
        {
            joueurs[i].x=5;
            joueurs[i].y=0;
        }
        if (i==1)
        {
            joueurs[i].x=5;
            joueurs[i].y=8;
        }  if (i==2)
        {
            joueurs[i].x=1;
            joueurs[i].y=4;
        }  if (i==3)
        {
            joueurs[i].x=9;
            joueurs[i].y=4;
        }
        plateau[joueurs[i].y][joueurs[i].x]=joueurs[i].pion;
    }

    printf("-----------------\n");
    printf("Bonne partie !\n");
    printf("-----------------\n");
}
void color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
void CréationDuPlateau(char plateau[TAILLE][TAILLE]) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            plateau[i][j] = ' ';
        }
    }
}
void Plateau(char plateau[TAILLE][TAILLE]) {
    color(0,15);
    printf("     ");
    color(15,0);
    for (int j = 0; j < TAILLE; j++) {
        color(0,15);
        printf("   %c  ", 'A' + j);
        color(15,0);
    }
    printf("\n");

    for (int i = 0; i < TAILLE; i++) {
        color(0,15);
        printf("  %d  ", i + 1);
        color(15,0);

        for (int j = 0; j < TAILLE; j++) {
            color(0,15);
            printf("+-----");
        }
        printf("+\n");

        for (int j = 0; j < TAILLE; j++) {
            color(0,15);
            if (plateau[i][j] == ' ') {
                printf("     |");
            } else {
                printf("  %c  |", plateau[i][j]);
            }

        }
        printf("     |\n");

    }

    printf("     ");
    for (int j = 0; j < TAILLE; j++) {
        color(0,15);
        printf("+-----");
    }
    printf("+\n");
}
void deplacementDuPion(char plateau[TAILLE][TAILLE],int*x,int*y,int X, int Y,Joueur joueurs[])
{
    char different_pion[]={3,4,5,6};
    for(int i = 0; i < TAILLE; i++)
    {
        printf("")
        plateau[joueurs[i].x][joueurs[i].y]=' ';
        scanf("%s",&joueurs[i].x);
        joueurs[i].pion=different_pion[i];
        plateau[X][Y]=3;
        joueurs[i].x=X;
        joueurs[i].y=Y;
    }
}
