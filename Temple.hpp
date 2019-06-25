/**********************************************************************************
** Program Name: Final Project
** Author: Kevin Allen
** Date: 3/12/2018
** Description: This file contains the header for the temple space class
***********************************************************************************/
#ifndef TEMPLE_HPP
#define TEMPLE_HPP
#include "Space.hpp"
#include "Utilities.hpp"
#include <iostream>

class Temple : public Space {
public:
	virtual void interact();
	Temple();
	Temple(Space*, Space*, Space*, Space*);
	int templeMenu();
};

#endif
