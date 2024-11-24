#include "fct.h"

#include <math.h>
#include <stdio.h>
#include <windows.h>
#define TAILLE 9

// Grilles pour les barrières
int barrieresHorizontales[TAILLE - 1][TAILLE] = {0};
int barrieresVerticales[TAILLE][TAILLE - 1] = {0};

void lancerNouvellePartie() {
    printf("Lancement d'une nouvelle partie...\n\n");
    printf("On vous souhaite une bonne partie\n");
    printf("------------------------------------\n");
}
void reprendrePartieSauvegardee() {
    printf("Reprise d'une partie sauvegardee...\n");
}
void afficherMenu() {
    printf("-----!! Menu du Jeu Quoridor !!-----\n");
    printf("1. Lancer une nouvelle partie\n");
    printf("2. Reprendre une partie sauvegardee\n");
    printf("3. Quitter le jeu\n");
    printf("\n");
    printf("Veuillez choisir une option (entre 1 et 3) :\n ");
}
void pion(Joueur joueurs[], int nbr, char plateau[TAILLE][TAILLE]) {
    char different_pion[] = {3, 4, 5, 6};
    printf("Le joueur 1 aura le pion %c, le joueur 2 aura %c, le troisieme aura %c et le quatrieme %c.\n", 3, 4, 5, 6);

    int barrieres = (nbr == 2) ? 10 : 5; // 10 barrières pour 2 joueurs, 5 pour 4 joueurs

    for (int i = 0; i < nbr; i++) {
        printf("Entrer le nom du joueur %d\n", i + 1);
        scanf("%s", joueurs[i].nom);
        joueurs[i].pion = different_pion[i];
        joueurs[i].barrieresRestantes = barrieres; // Initialiser le nombre de barrières restantes

        if (i == 0) {
            joueurs[i].x = 4;
            joueurs[i].y = 0;
        } else if (i == 1) {
            joueurs[i].x = 4;
            joueurs[i].y = 8;
        } else if (i == 2) {
            joueurs[i].x = 0;
            joueurs[i].y = 4;
        } else if (i == 3) {
            joueurs[i].x = 8;
            joueurs[i].y = 4;
        }
        plateau[joueurs[i].y][joueurs[i].x] = joueurs[i].pion;
    }

    printf("-----------------\n");
    printf("Bonne partie !\n");
    printf("-----------------\n");
}
void color(int couleurDuTexte, int couleurDeFond) {
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
}
int deplacementDuPion(char plateau[TAILLE][TAILLE], Joueur *joueur) {
    char direction;

    printf("Choisissez votre direction avec Z (haut), Q (gauche), S (bas), et D (droite) :\n");
    scanf(" %c", &direction);

    int X = joueur->x;
    int Y = joueur->y;

    if (direction == 'Z' || direction == 'z') {
        Y--;
    } else if (direction == 'Q' || direction == 'q') {
        X--;
    } else if (direction == 'S' || direction == 's') {
        Y++;
    } else if (direction == 'D' || direction == 'd') {
        X++;
    } else {
        printf("Direction invalide. Veuillez réessayer.\n");
        return 0;
    }

    if (X >= 0 && X < TAILLE && Y >= 0 && Y < TAILLE && plateau[Y][X] == ' ') {
        // Déplacement valide
        plateau[joueur->y][joueur->x] = ' '; // Efface l'ancienne position
        joueur->x = X;
        joueur->y = Y;
        plateau[Y][X] = joueur->pion; // Place le pion à la nouvelle position
        return 1;
    } else {
        printf("Mouvement invalide\n");
        return 0;
    }
}

void CréationDuPlateau(char plateau[TAILLE][TAILLE]) { // définition du tableau
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            plateau[i][j] = ' ';
        }
    }
}
void Plateau(char plateau[TAILLE][TAILLE], int barrieresHorizontales[TAILLE - 1][TAILLE], int barrieresVerticales[TAILLE][TAILLE - 1]) {
    for (int i = 0; i < TAILLE; i++) {
        // Affichage des barres horizontales
        for (int j = 0; j < TAILLE; j++) {
            if (i < TAILLE - 1 && barrieresHorizontales[i][j] == 1) {
                printf("+  B  "); // Barrière horizontale
            } else {
                printf("+-----");
            }
        }
        printf("+\n");

        // Affichage des cases et des barres verticales
        for (int j = 0; j < TAILLE; j++) {
            if (j < TAILLE - 1 && barrieresVerticales[i][j] == 1) {
                printf("|  %c  B", plateau[i][j]); // Barrière verticale
            } else {
                printf("|  %c  ", plateau[i][j]);
            }
        }
        printf("|\n");
    }

    // Dernière ligne horizontale
    for (int j = 0; j < TAILLE; j++) {
        printf("+-----");
    }
    printf("+\n");
}

int verifier_victoire(Joueur joueur) {
    if ((joueur.pion == 3 && joueur.y == 8) || (joueur.pion == 4 && joueur.y == 0) || (joueur.pion == 5 && joueur.x == 8) || (joueur.pion == 6 && joueur.x == 0)) {
        return 1;
    }
    return 0;
}
int poserBarriere(char plateau[TAILLE][TAILLE], int barrieresHorizontales[TAILLE - 1][TAILLE], int barrieresVerticales[TAILLE][TAILLE - 1], Joueur *joueur) {
    if (joueur->barrieresRestantes <= 0) {
        printf("%s n'a plus de barrieres disponibles.\n", joueur->nom);
        return 0;
    }

    int x1, y1,X;
    char orientation;
    printf("Entrez les coordonnees de la barriere. Format à respecter: \n1. colonne\n2. ligne \n3. orientation (H=Horizontal, V=Vertical)\n");
    scanf("%d %d %c", &X, &y1, &orientation);
    x1=X-1;


    // Vérifier si les coordonnées sont valides
    if (x1 < 0 || x1 >= TAILLE || y1 < 0 || y1 >= TAILLE ||
        (orientation != 'H' && orientation != 'V'&& orientation != 'h'&& orientation != 'v')) {
        printf("Coordonnees ou orientation invalides.\n");
        return 0;
    }

    if (orientation == 'v'|| orientation == 'V') { // Barrière horizontale
        if (y1 >= TAILLE - 1 || barrieresHorizontales[y1][x1]) {
            printf("Une barriere horizontale existe dejà ici.\n");
            return 0;
        }
        barrieresHorizontales[y1][x1] = 1;
    } else if (orientation == 'h'|| orientation != 'H') { // Barrière verticale
        if (x1 >= TAILLE - 1 || barrieresVerticales[y1][x1]) {
            printf("Une barriere verticale existe déjà ici.\n");
            return 0;
        }
        barrieresVerticales[y1][x1] = 1;
    }

    joueur->barrieresRestantes--;

    // Vérification de chemin libre (simplifiée ici, retourne toujours 1)
    if (!verifierCheminLibre(plateau, joueur)) {
        printf("Cette barrière bloque le chemin d'un joueur.\n");
        if (orientation == 1) {
            barrieresHorizontales[y1][x1] = 0;
        } else if (orientation == 2) {
            barrieresVerticales[y1][x1] = 0;
        }
        joueur->barrieresRestantes++;
        return 0;
    }

    printf("Barriere posee avec succes !\n");
    return 1;
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
        Plateau(plateau, barrieresHorizontales, barrieresVerticales);
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
            while (!poserBarriere(plateau, barrieresHorizontales, barrieresVerticales, &joueurs[joueurActuel]));
            break;
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
            Plateau(plateau, barrieresHorizontales, barrieresVerticales);
            printf("VICTOIRE ! Félicitations à %s (%c) !\n", joueurs[joueurActuel].nom, joueurs[joueurActuel].pion);
            break;
        }
        joueurActuel=(joueurActuel+1)% nbr;//joueur suivant


    }
}












int gererjeu() {
    int choix, nbr;
    char plateau_de_jeu[TAILLE][TAILLE];
    Joueur joueurs[4];

    afficherMenu();
    scanf("%d", &choix);

    switch (choix) {
    case 1:
        lancerNouvellePartie();
        do {
            printf("Combien de joueurs vont jouer (2 ou 4) ?\n");
            scanf("%d", &nbr);
        } while (nbr != 2 && nbr != 4);

        pion(joueurs, nbr, plateau_de_jeu);
        jeu(joueurs, nbr);
        break;
    case 2:
        reprendrePartieSauvegardee();
        break;
    case 3:
        printf("Merci d'avoir joue au jeu Quoridor !\n");
        break;
    default:
        printf("Choix invalide. Veuillez choisir une option valide (1, 2 ou 3).\n");
    }
}
#include <string.h>


// Fonction qui vérifie si un chemin est libre pour les joueurs (implémentation simplifiée)
int verifierCheminLibre(char plateau[TAILLE][TAILLE], Joueur *joueurs) {
    // Simplification : on suppose qu'il y a toujours un chemin libre
    return 1;
}

