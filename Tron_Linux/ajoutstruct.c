#include <stdio.h>
#include <stdlib.h>
#include "Robot.h"



/******************Fonction d'ajout de structures************************/

Couleur* ajoutCouleur(Couleur* in, int x, int y, int nb) //Ajout des structures couleurs
{
	Couleur *nouveau;
	nouveau=(Couleur *)malloc(sizeof(Couleur));
	nouveau->x=x;
	nouveau->y=y;
	nouveau->nombre=nb;
	nouveau->base=in;

	return nouveau;
}

Point* remplisCouleur(Point* in, Point* ferme, int x, int y) //Remplis les structures de Astar
{
	Point* nouveau;
	nouveau=(Point *)malloc(sizeof(Point));
	nouveau->x=x;
	nouveau->y=y;
	nouveau->G=10+ferme->G;
	nouveau->base=ferme;
	nouveau->suivant=in;

	return nouveau;
}

Point* remplis2(Point* in, Point* ferme, int G, int x, int y) //Remplis les structures de Coloriage
{
	Point* nouveau;
	nouveau=(Point *)malloc(sizeof(Point));
	nouveau->x=x;
	nouveau->y=y;
	nouveau->G=10+G;
	nouveau->base=ferme;
	nouveau->suivant=in;
	return nouveau;
}


Point* remplisInitCouleur(Point* in, Point* ferme, int x, int y) //Iniilise la première structure de Coloriage
{
	Point* nouveau;
	nouveau=(Point *)malloc(sizeof(Point));
	nouveau->x=x;
	nouveau->y=y;
	nouveau->G=0;
	nouveau->base=ferme;
	nouveau->suivant=ferme;
	return nouveau;
}

Point* remplis(Point* in, Point* ferme, int x, int y, int xF, int yF)
{
	Point* nouveau;
	nouveau=(Point *)malloc(sizeof(Point));
	nouveau->x=x;
	nouveau->y=y;
	nouveau->G=1+ferme->G;
	int Cap=x-xF;
	int Cap2=y-yF;
	nouveau->D=Cap*Cap+Cap2*Cap2;
	nouveau->F=nouveau->G+nouveau->D;
	nouveau->base=ferme;
	nouveau->suivant=in;
	return nouveau;
}


Point* remplis0(Point* in, Point* ferme, int x, int y, int xF, int yF)
{
	Point* nouveau;
	nouveau=(Point *)malloc(sizeof(Point));
	nouveau->x=x;
	nouveau->y=y;
	nouveau->G=0;
	int Cap=x-xF;
	int Cap2=y-yF;
	nouveau->D=Cap*Cap+Cap2*Cap2;
	nouveau->F=nouveau->G+nouveau->F;
	nouveau->base=ferme;
	nouveau->suivant=ferme;
	return nouveau;
}



Chemin* ajout(Chemin* in, int x, int y)
{
	Chemin *nouveau;
	nouveau=(Chemin *)malloc(sizeof(Chemin));
	nouveau->x=x;
	nouveau->y=y;
	nouveau->base=in;
	return nouveau;
}
