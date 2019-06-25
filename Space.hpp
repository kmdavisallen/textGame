/**********************************************************************************
** Program Name: Final Project
** Author: Kevin Allen
** Date: 2/14/2018
** Description: This file contains the header for the space class
***********************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include "Die.hpp"

class Space {
protected:
	Space* top;
	Space* bottom;
	Space* left;
	Space* right;
	int results[6] = {0, 0, 0, 0, 0, 0};
public:
	Space* getTop();
	Space* getBottom();
	Space* getLeft();
	Space* getRight();

	void setTop(Space*);
	void setBottom(Space*);
	void setLeft(Space*);
	void setRight(Space*);
	
	int* getResults();

	virtual void interact() = 0;

};


#endif