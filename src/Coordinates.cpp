
#include <iostream>
#include <cstdlib>
#include <cmath>

#include "Coordinates.h"
#include "Boid.h"

using namespace std;

/*
 * Créé une paire de coordonnées dans le rectangle [Xmin,Xmax]x[Ymin,Ymax]
 */
Coordinates::Coordinates() {
	this->x = (Boid::Xmax-Boid::Xmin)*(rand()/(1.0*RAND_MAX))+Boid::Xmin;
	this->y = (Boid::Ymax-Boid::Ymin)*(rand()/(1.0*RAND_MAX))+Boid::Ymin;
}

/*
 * Constructeur spécifique
 */
Coordinates::Coordinates(double leX, double leY) {
	this->x = leX;
	this->y = leY;
}

/*
 * GETTERS
 */
double Coordinates::getX() const {
	return this->x;
}

double Coordinates::getY() const {
	return this->y;
}

/*
 * SETTERS
 */
void Coordinates::setX(const double leX) {
	this->x = leX;
}

void Coordinates::setY(const double leY) {
	this->y = leY;
}

/*
 * Calcul de la norme du vecteur
 */
double Coordinates::norm() {
	return sqrt(this->x*this->x+this->y*this->y);
}


/*
 * Somme de deux coordonnées
 * Renvoie une nouvelle instance de coordonées
 */
Coordinates operator + (const Coordinates c1, const Coordinates c2) {
	Coordinates c(0,0);
	c.setX(c1.getX()+c2.getX());
	c.setY(c1.getY()+c2.getY());
	return c;
}

/*
 * Différence de deux coordonnées
 */
Coordinates operator - (const Coordinates c1, const Coordinates c2) {
	Coordinates c(0,0);
	c.setX(c1.getX()-c2.getX());
	c.setY(c1.getY()-c2.getY());
	return c;
}

/*
 * Multiplication à droite par un scalaire
 */
Coordinates operator * (const Coordinates c1,const double f) {
	Coordinates c(0,0);
	c.setX(f*c1.getX());
	c.setY(f*c1.getY());
	return c;
}

/*
 * Multiplication à gauche par un scalaire
 */
Coordinates operator * (const double f,const Coordinates c1) {
	Coordinates c(0,0);
	c.setX(f*(c1.getX()));
	c.setY(f*(c1.getY()));
	return c;
}

/*
 * Division à droite par un scalaire
 */
Coordinates operator / (const Coordinates c1,const double f) {
	Coordinates c(0,0);
	if (f==0) {
		return c1*1.7*pow(10,30);
	} else {
		c.setX(c1.getX()/f);
		c.setY(c1.getY()/f);
		return c;
	}
}

/*
 * Produit scalaire entre deux coordonnées
 */
double operator * (const Coordinates c1,const Coordinates c2) {
	return c1.getX()*c2.getX()+c1.getY()*c2.getY();
}

/*
 * To string
 */
ostream& operator << (ostream& flux,const Coordinates c) {
	flux << "X : " << c.getX() << " Y : " << c.getY() << endl;
	return flux;
}

/*
 * Destructeur
 */
Coordinates::~Coordinates() {}
