/*#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <time.h>
#ifndef DEF_JEU
#include "Header/Jeux.h"
#endif
#include <SDL/SDL_ttf.h>
#ifndef DEF_BOT
#include "Header/bot.h"
#endif
#include "Header/score.h"
#include <fmodex/fmod.h>
**/
/*void son_court(char son[40], FMOD_SYSTEM *system)
{

FMOD_SOUND *crash = NULL; //Initialisation d'un son court
FMOD_RESULT resultat;

resultat = FMOD_System_CreateSound(system, son, FMOD_CREATESAMPLE, 0,&crash); //Son du crash
    if (resultat !=FMOD_OK)
    {
        fprintf(stderr,"Impossible de lire %s", son);
       exit(EXIT_FAILURE);
    }
 FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, crash, 0, NULL); //On joue le son : objet système/numero de canal (ici gérer par fmod)/pointeur du son

}

void musique(char son[40], FMOD_SYSTEM *system)
{

FMOD_SOUND *bruit = NULL; //Initialisation d'un son court
FMOD_RESULT resultat;

resultat = FMOD_System_CreateSound(system, son, FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0,&bruit); //Son du crash
    if (resultat !=FMOD_OK)
    {
        fprintf(stderr,"Impossible de lire %s", son);
       exit(EXIT_FAILURE);
    }
FMOD_Sound_SetLoopCount(bruit,-1);

FMOD_System_PlaySound(system, 0, bruit, 0, NULL);
}


*/


