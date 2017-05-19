/*
 * Flock.h
 *
 *  Created on: 31 mars 2017
 *      Author: caroline
 */

#ifndef FLOCK_H_
#define FLOCK_H_

/**
 * \file Flock.h
 * \brief Description d'un groupement d'agents
 * \author Salomé Baulain
 * \date 14 avril 2017
 * \version 1.3
 */

#include <vector>
#include "Boid.h"

using namespace std;

/**
 * \class Flock
 * \brief Classe représentant un groupement d'agents
 */
class Flock {
private:
	/**
	 * Une collection d'adresse d'agents
	 */
	vector<Boid*> flock;

public:
	/**
	 * \brief Constructeur par défaut de la classe Flock
	 */
	Flock();

	/**
	 * \brief distance minimale entre agents
	 */
	static float interB;
	/**
	 * \brief Poids de pondération de la règle n°1
	 */
	static float m1;
	/**
	 * \brief Poids de pondération de la règle n°2
	 */
	static float m2;
	/**
	 * \brief Poids de pondération de la règle n°3
	 */
	static float m3;
	/**
	 * \brief Poids de pondération de la règle n°4
	 */
	static float m4;
	/**
	 * \brief Poids de pondération de la règle n°5
	 */
	static float m5;
	/**
	 * \brief Poids de pondération de la règle n°6
	 */
	static float m6;
	/**
	 * \brief POids dde pondération de la règle n°7
	 */
	static float m7;
	/**
	 * \brief Distance pour considérer que deux oiseaux sont proches
	 */
	static float closest;


	/**
	 * \brief Accesseur de la collection d'agent
	 * \return Un vecteur d'adresse des agents composant le goupement
	 */
	vector<Boid*> getFlock();
	/**
	 * \brief Ajout d'un agent à la colection
	 * \param Boid* : L'adresse mémoire de l'agent à ajouter
	 */
	void addBoid(Boid*);
	/**
	 * \brief Retrait du dernier agent de la collection
	 */
	void rmvBoid();

	/**
	 * \brief Méthode implémentant les règles du modèle
	 */
	void rules();

	/**
	 *\brief retourne une collection d'entiers représentant les indices des boids compris dans un rayon inférieur à closest autour du boid i.
	 *\param i Le numéro du boid autour duquel nous cherchons les  plus proches
	 */
	vector<int> find_closest(int);

	/**
	 * \brief Surcharge de l'opérateur []
	 * \param i : L'indice de l'agent que l'on veut récupérer
	 * \return L'agent à la ième position dans la collection
	 */
	Boid* operator [] (int);

	/**
	 * \brief Surcharge de l'opérateur <<
	 * \param ostream& : Un flux de sortie
	 * \param Flock : La collection d'agents que l'on souhaite afficher
	 * \details Permet une sortie console des données
	 */
	friend ostream& operator << (ostream&,Flock);

	/**
	 * \brief Destructeur de la classe Flock
	 */
	virtual ~Flock();
};

#endif /* FLOCK_H_ */
