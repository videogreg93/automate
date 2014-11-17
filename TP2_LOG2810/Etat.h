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
	Etat(bool isInitialState, bool isFinalState, int name vector<Transition> transitions);


};