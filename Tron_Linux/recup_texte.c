#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <time.h>
#ifndef DEF_JEU
#include "Jeux.h"
#endif
#include <SDL/SDL_ttf.h>

#include<string.h>
// Fonction permettant de récuper une chaine de 5 caractere saisie par l'utilisateur
//Seule les 26 lettre de l'alphabet sont pris en compte.
int texte (char Nom1[7],SDL_Surface *ecran)
{
    SDL_Surface *chaine=NULL;
    SDL_Rect pos_t;
    SDL_Event event;
    int continuer=1;
    int nb=0;
    TTF_Font *police = NULL;
    SDL_Color couleurBleu ={91,83,227};
    TTF_Init();
    police =TTF_OpenFont("times.ttf", 40);
    char Nom[7]="";

    pos_t.x=80;
    pos_t.y=130;
    strcpy(Nom,"");


    while(continuer && nb<5)
    {   fprintf(stderr,"\nnb=%d \n",nb);
        chaine = TTF_RenderText_Blended(police,Nom,couleurBleu); // affichage de la nouvelle chaine contenant le nom al 'ecran
         SDL_BlitSurface(chaine, NULL, ecran, &pos_t);
         SDL_Flip(ecran);

        SDL_WaitEvent(&event);
        switch(event.type)
            {
                case SDL_KEYDOWN:

                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE: //
                    continuer=0;
                    break;

                    case SDLK_o :
                    Nom[nb]='o';
                    nb++;
                    break;

                    case SDLK_q :
                    Nom[nb]='a';
                    nb++;
                    break;

                    case SDLK_a :
                    Nom[nb]='q';
                    nb++;
                    break;

                    case SDLK_w :
                    Nom[nb]='z';
                    nb++;
                    break;

                    case SDLK_z :
                    Nom[nb]='w';
                    nb++;
                    break;

                    case SDLK_e :
                    Nom[nb]='e';
                    nb++;
                    break;

                    case SDLK_r :
                    Nom[nb]='r';
                    nb++;
                    break;

                    case SDLK_t :
                    Nom[nb]='t';
                    nb++;
                    break;

                    case SDLK_y :
                    Nom[nb]='y';
                    nb++;
                    break;

                    case SDLK_u :
                    Nom[nb]='u';
                    nb++;
                    break;

                    case SDLK_i :
                    Nom[nb]='i';
                    nb++;
                    break;

                    case SDLK_p :
                    Nom[nb]='p';
                    nb++;
                    break;

                    case SDLK_s :
                    Nom[nb]='s';
                    nb++;
                    break;

                    case SDLK_d :
                    Nom[nb]='d';
                    nb++;
                    break;

                    case SDLK_f :
                    Nom[nb]='f';
                    nb++;
                    break;

                    case SDLK_g :
                    Nom[nb]='g';
                    nb++;
                    break;

                    case SDLK_h :
                    Nom[nb]='h';
                    nb++;
                    break;

                    case SDLK_j :
                    Nom[nb]='j';
                    nb++;
                    break;

                    case SDLK_k :
                    Nom[nb]='k';
                    nb++;
                    break;

                    case SDLK_l :
                    Nom[nb]='l';
                    nb++;
                    break;

                    case SDLK_x :
                    Nom[nb]='x';
                    nb++;
                    break;

                    case SDLK_c :
                    Nom[nb]='c';
                    nb++;
                    break;

                    case SDLK_v :
                    Nom[nb]='v';
                    nb++;
                    break;

                    case SDLK_b :
                    Nom[nb]='b';
                    nb++;
                    break;

                    case SDLK_n :
                    Nom[nb]='n';
                    nb++;
                    break;

                    case SDLK_SEMICOLON :
                    Nom[nb]='m';
                    nb++;
                    break;

                    default :
                    break;

                }

                default:
                break;
            }
    }
    strcpy(Nom1,Nom);

return (1) ;
}
