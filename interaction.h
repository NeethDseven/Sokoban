#ifndef INTERACTION_H
#define INTERACTION_H

void BougerCaisseEtPerso(int *xO, int *yO, char choix, int *xX, int *yY, int largeur, int longueur);

void afficherCadre(int largeur, int longueur, int xO, int yO, int xX, int yX, int xP, int yP);

void deplacerPersonnage(int *xO,int *yO, char choix, int largeur, int longueur);

int CaisseContreMur(int xX, int yY, int largeur, int longueur);

#endif