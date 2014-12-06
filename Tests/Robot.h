#ifndef Robot_TRON_24_04_2012
#define Robot_TRON_24_04_2012

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

struct Couleur {
			int x;
			int y;
			int nombre;
			struct Couleur* base;
			};
			
typedef struct Couleur Couleur;

/***************Structure du chemin final***************/
struct Chemin {
			int x;
			int y;
			struct Chemin* base;
			};
			
typedef struct Chemin Chemin;



Couleur* ajoutCouleur(Couleur* in, int x, int y, int nb);
Point* remplisCouleur(Point* in, Point* ferme, int x, int y);
Point* remplis2(Point* in, Point* ferme, int G, int x, int y);
Point* remplisInitCouleur(Point* in, Point* ferme, int x, int y);
void afficherCo(Couleur* Point1);
Point* Coloriage(Point* Ouvert, Point* Ferme, int xC, int yC, int T[][60], int bot);
int Compteur(int Grille[][60], int n);
void CopieTableau(int T[][60], int T2[][60]);
Couleur* Visuel(int Grille[][60], int x, int y, int XG, int YG, /*Couleur* In,*/ Couleur* Ennemy);
Couleur* Bot(int Map[][30], int x, int y, int XG, int YG);
Couleur* Random(int x, int y, Couleur* Done, int Grille[][30]);
Couleur* Mouv(int Map[][150], int x, int y);

void afficher(Point* Point1);
void afficherF(Point* Point1);
Point* remplis(Point* in, Point* ferme, int x, int y, int xF, int yF);
Point* remplis0(Point* in, Point* ferme, int x, int y, int xF, int yF);
Point* reMove(Point* in, Point* point);
Point* Astar(Point* Ouvert, Point* Ferme, int xF, int yF, int T[][150], int xC, int yC); //Trouve le chemin le plus court entre 2 points.

Chemin* AntiGrav(int Grille[][150], int x, int y, int XG, int YG);
void Determine(int Arrive[], int x, int y, int XG, int YG);
Chemin* Carre(int Arrive[], int x, int y, int XG, int YG, int Grille[][150], Chemin* Court);
int sommeY(Chemin* in);
int sommeX(Chemin* in);
Chemin* ajout(Chemin* in, int x, int y);
Couleur* LeRandomBot(int x, int y, int Grille[][30], int Map[][150]);


#endif /*Fin du bloc determiner par Robot_TRON_24_04_2012*/ 

