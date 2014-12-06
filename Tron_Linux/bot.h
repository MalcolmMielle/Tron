#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <time.h>
#ifndef DEF_JEU
//#include "Jeux.h"
#endif
#include <SDL/SDL_ttf.h>
#define DEF_BOT

struct Couleur {
			int x;
			int y;
			int nombre;
			struct Couleur* base;
			};

typedef struct Couleur Couleur;



struct Chemin {
			int x;
			int y;
			struct Chemin* base;
			};

typedef struct Chemin Chemin;

struct Point {
			int x;
			int y;
			int G;
			int D;
			int F;
			struct Point* base;
			struct Point* suivant;
			};

typedef struct Point Point;

/*******************************Fonction***********************************/
Couleur* ajoutCouleur(Couleur* in, int x, int y, int nb);
void afficherCo(Couleur* Point1); //Affichage des structures du chemin final
void afficher(Point* Point1);
void afficherF(Point* Point1) ;//Affichage des structures de la liste Fermee
void afficherC(Chemin* Point1); //Affichage des structures du chemin final
Point* remplis(Point* in, Point* ferme, int x, int y, int xF, int yF) ;//Remplis les structures de Astar
Point* remplis0(Point* in, Point* ferme, int x, int y, int xF, int yF); //Iniilise la première structure de Astar
Point* reMove(Point* in, Point* point); //Enlève une certaine structures d'une liste chainée
Point* Astar(Point* Ouvert, Point* Ferme, int xF, int yF, int T[][150], int xC, int yC); //Trouve le chemin le plus court entre 2 points.
Chemin* ajout(Chemin* in, int x, int y);
int sommeX(Chemin* in) ;//Somme des valeurs de x
int sommeY(Chemin* in); //Somme des valeurs de y
Chemin* AntiGrav(int Grille[][150], int x, int y, int XG, int YG);
Chemin* OnlyOneDEF(int Grille[][150], int x, int y, int XG, int YG);
Point* remplis2(Point* in, Point* ferme, int G, int x, int y); //Remplis les structures de Astar

Point* Coloriage(Point* Ouvert, Point* Ferme, int xC, int yC, int T[][60], int bot) ;
int Compteur(int Grille[][60], int n);
void CopieTableau(int T[][60], int T2[][60]);
Couleur* Bot(int Map[][30], int x, int y, int XG, int YG);// XG = 299 et YG = 149

Couleur* Visuel(int Grille[][60], int x, int y, int XG, int YG, Couleur* In, Couleur* Ennemy);
Couleur* Random(int x, int y, Couleur* Done, int Grille[][30]);
Couleur* Mouv(int Grille[][150], int x, int y);
Point* Coloriage(Point* Ouvert, Point* Ferme, int xC, int yC, int T[][60], int bot);
Couleur* ajoutCouleur(Couleur* in, int x, int y, int nb);







