#include <stdio.h>
#include <stdlib.h>

#include "Robot.h"

/******* Fonction de nettoyage des allocations dynamiques************/
/***** Pense à mettre les prototypes dans Robot.h *******************/

void freelist(Couleur* tete)
{

 Couleur*ptr=tete->base;

    while ( tete != NULL) 
    {
		free( tete );
		tete = ptr;
      	if(ptr!=NULL)
   	   		{
   	   		ptr = tete->base;
   	   		}
   	}
}

void freelistP(Point* tete)
{

 Point*ptr=tete->suivant;

    while (tete!=NULL) 
    {
     	free(tete);
      	tete = ptr;
      	if(ptr!=NULL)
      		{
      		ptr = tete->suivant;
      		}
    }
}
