#include <stdlib.h>
#include <stdio.h>
#include "Robot.h"

Couleur* Poursuite(int Grille[][150], int x, int y, int XP, int YP)
{
	int Xd, Yd;
	Xd=(x-XP)*(x-XP);
	Yd=(y-YP)*(y-YP);
	Couleur* End;
	if(Xd<5&&Yd<5)
	{
		End=Mouv(Grille, x, y);
		return End;
	}
	else
	{
		Point* Ouvert=NULL;
		Point* Ferme=NULL;
		Point* Pouf=NULL;
		Pouf=Astar(Ouvert, Ferme, XP, YP, Grille, 299, 149);
		if(Pouf!=NULL)
		{
			End=ajoutCouleur(End, Pouf->x, Pouf->y, 0);
			return End;
		}
		else
		{
		return NULL;
		}
	}
}
