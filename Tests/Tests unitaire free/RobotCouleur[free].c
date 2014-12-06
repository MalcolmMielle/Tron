#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Robot.h"

/*********************Fonction type Voronoi qui calcule le nombres de cases que le robot atteint atteint en premier***********/

Point* Coloriage(Point* Ouvert, Point* Ferme, int xC, int yC, int T[][60], int bot) //
{
	int i, j;
	int x=Ferme->x;
	int y=Ferme->y;
	int nG=10+Ferme->G; //Nouvelle valeur de G

	for (i=-1;i<2;i++)
		{						
			for(j=-2;j<4;j=j+2) //On regarde toutes les deux cases.
			{	
				if((x+i>=0)&&(y+j>=0)&&(x+i<=xC)&&(y+j<=yC))
				{
					if ((x+i!=x)||(y+j!=y))
					{	
						if(i+x==x||j+y==y)
						{	
							if(T[x+i][y+j]>=nG||T[x+i][y+j]==0)
							{
								Point* po=Ouvert; //Le point n'est pas dans la liste Ouverte
								int a=0;
								while (po!=NULL)
								{
									if((po->x==x+i) && (po->y==y+j))
									{
										a=1;
									}
									else if(po->y==59)
									{
										
										exit(0);
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
											a=1;
										}
										
										po2=po2->base;
									}
									if(a==0)
									{
										if(nG==T[x+i][y+j])
											{
												T[x+i][y+j+1]=1;
											}
										else
										{	
											Ouvert=remplisCouleur(Ouvert, Ferme, x+i, y+j); // On rajoute le point à laliste ouverte
											T[x+i][y+j]=nG;
											T[x+i][y+j+1]=bot;	

										}
									}
								}
							}						
						} 			
					}
				}
			}
		}
	if(Ouvert==NULL)
	{
//		free(Ouvert);
		return Ferme;
	}
	Point* parc=Ouvert;
	Point* memoire=Ouvert;
	while(parc!=NULL) // On trouve la meilleur valeur de F.
	{
		if(parc->G <= memoire->G)
		{
			memoire=parc;
		}
		parc=parc->suivant;
	}
	Ferme=remplis2(Ferme, Ferme, memoire->G, memoire->x,memoire->y);
	Ouvert=reMove(Ouvert, memoire); //On elève le point selectionné de l'Ouvert.
	if(Ferme->y%2!=0)
	{
		exit(0);
	}

	freelistP(memoire);
	free(parc);
	Ferme=Coloriage(Ouvert, Ferme, xC, yC, T, bot);

	
	
}

/********************Fonction agissant sur la Grille************************/

int Compteur(int Grille[][60], int n)// Compte le nombre de case à une valeur n
{
	int i, j; 
	int power=0;
	for(i=0;i<30;i++)
	{
		for(j=1;j<60;j=j+2)
		{
			if(Grille[i][j]==n)
			{
				power=power+1;
			}
		}
	}
	return power;
}


void CopieTableau(int T[][60], int T2[][60]) //Copie un tableau dans un autre
{
	int i,j;
	for(i=0;i<30;i++)
	{
		for(j=0;j<60;j++)
		{
			T2[i][j]=T[i][j];
		}
	}
}


/**************************Fonction qui calcul la position où doit aller le robot pour obtenir le plus de cases lors de son prochain mouvement si aucun autre robot ne bouge*******************/

Couleur* Visuel(int Grille[][60], int x, int y, int XG, int YG, Couleur* Ennemy)
{

	int i, j;
	Couleur* Full=NULL;
	int CopieGrille[30][60];
	int a1;
	
	Point* Ouvert=NULL;
	Point* Ferme=NULL;
	CopieTableau(Grille, CopieGrille);
	
	for(i=-1;i<2;i++)
	{
		for(j=-2;j<3;j=j+2)
		{
			if((x+i>=0 && y+j>=0) && (x+i<30 && y+j<60))
			{			

				if((i==0||j==0) && (i!=0||j!=0))
				{
					if(CopieGrille[x+i][y+j]!=1)
					{
						Couleur* Body=NULL;
						Body=Ennemy;
						while(Body!=NULL)
						{
							if(Body->x!=x && Body->y!=y)
							{

								Ouvert=NULL;
								Ferme=NULL;
								Ferme=remplisInitCouleur(Ferme, Ferme, Body->x, Body->y-1);
								Ferme=Coloriage (Ouvert, Ferme, 29, 59, CopieGrille, Body->nombre);
								free(Ouvert);
								freelistP(Ferme);

								
							}
							Body=Body->base;
														
						}
						Ouvert=NULL;
						Ferme=NULL;
						Ferme=remplisInitCouleur(Ferme, Ferme,x+i,y+j-1);
						Ferme=Coloriage (Ouvert, Ferme, 29, 59,CopieGrille, -1);
						printf("\n\n");
								free(Ouvert);
								freelistP(Ferme);
//													afficherF(Ferme);
//								scanf("%d",&i);	
						
						
							
						a1=0;
						a1=Compteur(CopieGrille,-1);
						printf("x y et y =%d j=%d %d %d \n", x+i,y+j,y,j);
						Full=ajoutCouleur(Full,x+i,y+j,a1);
						printf("\n FULL \n");
//						afficherCo(Full);

					}

					CopieTableau(Grille, CopieGrille);
					
				}
			}
		}
	}	


	
	Couleur* compteur=NULL;
	Couleur* Full2=Full;
	compteur=ajoutCouleur(compteur,-1,-1,0);
	while(Full!=NULL)
	{
		if(compteur->nombre<Full->nombre)
		{
			compteur=ajoutCouleur(compteur,Full->x,Full->y,Full->nombre);
		}
	Full=Full->base;
	free(Full2);
	Full2=Full;
	}
//	freelist(Full2);
	return compteur;		
}


/********************Fonction qui regarde la position la plus avantageuse de toutes les robots visible, et qui calcul la position la plus avantageuse pour le robot qui "réfléchi" si tous les autres vont à la position la plus avantageuse pour eux*************/

Couleur* Bot(int Grille[][30], int x, int y, int XG, int YG)// XG = 299 et YG = 149
{

	int i,j;
	int GrilleCopie[30][60]; //On double la carte. Ainsi La map est copie et à côté de chaque case on note une valeur G qui correspondra au nombre de pas effectué par le bot pour atteindre la case. Sur l'autre case est le numéro du robot qui est le plus proche (donc le numéro du bot associé au nombre de pas G).
	for(i=0;i<30;i++)
	{
		for(j=0;j<30;j++)
		{
			if(Grille[i][j]==0)
			{
				GrilleCopie[i][2*j]=0;
				GrilleCopie[i][(2*j)+1]=0;
			}
			else if(Grille[i][j]==1)
			{
				GrilleCopie[i][2*j]=1;
				GrilleCopie[i][(2*j)+1]=1;
			}
			else
			{
				GrilleCopie[i][2*j]=1;
				GrilleCopie[i][(2*j)+1]=Grille[i][j];
			}
		}
	}


	int n=3;
	Couleur* Ennemy=NULL;

	for (i=0;i<XG+1;i++)//On scanne la map vue par le bot à la recherche d'ennemis.
	{
		for(j=1;j<YG+1;j++)
		{
			if(GrilleCopie[i][(2*j)+1]==2)
			{
				Ennemy=ajoutCouleur(Ennemy,i,(2*j)+1, n);
				n=n+1;
			}
		}
	}
	
	Couleur* Ennemytemp=Ennemy;
	Couleur* Full=NULL;
	Couleur* Result=NULL;
	while (Ennemytemp!=NULL) //Pour chaque ennemy, on calcul la meilleur place qu'il a, sans que la Grille soit touchée.
	{
		if(Ennemytemp->x!=15 || Ennemytemp->y!=31)
		{
			Full=Visuel(GrilleCopie, Ennemytemp->x, Ennemytemp->y, XG, YG, Ennemy);
//			afficherCo(Full);
			Result=ajoutCouleur(Result, Full->x, Full->y, Ennemytemp->nombre);
			freelist(Full);
			Full=NULL;

		}		
		Ennemytemp=Ennemytemp->base;
	}
	
//	afficherCo(Ennemy);
	printf("\n");
//	afficherCo(Result);

	Couleur* Result2=Result;
	Ennemytemp=Ennemy;
	while(Ennemytemp!=NULL) //On place les ennemis à leur position la plus avantageuse du point de vue du robot.
	{
		GrilleCopie[Ennemytemp->x][Ennemytemp->y-1]=1; //On met un mur à leur position precedante
		GrilleCopie[Ennemytemp->x][Ennemytemp->y]=1;
		Ennemytemp=Ennemytemp->base;
	}
	
	while(Result2!=NULL)
	{
		GrilleCopie[Result2->x][Result2->y-1]=2;//On les places à leur nouvel emplacement
		GrilleCopie[Result2->x][Result2->y]=Result2->nombre;
		Result2=Result2->base;
	}
	
/*$	for(i=0;i<30;i++)
	{
		for(j=0;j<30;j=j++)
		{
			printf("%d ", GrilleCopie[i][(2*j+1)]);
		}
	printf("\n");
	}
	printf("La map refaite !\n");*/

	
	
	Full=NULL;
	Full=Visuel(GrilleCopie, 15, 31, XG, YG, Ennemy); //On cherche le meilleur point pour le robot avec tous les autres joueur à leur position la plus avantageuse.
	
	freelist(Ennemy);

//	freelist(Result);//Useless
	freelist(Result);
	freelist(Result2);
	
	
	if(Full->x==-1||Full->y==-1) //Si le robot est encerclé.
	{
		return NULL;
	}
	else
	{
		printf("ONa y = %d et Full->y = %d et x =%d et Full->x= %d\n\n", y, Full->y,x,Full->x);
		Full->x=x+(Full->x-15);
		Full->y=y+(((Full->y)-31)/2);
		return Full;
	}
}




/**********************************Fonction Robot totale !!!!********************************/


Couleur* Mouv(int Map[][150], int x, int y)
{
	int i,j;
	int Grille[30][30]; //On copie la grille en mettant le robot au milieu de Grille. Simule sa vision limité à 360 degrés
	for(i=-15;i<15;i++)
	{
		for(j=-15;j<15;j++)
		{
			if(x+i<0 || y+j<0)
			{
				Grille[15+i][15+j]=1;
			}
			else if(x+i>=300 || y+j>=150)
			{
				Grille[15+i][15+j]=1;
			}
			else
			{
				Grille[15+i][15+j]=Map[x+i][y+j];
			}
		}
	}	

	srand(time(NULL));
	int bob=0; 
	Couleur* End=NULL;
	for(i=0;i<30;i++)
	{
		for(j=0;j<30;j++)
		{
			printf("%d ", Grille[i][j]);
			if(Grille[i][j]==2 && (i!=15 || j!=15))
			{
				bob=bob+1;
				printf("\n\n le Bob evolue en %d %d\n\n", i, j);
			}
		}printf("\n");
	}
	
	if (bob!=0)
	{
		End=Bot(Grille,x ,y ,29 ,29);
		return End;
	}
	else
	{
	End=LeRandomBot(x,y,Grille, Map);		
	return End;
	}
}


