#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <time.h>
#include <SDL/SDL_ttf.h>

#define DEF_JEU
#ifndef DEF_BOT
#include "Robot.h"

//#include <fmod.h>
//#include <SDL/fmod.h>

void jeu(SDL_Surface *ecran,FILE* Scores, SDL_Surface* menuc,FILE* Nom_joueur,FILE* enr, int vitesse, FILE* Result);
//void jeu_multi(SDL_Surface *ecran,FMOD_SYSTEM *system,SDL_Surface* menuc,FILE* Nom_joueur,FILE* enr,char Nom_fic[17],FILE* enr2);
void jeu_multi(SDL_Surface *ecran,SDL_Surface* menuc,FILE* enr,FILE* enr2);
typedef struct position position;
int texte (char Nom1[7],SDL_Surface *ecran);
int touche (SDL_Surface *ecran,int *touche1,int *touche2);
void personnage (SDL_Surface* ecran,FILE* enr,char Nom_fic[]);
int config_touches(SDL_Surface *ecran);
char *  itoa ( int value, char * str, int base );



struct position {

SDL_Rect x,xc;

};

#endif
