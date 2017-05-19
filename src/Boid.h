/*
 * Boid.h
 *
 *  Created on: 31 mars 2017
 *      Author: caroline
 */

#ifndef BOID_H_
#define BOID_H_

/**
 * \file Boid.h
 * \brief Description d'un agent
 * \author Adam Quinquenel
 * \date 10 avril 2017
 * \version 1.7
 */

#include <iostream>
#include "Coordinates.h"

/**
 * \class Boid
 * \brief Classe représentant les caractéristiques d'un agent
 */
class Boid {
private :
	/**
	 *  Position de l'agent
	 */
	Coordinates position;
	/**
	 * Vitesse de l'agent
	 */
	Coordinates speed;
public:
	/**
	 * \brief Constructeur par défaut de la classe Boid
	 */
	Boid();
	/**
	 * \brief Constructeur spécifique de la classe Boid
	 * \param Coordinates : Vecteurposition de l'agent
	 * \param Coordinates : Vecteur vitesse de l'agent
	 * \return Un agent avec la position et la vitesse passés en paramètres
	 */
	Boid(Coordinates,Coordinates);
	 /**
	  * \brief Vitesse maximale des agents
	  */
	static float Vmax;
	/**
	 * \brief Vitesse de retour vers le domaine
	 */
	static float back;
	/**
	 *  \brief Position de la bordure ouest
	 */
	static int Xmin;
	/**
	 *  \brief Position de la bordure est
	 */
	static int Xmax;
	/**
	 *  \brief Position de la bordure sud
	 */
	static int Ymin;
	/**
	 *  \brief Position de la bordure nord
	 */
	static int Ymax;
	/**
	 * \brief si periodic est true alors il y a periodicité sur les bords ( quand le boid rencontre un mur, il rerentre dans le domaine par le mur opposé).
	 *  si periodic est false, le boid rebondit sur le mur.
	 */
	static bool periodic;


	/**
	 * \brief Accesseur de la position
	 * \return La position de l'agent
	 */
	Coordinates getPosition();
	/**
	 * \brief Accesseur de la vitesse
	 * \return La vitesse de l'agent
	 */
	Coordinates getSpeed();
	/**
	 * \brief Change la position de l'agent
	 * \param Coordinates : La nouvelle position de l'agent
	 */
	void setPosition(Coordinates);
	/**
	 * \brief Change la vitesse de l'agent
	 * \param Coordinates : La nouvelle vitesse de l'agent
	 */
	void setSpeed(Coordinates);

	/**
	 * \brief Limite la vitesse de l'agent
	 */
	void velocityMax();
	/**
	 * \brief Méthode pour lier l'agent au domaine
	 * \return Un vecteur vitesse en direction du domaine de calcul si l'agent en est sorti
	 */
	Coordinates bound();
	/**
	 * \brief Méthode pour éviter les obstacles
	 * \return Un vecteur vitesse d'évitement d'un obstacle
	 */
	Coordinates esquiv();

	/**
	 * \brief Surcharge de l'opérateur <<
	 * \param ostream& : Un flux de sortie
	 * \param Boid : L'agent que l'on souhaite afficher
	 * \details Permet une sortie console des données
	 */
	friend ostream& operator << (ostream&,Boid);
	/**
	 * \brief Destructeur de la classe Boid
	 */
	virtual ~Boid();
};

#endif /* BOID_H_ */
