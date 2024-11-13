#include <stdio.h>
#include"fct.h"

int main()
{
    int choix;
    afficherMenu();
    scanf("%d", &choix);

    switch (choix) {
    case 1:
        lancerNouvellePartie();
        pion();

        break;
    case 2:
        reprendrePartieSauvegardee();
        break;
    case 3:
        afficherScores();

        break;
    case 4:
       printf("Merci d'avoir joue... A bientot %c\n",1);
        return 0;
    default:
        printf("Choix invalide. Veuillez reessayer.\n");
        break;
    }


    return 0;
}

