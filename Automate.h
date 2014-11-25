#include "Transition.h"
#include "Etat.h"
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

#pragma once

class Automate {
private:
	vector<Etat> listeEtats_;
	vector<Transition> listeTransitions_;
	Etat initialState_;
	Etat endState_;
	void mauvaisFormat();
	Etat getState(int name);

public:
	
	// For testing
	Automate();
	Automate(string fichier);
	Etat getInitialState();
	void setInitialState(Etat e);
	void ajouterEtat(Etat e);
	Automate determiniserAutomate(); // TODO
	bool estDeterministe();
	bool reconnaitreMot(string mot);
	
};