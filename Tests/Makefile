# On cré le programme E
all : Couleur[Robot]main_postion1prise.o AntiGrav.o RobotCouleur.o Astar[tron].o affichage.o ajoutstruct.o BotAlea.o
	gcc Couleur[Robot]main_postion1prise.o AntiGrav.o RobotCouleur.o Astar[tron].o affichage.o ajoutstruct.o BotAlea.o -o e -g

#On renconstruit les .o s'ils ont été modifié
AntiGrav.o : AntiGrav.c Robot.h
	gcc -c AntiGrav.c -o AntiGrav.o
	
RobotCouleur.o : RobotCouleur.c Robot.h
	gcc -c RobotCouleur.c -o RobotCouleur.o
	
Astar[tron].o : Astar[tron].c Robot.h
	gcc -c Astar[tron].c -o Astar[tron].o
	
affichage.o : affichage.c Robot.h
	gcc -c affichage.c -o affichage.o
	
ajoutstruct.o : ajoutstruct.c Robot.h
	gcc -c ajoutstruct.c -o ajoutstruct.o
	
BotAlea.o : BotAlea.c Robot.h
	gcc -c BotAlea.c -o BotAlea.o
	
Couleur[Robot]main_postion1prise.o : Couleur[Robot]main_postion1prise.c Robot.h
	gcc -c Couleur[Robot]main_postion1prise.c -o Couleur[Robot]main_postion1prise.o
	
#On supprime les fichiers temporaires
clean:
	rm -rf *.o

#On supprime tous les fichiers sauf les sources.	
mrproper: clean
	rm -rf e
