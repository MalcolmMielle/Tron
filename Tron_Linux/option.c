#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <time.h>
#ifndef DEF_JEU
#include "Jeux.h"
#endif
#include <SDL/SDL_ttf.h>

#include "score.h"


void option (SDL_Surface *ecran, FILE* Opt, int *vitesse)
{
    int continuer=1,i, verf=0;
    SDL_Event event;
    SDL_Surface *carte=NULL, *Avater=NULL, *vitesse1=NULL, *vitesse2=NULL;
    SDL_Rect pos_avater,pos_vitesse;

    TTF_Font *police = NULL;
    SDL_Color couleurBleu ={91,83,227};
    TTF_Init();
    police =TTF_OpenFont("times.ttf", 40);

    vitesse1 = TTF_RenderText_Blended(police,"5",couleurBleu);
    vitesse2 = TTF_RenderText_Blended(police,"100",couleurBleu);

    pos_vitesse.x=990;
    pos_vitesse.y=30;



    rewind(Opt);
    fscanf(Opt, "%d", &i);

     switch(abs(i%7))
    {
        case 0:
        Avater=SDL_LoadBMP("21.bmp");
        break;

        case 1:
        Avater=SDL_LoadBMP("22.bmp");
        break;

        case 2:
        Avater=SDL_LoadBMP("23.bmp");
        break;

        case 3:
        Avater=SDL_LoadBMP("24.bmp");
        break;

        case 4:
        Avater=SDL_LoadBMP("25.bmp");
        break;

        case 5:
        Avater=SDL_LoadBMP("26.bmp");
        break;

        case 6:
        Avater=SDL_LoadBMP("27.bmp");
        break;

        default:
        break;
    }



    pos_avater.x=564;
    pos_avater.y=197+(461-(Avater->h))/2;



    carte=SDL_LoadBMP("Grille.bmp");
    ecran = SDL_SetVideoMode(1200, 700, 32, SDL_HWSURFACE |SDL_DOUBLEBUF|SDL_FULLSCREEN );
    SDL_BlitSurface(carte, NULL, ecran, NULL);
    SDL_BlitSurface(Avater, NULL, ecran, &pos_avater);
    SDL_Flip(ecran);


      while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
            {

                case SDL_QUIT:
                continuer = 0;
                break;

                case SDL_MOUSEBUTTONDOWN:

                if(event.button.x>22 && event.button.x<361 && event.button.y>594 && event.button.y<680) // quitter le programme
                {

                      if(verf==1)
                    {

                        remove("Opt.txt");
                        Opt=fopen("Opt.txt","w+");

                        fprintf(Opt, "%d %d",abs(i%7),*vitesse);

                        fclose(Opt);
                       continuer=0;

                    }




                }
                if(event.button.x>983 && event.button.x<1042&& event.button.y<69 && event.button.y >35)//Vitesse
                {
                   if (*vitesse==100)
                   {
                       *vitesse=5;
                   }
                   else
                   {
                       *vitesse=100;
                   }
                }

                if(event.button.x>445 && event.button.x<549&& event.button.y<466 && event.button.y >346)//fleche gauche
                    {


                        verf=1;
                        i++;
                        SDL_FreeSurface(Avater);
                        //fprintf(stderr,"i=%d  i/3=%f \n",i%3,i/3);
                        switch(abs(i%7))
                        {
                            case 0:
                            Avater=SDL_LoadBMP("21.bmp");
                            break;

                            case 1:
                            Avater=SDL_LoadBMP("22.bmp");
                            break;

                            case 2:
                            Avater=SDL_LoadBMP("23.bmp");
                            break;

                            case 3:
                            Avater=SDL_LoadBMP("24.bmp");
                            break;

                            case 4:
                            Avater=SDL_LoadBMP("25.bmp");
                            break;

                            case 5:
                            Avater=SDL_LoadBMP("26.bmp");
                            break;

                            case 6:
                            Avater=SDL_LoadBMP("27.bmp");
                            break;

                            default :
                            break;


                        }                    }
                    else
                    {
                        if(event.button.x>1077 && event.button.x<1180 && event.button.y<457 && event.button.y >358)//fleche droite
                     {
                         verf=1;
                         i--;
                         SDL_FreeSurface(Avater);

                        switch(abs(i%7))
                        {
                            case 0:
                            Avater=SDL_LoadBMP("21.bmp");
                            break;

                            case 1:
                            Avater=SDL_LoadBMP("22.bmp");
                            break;

                            case 2:
                            Avater=SDL_LoadBMP("23.bmp");
                            break;

                            case 3:
                            Avater=SDL_LoadBMP("24.bmp");
                            break;

                            case 4:
                            Avater=SDL_LoadBMP("25.bmp");
                            break;

                            case 5:
                            Avater=SDL_LoadBMP("26.bmp");
                            break;

                            case 6:
                            Avater=SDL_LoadBMP("27.bmp");
                            break;

                            default :
                            break;
                        }



                     }
                    }


                break;

                case SDL_KEYDOWN:


                case SDLK_ESCAPE :
                if(verf==1)
                {
                    remove("Opt.txt");
                    Opt=fopen("Opt.txt","w+");
                    fprintf(Opt, "%d %d",abs(i%7),*vitesse);
                }
                break;

                default :
                break;
            }


            pos_avater.y=197+(461-(Avater->h))/2;
            SDL_BlitSurface(carte, NULL, ecran, NULL);
            if (*vitesse==5)
            {
                SDL_BlitSurface(vitesse1, NULL, ecran, &pos_vitesse);
            }
            else
            {
                SDL_BlitSurface(vitesse2, NULL, ecran, &pos_vitesse);
            }
            SDL_BlitSurface(Avater, NULL, ecran, &pos_avater);
            SDL_Flip(ecran);

    }
    SDL_FreeSurface(Avater);
    SDL_FreeSurface(carte);
    SDL_FreeSurface(vitesse1);
    SDL_FreeSurface(vitesse2);
//    fclose(Opt);

}
