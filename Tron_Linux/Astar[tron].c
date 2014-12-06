#include <stdio.h>
#include <stdlib.h>
#include "Robot.h"








Point* Astar(Point* Ouvert, Point* Ferme, int xF, int yF, int T[][150], int xC, int yC) //Trouve le chemin le plus court entre 2 points.
{

	if(xF==Ferme->x && yF==Ferme->y)
	{

		return Ferme;
	}

	else
	{


		int i, j;
		int x=Ferme->x;
		int y=Ferme->y;
		for (i=-1;i<2;i++)
			{
				for(j=-1;j<2;j++)
				{

					if((x+i>=0)&&(y+j>=0)&&(x+i<=xC)&&(y+j<=yC)

					{

						if ((x+i!=x)||(y+j!=y))
						{
							if(i+x==x||j+y==y)
							{
								if(T[i+x][j+y]==0)
								{
									Point* po=Ouvert; //Le point n'est pas dans la liste Ouverte
									int a=0;
									while (po!=NULL)
									{
//
										if((po->x==x+i) && (po->y==y+j))
										{

											a=1;
										}
										po=po->suivant;
									}
									if(a==0)
									{
										Point* po2=Ferme; //Le point n'est pas dans la liste fermee
										 a=0;
										while (po2!=NULL)
										{
											if((po2->x == x+i) && (po2->y==y+j))
											{

												a=1;
											}
											po2=po2->base;
										}
										if(a==0)
										{
											Ouvert=remplis(Ouvert, Ferme, x+i, y+j, xF, yF); // On rajoute le point à laliste ouverte

										}
									}
								}
							}
						}
					}
				}
			}

		if (Ouvert==NULL)
		{


			return NULL;
		}

		Point* parc=Ouvert;
		Point* memoire=Ouvert;
		while(parc!=NULL) // On trouve la meilleur valeur de F.
		{
			if(parc->F <= memoire->F)
			{
				memoire=parc;
			}
			parc=parc->suivant;
		}
		Ferme=remplis(Ferme, Ferme, memoire->x,memoire->y, xC, yC);
		Ouvert=reMove(Ouvert, memoire); //On elève le point selectionné de l'Ouvert.


		Ferme=Astar(Ouvert, Ferme, xF, yF, T, xC, yC);


	}
}
