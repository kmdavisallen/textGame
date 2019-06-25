/**********************************************************************************
** Program Name: Final Project
** Author: Kevin Allen
** Date: 2/14/2018
** Description: This file contains the implementation for the game class
***********************************************************************************/
#include "Game.hpp"

using std::cout;
using std::endl;
using std::cin;

void Game::moveUp() {
	if (!board.getCurrent()->getTop()) {		//Check if the "space" already exists
		board.addNorth();						//if not, then make a space
	}
	else {
		board.setPrev(board.getCurrent());			//set current space to previous
		board.setCurrent(board.getCurrent()->getTop());	//set upper space to current
		
	}
	board.getCurrent()->interact();
}

void Game::moveDown() {
	if (!board.getCurrent()->getBottom()) {
		board.addSouth();
	}
	else {
		board.setPrev(board.getCurrent());
		board.setCurrent(board.getCurrent()->getBottom());
	}
	board.getCurrent()->interact();
}

void Game::moveLeft() {
	if (!board.getCurrent()->getLeft()) {
		board.addWest();
	}
	else {
		board.setPrev(board.getCurrent());
		board.setCurrent(board.getCurrent()->getLeft());
	}
	board.getCurrent()->interact();
}

void Game::moveRight() {
	if (!board.getCurrent()->getRight()) {
		board.addEast();
	}
	else {
		board.setPrev(board.getCurrent());
		board.setCurrent(board.getCurrent()->getRight());
	}
	board.getCurrent()->interact();
}

void Game::gameIntro() {
	cout << "You awake with a splitting headache on a cold stone floor. " << endl;
	cout << "There is a small, angry man sitting beside you as you get up and look around." << endl;
	cout << "As you get to your feet he exclaims 'About time you woke up!'" << endl;
	cout << "'You had better hurry up and find it if you plan on getting out of here alive.'" << endl;
	cout << " The man disappears back into the temple, leaving you with your thoughts" << endl;
	cout << "Your memory slowly comes back and you recall having stumbled upon an ancient temple in the jungle " << endl;
	cout << "populated with a native tribe.  They invited you to dinner and during the feast you drank some strange liquid." << endl;
	cout << "As the night went on, intoxicated, you took one of their sacred idols into the jungle and lost it." << endl;
	cout << "You must now wander the jungle, find the idol,and return it to the temple before you run out of food! " << endl;
	cout << "Keep an eye out for edable plants as well as dangerous snakes and traps!" << endl <<endl;
	cout << "WARNING: The jungle is very dense, if you do not return along the same path you left " << endl;
	cout << " you will be lost FOREVER!" << endl << endl;
}

int Game::moveMenu() {
	cout << "Which direction would you like to travel?" << endl;
	cout << "1. North" << endl;
	cout << "2. East" << endl;
	cout << "3. South" << endl;
	cout << "4. West" << endl;
	cout << "5. Consume some food" << endl;
	string choice;
	cin >> choice;
	while (1) {
		int valid = isValidInt(choice);
		if (valid >= 1 && valid <= 5) {
			return valid;
		}
		else {
			cout << "Please enter a valid integer" << endl;
			cin >> choice;
		}
	}

}

int Game::getStarveTimer() {
	return starvationTimer;
}

void Game::makeMove() {
	int direction = moveMenu();
	switch (direction) {
	case 1:	moveUp();
		break;
	case 2: moveRight();
		break;
	case 3: moveDown();
		break;
	case 4: moveLeft();
		break;
	case 5: eat();
	}
	starvationTimer = starvationTimer - starveMultiplier;
	cout << "You have " << getStarveTimer() << " moves left until you starve." << endl;
}

void Game::eat() {			//reset starvation timer
	bool hasFood = false;
	for (int i = backpackIndex; i >= 0; i--) {		//check if there is food in the backpack
		if (backpack[i] == 1) {
			starvationTimer = 20;					//reset the timer
			backpack[i] = 0;						//set backpack location to 0 
			backpackIndex--;						//decrement the index
			cout << "You have replenished you energy and are ready to resume the search." << endl;
			hasFood = true;
			break;
		}
	}
	if (hasFood == false) {
		cout << "You do not have any food in your backpack." << endl;
	}
}

void Game::interactRes() {			//process the results of interacting with space
	bool haveIdol = false;
	if (board.getCurrent()->getResults()[0] >= 1) {		//if  caught in trap, half remaining time
		starvationTimer = starvationTimer/(board.getCurrent()->getResults()[0]*2);
	}
	if (board.getCurrent()->getResults()[1] >= 1) {		//if bit by snake, double time expendature per move
		starveMultiplier = starveMultiplier * (2*board.getCurrent()->getResults()[1]);
	}
	if (board.getCurrent()->getResults()[2] >= 1) {		//if found food, add to backpack
		for (int i = 0; i < board.getCurrent()->getResults()[2]; i++) {
			if (backpackIndex <= 5) {
				backpack[backpackIndex] = 1;
				backpackIndex++;
			}
			else {
				cout << "Your backpack is full" << endl;
			}
		}
	}
	if (board.getCurrent()->getResults()[3] == 1) {	//if found idol, add to backpack
		if (backpackIndex <= 5) {
			backpack[backpackIndex] = 42;
			backpackIndex++;
		}
		else {
			cout << "Your backpack is full, you must drop an item" << endl;	
			backpackIndex--;				//"drop" and item if backpack is full
			backpack[backpackIndex] = 42;	//add the idol
			backpackIndex++;
		}
	}
	if (board.getCurrent()->getResults()[4] == 1) {		//temple specific results
		for (int i = 0; i <= backpackIndex; i++) {		//check if idol is in backpack
			if (backpack[i] == 42) {
				haveIdol = true;
			}
		}
		if (haveIdol == true) {
			cout << "The head shaman thanks you for returning the idol, and leads you out of the jungle.";
			gameWin = true;
		}
		else {
			cout << "You do not have the Idol, you must return to the jungle to search." << endl;
		}
	}
	if (board.getCurrent()->getResults()[5] == 1) {		//attempt to fool natives with fake idol
		Die bigDie(100);
		int luck = bigDie.rollDie();
		if (luck == 100) {					// 1 in 100 chance to fool
			cout << "You have sucessfully fooled the natives! " << endl;
			cout << "The head shaman thanks you for returning the idol, and leads you out of the jungle.";
			gameWin = true;
		}
		else {
			cout << "The natives are not amused with your shabby attempts to trick them." << endl;
			cout << "They have thrown you in a bottomless pit, never to be heard from again." << endl;
			gameLose = true;
		}
	}
	
	for (int i = 0; i < 6; i++) {		//reset the array for each space
		board.getCurrent()->getResults()[i] = 0;
	}
}

void Game::state() {
	if (starvationTimer <= 0) {
		gameLose = true;
	}

	if (gameWin == true) {
		cout << "You have won the game!" << endl;
	}

	if (gameLose == true) {
		cout << "You have lost." << endl;
		
	}
}

bool Game::getGameWin() {
	return gameWin;
}

bool Game::getGameLose() {
	return gameLose;
}