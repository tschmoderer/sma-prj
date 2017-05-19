/*
 * TestFlock.cpp
 *
 *  Created on: 5 mai 2017
 *      Author: tim
 */

#include "TestFlock.h"
#include <vector>
using namespace std;

/*
 * Constructeur
 */
TestFlock::TestFlock() {}

/*
 * test de la méthode find_closest()
 */
void TestFlock::testFind_closest()
{
	Flock f;
	int i;
	for (i=0;i<10;i++)
	{
		Boid * b = new Boid();
		f.addBoid(b);
	}
	cout<<"Création d'un flock : ";
	cout<<f<<endl;

	cout<<"On cherche les boids les plus proches du boid 5(par exemple), calculés grace à la variable closest égale à "<<Flock::closest<<endl;
	cout<<"Variable qui représente la distance maximum entre deux boid pour qu'ils soient considérés comme proches"<<endl;
	cout<<"On affiche la distance des Boids au Boid 5 : "<<endl;

	for (int j=0;j<10;j++) {
				Boid * tmp = f[j];
				Coordinates t = (*tmp).getPosition()-(*f[5]).getPosition();
				cout<<"Norme de la distance avec Boid n°"<<j<<" : "<<t.norm()<<endl;
	}
	cout<<"On affiche le tableau trouvé et on les test: "<<endl;
	for (unsigned int k=0;k<(f.find_closest(5)).size();k++)
	{
		cout<<f.find_closest(5)[k];
		Coordinates t = (*f[f.find_closest(5)[k]]).getPosition()-(*f[5]).getPosition();
		if (t.norm()<Flock::closest)
		{
			cout<<" Test OK !"<<endl;
		}
	}
}


