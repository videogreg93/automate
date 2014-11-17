#include "Transition.h"

#pragma once

Transition::Transition(Etat initialState, Etat endState, string letters) {
	initialState_ = initialState;
	endState_ = endState;
	letters_ = letters;
}