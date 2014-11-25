#include "Automate.h"
#include <iostream>
using namespace std;

void Automate::mauvaisFormat()
{
	cout << "ERREUR: Format de fichier non reconnu" << endl;
}

Automate::Automate() {
	
}

Etat Automate::getState(int name) {
	for (int i = 0; i < this->listeEtats_.size(); i++) {
		if (listeEtats_[i].getName() == name)
			return listeEtats_[i];
	}
}


/*Automate::Automate(string fichier)
{
	ifstream automate;
	automate.open(fichier);

	if (automate.is_open())
	{
		int i = 0, j = 0;
		static int array[15][4], nbEtats = 0;

		automate >> nbEtats;

		//Remplir la matrice de l'automate
		for (string line; getline(automate, line); j++)
		{
			while (line[i] != '\0')
			{
				array[i][j] = line[i];
				i++;
			}
		}

		do
		{
			// Détermination de l'état
			if (isalpha(array[0][0]))
			{
				if (array[0][1] == 'I')
				{
					if (array[0][1] == 'T')
					{
						creationEtat(Inital);
					}
					else if (isdigit(array[0][1]))
					{
						creationEtat(InitialFinal);
					}
					else mauvaisFormat();
				}
				else if (array[0][0] == 'T')
				{
					creationEtat(Final);
				}
				else mauvaisFormat();
			}
			else if (isdigit(array[0][0]))
			{
				creationEtat(Transitoire);
			}
			else mauvaisFormat();
		} while (!automate.eof());
	}
}*/

Etat Automate::getInitialState() {
	return initialState_;
}

void Automate::setInitialState(Etat e) {
	initialState_ = e;
}

void Automate::ajouterEtat(Etat e) {
	listeEtats_.push_back(e);
}

bool Automate::estDeterministe() {
	string allStrings = "";
	bool determinist = true;
	for (int i = 0; i < listeEtats_.size(); i++) {
		vector<Transition> transitions = listeEtats_[i].getTransitions();
		for (int j = 0; j < transitions.size(); j++) {
			string letters = transitions[j].getLetters();
			for (int x = 0; x < letters.size(); x++) {
				if (allStrings.find(letters[x] == string::npos)) // if a letter was found in previous letters, it is non determinist
					determinist = false;
			}
			allStrings = allStrings + transitions[j].getLetters(); // Once we compared all letters, add the whole string to allStrings for future comparaisons
		}
	}

	return determinist;
}

bool Automate::reconnaitreMot(string mot) {
	Etat currentState = initialState_;
	cout << "I'm starting at state " << currentState.getName() << endl << endl;
	for (int i = 0; i < mot.size(); i++) {
		if (currentState.existeTransition(mot[i])) // If a transition exists, current state becomes the new state 
		{
			currentState = this->getState(currentState.cible(mot[i])[0]); // If it is determinist, cible will return a vector of size 1
			cout << "After " << (i+1) << " iterations, I am now in state " << currentState.getName() << endl;
		}
		else
			cout << "I have no transition for letter " << mot[i] << " so I'm still in state " << currentState.getName() << endl;

	}

	if (this->getState(currentState.getName()).getIsFinalState())
		return true;
	else
		return false;
}