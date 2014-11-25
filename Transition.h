#include <string>
using namespace std;

#pragma once 

class Etat;

class Transition {
private:
	int initialState_;
	int endState_;
	string letters_;

public:
	Transition(int initialState, int endState_, string letters_);

	string getLetters();
	int getEndState();
			   
};