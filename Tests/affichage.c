#include <stdio.h>
#include <stdlib.h>
#include "Robot.h"

/****************Affichage des structures*********************/


void afficherC(Chemin* Point1) //Affichage des structures du chemin final
{
	Chemin* val = Point1;
	while(val!=NULL)
	{
		printf("x = %d   ", val->x);
		printf("y = %d", val->y);
		printf("Son papa : %p\n", val->base);	
//		printf("Le pointeur suivant est %p\n", val);
		val=val->base;
		
	}
}

void afficherCo(Couleur* Point1) //Affichage des structures du chemin final
{
	Couleur* val = Point1;
	while(val!=NULL)
	{
		printf("x = %d   ", val->x);
		printf("y = %d", val->y);
		printf("nombre = %d", val->nombre);
		printf("Son papa : %p\n", val->base);	
//		printf("Le pointeur suivant est %p\n", val);
		val=val->base;
		
	}
}

void afficher(Point* Point1)
{
	Point* val = Point1;
	while(val!=NULL)
	{
		printf("x = %d   ", val->x);
		printf("y = %d", val->y);
		printf(" G vaut : %d", val->G);
		printf(" D vaut : %d ", val->D);
		printf("Et F vaut : %d ", val->F);
		printf("Son papa : %p\n", val->suivant);	
//		printf("Le pointeur suivant est %p\n", val);
		val=val->suivant;
		
	}
}

void afficherF(Point* Point1)
{
	Point* val = Point1;
	while(val!=NULL)
	{
		printf("x = %d   ", val->x);
		printf("y = %d", val->y);
		printf(" G vaut : %d", val->G);
		printf(" D vaut : %d ", val->D);
		printf("Et F vaut : %d ", val->F);
		printf("Son papa : %p\n", val->base);	
//		printf("Le pointeur suivant est %p\n", val);
		val=val->suivant;
		
	}
}
