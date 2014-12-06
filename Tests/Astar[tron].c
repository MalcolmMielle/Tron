#include <stdio.h>
#include <stdlib.h>
#include "Robot.h"








Point* reMove(Point* in, Point* point)
{
	Point* ptr1=in;
	Point* ptr2=in;
	if(ptr1==point)
	{
		ptr1=ptr1->suivant;
		return ptr1;
	}
	ptr1=ptr1->suivant;
	if (ptr1==point)
	{
		ptr1=ptr1->suivant;
		ptr2->suivant=ptr1;
		return ptr2;
	}
	while (ptr1!=point)
	{
		ptr1=ptr1->suivant;
		ptr2=ptr2->suivant;
	}
	ptr1=ptr1->suivant;
	ptr2->suivant=ptr1;
	return in;
}

Point* Astar(Point* Ouvert, Point* Ferme, int xF, int yF, int T[][150], int xC, int yC) //Trouve le chemin le plus court entre 2 points.
{
//	printf("PIRATE\n\n");
	if(xF==Ferme->x && yF==Ferme->y)
	{
//		printf("LA FIN \n");
		return Ferme;
	}
	
	else
	{	
		
//		printf("\n Nous sommes au point %d %d et on va %d %d\n\n", Ferme->x, Ferme->y, xF, yF);
		int i, j;
		int x=Ferme->x;
		int y=Ferme->y;
		for (i=-1;i<2;i++)
			{						
				for(j=-1;j<2;j++)
				{	
//					printf("i %d j %d et avec lplace %d %d\n", i, j, x+i, y+j);		
					if((x+i>=0)&&(y+j>=0)&&(x+i<=xC)&&(y+j<=yC))
					{
				//		printf("\n\ncondition 1\n\n");
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
//										printf("pox et poy %d %d\n", po->x, po->y);
										if((po->x==x+i) && (po->y==y+j))
										{
//											printf("\n\nVu\n\n");
											a=1;
										}
										po=po->suivant;
									}
									if(a==0) 
									{
										Point* po2=Ferme; //Le point n'est pas dans la liste fermee
										int a=0;
										while (po2!=NULL)
										{
											if((po2->x == x+i) && (po2->y==y+j))
											{
//											printf("\n\nVu2\n\n");
												a=1;
											}
											po2=po2->base;
										}
										if(a==0)
										{
											Ouvert=remplis(Ouvert, Ferme, x+i, y+j, xF, yF); // On rajoute le point à laliste ouverte		
//											printf("La liste ouverte\n");
//											afficher(Ouvert);
//											printf("\n");
										}
									}
								}						
							} 			
						}
					}
				}
			}
//			afficher(Ouvert);
		//	if (x==5 && y==2) exit(0);
//		printf("Et 1 ouverte\n");
//		afficher(Ouvert);	
		if (Ouvert==NULL)
		{
			printf("\n PAS DE CHEMIN\n");
			return NULL;
		}
//		printf("La liste ouverte finale\n");
//		afficher(Ouvert);
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
		
//		printf("\nVoici les liste Ferme\n");
//		afficherF(Ferme);
//		printf("Et ouverte\n");
//		afficher(Ouvert);
//		scanf("%d",&i);
		Ferme=Astar(Ouvert, Ferme, xF, yF, T, xC, yC);
	}
}
