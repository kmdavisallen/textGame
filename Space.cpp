/**********************************************************************************
** Program Name: Final Project
** Author: Kevin Allen
** Date: 3/12/2018
** Description: This file contains the function definitions for the space class
***********************************************************************************/
#include <iostream>
#include "Space.hpp"

Space* Space::getTop() {
	return top;
}

Space* Space::getBottom() {
	return bottom;
}

Space* Space::getLeft() {
	return left;
}
Space* Space::getRight() {
	return right;
}

void Space::setTop(Space* newTop) {
	this->top = newTop;
}

void Space::setBottom(Space* bottom) {
	this->bottom = bottom;

}
void Space::setLeft(Space* left) {
	this->left = left;
}

void Space::setRight(Space* right) {
	this->right = right;
}

int* Space::getResults() {
	return results;
}



