/**
 * \file TestFlock.h
 * \brief Classe Test pour la classe Flock
 * \author Juliette Lemains
 * \date 10 mai 2017
 * \version 1.0
 */


#ifndef TESTFLOCK_H_
#define TESTFLOCK_H_
#include "Flock.h"

/**
 * \class TestFlock
 * \brief Classe testant la classe Flock
 */
class TestFlock {
public:
	/**
	 * \brief Constructeur
	 */
	TestFlock();
	/**
	 * \brief Test de la méthode find_closest()
	 */
	void testFind_closest();
};

#endif /* TESTFLOCK_H_ */
