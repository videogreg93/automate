#include "Transition.h"
#include <string>
#include <vector>
using namespace std;

#pragma once 


class Etat {
private:
	bool isInitialState_;
	bool isFinalState_;
	int name_;
	vector<Transition> listOfTransitions_;
	
public:
	Etat();
	Etat(int name);
	Etat(bool isInitialState, bool isFinalState, int name, vector<Transition> transitions);

	int getName();
	vector<Transition> getTransitions();
	bool getIsFinalState();

	bool existeTransition(char e);
	vector<int> cible(char e); // Returns a vector of all the names of the end states of transitions with e
	vector<int> cible(); // Returns all end states

	void ajouterTransition(string c, Etat e);
	string listerEtiquettes();
};