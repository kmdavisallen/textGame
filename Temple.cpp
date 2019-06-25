/**********************************************************************************
** Program Name: Final Project
** Author: Kevin Allen
** Date: 3/12/2018
** Description: This file contains the function definitions for the temple space class
***********************************************************************************/
#include "Temple.hpp"

using std::cout;
using std::endl;
using std::cin;

int Temple::templeMenu() {
	string choice;
	cout << "You are back at the temple" << endl;
	cout << "If you have the Idol, you may return it and safely leave the jungle" << endl;
	cout << "You may also try to trick the natives by making an Idol from pocket lint and tape." << endl;
	cout << "What would you like to do?" << endl;
	cout << "1. Return the Idol." << endl;
	cout << "2. Attempt to fool the natives. WARNING if they discover your plot you will be offered as a sacrafice" << endl;
	cout << "3. Do nothing and return to the jungle." << endl << endl;

	
	cin >> choice;

	while (1) {
		int valid = isValidInt(choice);
		if (valid >= 1 && valid <= 3) {
			return valid;
		}
		else {
			cout << "Please enter a valid integer" << endl;
			cin >> choice;
		}
	}

}

void Temple::interact() {
	int decision = 0;
	decision = templeMenu();
	if (decision == 1) {		//attempt to return the idol
		results[4] = 1;
	}
	if (decision == 2) {		//attempt to fool natives
		results[5] = 1;
	}
}

Temple::Temple() {
	top = nullptr;
	bottom = nullptr;
	right = nullptr;
	left = nullptr;
}

Temple::Temple(Space* top, Space* bottom, Space* right, Space* left) {
	this->top = top;
	this->bottom = bottom;
	this->right = right;
	this->left = left;
}
