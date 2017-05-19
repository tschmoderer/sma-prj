/*
 * TestBoid.cpp
 *
 *  Created on: 5 mai 2017
 *      Author: tim
 */

#include "TestBoid.h"
#include <iostream>
using namespace std;

/*
 * Constructeur
 */
TestBoid::TestBoid() {}

/*
 * Test de la méthode velocityMax()
 */
void TestBoid::testVelocityMax()
{
	Boid b;
	cout<<"Coordonnée de la vitesse du Boid créé : "<< b.getSpeed()<<" de norme : "<<b.getSpeed().norm()<<endl;
	cout<<"On veut ensuite diminuer cette vitesse si sa norme est superieur à Vmax, où Vmax = "<<Boid::Vmax<<endl;

	if (b.getSpeed().norm() > Boid::Vmax) {
				cout<<"La vitesse doit donc etre diminué"<<endl;
			}
		else { cout <<"La vitesse doit donc rester inchangée"<<endl; }

	Coordinates temp = b.getSpeed();
	b.velocityMax();

	cout<<"La nouvelle vitesse donnée par la fonction velocityMax est :"<< b.getSpeed()<<" de norme : "<<b.getSpeed().norm()<<endl;
	if (b.getSpeed().norm() > temp.norm()) {
			cout<<"Test NON OK"<<endl;
		}
	else { cout <<"Test OK"<<endl; }

	cout<<"On réapplique ensuite la fonction pour voir si le résultat reste inchangé : "<<endl;
	if (b.getSpeed().norm() > Boid::Vmax) {
					cout<<"La vitesse doit diminué, Test NON OK"<<endl;
				}
			else { cout <<"La vitesse doit rester inchangé, Test OK"<<endl; }
}

/*
 * Test de la fonction bound
 */
void TestBoid::testBound()
{
	Coordinates a(-1.5,0.2);//position
	Coordinates b(0.2,0.2);//vitesse
	Boid B(a,b);
	cout<<"Nous avons choisis Xmin= "<<Boid::Xmin<<" ,Xmax= "<<Boid::Xmax<<endl;
	cout<<"Coordonnée de la position du Boid créé : "<< B.getPosition()<<endl;

	cout<<"Premier cas : periodic false (condition de mur) "<<endl;
	cout<<"On souhaite ensuite un nouveau vecteur vitesse si le boid n'est pas dans [Xmin,Xmax]"<<endl;
	cout<<"La fonction retourne : "<<B.bound();
	if (B.bound().getX()==B.back)
	{
		cout<<"Le nouveau vecteur est bien le vecteur opposé; test OK"<<endl;
	}
	else {cout<<"Il n'y a pas égalité; test NON OK"<<endl;}

	cout<<endl;
	B.periodic=true;
	cout<<"Deuxième cas : periodic true (condition periodique)"<<endl;
	cout<<"On souhaite ensuite un nouveau vecteur vitesse si le boid n'est pas dans [Xmin,Xmax]"<<endl;
	cout<<"La fonction retourne: "<<B.bound();
	if (B.getPosition().getX()==Boid::Xmax-0.001)
	{
		cout<<"Le nouveau vecteur est bien du coté opposé; test OK"<<endl;
	}
	else {cout<<"Il n'y a pas égalité; test NON OK"<<endl;}
}
