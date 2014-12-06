void jeu(SDL_Surface *ecran,FILE* Scores, SDL_Surface* menuc, FILE* Nom_joueur,FILE* enr,char Nom_fic[17])
    {
        SDL_Surface *carte=NULL, *moto1=NULL, *moto2=NULL,*p_win=NULL,*bot=NULL,*carre=NULL, *blii=NULL;
        SDL_Event event,event1;
        position pos_moto1, pos_moto2,poswin,pos_bot,pos_b,pb,pos_ob,pos_moto_pre;

        int grille[300][150];
        int continuer=1;
        int tempsPrecedent = 0, tempsActuel = 0, temps_jeu=0;
        int i,j,k;
        int position=0;
        int trouver=0;
        int indice=2,indice2=2;
        int Scores_perso;
        int couleur_moto;
        int touche1, touche2;


        char chaine[1000000] = "";
        int tab_ch[10];
        char temp_jeu[10]="";
        char Nom_joueurc[5]="";
        char Joueur[5][10];
        char nom_perso_1[7]="";



        Chemin* Court=NULL;
        Couleur* retour=NULL;


/****************************************Lecture du fichier personnel personnage 1**************************/
    rewind(enr);
    fgets(nom_perso_1,7,enr);
    nom_perso_1[strlen(nom_perso_1)-1]=0;
    fscanf(enr,"%d %d %d %d",&couleur_moto,&Scores_perso,&touche1,&touche2);
     switch(abs(couleur_moto)) // Chargement de la coeulr de moto
    {
        case 0:
        moto1=SDL_LoadBMP("Image/Moto2_rouge.bmp");
        break;

        case 1:
        moto1=SDL_LoadBMP("Image/Moto2_bleue.bmp");
        break;

        case 2:
        moto1=SDL_LoadBMP("Image/Moto2_vert.bmp");
        break;

    }


/******************************************Chargmeent image****************************************************/
        p_win=SDL_LoadBMP("Image/p.bmp");
        carre=SDL_LoadBMP("Image/Moto7.bmp");
        carte=SDL_LoadBMP("carte.bmp");
        bot=SDL_LoadBMP("Image/Bot.bmp");
        ecran = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE |SDL_DOUBLEBUF );
        SDL_BlitSurface(menuc, NULL, ecran, NULL);
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

//SDL_BlitSurface(p_win, &pos_b.x, ecran, &pos_b.x);

        pos_moto2.xc.x=250;
        pos_moto2.xc.y=100;
        pos_moto2.x.x=pos_moto2.xc.x*4;
        pos_moto2.x.y=pos_moto2.xc.y*4;

        pos_bot.xc.x=100;
        pos_bot.xc.y=110;
        pos_bot.x.x=pos_bot.xc.x*4;
        pos_bot.x.y=pos_bot.xc.y*4;

        //poswin.x.x=1;
       // poswin.x.y=1- p_win->h/2;

         //SDL_BlitSurface(p_win, NULL, ecran, &poswin.x);
       // SDL_BlitSurface(blii, &pb.x, ecran, &pos_b.x);
        SDL_BlitSurface(bot, NULL, ecran, &pos_bot.x);
        SDL_BlitSurface(moto1, NULL, ecran, &pos_moto1.x); // Chargement de l'image du menu
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
               /* event1.type=SDL_KEYDOWN;
                while(event.type!=SDL_KEYUP)
                {
                   SDL_PollEvent(&event);
                }
*/

    if(event.key.keysym.sym==touche1)
        {grille[pos_moto1.xc.x][pos_moto1.xc.y]=2;
            grille[pos_moto_pre.xc.x][pos_moto_pre.xc.y]=1;
            pos_moto_pre.xc.x=pos_moto1.xc.x;
            pos_moto_pre.xc.y=pos_moto1.xc.y;



            switch (indice) // On se déplace vers la droite
                        {
                            case 4 :
                            //grille[pos_moto1.xc.x][pos_moto1.xc.y]=1;
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
                            i++;

                            break;
                            default:
                            break;
        }

        }
        else if (event.key.keysym.sym==touche2)
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
        }

        }
       /*
                   switch(event.key.keysym.sym) //gestion des déplacement "normaux" du joueur ( droite, gauche, haut, bas)
                    {

                         case SDLK_RIGHT:

                         switch (indice) // On se déplace vers la droite
                        {
                            case 4 :
                            grille[pos_moto1.xc.x][pos_moto1.xc.y]=1;
                            pos_b.x.x=pos_moto1.x.x+4;
                            pos_b.x.y=pos_moto1.x.y;
                            pos_moto1.xc.y++;



                            indice=-2;
                            break;

                            case -4 : // On se déplace vers la gauche

                            grille[pos_moto1.xc.x][pos_moto1.xc.y]=1;



                            pos_moto1.xc.y--;


                            indice=2;
                            break;

                            case 2 : // On se déplace vers le haut

                            grille[pos_moto1.xc.x][pos_moto1.xc.y]=1;
                            pos_moto1.xc.x++;


                            indice=4;
                            i++;


                            break;

                            case -2 : // On se déplace vers le bas

                            grille[pos_moto1.xc.x][pos_moto1.xc.y]=1;
                            pos_b.x.x=pos_moto1.x.x;
                            pos_b.x.y=pos_moto1.x.y+4;
                            pos_moto1.xc.x--;

                            indice=-4;
                            i++;

                            break;
                            default:
                            break;
                        }
                        break;
                         case SDLK_LEFT:
                       //  if (grille[pos_moto1.xc.x-1][pos_moto1.xc.y]!=-1 && pos_moto1.xc.x<2)
                        switch (indice) // On se déplace vers la droite
                        {
                            case 4 :
                            grille[pos_moto1.xc.x][pos_moto1.xc.y]=1;
                            pos_b.x.x=pos_moto1.x.x+4;
                            pos_b.x.y=pos_moto1.x.y;
                            pos_moto1.xc.y--;


                            i++;


                            indice=2;
                            break;

                            case -4 : // On se déplace vers la gauche

                            grille[pos_moto1.xc.x][pos_moto1.xc.y]=1;

                            indice=-2;
                            i++;
                            break;

                            case 2 : // On se déplace vers le haut

                            grille[pos_moto1.xc.x][pos_moto1.xc.y]=1;
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
                        }


                        break;
                        case SDLK_ESCAPE: // le joueur refusent de jouer et quitte le jeux.
                        continuer=0;
                        break;

                        default:
                        break;

                    }*/

                    break;

                default:
                break;
            }
/**************************Affichage des position intermediaire*****************************************************/

                            pos_moto1.x.x=pos_moto1.xc.x*4;
                            pos_moto1.x.y=pos_moto1.xc.y*4;

                           SDL_BlitSurface(moto1, NULL, ecran, &pos_moto1.x);
                           // SDL_BlitSurface(p_win, NULL, ecran, &pos_ob.x);
                            SDL_Flip(ecran);

/********************************************actualisation du joueur et du bot toutes les 30 ms seconde***********************************/
            tempsActuel = SDL_GetTicks();

            if (tempsActuel - tempsPrecedent > 30)
            {
                grille[pos_moto1.xc.x][pos_moto1.xc.y]=2;
            grille[pos_moto_pre.xc.x][pos_moto_pre.xc.y]=1;
            pos_moto_pre.xc.x=pos_moto1.xc.x;
            pos_moto_pre.xc.y=pos_moto1.xc.y;// grille[pos_moto1.xc.x][pos_moto1.xc.y]=1;

                    switch(indice) // On se déplace vers la droite
                    {
                        case 4 :
                      //  moto1=SDL_LoadBMP("TRON_droite.bmp");
                         carre=SDL_LoadBMP("Moto7_droite.bmp");
                       /* if (grille[pos_moto1.xc.x][pos_moto1.xc.y-1]==1||grille [pos_moto1.xc.x][pos_moto1.xc.y+1]==1)
                        {
                            grille[pos_moto1.xc.x][pos_moto1.xc.y]=1;
                            pos_moto1.xc.x++;

                            grille[pos_moto1.xc.x][pos_moto1.xc.y]=1;
                            pos_moto1.xc.x++;

                        }
                        else*/
                        {
                           // grille[pos_moto1.xc.x][pos_moto1.xc.y]=1;

                            pos_moto1.xc.x++;




                        }

                        break;

                    case -4 : // On se déplace vers la gauche
                   // moto1=SDL_LoadBMP("TRON_droite.bmp");
                     carre=SDL_LoadBMP("Moto7_droite.bmp");
                    //grille[pos_moto1.xc.x][pos_moto1.xc.y]=1;
                                    //pos_moto1.x.x=pos_moto1.xc.x*4;
                                    //pos_moto1.x.y=pos_moto1.xc.y*4;
                                  //  SDL_BlitSurface(moto1, NULL, ecran, &pos_moto1.x);
                                    //
                       pos_moto1.xc.x--;




                    break;


                    case 2 : // On se déplace vers le haut
                   // moto1=SDL_LoadBMP("TRON.bmp");
                     carre=SDL_LoadBMP("Moto7.bmp");
                       // grille[pos_moto1.xc.x][pos_moto1.xc.y]=1;



                        pos_moto1.xc.y--;


                        break;

                    case -2: // On se déplace vers le bas
                        //moto1=SDL_LoadBMP("TRON.bmp");
                         carre=SDL_LoadBMP("Moto7.bmp");

                        //grille[pos_moto1.xc.x][pos_moto1.xc.y]=1;

                        pos_moto1.xc.y++;

                        break;

                    default :
                        break;
                    }
              /*      Court=AntiGrav(grille,pos_bot.xc.x,pos_bot.xc.y,299,149);
                    if (Court==NULL)//Le bot se suicide
                    {
                       return 0;
                        break;
                    }
                  pos_bot.xc.x=Court->x;
                  pos_bot.xc.y=Court->y;
                  grille[pos_bot.xc.x][pos_bot.xc.y]=1;
*/                 fprintf(stderr,"X=%d Y=%d\n",pos_bot.xc.x,pos_bot.xc.y);
                retour=Mouv(grille,pos_bot.xc.x,pos_bot.xc.y);
                pos_bot.xc.x=retour->x;
                pos_bot.xc.y=retour->y;
                grille[pos_bot.xc.x][pos_bot.xc.y]=1;
fprintf(stderr,"Xff=%d Yff=%d\n",pos_bot.xc.x,pos_bot.xc.y);


                tempsPrecedent = tempsActuel;


            }else
            {
                SDL_Delay(30 - (tempsActuel - tempsPrecedent));
            }

        if (pos_moto1.xc.x>299 || pos_moto1.xc.x<1 || pos_moto1.xc.y<1 || pos_moto1.xc.y>149 || grille[pos_moto1.xc.x][pos_moto1.xc.y]==1)
        {
            continuer=0;
            break;
            fprintf(stderr,"ERRREUR");
            //return(0);
        }
        pos_moto1.x.x=pos_moto1.xc.x*4;
        pos_moto1.x.y=pos_moto1.xc.y*4;
        pos_bot.x.x=pos_bot.xc.x*4;
        pos_bot.x.y=pos_bot.xc.y*4;



/****** Pour afficher en carré, il faut blitter la surface a chaque fois que l'on tourne aussi !*********/
        SDL_BlitSurface(moto1, NULL, ecran, &pos_moto1.x);
        SDL_BlitSurface(bot, NULL, ecran, &pos_bot.x);
        SDL_Flip(ecran);
        SDL_Flip(ecran);

        pos_ob.x.x=pos_moto1.x.x-moto1->w/2;
        pos_ob.x.y=pos_moto1.x.y+moto1->h;

        }
        /*********************************Gestion du scores**************************************/
        rewind(Scores);
        temps_jeu = SDL_GetTicks();

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

                    for(j=4;j>=i;j--)
                    {
                        tab_ch[j]=tab_ch[j-1];
                    }
                    tab_ch[i]=temps_jeu;
                    position=i;
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



        /***********************fermeture  et réouverture du fichier en écrasement********/
        remove(Scores);
        Scores = fopen("Scores.txt", "w+");

        /************************** Récriture dans le fichier********************************/

        for(i=0;i<5;i++)
        {
            fprintf(Scores,"%d ",tab_ch[i]);

        }
        /**********************************************Comparaison et inscription dans le fichier personnage*************/
        if(temps_jeu>Scores_perso)
        {
        Scores_perso=temps_jeu;

         //close(enr);
        // enr=fopen(Nom_fic,"w+");
        rewind(enr);
        fprintf(enr,"%s\n%d\n%d %d %d",nom_perso_1,couleur_moto,Scores_perso,touche1,touche2);

        }


        SDL_FreeSurface(moto1);
        SDL_FreeSurface(bot);
return (0);

    }
