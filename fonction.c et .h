H!!!!!!!!


  #ifndef FONCTION_H
#define FONCTION_H
#include <windows.h>
#define TAILLE 9
void choixNom(char nom[10]);
void lancerNouvellePartie();
void reprendrePartieSauvegardee();
void afficherScores();
void afficherMenu();
void pion();
void color(int,int);
void CréationDuPlateau(char plateau[TAILLE][TAILLE]);
void Plateau(char plateau[TAILLE][TAILLE]);
void Plateau_final(char plateau[TAILLE][TAILLE]);
void deplacementDuPion(char plateau[TAILLE][TAILLE],int*x,int*y,int X, int Y);

#endif //FONCTION_H
-----------------------------------------------------------------------------------------------------------
C!!!!!!!!!!!!!!
  

#include "fct.h"
#include <stdio.h>
#include<windows.h>
#define TAILLE 9
void choixNom(char nom[10])
{
    printf("entrer votre nom : ");
    scanf("%9s", nom);
}
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
void pion()
{
    int nbr_joueur;
    char j1[10];
    char j2[10];
    char j3[10];
    char j4[10];

    printf("choisissez le nombre de joueur humain (1 à 4 max) :\n");
    scanf("%d",&nbr_joueur);

    switch (nbr_joueur)
    {
    case 1:
        choixNom(j1);
        printf("Joueur 1 est : %s, votre pion est le coeur : %c\n",j1,3);
        printf("Joueur 2 est : IA2 , votre pion est le carreau : %c\n",4);

        break;
    case 2:
        choixNom(j1);
        choixNom(j2);
        printf("Joueur 1 est : %s, votre pion est le coeur : %c\n",j1,3);
        printf("Joueur 2 est : %s , votre pion est le carreau : %c\n",j2,4);

        break;
    case 3:
        choixNom(j1);
        choixNom(j2);
        choixNom(j3);
        printf("Joueur 1 est : %s, votre pion est le coeur : %c\n",j1,3);
        printf("Joueur 2 est : %s, votre pion est le carreau : %c\n",j2,4);
        printf("Joueur 3 est : %s, votre pion est le trefle : %c\n",j3,5);
        printf("Joueur 4 est : IA4, votre pion est le pic: %c\n",6);
        break;
    case 4:
        choixNom(j1);
        choixNom(j2);
        choixNom(j3);
        choixNom(j4);

        printf("Joueur 1 est : %s, votre pion est le coeur : %c\n",j1,3);
        printf("Joueur 2 est : %s, votre pion est le carreau : %c\n",j2,4);
        printf("Joueur 3 est : %s, votre pion est le trefle : %c\n",j3,5);
        printf("Joueur 4 est : %s, votre pion est le pic: %c\n",j4,6);
        break;
    default:
        printf("ERREUR\n");
        break;
    }

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
void deplacementDuPion(char plateau[TAILLE][TAILLE],int*x,int*y,int X, int Y)
{
    plateau[*x][*y]=' ';
    plateau[X][Y]=3;
    *x=X;
    *y=Y;
}
void Plateau_final(char plateau[TAILLE][TAILLE])
{
    CréationDuPlateau(plateau);
    int xC=0 ,yC=5;
    plateau[xC][yC]=3;
    Plateau(plateau);
}

