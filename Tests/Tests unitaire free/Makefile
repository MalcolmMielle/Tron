# On cré le programme E
all : 
	make UnMurAlea
	make UneSeuleSol
	make Pos1
	make Coin
	make UndoubleUnsimple
	make Cerne
	make Rien
	make AleaRien
	make Aleacerne
	make Couleurmur
	make AleaCoin
	make Aleaperdu
	make Couleurperdu
	

UnMurAlea : Alea[Robot]main_unmur.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o
	gcc Alea[Robot]main_unmur.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o -o Alea_unmur -g
	
UneSeuleSol : Couleur[Robot]main_1seulesol.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o
	gcc Couleur[Robot]main_1seulesol.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o -o Couleur_unesol -g
	
Pos1 : Couleur[Robot]main_postion1prise.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o
	gcc Couleur[Robot]main_postion1prise.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o -o Couleur_pos1prise -g
	
Coin : Couleur[Robot]main_dans_le_coin.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o
	gcc Couleur[Robot]main_dans_le_coin.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o -o Couleur_coin -g

UndoubleUnsimple : Alea[Robot]main_undouble_unsimple.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o
	gcc Alea[Robot]main_undouble_unsimple.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o -o Alea_undoubleunsimple -g
	
Cerne : Couleur[Robot]main_solution_entoure_de_mur.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o
	gcc Couleur[Robot]main_solution_entoure_de_mur.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o -o Couleur_solcerne -g
	
Rien : Couleur[Robot]main_rien.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o
	gcc Couleur[Robot]main_rien.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o -o Couleur_rien -g
	
AleaRien : Alea[Robot]main_rien.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o
	gcc Alea[Robot]main_rien.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o -o Alea_rien -g

Aleacerne : Alea[Robot]main_solution_entoure_de_mur.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o
	gcc Alea[Robot]main_solution_entoure_de_mur.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o -o Alea_solcerne -g
	
Couleurmur : Couleur[Robot]main_1seulesol_entoure_de_deux_mur.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o
	gcc Couleur[Robot]main_1seulesol_entoure_de_deux_mur.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o -o Couleur_mur -g
	
AleaCoin : Alea[Robot]main_dans_le_coin.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o
	gcc Alea[Robot]main_dans_le_coin.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o -o Alea_coin -g
	
Aleaperdu : Alea[Robot]main_pas_de_solution.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o
	gcc Alea[Robot]main_pas_de_solution.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o -o Alea_perdu -g
	
Couleurperdu : Couleur[Robot]main_pas_de_solution.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o
	gcc Couleur[Robot]main_pas_de_solution.o AntiGrav.o RobotCouleur[free].o Astar[tron][free].o affichage.o ajoutstruct.o BotAlea[free].o free.o -o Couleur_perdu -g

#On renconstruit les .o s'ils ont été modifié
AntiGrav.o : AntiGrav.c Robot.h
	gcc -c AntiGrav.c -o AntiGrav.o -g
	
RobotCouleur[free].o : RobotCouleur[free].c Robot.h
	gcc -c RobotCouleur[free].c -o RobotCouleur[free].o -g
	
Astar[tron].o : Astar[tron][free].c Robot.h
	gcc -c Astar[tron][free].c -o Astar[tron][free].o -g
	
affichage.o : affichage.c Robot.h
	gcc -c affichage.c -o affichage.o -g
	
ajoutstruct.o : ajoutstruct.c Robot.h
	gcc -c ajoutstruct.c -o ajoutstruct.o -g
	
BotAlea[free].o : BotAlea[free].c Robot.h
	gcc -c BotAlea[free].c -o BotAlea[free].o -g
	
Alea[Robot]main_unmur.o : Alea[Robot]main_unmur.c Robot.h
	gcc -c Alea[Robot]main_unmur.c -o Alea[Robot]main_unmur.o -g
	
Couleur[Robot]main_1seulesol.o : Couleur[Robot]main_1seulesol.c Robot.h
	gcc -c Couleur[Robot]main_1seulesol.c -o Couleur[Robot]main_1seulesol.o -g
	
Couleur[Robot]main_postion1prise.o : Couleur[Robot]main_postion1prise.c Robot.h
	gcc -c Couleur[Robot]main_postion1prise.c -o Couleur[Robot]main_postion1prise.o -g
	
Couleur[Robot]main_dans_le_coin.o : Couleur[Robot]main_dans_le_coin.c Robot.h
	gcc -c Couleur[Robot]main_dans_le_coin.c -o Couleur[Robot]main_dans_le_coin.o -g
	
Alea[Robot]main_undouble_unsimple.o : Alea[Robot]main_undouble_unsimple.c Robot.h
	gcc -c Alea[Robot]main_undouble_unsimple.c -o Alea[Robot]main_undouble_unsimple.o -g
	
Couleur[Robot]main_solution_entoure_de_mur.o : Couleur[Robot]main_solution_entoure_de_mur.c Robot.h
	gcc -c Couleur[Robot]main_solution_entoure_de_mur.c -o Couleur[Robot]main_solution_entoure_de_mur.o
	
Couleur[Robot]main_1seulesol_entoure_de_deux_mur.o : Couleur[Robot]main_1seulesol_entoure_de_deux_mur.c Robot.h
	gcc -c Couleur[Robot]main_1seulesol_entoure_de_deux_mur.c -o Couleur[Robot]main_1seulesol_entoure_de_deux_mur.o
	
Alea[Robot]main_dans_le_coin.o : Alea[Robot]main_dans_le_coin.c Robot.h
	gcc -c Alea[Robot]main_dans_le_coin.c -o Alea[Robot]main_dans_le_coin.o
	
Alea[Robot]main_pas_de_solution.o :  Alea[Robot]main_pas_de_solution.c Robot.h
	gcc -c Alea[Robot]main_pas_de_solution.c -o Alea[Robot]main_pas_de_solution.o
	
Couleur[Robot]main_pas_de_solution.o : Couleur[Robot]main_pas_de_solution.c Robot.h
	gcc -c Couleur[Robot]main_pas_de_solution.c -o Couleur[Robot]main_pas_de_solution.o

	
free.o : free.c Robot.h
	gcc -c free.c -o free.o -g
	
#On supprime les fichiers temporaires
clean:
	rm -rf *.o

#On supprime tous les fichiers sauf les sources.	
mrproper: clean
	rm -rf e
