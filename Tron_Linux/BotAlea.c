#include <stdio.h>
#include <stdlib.h>

#include "Robot.h"

/************************Fonction qui génère une structure aléatoire avec de schiffres comris entre 0 et 3 autour du point envoyé, sans faire de diagonales**********/



Couleur* Random(int x, int y, Couleur* Done, int Grille[][30]) //Fonction déterminant une position alétoire autour du robot
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
				a=1;
			}
			Defile=Defile->base;
		}
	}while((x-1+alea==x && y-1+alea2==y) || (x-1+alea!=x && y-1+alea2!=y) || a==1 || Grille[15-1+alea][15-1+alea2]==1 );
	Fin=ajoutCouleur(Fin, x-1+alea, y-1+alea2, 0);
	return Fin;
}





Couleur* LeRandomBot(int x, int y, int Grille[][30], int Map[][150]) // Fonction pour choisir parmis les position autour du bot la meilleure
{

	int i,j;
	int N=1;
	int dec=0;
	int a;
	int K=0;
	Couleur* End=NULL;
	for(i=-1;i<2;i++)
	{
	for(j=-1;j<2;j++)
		{			
			if((i==0||j==0) && (i!=0||j!=0))	
			{
				if(Grille[15+i][15+j]==0)
				{
					K=K+1; //On compte le nombre de places libres
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
				freelist(Done);
				N=N+1;
				dec=0;
				Done=NULL;
			}

			freelist(End);
				
			End=Random(x,y,Done,Grille);	
		
			Done=ajoutCouleur(Done, End->x, End->y, 0);

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
									a=a+1; //On cherche la place libre la moins entouré de mur
								}
						}
					}
				}
			}
			
			dec=dec+1;
		
		}while(a>N);
	
	freelist(Done);
	
	return End; //On envoie la position de la case la meilleur pour le prochain déplacement.
}
