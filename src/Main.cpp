#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <string>
#include <sstream>
#include "Boid.h"
#include "Flock.h"
#include "Coordinates.h"
#include "Flock.h"
#include "Obstacles.h"

/**
 * Largeur de la fenetre d'affichage
 */
const int WIDTH = 800;
/**
 * Hauteur de la fenetre d'affichage
 */
const int HEIGHT = 600;

float viewXmin = Boid::Xmin - 0.2;
float viewXmax = Boid::Xmax + 0.2;
float viewYmin = Boid::Ymin - 3;
float viewYmax = Boid::Ymax + 0.5;

std::ostringstream flux_params;
std::ostringstream flux_intrucs;
/*
 * Nombre d'image par seconde
 */
const int framed = 10;
/*
 * Echelle du texte
 */
const float Zx = 0.0011;
const float Zy = 0.0019;
int niter = -1; // nombre d'itérations
int nbBoid = 0; // nombre d'agents
void init(); // fonction d'initialisation


using namespace sf;

/**
 * \brief Fonction principale
 */
int main() {
	init();
	/*
	 * Initialisation de l'affichage
	 */
	RenderWindow window(VideoMode(WIDTH,HEIGHT,32),"Boids de Reynolds");
	window.clear();
	window.setFramerateLimit(framed);

	CircleShape shape(0.005);
	CircleShape obst(Obstacles::radius);
	View view;

	Text params;
	Text instructions;

	Font maPolice;
	// /!\ la chemain de la police
	maPolice.loadFromFile("./raleway.ttf");
	shape.setFillColor(Color::Red);
	obst.setFillColor(Color::Blue);
	view.setCenter((viewXmin+viewXmax)/2.0,(viewYmin+viewYmax)/2.0);
	view.setSize(viewXmax-viewXmin,viewYmax-viewYmin);

	params.setFont(maPolice);
	params.setCharacterSize(20);
	params.setColor(Color::White);
	params.setPosition(WIDTH/2.0,0);
	params.setScale(2.0,1.5);
	instructions.setFont(maPolice);
	instructions.setCharacterSize(20);
	instructions.setColor(Color::White);
	instructions.setString(flux_intrucs.str());
	instructions.setPosition(20,0);
	instructions.setScale(0.6,0.75);
	window.draw(instructions);
	window.draw(params);

	window.setView(view);

	//Display borders
	ConvexShape border;
	border.setPointCount(4);

	// define the points
	border.setPoint(0, sf::Vector2f(Boid::Xmin, Boid::Ymin));
	border.setPoint(1, sf::Vector2f(Boid::Xmax, Boid::Ymin));
	border.setPoint(2, sf::Vector2f(Boid::Xmax, Boid::Ymax));
	border.setPoint(3, sf::Vector2f(Boid::Xmin, Boid::Ymax));

	border.setFillColor(Color::Transparent);
	border.setOutlineThickness(0.01);
	border.setOutlineColor(Color::White);

	/*
	 * Création d'un essaim
	 * Affichage de la position initial de l'essaim
	 * Affichage initial des obstacles
	 */
	Flock * ptr_flock = new Flock;
	for (int i=0;i<nbBoid;i++) {
		Boid * ptr_boid = new Boid;
		(*ptr_flock).addBoid(ptr_boid);
		double x = (*ptr_boid).getPosition().getX();
		double y = (*ptr_boid).getPosition().getY();
		shape.setPosition(x,y);
		window.draw(shape);
	}
	for (unsigned int i=0;i<Obstacles::obs.size();i++) {
		double x = Obstacles::obs[i].getX();
		double y = Obstacles::obs[i].getY();
		obst.setPosition(x,y);
		window.draw(obst);
	}

	window.draw(border);
	window.display();

	cout << "Règle n°1 : les boids veulent se rapprocher du centre de gravité de l'essaim." << endl;
	cout << "Règle n°2 : les boids s'écartent les uns des autres." << endl;
	cout << "Règle n°3 : les boids veulent avoir une vitesse proche de celle des voisins." << endl;
	cout << "Règle n°4 : les boids sont forcés de rester dans le domaien." << endl;
	cout << "Règle n°5 : les boids veulent se rapprocher du centre du domaine." << endl;
	cout << "Règle n°6 : les boids contournent les obstacles." << endl;
	cout << "Règle n°7 : un vent latéral pousse les boids." << endl;

	/*
	 * Boucle principale
	 */
	int k = 0;
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			//Si demande de fermer la fenetre, on arrete le programe
			if (event.type == Event::Closed)
				window.close();
			//Gestion event souris :
			if (event.type == Event::MouseButtonPressed)
			{
			    if (event.mouseButton.button == Mouse::Left)
			    	Obstacles::addObstacle();
			    if (event.mouseButton.button == Mouse::Right)
			    	if (Obstacles::obs.size() > 0)
			   			Obstacles::rmvObstacle();
			}
			//Getsion événement clavier
			if (event.type == Event::KeyPressed) {
				switch (event.key.code) {
				case Keyboard::BackSpace : {//Quitter
					window.close();
					break;
				}
				case Keyboard::Escape : {//Quitter
					window.close();
					break;
				}
				case Keyboard::X : {//Quitter
					window.close();
					break;
				}
				case Keyboard::A : {//Ajouter un agent
					Boid * ptr_boid = new Boid;
					(*ptr_flock).addBoid(ptr_boid);
					nbBoid++;
					break;
				}
				case Keyboard::S : {//Supprimer un agent
					if ((*ptr_flock).getFlock().size()>0) {
						(*ptr_flock).rmvBoid();
						nbBoid--;
					}
					break;
				}
				case Keyboard::Z : {//Augmenter la regle 1
					Flock::m1 += 0.01;
					break;
				}
				case Keyboard::E : {//Diminuer la regle 1
					Flock::m1 -= 0.01;
					break;
				}
				case Keyboard::R : {//Augmenter la regle 2
					Flock::m2 += 0.01;
					break;
				}
				case Keyboard::T : {//Diminuer la regle 2
					Flock::m2 -= 0.01;
					break;
				}
				case Keyboard::Y : {//Augmenter la regle 3
					Flock::m3 += 0.01;
					break;
				}
				case Keyboard::U : {//Diminuer la regle 3
					Flock::m3 -= 0.01;
					break;
				}
				case Keyboard::I : {//Augmenter la regle 4
					Flock::m4 += 0.01;
					break;
				}
				case Keyboard::O : {//Diminuer la regle 4
					Flock::m4 -= 0.01;
					break;
				}
				case Keyboard::P : {//Augmenter la regle 5
					Flock::m5 += 0.01;
					break;
				}
				case Keyboard::M : {//Diminuer la regle 5
					Flock::m5 -= 0.01;
					break;
				}
				case Keyboard::W : {//diminuer la vitesse des agents
					Boid::Vmax -= 0.01;
					if (Boid::Vmax <= 0) Boid::Vmax = 0.01;
					break;
				}
				case Keyboard::C : {//augmenter la vitesse des agents
					Boid::Vmax += 0.01;
					break;
				}
				case Keyboard::V : {//periodic ou non
					Boid::periodic = !Boid::periodic;
					break;
				}
				case Keyboard::G : {//lier les agents dans le domaine
					Boid::back -= 0.01;
					if (Boid::back <= 0.0) Boid::back = 0.01;
					break;
				}
				case Keyboard::F : {//lier les agents dans le domaine
					Boid::back += 0.01;
					break;
				}
				case Keyboard::B : {//diminuer distnce de sécurité
					Flock::interB -= 0.01;
					if (Flock::interB <= 0.0) Boid::back = 0.01;
					break;
				}
				case Keyboard::N : {//augmenter distance de sécurité
					Flock::interB += 0.01;
					break;
				}
				case Keyboard::H : {//boid plus égoiste
					if (Flock::closest - 0.01 >0) {
						Flock::closest -= 0.01;
					}
					break;
				}
				case Keyboard::J : {//boid altruistes
					Flock::closest +=0.01;
					break;
				}
				case Keyboard::K : {//boid évite les obstaces au plus proche
					if (Flock::m6 - 0.01 >0) {
						Flock::m6 -= 0.01;
					}
					break;
				}
				case Keyboard::L : {//boid évite les obstacles plus fortement
					Flock::m6 += 0.01;
					break;
				}
				case Keyboard::Q : {//vent latéral moins fort
					if (Flock::m7 - 0.01 >= 0) {
						Flock::m7 -= 0.01;
					}
					break;
				}
				case Keyboard::D : {//vent latéral plus fort
					Flock::m7 +=0.01;
					break;
				}


				case Keyboard::Space : {//Changer la couleur
					Color color(rand()%256,rand()%256,rand()%256);
					shape.setFillColor(color);
					break;
				}

				default : ; break;
				}
			}
		}

		// Application des règles
		(*ptr_flock).rules();
		// Affichage de l'essaim
		window.clear();

		int s = (*ptr_flock).getFlock().size();
		for (int i=0;i<s;i+=1) {
			Boid tmp = *(*ptr_flock)[i];
			double x = tmp.getPosition().getX();
			double y = tmp.getPosition().getY();
			shape.setPosition(x,y);
			window.draw(shape);
		}
		// Affichage des obstacles :
		for (unsigned int i=0;i<Obstacles::obs.size();i++) {
			double x = Obstacles::obs[i].getX();
			double y = Obstacles::obs[i].getY();
			obst.setPosition(x,y);
			window.draw(obst);
		}
		flux_params.clear();
		flux_params.str("");
		flux_params <<endl<< "Parametres : " << endl;
		flux_params << endl;
		flux_params << "Nombre de Boid : " << nbBoid << endl;
		flux_params << "Poids de la regle 1 : " << Flock::m1 << endl;
		flux_params << "Poids de la regle 2 : " << Flock::m2 << endl;
		flux_params << "Poids de la regle 3 : " << Flock::m3 << endl;
		flux_params << "Poids de la regle 4 : " << Flock::m4 << endl;
		flux_params << "Poids de la regle 5 : " << Flock::m5 << endl;
		flux_params << "Poids de la regle 6 : " << Flock::m6 << endl;
		flux_params << "Poids de la regle 7 : " << Flock::m7 << endl;
		flux_params << "Vitesse max : " << Boid::Vmax << endl;
		if (Boid::periodic) flux_params << "Conditions aux bords : periodiques" <<endl; else flux_params << "Conditions aux bords : murs" << endl;
		flux_params << "Vitesse de rebroussement : " << Boid::back << endl;
		flux_params << "Distance de securite entre les Boids : " << Flock::interB << endl;
		flux_params << "Champ de vision des Boids : " << Flock::closest << endl;
		flux_params << "Nombres d'obstacles : " << Obstacles::obs.size() << endl;
		params.setString(flux_params.str());

		params.setFont(maPolice);
		params.setCharacterSize(20);
		params.setColor(Color::White);
		params.setPosition((3.0*viewXmax+1.9*viewXmin)/4.0,viewYmin);
		params.setScale(0.004,0.0065);
		instructions.setFont(maPolice);
		instructions.setCharacterSize(20);
		instructions.setColor(Color::White);
		instructions.setString(flux_intrucs.str());
		instructions.setPosition(viewXmin+0.05,viewYmin);
		instructions.setScale(0.003,0.0065);

		window.draw(params);
		window.draw(instructions);

		window.draw(border);

		window.display();
		// Si on a effectué le nombre d'itérations demandée par l'utilisateur, on ferme al fenetre

		if (k == niter) {
			window.close();
		}
		k++;
		}
	return 0;
}
/**
 * \brief Initialisation des constantes
 */
void init() {
	//initialisation de l'aléatoire
	srand(time(0));


	flux_params.clear();
	flux_params.str("");
	flux_params << setprecision(2);

	flux_intrucs.clear();
	flux_intrucs.str("");
	flux_intrucs << endl;
	flux_intrucs << "--------------Instructions--------------" << endl;
	flux_intrucs << endl;
	flux_intrucs << "Appuyer sur 'A/S' pour ajouter/supprimer un agent" << endl;
	flux_intrucs << "Appuyer sur 'Z/E' pour jouer sur la regle 1" << endl;
	flux_intrucs << "Appuyer sur 'R/T' pour jouer sur la regle 2" << endl;
	flux_intrucs << "Appuyer sur 'Y/U' pour jouer sur la regle 3" << endl;
	flux_intrucs << "Appuyer sur 'I/O' pour jouer sur la regle 4" << endl;
	flux_intrucs << "Appuyer sur 'P/M' pour jouer sur la regle 5" << endl;
	flux_intrucs << "Appuyer sur 'K/L' pour jouer sur la regle 6" << endl;
	flux_intrucs << "Appuyer sur 'Q/D' pour jouer sur la regle 7" << endl;
	flux_intrucs << "Appuyer sur 'W/C' pour augmenter/diminuer la vitesse maximale" << endl;
	flux_intrucs << "Appuyer sur 'V' pour changer les conditions aux bords" << endl;
	flux_intrucs << "Appuyer sur 'F/G' pour influencer sur le comportement aux bords" << endl;
	flux_intrucs << "Appuyer sur 'B/N' pour changer la distance de sécurité entre les Boids" << endl;
	flux_intrucs << "Appuyer sur 'H/J' pour influencer le champ de vision des Boids" << endl;
	flux_intrucs << "Appuyer sur 'Espace' pour changer la couleur des oiseaux" << endl;
	flux_intrucs << "Appuyer sur 'Echap', 'Effacer', ou 'X' pour Quitter" << endl;

}
