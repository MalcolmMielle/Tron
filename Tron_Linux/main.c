#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <time.h>
#ifndef DEF_JEU
#include "Jeux.h"
#endif
#include <SDL/SDL_ttf.h>

#include "score.h"
//#include <fmod.h>





int main (int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *menu=NULL,*demarrage=NULL, *relance=NULL, *menuc=NULL, *image1=NULL, *image2=NULL;
    SDL_Event event,event2;
   // SDL_Rect position;
    int continuer=1,continuer2=1,continuer3=1,lecture=0,entrer=0;;
    char Nom_fic[17]="";
    char Nom_fic2[17]="";
    int verf_j=0;
    int vitesse=10;

    FILE* Scores = NULL;
    FILE* result = NULL;
    FILE* Nom = NULL;
    FILE* Opt=NULL;
    FILE* Nom_joueur=NULL;
    FILE* enr=NULL;
    FILE* enr2=NULL;
/*
    FMOD_SYSTEM *system;
    FMOD_System_Create(&system);
    FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);
    FMOD_CHANNEL *canal;
    FMOD_System_GetChannel(system, 0, &canal);
*/

    Nom_joueur=fopen("Nom_joueur.txt","r+");
    Nom    = fopen("Nom.txt","r+");
    Scores = fopen("Scores.txt", "r+");
    result = fopen("result.txt", "r+");
    Opt    = fopen("Opt.txt","r+");





    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(456, 630, 32, SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_RESIZABLE /*| SDL_FULLSCREEN*/);


    demarrage=SDL_LoadBMP("tron_demarage.bmp");
    menu=SDL_LoadBMP("Menu2.bmp");
    image1=SDL_LoadBMP("Choix_perso.bmp");
    image2=SDL_LoadBMP("Choix_perso2.bmp");
	relance=SDL_LoadBMP("relance.bmp");


    SDL_BlitSurface(demarrage, NULL, ecran, NULL);
   // Chargement de l'image du menu
    SDL_Flip(ecran);
   SDL_FreeSurface(demarrage);

    //musique("Ouverture.mp3", system);
   // fprintf(stderr,"AAAAA %d\n\n",SDL))
  while(continuer)
     {
    SDL_WaitEvent(&event);

        switch(event.type)
            {

                case SDL_QUIT:
                continuer = 0;
                break;

                case SDL_MOUSEBUTTONDOWN:

                if (event.button.button == SDL_BUTTON_LEFT)
                {

                   if(event.button.x>52 && event.button.x<176 && event.button.y>567 && event.button.y <603)
                   {
                       entrer=1;

                   }
                   else if ((event.button.x>254 && event.button.x<400 && event.button.y>567 && event.button.y <603))
                   {
                       entrer=0;
                       continuer=0;
                   }
                }
                break;



                case SDL_KEYDOWN:

                switch(event.key.keysym.sym)
                {

                    case SDLK_ESCAPE: // le joueur refusent de jouer et quittent le jeux.
                    continuer=0;
                    entrer=0;
                    break;

                 case SDLK_RETURN :// le joueur accepte de rentrer dans le jeux
                    entrer=1;
                    break;

                    default:
                    break;
                }

                break;

                default :
                break;
            }


                     if(entrer==1)
                     {

                    ecran = SDL_SetVideoMode(1200, 670, 32, SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_RESIZABLE/*|SDL_FULLSCREEN*/);
                    SDL_BlitSurface(menu, NULL, ecran, NULL);
                    SDL_Flip(ecran);




                        while (continuer2)
                        {
                                while(continuer)
                                {
                                    //fclose(Opt);
                                Opt=fopen("Opt.txt","r+");
                                rewind(Opt);
                                fscanf(Opt,"%d %d",&lecture,&vitesse);
                                SDL_FreeSurface(menuc);// erreur de segmentation !!!
                                switch(abs(lecture))
                            {
                                case 0:
                                menuc=SDL_LoadBMP("1.bmp");
                                break;

                                case 1:
                                menuc=SDL_LoadBMP("2.bmp");
                                break;

                                case 2:
                                menuc=SDL_LoadBMP("3.bmp");
                                break;

                                case 3:
                                menuc=SDL_LoadBMP("4.bmp");
                                break;

                                case 4:
                                menuc=SDL_LoadBMP("5.bmp");
                                break;

                                case 5:
                                menuc=SDL_LoadBMP("6.bmp");
                                break;

                                case 6:
                                menuc=SDL_LoadBMP("7.bmp");
                                break;

                                default :
                                break;


                            }
                                if (menuc==NULL)
                                {
                                    fprintf(stderr,"NULLLLLLLLL \n\n\n");
                                }

                                    SDL_WaitEvent(&event);
                                    switch(event.type)
                                    {
                                        case SDL_KEYDOWN:

                                        switch(event.key.keysym.sym)
                                        {

                                        case SDLK_ESCAPE:
                                        continuer=0;
                                        break;
            /*****************************************JJOUER 1 JOUEUR*****************************************************/
                                        case SDLK_KP1:
                                        case SDLK_1:
                                        case SDLK_j:
                                        ecran = SDL_SetVideoMode(350, 400, 32, SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_RESIZABLE/*|SDL_FULLSCREEN*/);
                                       // Fond=SDL_LoadBMP("Choix_perso.bmp");// affichage de l'ecran de sélection (Joueur 1, 2 ou 3)
                                        SDL_BlitSurface(image1, NULL, ecran, NULL);
                                        SDL_Flip(ecran);
                                        //SDL_FreeSurface(Fond);
                                        continuer3=1;
                                        while(continuer3==1)// attente de récuperation du numero du jouieur
                                            {
                                                SDL_WaitEvent(&event);
                                                switch(event.type)
                                                    {

                                                        case SDL_QUIT:
                                                        continuer3 = 0;
                                                        break;


                                                         case SDL_KEYDOWN:
                                                         switch(event.key.keysym.sym)
                                                          {

                                                              case SDLK_ESCAPE:
                                                                continuer3=3;

                                                                break;

                                /***********************Chargement du fichier correspondant************************/
                                                              case SDLK_KP1:
                                                              case SDLK_1:
                                                              case SDLK_j:

                                                              strcpy(Nom_fic,"Personnage_1.txt");
                                                              continuer3=0;
                                                              break;


                                                              case SDLK_KP2:
                                                              case SDLK_2:
                                                              strcpy(Nom_fic,"Personnage_2.txt");
                                                              //Nom_fic="Personnage_2.txt";
                                                              continuer3=0;
                                                              break;

                                                              case SDLK_KP3:
                                                              case SDLK_3:
                                                              strcpy(Nom_fic,"Personnage_3.txt");
                                                              //Nom_fic="Personnage_3.txt";
                                                              continuer3=0;
                                                              break;

                                                              default:
                                                              break;

                                                           }
                                                         break;

                                                         default :
                                                        break;
                                                    }
                                            }

                                        enr=fopen(Nom_fic,"r+");
                                        rewind(enr);
                                       // musique("TRON.mp3", system);
                                       // FMOD_Channel_SetVolume(canal, 0.5);
                                        if(continuer3==0)
                                        {
                                            Scores=fopen("Scores.txt","r+");
                                            rewind(result);
                                            //result = fopen("result.txt", "r+");
                                            jeu(ecran,Scores,menuc,Nom_joueur,enr, vitesse,result);
                                           // fclose(result);
                                           fclose(Scores);
                                        }

                                        continuer=0;
                                        fclose(enr);
                                        break;

                                        case SDLK_KP3:
                                        case SDLK_3:
                                        case SDLK_u:
                                        Scores=fopen("Scores.txt","r+");
                                        rewind(Scores);
                                        rewind(result);
                                        score(ecran,Scores,result);
                                        ecran = SDL_SetVideoMode(1200, 670, 32, SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_RESIZABLE/*|SDL_FULLSCREEN*/);
                                        SDL_BlitSurface(menu, NULL, ecran, NULL);
                                        SDL_Flip(ecran);
                                        fclose(Scores);

                                        break;

                                        case SDLK_KP4://Menu de gestion du personnage
                                        case SDLK_4:
                                        case SDLK_i:
                                        continuer3=1;
                                        ecran = SDL_SetVideoMode(350, 400, 32, SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_RESIZABLE/*|SDL_FULLSCREEN*/);
                                        //Fond=SDL_LoadBMP("Choix_perso.bmp");// affichage de l'ecran de sélection (Joueur 1, 2 ou 3)
                                        SDL_BlitSurface(image1, NULL, ecran, NULL);
                                        SDL_Flip(ecran);
                                       // SDL_FreeSurface(Fond);
                                         while(continuer3)// attente de récuperation du numero du jouieur
                                            {
                                                SDL_WaitEvent(&event);
                                                switch(event.type)
                                                    {

                                                        case SDL_QUIT:
                                                        continuer3 = 0;
                                                        break;


                                                         case SDL_KEYDOWN:
                                                         switch(event.key.keysym.sym)
                                                          {
                                                              case SDLK_ESCAPE:
                                                                continuer3=0;
                                                                break;
            /***************************************Chargement du fichier correspondant*******************************/
                                                              case SDLK_KP1:
                                                              case SDLK_1:
                                                              case SDLK_j:
                                                             // Nom_fic="Personnage_1.txt";

                                                              strcpy(Nom_fic,"Personnage_1.txt");
                                                              continuer3=0;
                                                              break;

                                                              case SDLK_KP2:
                                                              case SDLK_2:
                                                              strcpy(Nom_fic,"Personnage_2.txt");
                                                              //Nom_fic="Personnage_2.txt";
                                                              continuer3=0;
                                                              break;

                                                              case SDLK_KP3:
                                                              case SDLK_3:
                                                              strcpy(Nom_fic,"Personnage_3.txt");
                                                              //Nom_fic="Personnage_3.txt";
                                                              continuer3=0;
                                                              break;

                                                              default:
                                                              break;

                                                          }
                                                         break;

                                                         default :
                                                        break;
                                                    }
                                            }

                                        enr=fopen(Nom_fic,"r+");
                                        Scores=fopen("Scores.txt","r+");
                                        personnage(ecran,enr,Nom_fic);
                                        SDL_BlitSurface(menu, NULL, ecran, NULL);
                                        SDL_Flip(ecran);
                                        //fclose(enr);
                                        //fclose(Scores);
                                        //SDL_FreeSurface(Fond);

                                        break;

                                        case SDLK_KP2:
                                        case SDLK_o:
                                        while(verf_j ==0)
                                        {

                                        ecran = SDL_SetVideoMode(350, 400, 32, SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_RESIZABLE/*| SDL_FULLSCREEN*/);
                                       // Fond=SDL_LoadBMP("Choix_perso.bmp");// affichage de l'ecran de sélection (Joueur 1, 2 ou 3)
                                        SDL_BlitSurface(image1, NULL, ecran, NULL);
                                        SDL_Flip(ecran);
                                        //SDL_FreeSurface(Fond);
                                        continuer3=1;
                                        while(continuer3==1)// attente de récuperation du numero du jouieur
                                            {
                                                SDL_WaitEvent(&event);
                                                switch(event.type)
                                                    {
                                                        case SDL_KEYDOWN:
                                                         switch(event.key.keysym.sym)
                                                          {
                                                              case SDLK_ESCAPE:
                                                                continuer3=0;

                                                                break;

                                /***********************Chargement du fichier correspondant************************/
                                                              case SDLK_KP1:
                                                              case SDLK_j:

                                                            verf_j=1;
                                                              strcpy(Nom_fic,"Personnage_1.txt");
                                                              continuer3=0;
                                                              break;

                                                              case SDLK_KP2:
                                                              verf_j=2;
                                                              strcpy(Nom_fic,"Personnage_2.txt");
                                                              //Nom_fic="Personnage_2.txt";
                                                              continuer3=0;
                                                              break;

                                                              case SDLK_KP3:
                                                              verf_j=3;
                                                              strcpy(Nom_fic,"Personnage_3.txt");
                                                              //Nom_fic="Personnage_3.txt";
                                                              continuer3=0;
                                                              break;

                                                              default:
                                                              break;

                                                          }
                                                         break;

                                                         default :
                                                        break;
                                                    }
                                            }
  /******************************************Chargement du fichier numéro 2***********************************************/
//ecran = SDL_SetVideoMode(600, 400, 32, SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_RESIZABLE);
                                       //Fond=SDL_LoadBMP("Choix_perso2.bmp");// affichage de l'ecran de sélection (Joueur 1, 2 ou 3)
                                        SDL_BlitSurface(image2, NULL, ecran, NULL);
                                        SDL_Flip(ecran);
                                        //SDL_FreeSurface(Fond);
                                        continuer3=1;
                                        while(continuer3)// attente de récuperation du numero du jouieur
                                            {
                                                SDL_WaitEvent(&event);
                                                switch(event.type)
                                                    {
                                                        case SDL_KEYDOWN:
                                                         switch(event.key.keysym.sym)
                                                          {


                                /***********************Chargement du fichier correspondant************************/
                                                              case SDLK_KP1:

                                                              verf_j=verf_j-1;
                                                              strcpy(Nom_fic2,"Personnage_1.txt");
                                                              continuer3=0;
                                                              break;

                                                              case SDLK_KP2:
                                                              case SDLK_j:
                                                              verf_j=verf_j-2;
                                                              strcpy(Nom_fic2,"Personnage_2.txt");
                                                              //Nom_fic="Personnage_2.txt";
                                                              continuer3=0;
                                                              break;

                                                              case SDLK_KP3:
                                                              verf_j=verf_j-3;
                                                              strcpy(Nom_fic2,"Personnage_3.txt");
                                                              //Nom_fic="Personnage_3.txt";
                                                              continuer3=0;
                                                              break;

                                                              default:
                                                              break;

                                                          }
                                                         break;

                                                         default :
                                                        break;
                                                    }
                                            }
                                        }
                                        verf_j=0;
                                        enr=fopen(Nom_fic,"r+");
                                        enr2=fopen(Nom_fic2,"r+");
                                       // musique("TRON.mp3", system);
                                        //FMOD_Channel_SetVolume(canal, 0.3);
                                       // jeu_multi(ecran,Scores,menuc,Nom_joueur,enr,Nom_fic,enr2);
                                        jeu_multi(ecran,menuc,enr,enr2);
                                        continuer=0;
                                        fclose(enr);
                                        fclose(enr2);
                                        break;

                                        case SDLK_KP5:
                                        case SDLK_5:
                                        case SDLK_p:
                                        Opt=fopen("Opt.txt","r+");
                                        option (ecran,Opt, &vitesse);
                                        fclose(Opt);
                                        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format, 0,0,0));
                                        SDL_BlitSurface(menu, NULL, ecran, NULL);
                                        SDL_Flip(ecran);



                                        break;




                                        default:
                                            break;
                                        }

                                        default :
                                        break;
                                    }
                                   // SDL_FreeSurface(menuc);
                                }
                                   // ecran = SDL_SetVideoMode(550, 309, 32, SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_RESIZABLE |SDL_FULLSCREEN);
                                    SDL_FillRect(ecran,NULL,0);
                                    //relance=SDL_LoadBMP("relance.bmp");
                                    SDL_BlitSurface(relance, NULL, ecran, NULL);
                                    SDL_Flip(ecran);
//                                    SDL_FreeSurface(relance);

                                SDL_WaitEvent(&event2);
                                switch(event2.type)
                                {
                                     case SDL_KEYDOWN:
                                     switch(event2.key.keysym.sym)
                                     {
                                         case SDLK_n:
                                         continuer2=0;
                                         continuer=0;
                                         break;

                                         case SDLK_y :
                                         continuer=1;
                                          ecran = SDL_SetVideoMode(1200, 670, 32, SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_RESIZABLE /*|SDL_FULLSCREEN*/);
                                          SDL_BlitSurface(menu, NULL, ecran, NULL);
                                          SDL_Flip(ecran);
                                          SDL_Delay(1000);
                                         break;

                                         default :
                                            break;
                                    }
                                    break;
                                    default:
                                    break;

                            }




            }

                     }


     }

//SDL_FreeSurface(Fond);

SDL_FreeSurface(relance);
SDL_FreeSurface(menu);
SDL_FreeSurface(menuc);

/***** Impossible de liberer ces deux surfaces....*****/
SDL_FreeSurface(image1);
SDL_FreeSurface(image2);

//FMOD_System_Close(system);
//FMOD_System_Release(system);
//
SDL_Quit();

return (EXIT_SUCCESS);
}











