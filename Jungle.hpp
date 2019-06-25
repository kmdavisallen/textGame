/**********************************************************************************
** Program Name: Final Project
** Author: Kevin Allen
** Date: 3/12/2018
** Description: This file contains the header for the jungle space class
***********************************************************************************/
#ifndef JUNGLE_HPP
#define JUNGLE_HPP

#include <vector>
#include <iostream>
#include "Utilities.hpp"
#include "Space.hpp"
//#include "Items.hpp"

class Jungle : public Space {
private:
	int searchAreas[3] = { 0, 0, 0 };
public:
	int jungleMenu();
	virtual void interact();
	Jungle(Space*, Space*, Space*, Space*);
	Jungle();
};


#endif