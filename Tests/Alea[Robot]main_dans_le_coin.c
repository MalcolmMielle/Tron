#include <stdlib.h>
#include <stdio.h>
#include "Robot.h"



void main()
{
	int T[300][150];
	int i,j,m;
	for(i=0;i<300;i++)
	{
		for(j=0;j<150;j++)
		{
			T[i][j]=0;
		}
	}
	
	
	for(i=0;i<29;i++)
	{
		T[i][6]=1;
	}
	int x,y;

	x=299;
	y=0;
	T[x][y]=2;
	
	
	Couleur* Full=NULL;
	Full=NULL;
	Full=Mouv(T,299,0); 
	printf("\n LA SOL pour 6 15 \n");

	if(Full==NULL)
	{
		printf("\nLe robot a perdu !");
		exit(0);
	}
	
	afficherCo(Full);
	printf("Pouet de fin !\n");	
	if( T[Full->x][Full->y] != 0)
	{
		printf("\n SUCH A FAIL %d\n", T[Full->x][Full->y]);
	}

}


/*
void main()
{
	int T[15][15];
	int i, j;
	for (i=0;i<15;i++)
	{
		for(j=0;j<15;j++)
		{
			T[i][j]=0;
		}
	}

	int x, y;
	x=6;
	y=6;
	Chemin* Court=NULL;
	int n=70;
	Court=ajout(Court,x,y);
	int Arrive[2]={0,0};
	while(Court!=NULL || n!=0)
	{
		for(i=0;i<15;i++)
		{
			printf("%d ",i);
		}
		printf("\n");
		for(i=0;i<15;i++)
		{
			for(j=0;j<15;j++)
			{
				printf("%d ", T[i][j]);
			}
			printf("\n");
		}

//		printf("x=%d, y=%d \n",Court->x, Court->y);
//		Court=AntiGrav(T,Court->x,Court->y, 29,29);
		Court=Carre(Arrive, Court->x, Court->y, 14, 14, T, Court);
//		printf("\n\n On a alors : %d %d\n\n", Court->x, Court->y);
		scanf("%d",&n);	
	}
}	*/
