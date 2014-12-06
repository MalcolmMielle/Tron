#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <time.h>
#include <SDL/SDL_ttf.h>
#ifndef DEF_JEU
#include "Jeux.h"
#endif
#ifndef DEF_BOT
#include "Robot.h"
#endif
//#include "son.h"




//void jeu_multi(SDL_Surface *ecran,FMOD_SYSTEM *system,SDL_Surface* menuc,FILE* Nom_joueur,FILE* enr,char Nom_fic[17],FILE* enr2)
void jeu_multi(SDL_Surface *ecran,SDL_Surface* menuc,FILE* enr,FILE* enr2)
    {
        SDL_Surface *carte=NULL, *moto1=NULL, *moto2=NULL,*p_win=NULL,*img_h=NULL,*img_c=NULL,*img_h2=NULL,*img_c2=NULL ;
        SDL_Event event;
        position pos_moto1, pos_moto2,pos_win,pos_b,pos_moto_pre;
        int grille[300][150];
        int continuer=1;
        int tempsPrecedent = 0, tempsActuel = 0;
        int i,j;
        int indice=2,indice2=2;
        SDL_Rect mem[500];
        SDL_Rect mem2[500];
        int cpt=0;
        int mur=500;
        int Scores_perso,Scores_perso2;
        int couleur_moto,couleur_moto2;
        int touche1=0, touche2=108;
        int touche3,touche4;

        char nom_perso_1[7]="";
        char nom_perso_2[7]="";

        rewind(enr);
        fgets(nom_perso_1,7,enr);
        nom_perso_1[strlen(nom_perso_1)-1]=0;
        fscanf(enr,"%d %d %d %d",&couleur_moto,&Scores_perso,&touche1,&touche2);

        rewind(enr2);
        fgets(nom_perso_1,7,enr2);
        nom_perso_2[strlen(nom_perso_2)-1]=0;
        fscanf(enr2,"%d %d %d %d",&couleur_moto2,&Scores_perso2,&touche3,&touche4);




    switch(abs(couleur_moto)) // Chargement de la coeulr de moto
    {
        case 0:
        moto1=SDL_LoadBMP("Moto2_rouge.bmp");
        img_h=SDL_LoadBMP("moto_rouge_h.bmp");
        img_c=SDL_LoadBMP("moto_rouge_v.bmp");
        break;

        case 1:
        moto1=SDL_LoadBMP("Moto2_bleue.bmp");
        img_h=SDL_LoadBMP("TRON_droite.bmp");
        img_c=SDL_LoadBMP("TRON_coucher.bmp");
        break;

        case 2:
        moto1=SDL_LoadBMP("Moto2_vert.bmp");
        img_h=SDL_LoadBMP("moto_vert_h.bmp");
        img_c=SDL_LoadBMP("moto_vert_v.bmp");
        break;

        default :
        break;

    }

    switch(abs(couleur_moto2)) // Chargement de la coeulr de moto
    {
        case 0:
        moto2=SDL_LoadBMP("Moto2_rouge.bmp");
        img_h2=SDL_LoadBMP("moto_rouge_h.bmp");
        img_c2=SDL_LoadBMP("moto_rouge_v.bmp");
        break;

        case 1:
        moto2=SDL_LoadBMP("Moto2_bleue.bmp");
        img_h2=SDL_LoadBMP("TRON_droite.bmp");
        img_c2=SDL_LoadBMP("TRON_coucher.bmp");
        break;

        case 2:
        moto2=SDL_LoadBMP("Moto2_vert.bmp");
        img_h2=SDL_LoadBMP("moto_vert_h.bmp");
        img_c2=SDL_LoadBMP("moto_vert_v.bmp");
        break;

        default :
        break;

    }


        carte=SDL_LoadBMP("carte.bmp");
        ecran = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE |SDL_DOUBLEBUF /*|SDL_FULLSCREEN*/);
        SDL_BlitSurface(menuc, NULL, ecran, NULL); // Chargement de l'image du menu
        SDL_Flip(ecran);

/*****************Debut du programme********************************************/
        pos_moto1.xc.x=100;
        pos_moto1.xc.y=100;
        pos_moto1.x.x=pos_moto1.xc.x*4;
        pos_moto1.x.y=pos_moto1.xc.y*4;


        pos_moto2.xc.x=200;
        pos_moto2.xc.y=100;
        pos_moto2.x.x=pos_moto2.xc.x*4;
        pos_moto2.x.y=pos_moto2.xc.y*4;

        for(i=0;i<mur;i++)
        {
            mem[i].x=pos_moto1.x.x;
            mem[i].y=pos_moto1.x.y;
            mem2[i].x=pos_moto2.x.x;
            mem2[i].y=pos_moto2.x.y;

        }

       // SDL_BlitSurface(moto1, NULL, ecran, &pos_moto1.x); // Chargement de l'image du menu
        SDL_Flip(ecran);

/*************************************initialisation de la grille a 0**************************/

        for(i=0;i<150;i++)
        {
            for(j=0;j<300;j++)
            {
                grille[j][i]=0;
            }
        }

i=0;

        while(continuer)
        {
            event.type=SDLK_UNKNOWN;
            SDL_PollEvent(&event);

            switch(event.type)
            {
                case SDL_QUIT:
                    continuer = 0;
                break;

                case SDL_KEYDOWN:


                    //switch(event.key.keysym.sym) //gestion des déplacement "normaux" du joueur ( droite, gauche, haut, bas)
                    if(abs(event.key.keysym.sym)==abs(touche3))
                    {
                        //case SDLK_d:
                         switch (indice2) // On se déplace vers la droite
                        {
                            case 4 :
                            grille[pos_moto2.xc.x][pos_moto2.xc.y]=-1;
                            pos_moto2.xc.y++;
                            indice2=-2;
                            i++;
                            break;

                            case -4 : // On se déplace vers la gauche

                            grille[pos_moto2.xc.x][pos_moto2.xc.y]=-1;
                            pos_moto2.xc.y--;
                            indice2=2;
                            i++;
                            break;

                            case 2 : // On se déplace vers le haut

                            grille[pos_moto2.xc.x][pos_moto2.xc.y]=-1;
                            pos_moto2.xc.x++;
                            indice2=4;
                            i++;
                            break;

                            case -2 : // On se déplace vers le bas

                            grille[pos_moto2.xc.x][pos_moto2.xc.y]=-1;
                            pos_moto2.xc.x--;
                            indice2=-4;
                            i++;
                            break;

                            default :
                            break;
                        }
                    }
                           // break;
                         //case SDLK_a:
                       //  if (grille[pos_moto1.xc.x-1][pos_moto1.xc.y]!=-1 && pos_moto1.xc.x<2)
                       if(abs(event.key.keysym.sym)==  abs(touche4))
                       {

                        switch (indice2) // On se déplace vers la droite
                        {
                            case 4 :
                            grille[pos_moto2.xc.x][pos_moto2.xc.y]=-1;
                            pos_moto2.xc.y--;
                            indice2=2;
                            i++;
                            break;

                            case -4 : // On se déplace vers la gauche

                            grille[pos_moto2.xc.x][pos_moto2.xc.y]=-1;
                            pos_moto2.xc.y++;
                            indice2=-2;
                            i++;
                            break;

                            case 2 : // On se déplace vers le haut

                            grille[pos_moto2.xc.x][pos_moto2.xc.y]=-1;
                            pos_moto2.xc.x--;
                            indice2=-4;
                            i++;
                            break;

                            case -2 : // On se déplace vers le bas

                            grille[pos_moto2.xc.x][pos_moto2.xc.y]=-1;
                            pos_moto2.xc.x++;
                            indice2=4;
                            i++;
                            break;

                            default :
                            break;
                        }
                           // break;


                    }
                    //break;

        if(abs(event.key.keysym.sym)==abs(touche1))
        {
            grille[pos_moto1.xc.x][pos_moto1.xc.y]=2;
            //grille[pos_moto_pre.xc.x][pos_moto_pre.xc.y]=1;
            pos_moto_pre.xc.x=pos_moto1.xc.x;
            pos_moto_pre.xc.y=pos_moto1.xc.y;



            switch (indice) // On se déplace vers la droite
                {
                    case 4 :

                    pos_b.x.x=pos_moto1.x.x+4;
                    pos_b.x.y=pos_moto1.x.y;
                    pos_moto1.xc.y++;



                    indice=-2;
                    break;

                    case -4 : // On se déplace vers la gauche

                    //grille[pos_moto1.xc.x][pos_moto1.xc.y]=1;



                    pos_moto1.xc.y--;


                    indice=2;
                    break;

                    case 2 : // On se déplace vers le haut

                    //grille[pos_moto1.xc.x][pos_moto1.xc.y]=1;
                    pos_moto1.xc.x++;


                    indice=4;
                    i++;


                    break;

                    case -2 : // On se déplace vers le bas

                    //grille[pos_moto1.xc.x][pos_moto1.xc.y]=1;
                    pos_b.x.x=pos_moto1.x.x;
                    pos_b.x.y=pos_moto1.x.y+4;
                    pos_moto1.xc.x--;

                    indice=-4;


                    break;
                    default:
                    break;
            }

        }
        else if (abs(event.key.keysym.sym)==abs(touche2))
        {
            grille[pos_moto1.xc.x][pos_moto1.xc.y]=2;
            //grille[pos_moto_pre.xc.x][pos_moto_pre.xc.y]=1;
            pos_moto_pre.xc.x=pos_moto1.xc.x;
            pos_moto_pre.xc.y=pos_moto1.xc.y;
            switch (indice) // On se déplace vers la droite
            {
                case 4 :

                pos_b.x.x=pos_moto1.x.x+4;
                pos_b.x.y=pos_moto1.x.y;
                pos_moto1.xc.y--;


                i++;


                indice=2;
                break;

                case -4 : // On se déplace vers la gauche


                indice=-2;
                pos_moto1.xc.y++;
                i++;
                break;

                case 2 : // On se déplace vers le haut


                pos_moto1.xc.x--;

                indice=-4;
                i++;
                break;

                case -2 : // On se déplace vers le bas

                pos_b.x.x=pos_moto1.x.x;
                pos_b.x.y=pos_moto1.x.y+4;
                pos_moto1.xc.x++;

                indice=4;
                i++;
                break;

                default :
                break;
            }

        }
        break;

                default:
                break;



                        break;
                        case SDLK_ESCAPE: // le joueur refusent de jouer et quitte le jeux.
                        continuer=0;
                        break;
                    }
                    pos_moto1.x.x=pos_moto1.xc.x*4;
                    pos_moto1.x.y=pos_moto1.xc.y*4;
                    pos_moto2.x.x=pos_moto2.xc.x*4;
                    pos_moto2.x.y=pos_moto2.xc.y*4;

                    cpt++;
                    if(cpt>mur-1)
                    {
                        grille[(mem[mur-1].x)/4][(mem[mur-1].y)/4]=0;
                        grille[(mem2[mur-1].x)/4][(mem2[mur-1].y)/4]=0;
                    }
                    for(i=mur-1;i>0;i--)
                    {
                        mem[i].x=mem[i-1].x;
                        mem[i].y=mem[i-1].y;
                        mem2[i].x=mem2[i-1].x;
                        mem2[i].y=mem2[i-1].y;
                    }
                     mem[0].x=pos_moto1.x.x;
                     mem[0].y=pos_moto1.x.y;
                     mem2[0].x=pos_moto2.x.x;
                     mem2[0].y=pos_moto2.x.y;

/***************************Avance automatique des joueurs*****************************/
            tempsActuel = SDL_GetTicks();

            if (tempsActuel - tempsPrecedent > 20)
            {
                    switch(indice) // On se déplace vers la droite
                    {
                        case 4 :
                        grille[pos_moto1.xc.x][pos_moto1.xc.y]=-1;
                        pos_moto1.xc.x++;
                        break;

                    case -4 : // On se déplace vers la gauche
                    grille[pos_moto1.xc.x][pos_moto1.xc.y]=-1;
                       pos_moto1.xc.x--;
                    break;


                    case 2 : // On se déplace vers le haut
                        grille[pos_moto1.xc.x][pos_moto1.xc.y]=-1;
                        pos_moto1.xc.y--;
                        break;

                    case -2: // On se déplace vers le bas
                        grille[pos_moto1.xc.x][pos_moto1.xc.y]=-1;
                        pos_moto1.xc.y++;
                        break;

                        default :
                        break;
                    }

                    switch(indice2) // On se déplace vers la droite
                    {
                        case 4 :
                        grille[pos_moto2.xc.x][pos_moto2.xc.y]=-1;
                        pos_moto2.xc.x++;
                        break;

                        case -4 : // On se déplace vers la gauche
                        grille[pos_moto2.xc.x][pos_moto2.xc.y]=-1;
                           pos_moto2.xc.x--;
                        break;


                        case 2 : // On se déplace vers le haut
                            grille[pos_moto2.xc.x][pos_moto2.xc.y]=-1;
                            pos_moto2.xc.y--;
                        break;

                        case -2: // On se déplace vers le bas
                            grille[pos_moto2.xc.x][pos_moto2.xc.y]=-1;
                            pos_moto2.xc.y++;
                        break;

                        default :
                        break;


                    }

                tempsPrecedent = tempsActuel;
            }else
            {
                SDL_Delay(20 - (tempsActuel - tempsPrecedent));
            }

        if (pos_moto1.xc.x>299 || pos_moto1.xc.x<1 || pos_moto1.xc.y<1 || pos_moto1.xc.y>149 || grille[pos_moto1.xc.x][pos_moto1.xc.y]==-1)
        {
           // son_court("water.wav", system);
            continuer=0;
            p_win=SDL_LoadBMP("p2_win.bmp");
            pos_win.x.x=400;
            pos_win.x.y=250;
            SDL_BlitSurface(p_win, NULL, ecran, &pos_win.x);
            SDL_Flip(ecran);
            SDL_Delay(2000);

        }

        if (pos_moto2.xc.x>299 || pos_moto2.xc.x<1 || pos_moto2.xc.y<1 || pos_moto2.xc.y>149 || grille[pos_moto2.xc.x][pos_moto2.xc.y]==-1)
        {
           // son_court("water.wav", system);
            continuer=0;
            p_win=SDL_LoadBMP("p1_win.bmp");
            pos_win.x.x=400;
            pos_win.x.y=250;
            SDL_BlitSurface(p_win, NULL, ecran, &pos_win.x);
            SDL_Flip(ecran);
            SDL_Delay(2000);
        }
        pos_moto1.x.x=pos_moto1.xc.x*4;
        pos_moto1.x.y=pos_moto1.xc.y*4;
        pos_moto2.x.x=pos_moto2.xc.x*4;
        pos_moto2.x.y=pos_moto2.xc.y*4;

        cpt++;
        if(cpt>mur-1)
        {
            grille[(mem[mur-1].x)/4][(mem[mur-1].y)/4]=0;
            grille[(mem2[mur-1].x)/4][(mem2[mur-1].y)/4]=0;
        }
        for(i=mur-1;i>0;i--)
        {
            mem[i].x=mem[i-1].x;
            mem[i].y=mem[i-1].y;
            mem2[i].x=mem2[i-1].x;
            mem2[i].y=mem2[i-1].y;
        }
         mem[0].x=pos_moto1.x.x;
         mem[0].y=pos_moto1.x.y;
         mem2[0].x=pos_moto2.x.x;
         mem2[0].y=pos_moto2.x.y;

/****** Pour afficher en carré, il faut blitter la surface a chaque fois que l'on tourne aussi !*********/
        SDL_BlitSurface(menuc, NULL, ecran, NULL);
        for(i=0;i<mur-1;i++)
        {
            SDL_BlitSurface(moto1, NULL, ecran, &mem[i]);
            SDL_BlitSurface(moto2, NULL, ecran, &mem2[i]);

        }


        if(indice==2||indice==-2)
         {


            SDL_BlitSurface(img_c, NULL, ecran, &pos_moto1.x);
         }
         else if (indice==4||indice==-4)
         {
            SDL_BlitSurface(img_h, NULL, ecran, &pos_moto1.x);
         }
         if(indice2==2||indice2==-2)
         {
            SDL_BlitSurface(img_c2, NULL, ecran, &pos_moto2.x);
         }
         else if (indice2==-4 || indice2==4)
         {
            SDL_BlitSurface(img_h2, NULL, ecran, &pos_moto2.x);
         }

        SDL_Flip(ecran);



        }
        //SDL_Delay(1000);
        SDL_FreeSurface(moto1);
        SDL_FreeSurface(moto2);
        SDL_FreeSurface(p_win);

    }


