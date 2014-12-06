#include <stdlib.h>
#include <stdio.h>
#include "Robot.h"

void main()
{
	int T[30][150];
	int i,j,m;
	for(i=0;i<30;i++)
	{
		for(j=0;j<30;j++)
		{
			T[i][j]=0;
		}
	}
	
	
	for(i=0;i<29;i++)
	{
		T[i][6]=1;
	}
	int x,y;
	x=0;
	y=0;
	T[0][1]=2;
	int x2, y2;
	
	
	x=28;
	y=28;
	T[x][y]=2;
	
	
	
	x=15;
	y=22;
	T[x][y]=2;


	x=6;
	y=15;
	T[x][y]=2;
	
	x=7;
	y=15;
	T[x][y]=1;

	Couleur* Full=NULL;
	Full=NULL;
	Full=Mouv(T,6,15); 
	printf("\n LA SOL pour 6 15 \n");
	afficherCo(Full);
	printf("Pouet de fin !\n");	
	if( T[Full->x][Full->y] != 0)
	{
		printf("\n SUCH A FAIL %d\n", T[Full->x][Full->y]);
	}
	freelist(Full);

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
