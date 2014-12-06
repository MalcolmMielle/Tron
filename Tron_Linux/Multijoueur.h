#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <time.h>
#ifndef DEF_JEU
//#include "Header/Jeux.h"
#endif
#ifndef DEF_BOT
#include "Header/bot.h"
#endif



void jeu(SDL_Surface *ecran,FILE *Scores);
void jeu_multi(SDL_Surface *ecran);

