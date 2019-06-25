/*********************************************************************
** Program Name: Lab 3
** Author: Kevin Allen
** Date: 1/26/2018
** Description: This file contains the member functions for the die class
***********************************************************************/

#include "Die.hpp"
#include <cstdlib>

Die::Die(int num): N(num) {}

int Die:: getSides() {
	return N;
}

int Die::rollDie() {
	return rand() % N + 1;
}
