#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "interaction.h"

void effacerEcran(){

	#ifdef _WIN32
		system("cls");

	#else
		system("clear");

	#endif
}

int main()
{
	int largeur = 10;
	int longueur = 10;
	
	srand(time(NULL));

	int xO = 1 + rand() % (largeur - 2);
	int yO = 1 + rand() % (longueur- 2); 

	int xX, yY;

		do {
			xX = 2 + rand() % (largeur - 4);
			yY = 2 + rand() % (longueur - 4);
		}
		while (xX == xO && yY == yO);

	int xP, yP;
		
		do{
			xP = 1 + rand() % (largeur - 2);
			yP = 1 + rand() % (longueur - 2);
		}
		while ((xP == xO && yP == yO) || (xP == xX && yP == yY)) ;

		char choix;
		while(1){
				
				effacerEcran();

				afficherCadre(largeur, longueur, xO, yO, xX, yY, xP, yP);

				if (xX == xP && yY == yP){
					printf("Félicitation, vous avez gagné la partie! \n");
					break;
				}

				if (CaisseContreMur(xX, yY, largeur, longueur)){
					printf("La caisse est bloquée contre un mur, vous avez perdu la partie! \n");
					break;
				}

				printf("déplacez vous avec les touche z (haut) s(bas) q(gauche) d(droite) : \n");
				scanf(" %c", &choix);

				if (choix == 'x'){
					printf("vous avez quitté le jeu.\n");
					break;
				}
				BougerCaisseEtPerso(&xO, &yO, choix, &xX, &yY, largeur, longueur);
				
		}

		return 0;
	}