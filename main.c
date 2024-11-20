#include <stdio.h>
#include"fct.h"
#define TAILLE 9

int main()
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
        Plateau(plateau_de_jeu);
for(int tour=0; tour<5; tour++)
{
    deplacementDuPion(plateau_de_jeu, nbr, joueurs);
    Plateau(plateau_de_jeu);
}
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
