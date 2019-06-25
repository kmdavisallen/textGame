/**********************************************************************************
** Program Name: Final Project
** Author: Kevin Allen
** Date: 3/12/2018
** Description: This file contains the header for the linked class
***********************************************************************************/
#include "Linked.hpp"


Linked::Linked() {
	prev = nullptr;
	current = new Jungle;
	boardList.push_back(current);
}

Linked::~Linked() {
	for (Space* temp : boardList) {
		delete temp;
	}
}

void Linked::addNorth() {
	int type = determineSpace();		//determine what derived type of space is going to be created
	if (type == 2) {
		Space* jungle = new Jungle(nullptr, current, nullptr, nullptr);
		prev = current;				//update prev
		prev->setTop(jungle);		//link prev to current
		current = jungle;			//set new current
		boardList.push_back(jungle);	//add to vector for destructor
	}
	else if(type == 1 && haveIdolSpace == false){		//use bool flag to only create one Idol space
		Space* idol = new Idol(nullptr, current, nullptr, nullptr);
		prev = current;
		prev->setTop(idol);
		current = idol;
		haveIdolSpace = true;
		boardList.push_back(idol);
	}
	else {
		Space* jungle = new Jungle(nullptr, current, nullptr, nullptr);
		prev = current;
		prev->setTop(jungle);
		current = jungle;
		boardList.push_back(jungle);
	}
	numSteps++;
}

void Linked::addSouth() {
	int type = determineSpace();
	if (type == 2) {
		Space* jungle = new Jungle(current, nullptr, nullptr, nullptr);
		prev = current;
		current = jungle;
		prev->setBottom(current);
		boardList.push_back(jungle);
	}
	else if (type == 1 && haveIdolSpace == false) {
		Space* idol = new Idol(current, nullptr, nullptr, nullptr);
		prev = current;
		current = idol;
		prev->setBottom(current);
		haveIdolSpace = true;
		boardList.push_back(idol);
	}
	else {
		Space* jungle = new Jungle(current, nullptr, nullptr, nullptr);
		prev = current;
		current = jungle;
		prev->setBottom(current);
		boardList.push_back(jungle);
	}
	numSteps++;
}

void Linked::addWest() {
	int type = determineSpace();
	if (type == 2) {
		Space* jungle = new Jungle(nullptr, nullptr, current, nullptr);
		prev = current;
		current = jungle;
		prev->setLeft(current);
		boardList.push_back(jungle);
	}
	else if (type == 1 && haveIdolSpace == false) {
		Space* idol = new Idol(nullptr, nullptr, current, nullptr);
		prev = current;
		current = idol;
		prev->setLeft(current);
		haveIdolSpace = true;
		boardList.push_back(idol);
	}
	else {
		Space* jungle = new Jungle(nullptr, nullptr, current, nullptr);
		prev = current;
		current = jungle;
		prev->setLeft(current);
		boardList.push_back(jungle);
	}
	numSteps++;
}

void Linked::addEast() {
	int type = determineSpace();
	if (type == 2) {
		Space* jungle = new Jungle(nullptr, nullptr, nullptr, current);
		prev = current;
		current = jungle;
		prev->setRight(current);
		boardList.push_back(jungle);
	}
	else if (type == 1 && haveIdolSpace == false) {
		Space* idol = new Idol(nullptr, nullptr, nullptr, current);
		prev = current;
		current = idol;
		prev->setRight(current);
		haveIdolSpace = true;
		boardList.push_back(idol);
	}
	else {
		Space* jungle = new Jungle(nullptr, nullptr, nullptr, current);
		prev = current;
		current = jungle;
		prev->setRight(current);
		boardList.push_back(jungle);
	}
	numSteps++;
}

Space* Linked::getCurrent() {
	return current;
}

void Linked::setCurrent(Space* next) {
	current = next;
}

void Linked::setPrev(Space* prev) {
	this->prev = prev;
}

int Linked::determineSpace() {
	if (numSteps <= 6) {	//if number of spaces is less than or equal to 6, don't make a temple space
		return 2;
	}
	else {					//once six spaces have been made, then equal chance to make jungle/idol
		Die one(2);
		return one.rollDie();
	}
}

Space* Linked::getPrev() {	//function to return the previous space for use in the destructor
	return prev;
}