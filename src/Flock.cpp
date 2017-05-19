/*
 * Flock.cpp
 *
 *  Created on: 31 mars 2017
 *      Author: caroline
 */


#include <vector>
#include "Flock.h"
#include <cstdlib>

using namespace std;

/*
 * Initialisation des paramètres
 */
float Flock::m1 = 1.0;
float Flock::m2 = 1.0;
float Flock::m3 = 1.0;
float Flock::m4 = 1.0;
float Flock::m5 = 0.0;
float Flock::m6 = 1.0;
float Flock::m7 = 1.0;
float Flock::interB = 0.08;
float Flock::closest = 0.99;

Coordinates center((Boid::Xmax+Boid::Xmin)/2.0,(Boid::Ymax+Boid::Ymin)/2.0);
/*
 * Constructeur
 */
Flock::Flock() {}

/*
 * GETTER
 */
vector<Boid*> Flock::getFlock() {
	return this->flock;
}

/*
 * Ajout d'un Boid à la collection
 */
void Flock::addBoid(Boid* b) {
	this->flock.push_back(b);
}
/*
 * Retrait du dernier ~ aléatoire Boid à la collection
 */
void  Flock::rmvBoid() {
	this->flock.pop_back();
}


/*
 * Les règles du modèle
 */
void Flock::rules() {
	// la taille de l'essaim
	int s = this->flock.size();
	// On parcourt toute la collection et chaque oiseau recoit un traitement spécifique
	for (int j = 0; j < s; j++) {
		//On stock l'oiseau à traiter
		Boid * tmp = this->flock[j];
		//Initialisation
		Coordinates p(0,0);
		Coordinates c(0,0);
		Coordinates q(0,0);
		//les agents les plus proches
		vector<int> amis = this->find_closest(j);
		//On regarde tout les autres oiseaux
		while (!amis.empty()) {
			Boid * tmp2 = this->flock[amis.back()];
			//Calcul barycentre de l'essaim
			p = p + (*tmp2).getPosition();
			//Calcul vitesse moyenne de l'essaim
			q = q + (*tmp2).getSpeed();
			//calcul des nouvelles coordonnees du boid choisi a chaque traitement d ami.
			Coordinates t = (*tmp2).getPosition() - (*tmp).getPosition();
			//Si trop proche de ses voisins
			if (t.norm() < interB) {
				c = c - t;
			}
			amis.pop_back();
		}

		p = p / (s-1); // le barycentre
		q = q / (s-1); // la moyenne des vitesses
		//On pondère les résultats pour ne pas aller trop vite
		Coordinates v1 = (p-(*tmp).getPosition())/100.0; // Vitesse donnée par la première règle
		Coordinates v2 = c/8.0; // Vitesse donnée par la seconde règle
		Coordinates v3 = (q-(*tmp).getSpeed())/8.0; // Vitesse donnée par la troisème règle
		Coordinates v4 = (*tmp).bound(); // Vitesse donnée par la quatrième  règle

		// On envoie tous les n oiseaux légèrement vers le centre pour les rapprocher du domaine de calcul

		Coordinates v5 = (center-(*tmp).getPosition())/80.0; // Vitesse donnée par la cinquième règle
		Coordinates v6 = (*tmp).esquiv();
		Coordinates v7 = Coordinates(Boid::Ymax-Boid::Ymin,0)/10000.0;

		// Nouvelle vitesse de l'oiseau v
		Coordinates v = m1*v1 + m2*v2 + m3*v3 + m4*v4 + m5*v5 + m6*v6 + m7*v7;

		(*tmp).setSpeed((*tmp).getSpeed() + v);
		// On limite la vitesse
		(*tmp).velocityMax();
		// on met à jour la position
		(*tmp).setPosition((*tmp).getPosition() + (*tmp).getSpeed());
	}

}

/*
 * Trouver les boids adjacents
 */
vector<int> Flock::find_closest(int i) {
	vector<int> v;
	int s = this->flock.size();
	Boid * me = this->flock[i];
	for (int j=0;j<s;j++) {
		if ( j != i) {
			Boid * tmp = this->flock[j];
			Coordinates t = (*tmp).getPosition()-(*me).getPosition();
			if (t.norm() < closest) v.push_back(j);
		}
	}
	return v;
}

/*
 * Surcharge de l'opérateur []
 */
Boid* Flock::operator [] (int i) {
	return flock.at(i);
}

/*
 * To string
 */
ostream& operator << (ostream& flux,Flock f) {
	int s = f.flock.size();
	for (int i=0;i<s;i++) {
		cout << "Boid n°" << i << " : " << endl << *f.flock[i] << endl;
	}
	return flux;
}

/*
 * Destructeur
 */
Flock::~Flock() {}

