/*
 * Obstacles.cpp
 *
 *  Created on: 7 mai 2017
 *      Author: tim
 */

#include "Obstacles.h"
#include "Coordinates.h"
#include <vector>

float Obstacles::radius = 0.03;
vector<Coordinates> Obstacles::obs;

/*
 * Constructeur
 */
Obstacles::Obstacles() {}

/*
 * Ajout d'un obstacle
 */
void Obstacles::addObstacle(Coordinates p) {
	obs.push_back(p);
}

/*
 * Ajout d'un obstacle aléatoire
 */
void Obstacles::addObstacle() {
	Coordinates c;
	obs.push_back(c);
}

/*
 * Supression d'un obstacle
 */
void Obstacles::rmvObstacle() {
	obs.pop_back();
}

/*
 * Destructeur
 */
Obstacles::~Obstacles() {
}

