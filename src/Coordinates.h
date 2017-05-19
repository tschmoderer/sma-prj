
#ifndef COORDINATES_H_
#define COORDINATES_H_

/**
 * \file Coordinates.h
 * \brief Coordonnées pour un vecteur
 * \author Caroline Montassier
 * \date 10 mars 2017
 * \version 1.2
 */


#include <iostream>
using namespace std;

/**
 * \class Coordinates
 * \brief Classe représentant les coordonnées d'un vecteur dans le plan
 */
class Coordinates {
private:
	double x; /*!< Abscisse du vecteur*/
	double y;  /*!< Ordonnée du vecteur*/
public:
	/**
	 * \brief Constructeur par défaut de la classe Coordinates
	 */
	Coordinates();
	/**
	 * \brief Constructeur spécifique de la classe Coordinates
	 * \param leX : spécifie l'abscisse du vecteur construit
	 * \param leY : spécifie l'ordonnée du vecteur construit
	 */
	Coordinates(double leX, double leY);

	/**
	 * \brief Destructeur de la classe Coordinates
	 */
	virtual ~Coordinates();

	/**
	 * \brief Accesseur de l'abscisse
	 * \return L'abscisse du vecteur spécifié
	 */
	double getX() const;
	/**
	 * \brief Accesseur de l'ordonnée
	 * \return L'ordonnée du vecteur spécifié
	 */
	double getY() const;

	/**
	 * \brief Change la valeur de l'abscisse du vecteur
	 * \param leX : La nouvelle valeur de l'abscisse du vecteur
	 */
	void setX(const double leX);
	/**
	 * \brief Change la valeur de l'ordonnée du vecteur
	 * \param leY : La nouvelle valeur de l'ordonnée du vecteur
	 */
	void setY(const double leY);

	/**
	 * \brief Calcul la norme euclidienne du vecteur
	 * \return La norme euclidienne du vecteur :\f$\sqrt{x^2+y^2}\f$
	 */
	double norm();

	/**
	 * \brief Surcharge de l'opérateur +
	 * \details Fait la somme mathématique de deux vecteurs
	 * \param Coordinates : Le premier vecteur
	 * \param Coordinates : Le second vecteur
	 * \return Un vecteur dont les coordonnées sont la somme des coordonnées des deux vecteurs passés en entrée
	 */
	friend Coordinates operator + (const Coordinates, const Coordinates);
	/**
	 * \brief Surcharge de l'opérateur -
	 * \details Fait la différence mathématique de deux vecteurs
	 * \param Coordinates : Le premier vecteur
	 * \param Coordinates : Le second vecteur
	 * \return Un vecteur dont les coordonnées sont la différence des des coordonnées des deux vecteurs passés en entrée
	 */
	friend Coordinates operator - (const Coordinates, const Coordinates);
	/**
	 * \brief Surcharge de l'opérateur *
	 * \details Fait la multiplication à droite d'un vecteur par un sclaire
	 * \param Coordinates : Le premier vecteur
	 * \param double : Un scalaire
	 * \return Un vecteur dont les coordonnées sont les coordonnées du vecteur passé en entrée multpliées par le scalaire
	 */
	friend Coordinates operator * (const Coordinates,const double);
	/**
	 * \brief Surcharge de l'opérateur *
	 * \details Fait la multiplication à gauche d'un vecteur par un sclaire
	 * \param double : Un scalaire
	 * \param Coordinates : Le premier vecteur
	 * \return Un vecteur dont les coordonnées sont les coordonnées du vecteur passé en entrée multpliées par le scalaire
	 */
	friend Coordinates operator * (const double,const Coordinates);
	/**
	 * \brief Surcharge de l'opérateur /
	 * \details Fait la division à droite d'un vecteur par un sclaire
	 * \param Coordinates : Le premier vecteur
	 * \param double : Un scalaire
	 * \return Un vecteur dont les coordonnées sont les coordonnées du vecteur passé en entrée divisées par le scalaire
	 */
	friend Coordinates operator / (const Coordinates,const double);
	/**
	 * \brief Surcharge de l'opérateur *
	 * \details Fait le produit scalaire de deux vecteurs
	 * \param Coordinates : Le premier vecteur \f$v_1\f$
	 * \param Coordinates : Le second vecteur \f$v_1\f$
	 * \return Le produit scalaire des deux vecteurs \f$v_1.x*v_2.x+v_1.y*v_2.y\f$
	 */
	friend double operator * (const Coordinates,const Coordinates);

	/**
	 * \brief Surcharge de l'opérateur <<
	 * \param ostream& : Un flux de sortie
	 * \param Coordinates : Les coordonnées que l'on souhaite afficher
	 * \details Permet une sortie console des données
	 */
	friend ostream& operator << (ostream&,const Coordinates);
};

#endif /* COORDINATES_H_ */
