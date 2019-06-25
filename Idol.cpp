/**********************************************************************************
** Program Name: Final Project
** Author: Kevin Allen
** Date: 3/12/2018
** Description: This file contains the function definitions for the idol space class
***********************************************************************************/
#include "Idol.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int Idol::jungleMenu() {
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

void Idol::interact() {
	cout << "You are surrounded by jungle with many hidden places to search, " << endl;
	cout << "although this particular place seems oddly familiar." << endl;			
	Die tenDie(10);				//roll die to determine results of search
	int luck = 0;
	int decision;
	bool locateIdol = false;
	do {
		decision = jungleMenu();
		if (decision != 4) {
			if (searchCount == 2 && locateIdol == false) {		//make sure that idol is found, if other two locations have been checked
				cout << "You have found the Idol!" << endl;
				cout << "Now find your way to the temple!" << endl << endl;
				results[3] = 1;
				break;
			}
			if (searchAreas[decision - 1] != 1) {	//check if area has already been searched
				luck = tenDie.rollDie();		//roll die to determine search results
				if (luck == 1) {
					cout << "You have been cought in a trap!" << endl;
					cout << "By the time you have freed yourself you have expended half you food resources." << endl << endl;
					results[0] += 1;
				}
				else if (luck == 2 || luck == 3) {
					cout << "You have been bitten by a snake!" << endl;
					cout << "As you try to fight off the venom you deplete your food reserves twice as fast." << endl <<endl;
					results[1] += 1;
				}
				else if (luck >= 4 && luck <= 10) {
					if (locateIdol == false) {
						cout << "You have found the Idol!" << endl;
						cout << "Now find your way to the temple!" << endl << endl;
						results[3] = 1;
						locateIdol = true;
					}
					else {
						cout << "You have found nothing." << endl << endl;
					}
				}
				else {
					cout << "You have found nothing." << endl;
					
				}
				searchAreas[(decision - 1)] = 1;	//flag that area as "been searched"
				searchCount++;
			}
			else {
				cout << "You have already searched that area" << endl << endl;
			}
		}
	} while (decision != 4);
}


Idol::Idol(Space* top, Space* bottom, Space* right, Space* left) {
	this->top = top;
	this->bottom = bottom;
	this->right = right;
	this->left = left;
}

Idol::Idol() {
	top = nullptr;
	bottom = nullptr;
	right = nullptr;
	left = nullptr;
}