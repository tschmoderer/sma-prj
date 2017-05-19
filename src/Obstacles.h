/**
 * \file Obstacles.h
 * \brief Description du groupement d'obstacles
 * \author Timothée Schmoderer
 * \date 14 mai 2017
 * \version 1.8
 */

#ifndef OBSTACLES_H_
#define OBSTACLES_H_

#include "Coordinates.h"
#include <vector>

/**
 * \class Obstacles
 * \brief Classe représentant un groupement d'obstacles
 */
class Obstacles {
private:

public:
	/**
	 * \brief Liste des corrdonnées des Obstacles
	 */
	static vector<Coordinates> obs;
	/**
	 * \brief le rayon d'un obstaccles
	 */
	static float radius;
	/**
	 * \brief Constructeur par défaut
	 */
	Obstacles();
	/**
	 * \brief Ajoute un obstacle à la liste des obstacles
	 * \param p Les coordonnées de l'obstacles à ajouter
	 */
	void addObstacle(Coordinates);
	/**
	 * \brief Ajoute un obstacle aléatoirement dans le domaine
	 */
	static void addObstacle();
	/**
	 * \brief Supprime un obstacle de la liste
	 */
	static void rmvObstacle();
	/**
	 * \brief Destructeur
	 */
	virtual ~Obstacles();
};

#endif /* OBSTACLES_H_ */
