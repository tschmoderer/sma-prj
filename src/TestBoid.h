/**
 * \file TestBoid.h
 * \brief Classe Test pour la classe Boid
 * \author Juliette Lemains
 * \date 10 mai 2017
 * \version 1.0
 */

#ifndef TESTBOID_H_
#define TESTBOID_H_

#include "Boid.h"
/**
 * \class TestBoid
 * \brief Classe testant la classe Boid
 */
class TestBoid {
	public:
	/**
	 * \brief Constructeur
	 */
	TestBoid();
	/*
	 * \brief Test de la méthode velocityMax()
	 */
	void testVelocityMax();
	/**
	 * \brief Test de la méthode bound()
	 */
	void testBound();

};

#endif /* TESTBOID_H_ */
