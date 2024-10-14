#include <stdio.h>
#include "interaction.h"

void afficherCadre(int largeur, int longueur, int xO, int yO, int xX, int yX, int xP,int yP){

		for (int i = 0; i < longueur; i++){

			for (int j = 0; j < largeur; j++){
		
				if (i == 0 || i == longueur - 1 || j == 0 || j == largeur - 1) {
				printf("#");
				}
					else if (i == yO && j == xO){
						printf("O");
					}
					else if ( i == yX && j == xX){
						printf("X");
					}
					else if (i == yP && j == xP){
						printf(".");
					}
					else {
					printf(" ");
					}
				}
				printf("\n");
			}
}


void deplacerPersonnage(int *xO, int *yO, char choix, int largeur, int longueur){
	
	int newXO = *xO;
	int newYO = *yO;

	switch (choix) {

		case 'z' : 
			newYO--;
			break;

		case 's' : 
			newYO++;
			break;

		case 'q' : 
			newXO--;
			break;

		case 'd' : 
			newXO++;
			break;
		default: 
			printf("déplacement impossible!\n");
			return;
	}
		if (newXO > 0 && newXO < largeur - 1 && newYO > 0 && newYO < longueur -1){
	*xO = newXO;
	*yO = newYO;
}
 		else{
 			printf("déplacement impossible!\n");
 		}
}
int CaisseContreMur (int xX, int yY, int largeur, int longueur){
	if ((xX == 1 && yY == 1) ||
		(xX == 1 && yY == longueur - 2) ||
		(xX == largeur - 2 && yY == 1) ||
		(xX == largeur - 2 && yY == longueur - 2)) {
		return 1;
	}
	return 0;
}

void BougerCaisseEtPerso(int *xO, int *yO, char choix, int *xX, int *yY, int largeur, int longueur){


int newXO = *xO;
int newYO = *yO;

switch (choix) {

		case 'z' :
			newYO--;
			break;
		case 's' : 
			newYO++;
			break;

		case 'q' : 
			newXO--;
			break;
		case 'd' : 
			newXO++;
			break;
		default: 
			printf("déplacement impossible!\n");
			return;
	}

	if (newXO == *xX && newYO == *yY) {

		int newXX = *xX;
		int newYX = *yY; 
	
		switch (choix) {

			case 'z' :
				newYX--;
				break;
			case 's' : 
				newYX++;
				break;

			case 'q' : 
				newXX--;
				break;
			case 'd' : 
				newXX++;
				break;
	}

		if (newXX > 0 && newXX < largeur - 1 && newYX > 0 && newYX < longueur - 1){
			*xX = newXX;
			*yY = newYX;

			*xO = newXO;
			*yO = newYO;
		} else {
			printf("Impossible de pousser la caisse par la ! \n");
		}
		} else {
		if(newXO > 0 && newXO < largeur - 1 && newYO > 0 && newYO < longueur - 1) {
			if (!(newXO == *xX && newYO == *yY)){

			*xO = newXO;
			*yO = newYO;
		
		}else {
			printf("Déplacement impossible : vous ne pouvez pas être sur la même case que la caisse !\n");
		}
		
		
		}else{
			printf("Déplacement impossible\n");
		}
	}
}