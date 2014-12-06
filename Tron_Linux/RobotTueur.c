#include <stdlib.h>
#include <stdio.h>

#include "Robot.h"

Couleur* Poursuite(int Grille[][150], int x, int y, int XP, int YP)
{
	int Xd, Yd;
	Xd=(x-XP)*(x-XP);
	Yd=(y-YP)*(y-YP);
	Couleur* End=NULL;
	if(Xd<=5&&Yd<=5)
	{
		End=Mouv(Grille, x, y);
		return End;
	}
	else
	{
		Point* Ouvert=NULL;
		Point* Ferme=NULL;
		Point* Pouf=NULL;
		fprintf(stderr,"Loooosseerr5214521+++++++++++++\n");
		Pouf=Astar(Ouvert, Ferme, XP, YP, Grille, 299, 149);
		fprintf(stderr,"Loooosseerr5214521+++++++++++++\n");
		if(Pouf!=NULL)
		{
			End=ajoutCouleur(End, Pouf->x, Pouf->y, 0);
			return End;
		}
		else
		{
            End=Mouv(Grille, x, y);
            fprintf(stderr,"Loooosseerr5214521+++++ttttttttttttttttttttt++++++++\n");
		}
	}
}
