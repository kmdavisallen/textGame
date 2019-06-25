/**********************************************************************************
** Program Name: Final Project
** Author: Kevin Allen
** Date: 3/12/2018
** Description: This file contains the function definitions for the jungle space class
***********************************************************************************/

#include "Jungle.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int Jungle::jungleMenu() {
	string choice;
	
	cout << "Would you like to search :" << endl;
	cout << "1. Under a large rock." << endl;
	cout << "2. Behind the fallen tree." << endl;
	cout << "3. Within the tangled vines." << endl;
	cout << "4. Continue through the jungle." << endl << endl;
	cin >> choice;
	
	while (1) {
		int valid = isValidInt(choice);
		if (valid >= 1 && valid <= 4) {
			return valid;
		}
		else {
			cout << "Please enter a valid integer" << endl;
			cin >> choice;
		}
	}
		
}

void Jungle::interact() {
	cout << "You are surrounded by jungle with many hidden places to search" << endl;
	Die tenDie(10);
	int luck = 0;
	int decision;
	do {
		decision = jungleMenu();
		if (decision != 4) {
			if (searchAreas[decision - 1] != 1) {	//check if area has been previously searched
				luck = tenDie.rollDie();			//roll the die to determine search results
				if (luck == 1) {
					cout << "You have been cought in a trap!" << endl;
					cout << "By the time you have freed yourself you have expended half you food resources." << endl << endl;
					results[0] += 1;
				}
				else if (luck == 2 || luck == 3) {
					cout << "You have been bitten by a snake!" << endl;
					cout << "As you try to fight off the venom you deplete your food reserves twice as fast." << endl << endl;
					results[1] += 1;
				}
				else if (luck >= 4 && luck <= 6) {
					cout << "You have found a stash of edible plants!" << endl;
					cout << "They have been added to your backpack for future consumption" << endl << endl;
					results[2] += 1;
				}
				else {
					cout << "You have found nothing." << endl << endl;
					
				}
				searchAreas[(decision - 1)] = 1;		//flag the area has having been searched
			}
			else {
				cout << "You have already searched that area" << endl << endl;
			}
		}
	} while (decision != 4);
}


Jungle::Jungle(Space* top, Space* bottom, Space* right, Space* left) {
	this->top = top;
	this->bottom = bottom;
	this->right = right;
	this->left = left;
}

Jungle::Jungle() {
	top = nullptr;
	bottom = nullptr;
	right = nullptr;
	left = nullptr;
}