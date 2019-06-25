/*********************************************************************
** Program Name: Utility functions
** Author: Kevin Allen
** Date: 1/13/2018
** Description: This file is for menus and input validation
***********************************************************************/
#include <string>
#include <sstream>
#include <iostream>
#include "Utilities.hpp"



using std::string;
using std::cout;
using std::endl;
using std::stringstream;
using std::cin;

int isValidInt(string test) { //adapted from ari-free on stackoverflow.com
	int validInt;
	while (1) {
		stringstream myStream(test);
		if ((myStream >> validInt)) {
			return validInt;
		}
		cout << "Please enter a vaild integer" << endl;
		cin >> test;
	}
}

int playAgainMenu(){
	
	string choice;
	cout << "Would you like to play again?" << endl;
	cout << " 1: Play agin" << endl;
	cout << " 2: Exit" << endl;
	
	while (1) {
		cin >> choice;
		int validChoice = isValidInt(choice);
		if (validChoice >= 1 && validChoice <= 2) {
			return validChoice;
		}
		else {
			cout << "Please enter a vaild integer" << endl;
		}
	}
}

int userValue() {
	cout << "Please enter an integer" << endl;
	string tempVar;
	while (1) {
		cin >> tempVar;
		int valid = isValidInt(tempVar);
		if (valid >= -2147483647 && valid <= 2147483647) {
			return valid;
		}
		else {
			cout << "Please enter a valid integer" << endl;
		}
	}
}



