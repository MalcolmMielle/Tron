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
#include "score.h"
//#include <fmod.h>
#include<math.h>



void personnage (SDL_Surface* ecran,FILE* enr,char Nom_fic[17])
{
    SDL_Surface *moto=NULL,*texte_nom=NULL,*texte_Score=NULL, *Avatar=NULL,*Fond_nom=NULL, *Fond=NULL;
    SDL_Event event;
    SDL_Rect pos_Moto,pos_Nom,pos_Score, pos_Avatar;
    int continuer=1,i,verf=0;
    

    char nom[7]="";
    char Scores[15]="";
    int couleur_moto;
    int touche1,touche2;
    int choix_Avatar;

    TTF_Font *police = NULL;
    SDL_Color couleurBleu ={91,83,227};
    TTF_Init();
    police =TTF_OpenFont("times.ttf", 40);
/*********************Lancement du menu de selection de modifcation du jouieur********************/


    continuer=1;
    rewind(enr);
    fgets(nom,7,enr);
    nom[strlen(nom)-1]=0;
    fscanf(enr,"%d %s %d %d %d",&couleur_moto,Scores,&touche1,&touche2,&choix_Avatar);

    switch(abs(couleur_moto)) // Chargement de la coeulr de moto
    {
        case 0:
        moto=SDL_LoadBMP("MOTOS/RED/RED.bmp");
        break;

        case 1:
        moto=SDL_LoadBMP("MOTOS/BLUE/BLUE.bmp");
        break;

        case 2:
        moto=SDL_LoadBMP("MOTOS/GREEN/GREEN.bmp");
        break;

        default :
        break;

    }


    switch (abs(choix_Avatar))
    {
        case 0:
        Avatar=SDL_LoadBMP("11.bmp");
        break;

        case 1:
        Avatar=SDL_LoadBMP("12.bmp");
        break;

        case 2:
        Avatar=SDL_LoadBMP("13.bmp");
        break;

        default :
        break;

    }
    i=couleur_moto;





    pos_Moto.x=360;
    pos_Moto.y=470;

    pos_Nom.x=20;
    pos_Nom.y=456;

    pos_Score.x=20;
    pos_Score.y=546;

    pos_Avatar.x=888;
    pos_Avatar.y=123+(252-(Avatar->h))/2;


     ecran = SDL_SetVideoMode(1024, 600, 32, SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_RESIZABLE|SDL_FULLSCREEN);
     Fond=SDL_LoadBMP("ecran_personnage.bmp");
      Fond_nom=SDL_LoadBMP("Nouveau_nom.bmp");





     while(continuer)
     {
     pos_Avatar.y=123+(252-(Avatar->h))/2;

     //SDL_FreeSurface(texte_Score);
     //SDL_FreeSurface(texte_nom);

     texte_nom = TTF_RenderText_Blended(police,nom,couleurBleu);
     texte_Score = TTF_RenderText_Blended(police,Scores,couleurBleu);
     SDL_BlitSurface(Fond, NULL, ecran, NULL);
     SDL_BlitSurface(moto, NULL, ecran, &pos_Moto);
     SDL_BlitSurface(Avatar, NULL, ecran, &pos_Avatar);
     SDL_BlitSurface(texte_nom, NULL, ecran, &pos_Nom);
     SDL_BlitSurface(texte_Score, NULL, ecran, &pos_Score);



     SDL_Flip(ecran);

        SDL_WaitEvent(&event);
        switch(event.type)
            {

                case SDL_QUIT:
                continuer = 0;
                couleur_moto=abs(i%3);
                remove(Nom_fic);
                enr=fopen(Nom_fic,"w+");
                fprintf(enr,"%s\n%d\n%s\n%d\n%d\n%d",nom,couleur_moto,Scores,touche1,touche2,choix_Avatar%3);

                break;


                case SDL_KEYDOWN:

                    if(event.key.keysym.sym==SDLK_ESCAPE)
                  {

                    continuer = 0;

                    }
                   break;


                case SDL_MOUSEBUTTONDOWN:

                if (event.button.button == SDL_BUTTON_LEFT)
                {
                   // fprintf(stderr,"x=%d y = %d \n",event.button.x,event.button.y);
                   if(event.button.x>853 && event.button.x<1004 && event.button.y<580 && event.button.y >566) // retour menu
                   {
                       if(verf==1)
                       {
                         couleur_moto=abs(i%3);
                         remove(Nom_fic);
                        // fclose(enr);
                         enr=fopen(Nom_fic,"w+");
                         //fprintf(enr,"AHHH");
                        fprintf(enr,"%s\n%d\n%s\n%d\n%d\n%d",nom,couleur_moto,Scores,touche1,touche2,choix_Avatar%3);
                         fclose(enr);
                       }

                       continuer=0;
                   }
                   else
                   {
                       if(event.button.x>709 && event.button.x<1008 && event.button.y<559 && event.button.y >546)//Configuer touche
                       {
                           verf=1;
                          // ecran = SDL_SetVideoMode(1024, 600, 32, SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_RESIZABLE);
                            touche(ecran,&touche1,&touche2);
                            fprintf(stderr,"Touhce1= %d tpuche2=%d\n",touche1,touche2);
                            //touche1=config_touches(ecran);
                            ecran = SDL_SetVideoMode(1024, 600, 32, SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN);
                            SDL_BlitSurface(Fond, NULL, ecran, NULL);
                            SDL_Flip(ecran);
                       }
                       else
                       {
                            if(event.button.x>588 && event.button.x<594 && event.button.y<515 && event.button.y >506)//fleche droite
                            {
                               	//SDL_FreeSurface(moto);
                                verf=1;
                                i++;

                                switch(abs(i%3))
                                {
                                    case 0:
                                    moto=SDL_LoadBMP("RED.bmp");
                                    break;

                                    case 1:
                                    moto=SDL_LoadBMP("BLUE.bmp");
                                    break;

                                    case 2:
                                    moto=SDL_LoadBMP("GREEN.bmp");
                                    break;

                                    default :
                                    break;

                                }
                             }
                                else
                                {
                                    if(event.button.x>328 && event.button.x<336 && event.button.y<516 && event.button.y >506)//fleche gauche
                                 {
                                     SDL_FreeSurface(moto);
                                     verf=1;
                                     i--;

                                    switch(abs(i%3))
                                    {
                                        case 0:
                                        moto=SDL_LoadBMP("RED.bmp");
                                        break;

                                        case 1:
                                        moto=SDL_LoadBMP("BLUE.bmp");
                                        break;

                                        case 2:
                                        moto=SDL_LoadBMP("GREEN.bmp");
                                        break;

                                        default :
                                        break;


                                    }
                                }
                                 else
                                 {
                                     if(event.button.x>883 && event.button.x<997 && event.button.y<376 && event.button.y >123)//Avatar
                                     {
                                         SDL_FreeSurface(Avatar);
                                        verf=1;
                                        choix_Avatar++;
                                        switch (abs(choix_Avatar%3))
                                        {
                                            case 0:
                                            Avatar=SDL_LoadBMP("11.bmp");
                                            break;

                                            case 1:
                                            Avatar=SDL_LoadBMP("12.bmp");
                                            break;

                                            case 2:
                                            Avatar=SDL_LoadBMP("13.bmp");
                                            break;

                                            default :
                                            break;
                                        }
                                     }
                                     else
                                     {
                                         if(event.button.x>12 && event.button.x<307 && event.button.y<505 && event.button.y >436)//Nom
                                         {
                                            ecran = SDL_SetVideoMode(350, 250, 32, SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_RESIZABLE);
                                            //Fond=SDL_LoadBMP("Nouveau_nom.bmp");
                                            SDL_BlitSurface(Fond_nom, NULL, ecran, NULL);
                                            SDL_Flip(ecran);
                                            verf=texte(nom,ecran);

                                             ecran = SDL_SetVideoMode(1024, 600, 32, SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN);



                                         }
                                     }
                                 }

                        }

                       }
                   }


                }
                break;


                default :
                break;
            }
            SDL_Flip(ecran);
            SDL_FreeSurface(texte_nom);
            SDL_FreeSurface(texte_Score);
           // 
     }
     SDL_FreeSurface(moto);
     SDL_FreeSurface(Fond);
     SDL_FreeSurface(Fond_nom);
     SDL_FreeSurface(Avatar);

      //      fclose(enr);
//TTF_Quit();
}

int touche (SDL_Surface *ecran,int *touche1, int *touche2)
{
   SDL_Surface *Fond=NULL;
   SDL_Surface *texte1=NULL,*texte2=NULL;
   SDL_Rect pos_t1,pos_t2;
   SDL_Event event;
   int continuer=1;
   char car[2]="";
   char car2[2]="";
   TTF_Font *police = NULL;
   SDL_Color couleurBleu ={91,83,227};
   TTF_Init();
   police =TTF_OpenFont("times.ttf", 40);




        pos_t1.x=275;
        pos_t1.y=273;
        pos_t2.x=280;
        pos_t2.y=395;


    Fond=SDL_LoadBMP("Touches.bmp");


    SDL_Flip(ecran);

    while(continuer)
     {
    car[0] = *touche1;
    car2[0] = *touche2;
    SDL_BlitSurface(Fond, NULL, ecran, NULL);
    texte1 = TTF_RenderText_Blended(police,car,couleurBleu);
    texte2 = TTF_RenderText_Blended(police,car2,couleurBleu);
    SDL_BlitSurface(texte1, NULL, ecran, &pos_t1);
    SDL_BlitSurface(texte2, NULL, ecran, &pos_t2);
    SDL_Flip(ecran);

        SDL_WaitEvent(&event);
        switch(event.type)
            {

                case SDL_QUIT:
                continuer = 0;
                break;

                case SDL_KEYDOWN:

                    if(event.key.keysym.sym==SDLK_ESCAPE)
                  {

                    continuer = 0;
                    return 0;
                    }

                case SDL_MOUSEBUTTONDOWN:

                if (event.button.button == SDL_BUTTON_LEFT)
                {
                   if(event.button.x>220 && event.button.x<360 && event.button.y<680 && event.button.y >615) // retour menu
                   {
                     return 0;
                    }
                    else if (event.button.x>218 && event.button.x<358 && event.button.y<331 && event.button.y >264)
                        {
                          *touche1=config_touches(ecran);

                        }
                        else if(event.button.x>218 && event.button.x<358 && event.button.y<445 && event.button.y >379)
                                {
                                   *touche2=config_touches(ecran);                                }
                }

                break;



                default:
                break;
            }

     }


SDL_FreeSurface(texte1);
SDL_FreeSurface(texte2);
SDL_FreeSurface(Fond);

TTF_Quit();
 return 0;
}

int config_touches(SDL_Surface *ecran)
{


    SDL_Event event;

    int continuer=1;
    int majuscule=0;



    while (continuer)
    {

        SDL_WaitEvent(&event);
        switch(event.type)
            {
                case SDL_KEYDOWN:

                switch(event.key.keysym.sym)
                {
                    case SDLK_a:
                    return(97-32*(majuscule));
                    break;

                    case SDLK_q:
                    return(113-32*(majuscule));
                    break;

                    case SDLK_g:
                    case SDLK_f:
                    case SDLK_p:
                    case SDLK_t:
                    case SDLK_y:
                    case SDLK_u:
                    case SDLK_o:
                    case SDLK_h:
                    case SDLK_j:
                    case SDLK_k:
                    case SDLK_l:
                    case SDLK_d:
                    case SDLK_RIGHT :
                    case SDLK_LEFT :

                        return(event.key.keysym.sym-32*(majuscule));

                    break;
                    case SDLK_RSHIFT:
                    case SDLK_LSHIFT:
                    majuscule=1;
                    break;

                default:
                break;

                }
                break;
                case SDL_KEYUP:
                switch(event.key.keysym.sym)
               {
                    case SDLK_RSHIFT:
                    case SDLK_LSHIFT:
                    majuscule=0;
                    break;

                    default :
                    break;


               }
                break;

                default:
                break;

            }
    }
    return 0;
}


