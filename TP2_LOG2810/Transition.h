#include "Etat.h"
#include <string>
using namespace std;

#pragma once 

class Transition {
private:
	Etat initialState_;
	Etat endState_;
	string letters_;

public:
	Transition(Etat initialState, Etat endState_, string letters_);
			   
};