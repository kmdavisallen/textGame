/**********************************************************************************
** Program Name: Final Project
** Author: Kevin Allen
** Date: 3/12/2018
** Description: This file contains the header for the idol space class
***********************************************************************************/
#ifndef IDOL_HPP
#define IDOL_HPP

#include <vector>
#include <iostream>
#include "Utilities.hpp"
#include "Space.hpp"


class Idol : public Space {
private:
	int searchAreas[3] = { 0, 0, 0};
	int searchCount = 0;
	
public:
	int jungleMenu();
	virtual void interact();
	Idol(Space*, Space*, Space*, Space*);
	Idol();
};

#endif