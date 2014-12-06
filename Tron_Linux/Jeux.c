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


void jeu(SDL_Surface *ecran,FILE* Scores, SDL_Surface* menuc, FILE* Nom_joueur,FILE* enr, int vitesse, FILE* Result)
    {
        SDL_Surface *carte=NULL,*img_h=NULL,*img_c=NULL, *moto1=NULL, *p_win=NULL, *titre=NULL,*victoire=NULL;
        SDL_Surface *bot=NULL, *img_bot_h=NULL,*img_bot_c=NULL;
        SDL_Surface *bot2=NULL;
        SDL_Surface *Explosion=NULL;
        SDL_Event event;
        position pos_moto1, pos_moto2,pos_bot,pos_bot2,pos_b,pb,pos_ob,pos_moto_pre,pos_titre,pos_win, pos_bot_precedente,pos_bot_precedente2;
        SDL_Rect pos_victoire;


        int grille[300][150];
        int continuer=1;
        int tempsPrecedent = 0, tempsActuel = 0, temps_jeu=0,temps_parti_pre;
        int i,j,k;
        int position_i=0;
        int trouver=0;
        int indice=2,indice_bot1, indice_bot2;
        int Scores_perso;
        int couleur_moto;
        int touche1=0, touche2=108;
        SDL_Rect mem[700];
        SDL_Rect mem_bot[700];
        SDL_Rect mem_bot2[700];
        int cpt=0;
        int cpt_explosion=50;// En Milliseconde
        int mur=700;
        int nbjoueur=1; //Le nombre pourra varier
 //       int Arrive[2]={0,0};
        int Stay_alive_bot1=1, Stay_alive_bot2=1;
        int choix_Avatar;  // Bot encore en vie

        char resu_score[10]="";
        int tab_ch[10];
        char Joueur[5][10];
        char nom_perso_1[7]="";

        TTF_Font *police = NULL;
        SDL_Color couleurRouge ={255,0,0};

 //       Chemin* Court=NULL;
        Couleur* retour=NULL,  *retour2=NULL, *check=NULL, *check1=NULL ;
		//Chemin* retour2=NULL;



        pos_titre.x.x=1200;
        pos_titre.x.y=100;
        TTF_Init();
        police =TTF_OpenFont("times.ttf", 65);


/****************************************Lecture du fichier personnel personnage 1**************************/
    rewind(enr);
    fgets(nom_perso_1,7,enr);
    nom_perso_1[strlen(nom_perso_1)-1]=0 ;
    fscanf(enr,"%d\n%d\n%d\n%d\n%d",&couleur_moto,&Scores_perso,&touche1,&touche2,&choix_Avatar);


   /* rewind(Result);
    fscanf(Result,"%s %s %s %s %s", &Nom_fichier[0],&Nom_fichier[1],Nom_fichier[2],&Nom_fichier[3],&Nom_fichier[4]);
    fprintf(stderr,"%s %s %s %s %s\n",Nom_fichier[0],Nom_fichier[1],Nom_fichier[2],Nom_fichier[3],Nom_fichier[4]);*/
/**************************************Chargement image******************************************************/

        Explosion=SDL_LoadBMP("explosion.bmp");

        bot=SDL_LoadBMP("Moto2_violette.bmp");
        img_bot_c=SDL_LoadBMP("moto_violette_h.bmp");
        img_bot_h=SDL_LoadBMP("moto_violette_v.bmp");

        bot2=SDL_LoadBMP("Moto2_violette.bmp");

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
SDL_SetColorKey(img_bot_c, SDL_SRCCOLORKEY, SDL_MapRGB(img_bot_c->format, 0,0, 0));
SDL_SetColorKey(img_bot_h, SDL_SRCCOLORKEY, SDL_MapRGB(img_bot_c->format, 0,0, 0));
SDL_SetColorKey(img_c, SDL_SRCCOLORKEY, SDL_MapRGB(img_c->format, 0,0, 0));
SDL_SetColorKey(img_h, SDL_SRCCOLORKEY, SDL_MapRGB(img_c->format, 0,0, 0));

/******************************************Chargmeent image****************************************************/
 //       p_win=SDL_LoadBMP("p.bmp");
        carte=SDL_LoadBMP("Carte.bmp");
        ecran = SDL_SetVideoMode(1300, 600, 32, SDL_HWSURFACE |SDL_DOUBLEBUF );

        SDL_Flip(ecran);

/*****************Debut du programme********************************************/

        pos_moto1.xc.x=100;
        pos_moto1.xc.y=100;
        pos_moto_pre.xc.x=pos_moto1.xc.x;
        pos_moto_pre.xc.y=pos_moto1.xc.y;
        pos_moto1.x.x=pos_moto1.xc.x*4;
        pos_moto1.x.y=pos_moto1.xc.y*4;




        pos_ob.x.x=pos_moto1.x.x;
        pos_ob.x.y=pos_moto1.x.y;

        pb.x.x=44;
        pb.x.y=15;
        pos_b.x.h=14;
        pos_b.x.w=7;

        pos_b.x.x=100;
        pos_b.x.y=100;


        pos_moto2.xc.x=250;
        pos_moto2.xc.y=100;
        pos_moto2.x.x=pos_moto2.xc.x*4;
        pos_moto2.x.y=pos_moto2.xc.y*4;

        pos_bot.xc.x=200;
        pos_bot.xc.y=50;
        pos_bot.x.x=pos_bot.xc.x*4;
        pos_bot.x.y=pos_bot.xc.y*4;

        pos_bot2.xc.x=50;
        pos_bot2.xc.y=75;
        pos_bot2.x.x=pos_bot2.xc.x*4;
        pos_bot2.x.y=pos_bot2.xc.y*4;

        pos_victoire.x=100;
        pos_victoire.y=300;

        for(i=0;i<mur;i++)
        {
            mem[i].x=pos_moto1.x.x;
            mem[i].y=pos_moto1.x.y;
            mem_bot[i].x= pos_bot.x.x;
            mem_bot[i].y= pos_bot.x.y;
            mem_bot2[i].x= pos_bot2.x.x;
            mem_bot2[i].y= pos_bot2.x.y;

        }

        SDL_BlitSurface(bot, NULL, ecran, &pos_bot.x);
        SDL_BlitSurface(bot2, NULL, ecran, &pos_bot2.x);
        SDL_BlitSurface(moto1, NULL, ecran, &pos_moto1.x);
        SDL_Flip(ecran);

/*************************************initialisation de la grille a 0**************************/

        for(i=0;i<150;i++)
        {
            for(j=0;j<300;j++)
            {
                grille[j][i]=0;
            }
        }

temps_parti_pre = SDL_GetTicks();
/**************************************************Deplacement du joueur ***********************************************************/

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

                    if(event.key.keysym.sym==SDLK_ESCAPE)
                  {

                    continuer = 0;
                    //return 0;
                    }



    if(abs(event.key.keysym.sym)==abs(touche1))
        {
            grille[pos_moto1.xc.x][pos_moto1.xc.y]=2;
            grille[pos_moto_pre.xc.x][pos_moto_pre.xc.y]=1;
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

                    case -4 :

                        pos_moto1.xc.y--;
                        indice=2;
                    break;

                    case 2 : // On se déplace vers le haut
                    pos_moto1.xc.x++;
                    indice=4;
                    break;

                    case -2 : // On se déplace vers le bas

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
            grille[pos_moto_pre.xc.x][pos_moto_pre.xc.y]=1;
            pos_moto_pre.xc.x=pos_moto1.xc.x;
            pos_moto_pre.xc.y=pos_moto1.xc.y;
            switch (indice) // On se déplace vers la droite
            {
                case 4 :
                pos_moto1.xc.y--;
                indice=2;
                break;

                case -4 : // On se déplace vers la gauche
                indice=-2;
                pos_moto1.xc.y++;
                 break;

                case 2 : // On se déplace vers le haut


                pos_moto1.xc.x--;

                indice=-4;
                i++;
                break;

                case-2 : // On se déplace vers le bas

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
            }
/**************************Affichage des position intermediaire*****************************************************/

                            pos_moto1.x.x=pos_moto1.xc.x*4;
                            pos_moto1.x.y=pos_moto1.xc.y*4;
                            cpt++;
                            if(cpt>mur-1)
                            {
                                grille[(mem[mur-1].x)/4][(mem[mur-1].y)/4]=0;//Mise a 0 de la dernière case du tableau => case qui redevient case jouable et non mur
                                grille[(mem_bot[mur-1].x)/4][(mem_bot[mur-1].y)/4]=0;
                                grille[(mem_bot2[mur-1].x)/4][(mem_bot2[mur-1].y)/4]=0;
                            }
                            for(i=mur-1;i>0;i--) // Décalage du tableau vers la doirte pour stockage du nouveau mur a placer
                            {
                                mem[i].x=mem[i-1].x;
                                mem[i].y=mem[i-1].y;
                                mem_bot[i].x=mem_bot[i-1].x;
                                mem_bot[i].y=mem_bot[i-1].y;
                                mem_bot2[i].x=mem_bot2[i-1].x;
                                mem_bot2[i].y=mem_bot2[i-1].y;
                            }
                             mem[0].x=pos_moto1.x.x;
                             mem[0].y=pos_moto1.x.y;
                             mem_bot[0].x=pos_bot.x.x;
                             mem_bot[0].y=pos_bot.x.y;
                             mem_bot2[0].x=pos_bot2.x.x;
                             mem_bot2[0].y=pos_bot2.x.y;

/********************************************actualisation du joueur et du bot toutes les 30 ms seconde***********************************/
            tempsActuel = SDL_GetTicks()-temps_parti_pre;
//            itoa((tempsActuel/1000),resu_score,10);
            titre = TTF_RenderText_Blended(police,resu_score,couleurRouge);


            if (tempsActuel - tempsPrecedent > vitesse)
            {
                grille[pos_moto1.xc.x][pos_moto1.xc.y]=2;
                grille[pos_moto_pre.xc.x][pos_moto_pre.xc.y]=1;
                pos_moto_pre.xc.x=pos_moto1.xc.x;
                pos_moto_pre.xc.y=pos_moto1.xc.y;

                    switch(indice) // On se déplace vers la droite
                    {
                        case 4 :
                        pos_moto1.xc.x++;
                        break;

                        case -4 : // On se déplace vers la gauche

                       pos_moto1.xc.x--;

                        break;


                        case 2 : // On se déplace vers le haut

                        pos_moto1.xc.y--;
                        break;

                        case -2: // On se déplace vers le bas

                        pos_moto1.xc.y++;

                        break;

                    default :
                        break;
                    }

/**************************************************Zone des bots***************************************************************/

   /*              if(nbjoueur=1)
                 {
                    Court=AntiGrav(grille,pos_bot.xc.x,pos_bot.xc.y,299,149); //Marche bien. Utile contre moult bot
                 }
                 else
                 {
                     Court=Carre(Arrive,pos_bot.xc.x,pos_bot.xc.y,299,149,grille,Court); //Seg fault
                 }
                 if (Court==NULL)//Le bot se suicide
                 {
                    return 0;
                    break;
                 }
                pos_bot.xc.x=Court->x;
                pos_bot.xc.y=Court->y;
                pos_bot.x.x=pos_bot.xc.x*4;
                pos_bot.x.y=pos_bot.xc.y*4;

                  grille[pos_bot.xc.x][pos_bot.xc.y]=1;


*/


/* Le bon bot qui fait mal !*/

           if (Stay_alive_bot1==1)
            {
                pos_bot_precedente.xc.x=pos_bot.xc.x;
                pos_bot_precedente.xc.y=pos_bot.xc.y;

                retour=Mouv(grille,pos_bot.xc.x,pos_bot.xc.y);
                check=retour;
                //retour=Poursuite(grille,pos_bot.xc.x,pos_bot.xc.y,pos_moto1.xc.x,pos_moto1.xc.y );
                if (retour==NULL)
                {

                    Stay_alive_bot1=0;
                }
                else
                {
                    pos_bot.xc.x=retour->x;
                    pos_bot.xc.y=retour->y;
                    pos_bot.x.x=pos_bot.xc.x*4;
                    pos_bot.x.y=pos_bot.xc.y*4;
                    grille[pos_bot.xc.x][pos_bot.xc.y]=1;

                }

            }



            if (Stay_alive_bot2==1)
            {
                pos_bot_precedente2.xc.x=pos_bot2.xc.x;
                pos_bot_precedente2.xc.y=pos_bot2.xc.y;

                retour2=Mouv(grille,pos_bot2.xc.x,pos_bot2.xc.y );
          
          		//retour2=AntiGrav(grille,pos_bot2.xc.x,pos_bot2.xc.y,299,149);
                check1=retour2;
                if (retour2==NULL)
                {
                   Stay_alive_bot2=0;
                }
                else
                {
                    pos_bot2.xc.x=retour2->x;
                    pos_bot2.xc.y=retour2->y;
                    pos_bot2.x.x=pos_bot2.xc.x*4;
                    pos_bot2.x.y=pos_bot2.xc.y*4;
                    grille[pos_bot2.xc.x][pos_bot2.xc.y]=1;
                }

            }

                freelist(check);
                freelist(check1);

           /*   retour=Mouv(grille,pos_bot.xc.x,pos_bot.xc.y );
             retour2=Mouv(grille,pos_bot2.xc.x,pos_bot2.xc.y );
                    if (retour==NULL || retour2==NULL)//Le bot se suicide
                    {


                       return 0;
                        break;
                    }
*/
      /****************************************Sens du mouvement de bots 1 et 2*********************************/
                if (pos_bot_precedente.xc.x>pos_bot.xc.x || pos_bot_precedente.xc.x<pos_bot.xc.x)
                {
                    indice_bot1=2;
                }
                else if (pos_bot_precedente.xc.y<pos_bot.xc.y ||pos_bot_precedente.xc.y>pos_bot.xc.y)
                {
                    indice_bot1=4;
                }

                 if (pos_bot_precedente2.xc.x>pos_bot2.xc.x || pos_bot_precedente2.xc.x<pos_bot2.xc.x)
                {
                    indice_bot2=2;
                }
                else if (pos_bot_precedente2.xc.y<pos_bot2.xc.y ||pos_bot_precedente2.xc.y>pos_bot2.xc.y)
                {
                    indice_bot2=4;
                }





/**************************************************************Fin de gestion des bots*************************************************************************/




                tempsPrecedent = tempsActuel;


            }else
            {
                SDL_Delay(vitesse - (tempsActuel - tempsPrecedent));
            }
/**********************************************Collision***************************************************************************************/
        if (pos_moto1.xc.x>299 || pos_moto1.xc.x<1 || pos_moto1.xc.y<1 || pos_moto1.xc.y>149 || grille[pos_moto1.xc.x][pos_moto1.xc.y]==1)
        {
            nbjoueur=nbjoueur-1;//On décrémente le nb de joueur pour savoir combien il y en a
            p_win=SDL_LoadBMP("Defaite_joueur.bmp");
            SDL_SetColorKey(p_win, SDL_SRCCOLORKEY, SDL_MapRGB(p_win->format, 0,0, 0));
            pos_win.x.x=0;
            pos_win.x.y=100;
            SDL_BlitSurface(p_win, NULL, ecran, &pos_win.x);
            SDL_Flip(ecran);
            SDL_Delay(2000);
            continuer=0;
            SDL_FreeSurface(p_win);
            break;
            //return(0);
        }
/*************************************************Affichage des éléments graphique***************************************************************/
        pos_moto1.x.x=pos_moto1.xc.x*4;
        pos_moto1.x.y=pos_moto1.xc.y*4;


        cpt++;
        if(cpt>mur-1)
        {

            grille[(mem[mur-1].x)/4][(mem[mur-1].y)/4]=0;//Mise a 0 de la dernière case du tableau => case qui redevient case jouable et non mur
            if ( Stay_alive_bot1==1)
            {
                grille[(mem_bot[mur-1].x)/4][(mem_bot[mur-1].y)/4]=0;
            }

            if (Stay_alive_bot2==1)
            {
                grille[(mem_bot2[mur-1].x)/4][(mem_bot2[mur-1].y)/4]=0;
            }
        }


        for(i=mur-1;i>0;i--) // Décalage du tableau vers la doirte pour stockage du nouveau mur a placer
        {
            mem[i].x=mem[i-1].x;
            mem[i].y=mem[i-1].y;

            if (Stay_alive_bot1==1)
            {
                mem_bot[i].x=mem_bot[i-1].x;
                mem_bot[i].y=mem_bot[i-1].y;
            }
           if (Stay_alive_bot2==1)
           {
               mem_bot2[i].x=mem_bot2[i-1].x;
               mem_bot2[i].y=mem_bot2[i-1].y;
           }

        }

        if (Stay_alive_bot1==1)
        {
            mem_bot[0].x=pos_bot.x.x;
            mem_bot[0].y=pos_bot.x.y;
        }

        if (Stay_alive_bot2==1)
        {
            mem_bot2[0].x=pos_bot2.x.x;
            mem_bot2[0].y=pos_bot2.x.y;

        }

         mem[0].x=pos_moto1.x.x;
         mem[0].y=pos_moto1.x.y;



        SDL_FillRect(ecran,NULL,0);
        SDL_BlitSurface(menuc, NULL, ecran, NULL);

        if (Stay_alive_bot1==0)
        {
            for(i=0;i<700; i++)
            {
                grille[(mem_bot[i].x)/4][(mem_bot[i].y)/4]=0;
            }
        }

        if (Stay_alive_bot2==0)
        {
            for(i=0;i<700; i++)
            {
                grille[(mem_bot2[i].x)/4][(mem_bot2[i].y)/4]=0;
            }
        }

        for(i=0;i<mur-1;i++)
        {
            SDL_BlitSurface(moto1, NULL, ecran, &mem[i]);

            if (Stay_alive_bot1==1)
            {
                SDL_BlitSurface(bot, NULL, ecran, &mem_bot[i]);
            }
            if (Stay_alive_bot2==1)
            {
                SDL_BlitSurface(bot2, NULL, ecran, &mem_bot2[i]);
            }


        }


        if(indice==2||indice==-2)
         {
            SDL_BlitSurface(img_c, NULL, ecran, &pos_moto1.x);
         }
         else
         {
            SDL_BlitSurface(img_h, NULL, ecran, &pos_moto1.x);
         }

         if ( Stay_alive_bot1==1)
         {
             if((indice_bot1==2||indice_bot1==-2) )
             {
                SDL_BlitSurface(img_bot_c, NULL, ecran, &pos_bot.x);
             }
             else
             {
                SDL_BlitSurface(img_bot_h, NULL, ecran, &pos_bot.x);
             }
         }

        if ( Stay_alive_bot2==1)
        {
            if((indice_bot2==2||indice_bot2==-2) )
             {
                SDL_BlitSurface(img_bot_c, NULL, ecran, &pos_bot2.x);
             }
             else
             {
                SDL_BlitSurface(img_bot_h, NULL, ecran, &pos_bot2.x);
             }
        }
        if ( Stay_alive_bot1==0 && cpt_explosion>0)
            {
                cpt_explosion--;
                SDL_SetColorKey(Explosion, SDL_SRCCOLORKEY, SDL_MapRGB(Explosion->format, 0,0, 0));
                SDL_BlitSurface(Explosion, NULL, ecran, &pos_bot.x);
               SDL_Flip(ecran);
            }

         if (Stay_alive_bot2==0 && cpt_explosion>0)
            {
                cpt_explosion--;
                SDL_SetColorKey(Explosion, SDL_SRCCOLORKEY, SDL_MapRGB(Explosion->format, 0,0, 0));
                SDL_BlitSurface(Explosion, NULL, ecran, &pos_bot2.x);
                SDL_Flip(ecran);
            }


        SDL_BlitSurface(titre, NULL, ecran, &pos_titre.x);

        if (Stay_alive_bot1==0 && Stay_alive_bot2==0) //Le joueur gagne !
        {
            p_win=SDL_LoadBMP("Victoire_joueur.bmp");
            SDL_SetColorKey(p_win, SDL_SRCCOLORKEY, SDL_MapRGB(p_win->format, 0,0, 0));
            pos_win.x.x=0;
            pos_win.x.y=100;
            SDL_BlitSurface(p_win, NULL, ecran, &pos_win.x);
            SDL_Flip(ecran);
            SDL_Delay(2000);
            SDL_FreeSurface(p_win);
            continuer=0;
            //return 0;
        }


        SDL_Flip(ecran);


        }
        /*********************************Gestion du scores**************************************/
        rewind(Scores);
        temps_jeu = SDL_GetTicks()-temps_parti_pre;

        i=0;
        fscanf(Scores, "%d %d %d %d %d",&tab_ch[0],&tab_ch[1],&tab_ch[2],&tab_ch[3],&tab_ch[4]);

             /**************************Classement des scores dans le tableau de chaine***************/
        for(i=0;i<5;i++)
        {
            for(j=i;j<5;j++)
            {

                if (tab_ch[i]<tab_ch[j])
                {
                    k=tab_ch[i];
                    tab_ch[i]=tab_ch[j];
                    tab_ch[j]=k;
                }
            }
        }

        /*********************** Insertion du nouveau scores dans le tableau**************/
        for(i=0;i<5;i++)
        {

                if(temps_jeu>tab_ch[i])
                {
                    trouver=1;
                    victoire=SDL_LoadBMP("Victoire.bmp");
                    SDL_BlitSurface(victoire, NULL, ecran, &pos_titre.x);
                    SDL_Flip(ecran);

                    for(j=4;j>=i;j--)
                    {
                        tab_ch[j]=tab_ch[j-1];
                    }
                    tab_ch[i]=temps_jeu;
                    //strcpy(Nom_fichier[i],"");
                   // strcpy(Nom_fichier[i],nom_perso_1);
                   // fprintf(stderr,"Le nom vaut %s %d \n",Nom_fichier[i],i);
                    position_i=i;
                    break;
                }
        }
        /************************recuperation du Nom du joueur gagnant*********************/
        if(trouver==1)
        {

            rewind (Nom_joueur);
            for(i=0;i<5;i++)
            {
                fgets(Joueur[i],7,Nom_joueur);
                Joueur[i][strlen(Joueur[i])-1]=0;
            }

        }

                    //strcpy(Nom_fichier[position_i],"");
                    //strcpy(Nom_fichier[i],nom_perso_1);
                   // fprintf(stderr,"Le nom vaut %s",Nom_fichier[position_i]);

        /***********************fermeture  et réouverture du fichier en écrasement********/
        remove("Scores.txt");
        Scores = fopen("Scores.txt", "w+");

        /************************** Récriture dans le fichier********************************/

        for(i=0;i<5;i++)
        {
            fprintf(Scores,"%d ",tab_ch[i]);

        }
        fclose(Scores);
        /*******************************Comparaison et inscription dans le fichier personnage*****************************/
        if(temps_jeu>Scores_perso)
        {
            victoire=SDL_LoadBMP("Victoire.bmp");
            SDL_BlitSurface(victoire, NULL, ecran, &pos_titre.x);
            SDL_Flip(ecran);
            SDL_FreeSurface(victoire);
            Scores_perso=temps_jeu;

         //close(enr);
         //remove(enr);
         //enr=fopen(Nom_fic,"w+");
        rewind(enr);
        fprintf(enr,"%s\n%d\n%d %d %d %d",nom_perso_1,couleur_moto,Scores_perso,touche1,touche2,choix_Avatar);
        //remove("result.txt");
        //"=fopen("result.txt","w+");
        //fprintf(Result,"%s %s %s %s %s",Nom_fichier[0],Nom_fichier[1],Nom_fichier[2],Nom_fichier[3],Nom_fichier[4]);
       // fclose(Result);


        }

        SDL_Delay(2000);
        SDL_FreeSurface(titre);

        SDL_FreeSurface(img_c);
        SDL_FreeSurface(img_h);
        SDL_FreeSurface(img_bot_c);
        SDL_FreeSurface(img_bot_h);
//        SDL_FreeSurface(menuc);
        SDL_FreeSurface(moto1);
        SDL_FreeSurface(bot);
        SDL_FreeSurface(carte);
        SDL_FreeSurface(Explosion);


//return (0);

    }
