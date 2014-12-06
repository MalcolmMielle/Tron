// Bot antigravity

#include <stdio.h>
#include <stdlib.h>

#include "Robot.h"

//Taille de la grille : 0-XG, 0-YG
//un joueur est représenté par un 2 et un mur est représenté par un 1


/******Somme des valeurs de X ou Y d'une structure***********/
int sommeX(Chemin* in) //Somme des valeurs de x
{
	Chemin *pointeur;
	int som=0;
	while (pointeur!=NULL)
	{
		som=som+pointeur->x;
//		printf("\n Gnagnagna %d\n", som);
		pointeur=pointeur->base;
	}
	return som;
}

int sommeY(Chemin* in) //Somme des valeurs de y
{
	Chemin *pointeur;
	int som=0;
	while (pointeur!=NULL)
	{
		som=som+pointeur->y;
//		printf("\n Gnagnagna %d\n", pointeur->y);
		pointeur=pointeur->base;
	}
	return som;
}

/*********Remplis la liste Astar****************/



Chemin* AntiGrav(int Grille[][150], int x, int y, int XG, int YG)
{
	if(Grille[0][0]==0) //Transforme les 4 coins en mur
	{
		Grille[0][0]=1;
	}
	if(Grille[299][0]==0)
	{
		Grille[299][0]=1;
	}
	if(Grille[0][99]==0)
	{
		Grille[0][99]=1;
	}
	if(Grille[299][99]==0)
	{
		Grille[299][99]=1;
	}
	
	Chemin* Anti=NULL;
	Chemin* Construction=NULL;
	
	int i,j,a=0;
	
	for (i=0;i<XG+1;i++)
	{
		for(j=0;j<YG+1;j++)
		{
			if (Grille[i][j]==1)
			{
				Construction=ajout(Construction,i,j); //Calcul des forces des murs et joueurs
				a=a+1;
			}
			else if (Grille[i][j]==2)
			{
				Construction=ajout(Construction,2*i,2*j);
				a=a+2;
			}
		}
	}
//	afficherC(Construction);
	Chemin *pointeur=Construction; //Calcul du barycentre où va se déplacer le bot
	int baryx=0;
	while (pointeur!=NULL)
	{
		baryx=baryx+pointeur->x;
//		printf("\n Gnagnagna %d\n", baryx);
		pointeur=pointeur->base;
	}
//	printf("x =%d\n", baryx);
	baryx=baryx/a;
//	printf("Après division %d\n", baryx);
	Chemin *pointeur2=Construction;
	int baryy=0;
	while (pointeur2!=NULL)
	{
		baryy=baryy+pointeur2->y;
//		printf("\n Gnagnagna %d\n", baryy);
		pointeur2=pointeur2->base;
	}
//	printf("y =%d\n", baryy);
	baryy=baryy/a;
//	printf("baryy=%d\n", baryy);


	Point* Ferme=NULL;	
	Point* Ouvert=NULL;
	Ferme=remplis0(Ferme, Ferme, x, y, baryx, baryy);
//	printf("avant A star");
//	afficherF(Ferme);
	baryx=1;
	baryy=1;
	Ferme=Astar(Ouvert, Ferme, baryx, baryy, Grille, XG, YG); //Calcul du chemin le plus court.
//	printf("Après Astar\n\n");
//	afficherF(Ferme);
//	printf("\nVoilou\n");
	Chemin* Court=NULL;
	if(Ferme==NULL)
	{
		int i,j;
		for (i=-1;i<2;i++)
			{						
				for(j=-1;j<2;j++)
				{		
					if((Grille[x+i][y+j]==0)&&(x+i>=0)&&(y+j>=0)&&(x+i<=XG)&&(y+j<=YG))
					{
						if ((x+i!=x)||(y+j!=y))
						{	
							if(i+x==x||j+y==y)
							{
								Court=ajout(Court, x+i, y+j); 
								return Court;
							}
						}
					}
				}
			}
	}
	else 
	{
		while (Ferme!=NULL)
		{
			Court=ajout(Court, Ferme->x, Ferme->y);
			Ferme=Ferme->base;
		}
		Court=Court->base;
		return Court;
	}
	return Court;
}
	
/***************************************/

void Determine(int Arrive[], int x, int y, int XG, int YG)
{
	printf("\n debut de la fonction Deter\n");
	if(x<=XG/2&&y<=YG/2)//partie supérieur gauche et ligne haute vers gauche
	{
		Arrive[0]= 3;
		Arrive[1]= 3;
	}
	else if(x<XG/2&&y>YG/2)//partie inférieure gauche et ligne gauche descendante
	{
		Arrive[0]= 3;
		Arrive[1]= YG-3;
	}
	else if(x>XG/2&&y<YG/2)//partie supérieure droite et ligne droite montante
	{
		Arrive[0]= XG-3;
		Arrive[1]= 3;
	}
	else if(x>XG/2&&y>YG/2)//partie inférieure droite et ligne basse vers la droite
	{
		Arrive[0]=XG-3;
		Arrive[1]=YG-3;
	}
	
	
}
	
Chemin* Carre(int Arrive[], int x, int y, int XG, int YG, int Grille[][150], Chemin* Court)
{	
//	printf("\ndebut de la fonction Carre\n");
	if(Arrive[0]==0 && Arrive[1]==0)
	{
//		printf("Premier\n");
		Determine(Arrive,x,y,XG,YG);
	}
	
//	printf("On a x %d y %d\n", Arrive[0], Arrive[1]);
	Grille[x][y]=1;
	int m=0;

		if(Arrive[0]==Court->x && Arrive[1]==Court->y)
		{
			if(Arrive[0]>XG/2 && Arrive[1]>YG/2)
			{
				Arrive[0]=3;
				Arrive[1]=YG-3;
			}
		
			else if (Arrive[0]<=XG/2 && Arrive[1]<=YG/2)
			{
				Arrive[0]=XG-3;
				Arrive[1]=3;
			}
		
			else if (Arrive[0]<XG/2 && Arrive[1]>YG/2)
			{
				Arrive[0]=3;
				Arrive[1]=3;		
			}
		
			else if (Arrive[0]>XG/2 && Arrive[1]<YG/2)
			{
				Arrive[0]=XG-3;
				Arrive[1]=YG-3;
			}
		}


	while(Grille[Arrive[0]][Arrive[1]]!=0)
		{	
			if(Arrive[0]>XG/2 && Arrive[1]>YG/2)//partie inférieure droite et ligne basse vers la droite
			{
				Arrive[0]=Arrive[0]-1;
				Arrive[1]=Arrive[1]-1;
			}
		
			else if (Arrive[0]<=XG/2 && Arrive[1]<=YG/2)//partie supérieur gauche et ligne haute vers gauche
			{
				Arrive[0]=Arrive[0]+1;
				Arrive[1]=Arrive[1]+1;
			}
		
			else if (Arrive[0]<XG/2 && Arrive[1]>YG/2)//partie inférieure gauche et ligne gauche descendante
			{
				Arrive[0]=Arrive[0]+1;
				Arrive[1]=Arrive[1]-1;		
			}
		
			else if (Arrive[0]>XG/2 && Arrive[1]<YG/2)//partie supérieure droite et ligne droite montante
			{
				Arrive[0]=Arrive[0]-1;
				Arrive[1]=Arrive[1]+1;
			}
			m=m+1;
			if(m>15*15)
			{
				printf("FAILLLL\n");
				exit(0);
			}

			printf("On ne dépasse pas les conditions avec Grille = %d\n",Grille[Arrive[0]][Arrive[1]]);
			
		}

	
	printf("On dépasse les conditions avec Grille = %d\n et arrive %d %d et arrive+m %d %d",Grille[Arrive[0]+m][Arrive[1]+m],Arrive[0],Arrive[1],Arrive[0]+m,Arrive[1]+m);	
			
	Point* Ferme=NULL;
	Point* Ouvert=NULL;	
	Ferme=remplis0(Ferme, Ferme, x, y, Arrive[0], Arrive[1]);
//	printf("On dépasse les conditions2\n");	
	printf("\nOn veut aller à %d %d depuis %d %d alors que Grille = %d\n",Arrive[0],Arrive[1],x,y,Grille[Arrive[0]][Arrive[1]]);
	Ferme=Astar(Ouvert, Ferme, Arrive[0], Arrive[1], Grille, XG,YG);
//	printf("On atteint un stade critique\n");
//	afficherF(Ferme);
//	printf("\nYep\n");

	Chemin* Out=NULL;
	while(Ferme!=NULL)
	{
		Out=ajout(Out, Ferme->x, Ferme->y);
		Ferme=Ferme->base;
	}
	
	Out=Out->base;
//	afficherC(Out);
	
	Court=ajout(Court, Out->x, Out->y);
	return Court;
}
	
	
	

