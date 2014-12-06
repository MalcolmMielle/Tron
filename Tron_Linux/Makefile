SDL = -lSDLmain -lSDL -lSDL_ttf #Définition d'une constante pour la SDL TTF

#compilation des différentes parties du projet

all : Jeux.o Multijoueur.o Perso.o option.o score.o main.o RobotCouleur.o ajoutstruct.o BotAlea.o recup_texte.o AntiGrav.o
	gcc Jeux.o Multijoueur.o Perso.o option.o score.o main.o RobotCouleur.o ajoutstruct.o BotAlea.o recup_texte.o AntiGrav.o $(SDL) -o e -g `sdl-config --cflags --libs`
	
Jeux.o : Jeux.c Robot.h
	gcc -c Jeux.c $(SDL) -o Jeux.o -g `sdl-config --cflags --libs`
	
Multijoueur.o : Multijoueur.c Jeux.h
	gcc -c Multijoueur.c $(SDL) -o Multijoueur.o -g `sdl-config --cflags --libs`

Perso.o : Perso.c Jeux.h score.h
	gcc -c Perso.c $(SDL) -o Perso.o -g `sdl-config --cflags --libs`

score.o : score.c Jeux.h 
	gcc -c score.c $(SDL) -o score.o -g `sdl-config --cflags --libs`

main.o : main.c score.h Jeux.h
	gcc -c main.c $(SDL) -o main.o -g `sdl-config --cflags --libs`
	
RobotCouleur.o : RobotCouleur.c Robot.h
	gcc -c RobotCouleur.c -o RobotCouleur.o -g
		
ajoutstruct.o : ajoutstruct.c Robot.h
	gcc -c ajoutstruct.c -o ajoutstruct.o -g
	
BotAlea.o : BotAlea.c Robot.h
	gcc -c BotAlea.c -o BotAlea.o -g
	
recup_texte.o : recup_texte.c Jeux.h
	gcc -c recup_texte.c $(SDL) -o recup_texte.o -g `sdl-config --cflags --libs`
	
AntiGrav.o : AntiGrav.c  Robot.h
	gcc -c AntiGrav.c  -o AntiGrav.o -g `sdl-config --cflags --libs`
	
	
	#On supprime les fichiers temporaires
clean:
	rm -rf *.o

#On supprime tous les fichiers sauf les sources.	
mrproper: clean
	rm -rf e
