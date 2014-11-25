#include "Transition.h"

#pragma once

Transition::Transition(int initialState, int endState, string letters) {
	initialState_ = initialState;
	endState_ = endState;
	letters_ = letters;
}

string Transition::getLetters() {
	return letters_;
}

int Transition::getEndState() {
	return endState_;
}