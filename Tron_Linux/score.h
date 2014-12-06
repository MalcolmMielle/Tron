#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <time.h>
#ifndef DEF_JEU
#include "Jeux.h"
#endif
#include <SDL/SDL_ttf.h>



void score (SDL_Surface *ecran,FILE* Scores,FILE* result);
void option (SDL_Surface *ecran, FILE* Opt, int *vitesse);
