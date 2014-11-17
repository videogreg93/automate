#include "Etat.h"

#pragma once 

Etat::Etat() {
	isInitialState_ = false;
	isFinalState_ = false;
	name_ = -1;
}

Etat::Etat(int name) {
	isInitialState_ = false;
	isFinalState_ = false;
	name_ = name;
}

Etat::Etat(bool isInitialState, bool isFinalState, int name, vector<Transition> transitions) {
	isInitialState_ = isInitialState;
	isFinalState_ = isFinalState;
	name_ = name;
	listOfTransitions_ = transitions;

}
