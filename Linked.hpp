/**********************************************************************************
** Program Name: Final Project
** Author: Kevin Allen
** Date: 3/12/2018
** Description: This file contains the header for the linked class
***********************************************************************************/
#ifndef LINKED_HPP
#define LINKED_HPP
#include "Space.hpp"
#include "Jungle.hpp"
#include "Temple.hpp"
#include "Idol.hpp"
#include <vector>


class Linked {
private:
	Space* prev;
	Space* current;
	int numSteps = 0;
	bool haveIdolSpace = false;
	std::vector<Space*> boardList;  //stores the address of "new" spaces for destructor

public:
	Linked();
	~Linked();
	void addNorth();
	void addSouth();
	void addWest();
	void addEast();

	int determineSpace();

	Space* getCurrent();
	Space* getPrev();

	void setCurrent(Space*);

	void setPrev(Space*);

};
#endif
