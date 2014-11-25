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

int Etat::getName() {
	return name_;
}

bool Etat::getIsFinalState() {
	return isFinalState_;
}

bool Etat::existeTransition(char e) {
	for (int i = 0; i < listOfTransitions_.size(); i++) {
		if (listOfTransitions_[i].getLetters().find(e) != std::string::npos)
			return true;
	}
	return false;
}

vector<int> Etat::cible(char e) {
	vector<int> cibles;
	for (int i = 0; i < listOfTransitions_.size(); i++) {
		if (listOfTransitions_[i].getLetters().find(e) != std::string::npos) {
			cibles.push_back(listOfTransitions_[i].getEndState());
		}
	}

	return cibles;
}

vector<int> Etat::cible(){
	vector<int> cibles;
	for (int i = 0; i < listOfTransitions_.size(); i++) {
		cibles.push_back(listOfTransitions_[i].getEndState());
	}

	return cibles;
}

vector<Transition> Etat::getTransitions() {
	return this->listOfTransitions_;
}

void Etat::ajouterTransition(string c, Etat e){
	Transition temp(this->getName(), e.getName(), c);
	listOfTransitions_.push_back(temp);
}

string Etat::listerEtiquettes() {
	string etiquettes = "";
	for (int i = 0; i < listOfTransitions_.size(); i++) {
		etiquettes = etiquettes + listOfTransitions_[i].getLetters();
	}
	return etiquettes;
}