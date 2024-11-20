#ifndef FONCTION_H
#define FONCTION_H
#include <windows.h>
#define TAILLE 9
typedef struct
{
    char nom[50];char pion;int x;int y;int brx; int bry;
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
void deplacementDuPion(char plateau[TAILLE][TAILLE],int nbr,Joueur joueurs[4]);
void afficherPlateau(char plateau[TAILLE][TAILLE]);


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
        scanf("%s",joueurs[i].nom);
        joueurs[i].pion=different_pion[i];
        if (i==0)
        {
            joueurs[i].x=4;
            joueurs[i].y=0;
        }
        if (i==1)
        {
            joueurs[i].x=4;
            joueurs[i].y=8;
        }  if (i==2)
        {
            joueurs[i].x=0;
            joueurs[i].y=4;
        }  if (i==3)
        {
            joueurs[i].x=8;
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
void Plateau(char plateau[TAILLE][TAILLE])
{
    for(int i=0; i < TAILLE; i++)
    {
        for(int j=0; j < TAILLE; j++)
        {
            color(0,15);
            printf("+-----");
        }
        printf("+\n");

        for(int j=0; j < TAILLE; j++)
        {
            color(0,15);
            printf("|  %c  ",plateau[i][j]);

        }
        printf("|\n");
    }

    for(int j=0; j < TAILLE; j++)
    {
        color(0,15);
        printf("+-----");
    }
    printf("+\n");
    color(15,0);
}

void deplacementDuPion(char plateau[TAILLE][TAILLE],int nbr,Joueur joueurs[4])
{
    int X,Y;
    char direction;


    for(int i = 0; i < nbr; i++)
    {
        printf("tour de %s (pion %c):\n",joueurs->nom,joueurs->pion);
        printf("choisissez votre direction avec Z(haut) Q(gauche) S(bas) et D(droite)\n");

        scanf(" %c",&direction);
        X=joueurs[i].x;
        Y=joueurs[i].y;

            if(direction=='Z'||direction=='z')
            {
                Y--;
            }
            else if(direction=='Q'||direction=='q')
            {
                X--;
            }
            else if(direction=='S'||direction=='s')
            {
                Y++;
            }
            else if(direction=='d'||direction=='D')
            {
                X++;
            }
            else
            {
                printf("direction invalide. Veuillez reessayer.\n");
                i--;
                continue;
            }
        if(X>= 0 && X< TAILLE && Y>= 0 && Y< TAILLE && plateau[X][Y] == ' ')
    {
        plateau[joueurs[i].y][joueurs[i].x]=' ';
        joueurs[i].x=X;
        joueurs[i].y=Y;
        plateau[Y][X]=joueurs[i].pion;
    }
        else
    {
        printf("mouvement invalide\n");
        i--;
    }


    }
}

