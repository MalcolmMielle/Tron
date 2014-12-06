#include <stdio.h>
#include <stdlib.h>

#include "Robot.h"

/************************Fonction qui génère une structure aléatoire avec de schiffres comris entre 0 et 3 autour du point envoyé, sans faire de diagonales**********/



Couleur* Random(int x, int y, Couleur* Done, int Grille[][30])
{
	
	Couleur* Fin=NULL;
	int alea2;
	int alea, a;
	Couleur* Defile;
	do
	{
		a=0;
		alea=rand()%3;
		alea2=rand()%3;
		Defile=Done;
		while(Defile!=NULL)
		{
			if(x-1+alea==Defile->x && y-1+alea2==Defile->y)
			{	
				printf("chouette\n");
				a=1;
			}
			Defile=Defile->base;
		}
		printf("on a %d %d  avec x y %d %d a %d et grille %d\n", x-1+alea, y-1+alea2, x, y, a, Grille[15-1+alea][15-1+alea2]);
	}while((x-1+alea==x && y-1+alea2==y) || (x-1+alea!=x && y-1+alea2!=y) || a==1 || Grille[15-1+alea][15-1+alea2]==1 );

	Fin=ajoutCouleur(Fin, x-1+alea, y-1+alea2, 0);
	freelist(Defile);
	return Fin;
}




Couleur* LeRandomBot(int x, int y, int Grille[][30], int Map[][150])
{
	printf("LA SOLUTION SERA ALEATOIRE \n\n");
	int i,j;
	int N=1;
	int dec=0;
	int a;
	int K=0;
	Couleur* End;
	for(i=-1;i<2;i++)
	{
	for(j=-1;j<2;j++)
		{			
			if((i==0||j==0) && (i!=0||j!=0))	
			{
				if(Grille[15+i][15+j]==0)
				{
					K=K+1;
				}
			}
		}
	}
	if(K==0)
	{
		End=NULL;
		return End;
	}	
	Couleur* Done=NULL;
	do
		{
			
			a=1;
			if (dec==K)
			{
				printf("N tour %d\n",N);
				N=N+1;
				dec=0;
				Done=NULL;
			}
			
			End=Random(x,y,Done,Grille);	
		
			Done=ajoutCouleur(Done, End->x, End->y, 0);
			printf("\n HERE\n");
			for(i=-1;i<2;i++)
			{
				for(j=-1;j<2;j++)
				{
					if(End->x+i>0 && End->y+j>0 && End->x+i<300 && End->y+j<150)
					{	
						if((i==0||j==0) && (i!=0||j!=0))	
						{
							if(Map[End->x+i][End->y+j]==1)
							
								{
									printf("It happened×\n");
									a=a+1;
								}
						}
					}
				}
			}
			
			dec=dec+1;
			printf("Getting out with a DEC of %d and a a= %d and a N = %d \n\n", dec, a, N);
		}while(a>N);
	
	freelist(Done);
	
	return End;
}
