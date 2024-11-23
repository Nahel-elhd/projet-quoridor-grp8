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
int deplacementDuPion(char plateau[TAILLE][TAILLE],Joueur joueurs[4]);
void afficherPlateau(char plateau[TAILLE][TAILLE]);
int verifier_victoire(Joueur joueur);
void jeu(Joueur joueurs[],int );
int gererjeu();



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
void afficherMenu() {
    printf("-----!! Menu du Jeu Quoridor !!-----\n");
    printf("1. Lancer une nouvelle partie\n");
    printf("2. Reprendre une partie sauvegardee\n");
    printf("3. Quitter le jeu\n");
    printf("\n");
    printf("Veuillez choisir une option (entre 1 et 4) :\n ");
}
void pion( Joueur joueurs[],int nbr,char plateau[TAILLE][TAILLE])
{
    char different_pion[]={3,4,5,6};
    printf(" Le joueur 1 aura le pion %c le joueur 2 aura %c le troisieme aura %c et la quatrieme %c, a vous de choisie.\n",3,4,5,6);

    for(int i = 0; i < nbr; i++)///boucle pour definir le nom des joueurs et leur pion associé et mise en place sur le plateau
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
void CréationDuPlateau(char plateau[TAILLE][TAILLE]) {///definition du tableau = nbr de ligne et de colonne
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            plateau[i][j] = ' ';
        }
    }
}
void Plateau(char plateau[TAILLE][TAILLE])
{
    for(int i=0; i < TAILLE; i++)//affichage en separant les cases du plateau
    {
        for(int j=0; j < TAILLE; j++)// pour faire les lignes du tableau
        {
            color(0,15);
            printf("+-----");
        }
        printf("+\n");

        for(int j=0; j < TAILLE; j++)
        {
            color(0,15);
            printf("|  %c  ",plateau[i][j]);//affichage des barres entre les cases pour separer les colonnes

        }
        printf("|\n");
    }

    for(int j=0; j < TAILLE; j++)//la derniere ligne tu tableau pour avoir un plateau fermer
    {
        color(0,15);
        printf("+-----");
    }
    printf("+\n");
    color(15,0);
}
int verifier_victoire(Joueur joueur) {
    if ((joueur.pion == 3 && joueur.y == 8) || (joueur.pion == 4 && joueur.y == 0) || (joueur.pion == 5 && joueur.x == 8) || (joueur.pion == 6 && joueur.x == 0))
        {
        return 1;
        }
    return 0;
}
int deplacementDuPion(char plateau[TAILLE][TAILLE],Joueur *joueur)
{
    char direction;




        printf("choisissez votre direction avec Z(haut) Q(gauche) S(bas) et D(droite)\n");

        scanf(" %c",&direction);
        int X=joueur->x;
        int Y=joueur->y;

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
                return 0;
            }
        if(X>= 0 && X< TAILLE && Y>= 0 && Y< TAILLE && plateau[Y][X] == ' ')//si le pion est en dehors du plateau ou va vers un case deja occuper alors mouv invalide si le mouv est accepter alors ca retourne 1 sinon 0
    {//deplacement
        plateau[joueur->y][joueur->x]=' ';//efface l ancienne position
        joueur->x=X;
        joueur->y=Y;

        plateau[Y][X]=joueur->pion;//met le pion a la nouvelle position
            return 1;
    }
        else
    {
        printf("Mouvement invalide\n");
        return 0;
    }
}
void jeu(Joueur joueurs[4],int nbr)
{
    int action, joueurActuel=0;
    char plateau[TAILLE][TAILLE];
    CréationDuPlateau(plateau);
    for(int i=0; i < nbr; i++)
    {
        plateau[joueurs[i].y][joueurs[i].x]=joueurs[i].pion;//met le pion sur plateau a ca position actuelle
    }


    while(1){//on repete le deplacement sauf si la victoire est verifier dans le if
        Plateau(plateau);
        printf("tour de %s (pion %c):\n",joueurs[joueurActuel].nom,joueurs[joueurActuel].pion);
        printf("1. deplacement\n2. poser une barriere\n3. passer son tour\n4. Pause\n");
        scanf("%d",&action);
        while(action!=1&&action!=4&&action!=2&&action!=3)
        {
            printf("Merci de choisir une valeur valide\n");
            scanf("%d",&action);
        }
        switch(action)
        {
        case 1:///choix de se deplacer
            int deplaFait=0;
            do
            {
                deplaFait=deplacementDuPion(plateau, &joueurs[joueurActuel]);
            }while(!deplaFait);//tant que le deplacement n'est pas fait donc invalide alors on rejoue le coup jusqua avoir un mouvement valide
            break;
        case 2:
            break;
        case 3:printf("%s passe son tour\n",joueurs[joueurActuel].nom);//paser son tour
            break;
        case 4: // Menu pause
            {
                int choixPause;
                printf("----- Menu Pause -----\n");
                printf("1. Continuer la partie\n");
                printf("2. Retour au menu principal\n");
                printf("3. Sauvegarder la partie (non implémenté)\n");
                printf("Choisissez une option : ");
                scanf("%d", &choixPause);

                switch (choixPause) {
                case 1: // Continuer la partie
                    printf("Reprise de la partie...\n");
                    continue; // Retour à la boucle du jeu
                case 2: // Retour au menu principal
                    printf("Retour au menu principal...\n");
                    gererjeu();
                case 3: // Sauvegarder la partie
                    printf("Sauvegarder la partie.\n");
                    break;
                default:
                    printf("Choix invalide. Retour au jeu.\n");
                    break;
                }

            }
        default:
            break;
        }
        if (verifier_victoire(joueurs[joueurActuel])) {
            Plateau(plateau);
            printf("VICTOIRE ! Félicitations à %s (%c) !\n", joueurs[joueurActuel].nom, joueurs[joueurActuel].pion);
            break;
        }
        joueurActuel=(joueurActuel+1)% nbr;//joueur suivant


    }
}
int gererjeu()
{
    int choix,nbr;
    char plateau_de_jeu[TAILLE][TAILLE];
    Joueur joueurs[4];

    afficherMenu();
    scanf("%d", &choix);

    switch (choix) {
    case 1:
        lancerNouvellePartie();
        CréationDuPlateau(plateau_de_jeu);
        printf("choisissez le nombre de joueur  (2 ou 4 max) :\n");
        scanf("%d",&nbr);
        while (nbr!= 4 && nbr!= 2)
        {
            printf("ERREUR,veuillez choisis une valeur valide.\n");
            scanf("%d",&nbr);
        }

        pion(joueurs,nbr, plateau_de_jeu);
        jeu(joueurs,nbr);
        break;

    case 2:
        reprendrePartieSauvegardee();
        break;
    case 3:
        printf("Merci d'avoir joue ! A bientot.\n");
        return 0;
    default:
        printf("Choix invalide. Veuillez reessayer.\n");
        break;
    }
}







