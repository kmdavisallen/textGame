/*********************************************************************
** Program Name: Lab 3
** Author: Kevin Allen
** Date: 1/26/2018
** Description: This file contains the header for the die class
***********************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

class Die {
private:
	int N;
public:
	Die(int);
	int rollDie();
	int getSides();

};

#endif
