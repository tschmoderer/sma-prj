/*
 * Boid.cpp
 *
 *  Created on: 31 mars 2017
 *      Author: caroline
 */

#include <iostream>
#include <cstdlib>

#include "Boid.h"
#include <vector>
#include "Obstacles.h"
#include "Flock.h"

using namespace std;

/*
 * Initialisation des paramètres
 */
float Boid::Vmax = 0.2;
float Boid::back = 0.02;
int Boid::Xmin = -2;
int Boid::Xmax = 2;
int Boid::Ymin = -2;
int Boid::Ymax = 2;
bool Boid::periodic = false;



/*
 * Constructeur par défaut
 */
Boid::Boid() {
	this->position = Coordinates();
	this->speed = Coordinates();
}
/*
 * Constructeur spécifique
 */
Boid::Boid(Coordinates p,Coordinates s) {
	this->position = p;
	this->speed = s;
}

/*
 * GETTERS
 */
Coordinates Boid::getPosition() {
	return position;
}

Coordinates Boid::getSpeed() {
	return speed;
}

/*
 * SETTERS
 */
void Boid::setSpeed(Coordinates s) {
	this->speed = s;
}
void Boid::setPosition(Coordinates p) {
	this->position = p;
}

/*
 * Si l'agent est trop rapide, on réduit sa vitesse
 */
void Boid::velocityMax() {
	float n = this->speed.norm();
	if (n > Vmax) {
		float delta = rand()/(1.0*RAND_MAX);
		this->speed = Vmax * delta * (this->speed / n);
	}
}

/*
 * Méthode pour éloigner l'oiseau du bord,
 * renvoie v4
 */
Coordinates Boid::bound() {
	Coordinates v4(0,0);
	if (this->position.getX() < Xmin ) {
		if (periodic) {
			this->position.setX(Xmax-0.001);
		} else {
			v4.setX(back);
		}
	} else if (this->position.getX() > Xmax) {
		if (periodic) {
			this->position.setX(Xmin+0.001);
		} else {
			v4.setX(-back);
		}
	}
	if (this->position.getY() < Ymin ) {
		if (periodic) {
			this->position.setY(Ymax-0.001);
		} else {
			v4.setY(+back);
		}
	} else if (this->position.getY() > Ymax) {
		if (periodic) {
			this->position.setY(Ymin+0.001);
		} else {
			v4.setY(-back);
		}
	}
	return v4;
}

Coordinates Boid::esquiv() {
	Coordinates v6(0,0);
	vector<Coordinates> lst_obst = Obstacles::obs;
	int s = lst_obst.size();
	for (int i=0;i<s;i++) {
		Coordinates tmp = this->position - lst_obst[i];
		if (tmp.norm() < Obstacles::radius + Flock::interB) {
			Coordinates vOrth(-this->speed.getY(),this->speed.getX());
			vOrth = 2.2*Obstacles::radius * (vOrth / vOrth.norm());
			v6 = v6 + vOrth + this->speed;
		}
	}

	return v6;
}
/*
 * To string
 */
ostream& operator << (ostream& flux,Boid b) {
	flux << "Position : " << b.getPosition() << "Vitesse : " << b.getSpeed();
	return flux;
}

/*
 * Destructeur
 */
Boid::~Boid() {}

