#ifndef DEF_BOT
#include "Header/bot.h"
#endif
#include <stdio.h>
#include <stdlib.h>
/***************Structure du chemin final***************/


/***************************************************************/

Chemin* OnlyOneDEF(int Grille[][150], int x, int y, int XG, int YG)
{

	Chemin* Court=NULL;
	int i,j;

	if((y==3&&x!=3)||(y==3&&XG-x==3)||(x<XG/2&&y<YG/2))//partie supérieur gauche et ligne haute vers gauche
	{
		if(Grille[x-1][y]==1)
		{
			for(i=-1;i<2;i++)
			{
				for(j=1;j<-2;j--)
				{
					if((i!=j)||(i!=-j))
					{
						if(Grille[i][j]==0)
						{
							Court=ajout(Court, j, i);
							return Court;
							/*x=j;
							y=i;*/
						}
					}
				}
			}
		}
		else
		{
			Court=ajout(Court, x-1, y);
			return Court;
		}
	}
	else if((x==3&&y==3)||(x==3&&y!=3)||(x<XG/2&&y>YG/2))//partie inférieure gauche et ligne gauche descendante
	{
		if(Grille[x][y++]==1)
		{
			if(Grille[x-1][y]==1)
			{
				for(i=1;i<-2;i--)
				{
					for(j=1;j<-2;j--)
					{
						if((i!=j)||(i!=-j))
						{
							if(Grille[j][i]==0)
							{
								Court=ajout(Court, j, i);
								return Court;
								/*x=j;
								y=i;*/
							}
						}
					}
				}
			}
		}
		else
		{
			Court=ajout(Court, x, y++);
			return Court;
		}
	}
	else if((XG-x==3&&YG-y!=3)||(XG-x==3||YG-y==3)||(x>XG/2&&y<YG/2))//partie supérieure droite et ligne droite montante
	{
		if(Grille[x][y-1]==1)
		{
			if(Grille[x-1][y]==1)
			{
				for(i=-1;i<2;i++)
				{
					for(j=-1;j<2;j++)
					{
						if((i!=j)||(i!=-j))
						{
							if(Grille[i][j]==0)
							{
								Court=ajout(Court, j, i);
								return Court;
								/*x=j;
								y=i;*/
							}
						}
					}
				}
			}
		}
		else
		{
		Court=ajout(Court, x, y-1);
		return Court;
		}
	}
	else if((YG-y==3&&XG-x!=3)||(x==3&&YG-y==3)||(x>XG/2&&y>YG/2))//partie inférieure droite et ligne basse vers la droite
	{
		if(Grille[x++][y]==1)
		{
			if(Grille[x-1][y]==1)
			{
				for(i=-1;i<2;i++)
				{
					for(j=1;j<-2;j--)
					{
						if((i!=j)||(i!=-j))
						{
							if(Grille[j][i]==0)
							{
								Court=ajout(Court, j, i);
								return Court;
								/*x=j;
								y=i;*/
							}
						}
					}
				}
			}
		}
		else
		{
		Court=ajout(Court, x++, y);
		return Court;
		}
	}
}




