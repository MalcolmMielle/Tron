#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <time.h>
#ifndef DEF_JEU
#include "Jeux.h"
#endif
#include <SDL/SDL_ttf.h>
#ifndef DEF_BOT
#include "bot.h"
#endif
#include<string.h>

void score (SDL_Surface *ecran,FILE* Scores,FILE* result)
{
    SDL_Surface *fond=NULL,*texte3 = NULL,*rang=NULL,*titre=NULL, *Quitter=NULL;
    SDL_Event event;
    SDL_Rect pos_score,pos_rang,pos_titre,pos_Quit;
    int continuer=1,i=0;
    TTF_Font *police = NULL;

    char  num[2]="";


    char stock [5][10];
    char tab_ch[5][10];

    pos_score.x=500;
    pos_score.y=100;

    pos_Quit.x=800;
    pos_Quit.y=310;

    SDL_Color couleurNoire = {255, 255, 0};
    SDL_Color couleurRouge ={255,0,0};


    TTF_Init();
    police =TTF_OpenFont("times.ttf", 65);


    ecran = SDL_SetVideoMode(1000, 400, 32, SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_RESIZABLE|SDL_FULLSCREEN);
    fond=SDL_LoadBMP("Carte.bmp");
    SDL_BlitSurface(fond, NULL, ecran, NULL);


        fscanf(Scores, "%s %s %s %s %s",tab_ch[0],tab_ch[1],tab_ch[2],tab_ch[3],tab_ch[4]);
        fscanf(result, "%s %s %s %s %s",stock[0],stock[1],stock[2],stock[3],stock[4]);

        num[1]='.';



    titre = TTF_RenderText_Blended(police,"Resultats des Courses",couleurRouge);
    pos_titre.x=200;
    pos_titre.y=0;
    SDL_BlitSurface(titre, NULL, ecran, &pos_titre);
for(i=0;i<5;i++)
{


        pos_rang.y=pos_score.y;
        pos_rang.x=pos_score.x-250;
        texte3 = TTF_RenderText_Blended(police,tab_ch[i],couleurNoire);

        rang= TTF_RenderText_Blended(police,stock[i],couleurNoire);


        SDL_BlitSurface(texte3, NULL, ecran, &pos_score);
        SDL_BlitSurface(rang, NULL, ecran, &pos_rang);

        pos_score.y=pos_score.y+50;
}
        Quitter= TTF_RenderText_Blended(police,"Quit",couleurNoire);
        SDL_BlitSurface(Quitter, NULL, ecran, &pos_Quit);


 SDL_Flip(ecran);


    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
            {

                case SDL_QUIT:
                continuer = 0;
                break;

                case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT)
                {                    fprintf(stderr,"x=%d y = %d \n",event.button.x,event.button.y);

                  if(event.button.x>800 && event.button.x<924 && event.button.y<377 && event.button.y >325)
                  {
                    fprintf(stderr,"x=%d y = %d \n",event.button.x,event.button.y);

                      continuer = 0;

                  }
                }
                break;


                case SDL_KEYDOWN:

                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE: // le joueur refusent de jouer et quitte le jeux.
                    continuer=0;
                    break;


                    default:
                        break;
                }
                break;
                default :
                break;
            }
    }
TTF_CloseFont(police);
TTF_Quit;

}
