H!!!!!!!!
#ifndef FONCTION_H
#define FONCTION_H
void choixNom(char nom[10]);
void lancerNouvellePartie();
void reprendrePartieSauvegardee();
void afficherScores();
void afficherMenu();
void pion();
#endif //FONCTION_H
-----------------------------------------------------------------------------------------------------------
C!!!!!!!!!!!!!!
  
#include "fct.h"
#include <stdio.h>
void choixNom(char nom[10])
{
    printf("entrer votre nom : ");
    scanf("%s", nom);
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
    printf("3. Afficher l'aide\n");
    printf("4. Afficher les scores des joueurs\n");
    printf("5. Quitter le jeu\n");
    printf("\n");
    printf("Veuillez choisir une option (entre 1 et 5) :\n ");
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
