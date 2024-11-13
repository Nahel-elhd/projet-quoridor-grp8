#include <stdio.h>
#include"fct.h"
#define TAILLE 9

int main()
{
    int choix;
    char plateau_de_jeu[TAILLE][TAILLE];
    afficherMenu();
    scanf("%d", &choix);

    switch (choix) {
    case 1:
        lancerNouvellePartie();
        pion();
        Plateau_final(plateau_de_jeu);
        break;
    case 2:
        reprendrePartieSauvegardee();
        break;
    case 3:
        afficherScores();

        break;
    case 4:
        printf("Merci d'avoir joue ! A bientot.\n");
        return 0;
    default:
        printf("Choix invalide. Veuillez reessayer.\n");
        break;
    }


    return 0;
}
