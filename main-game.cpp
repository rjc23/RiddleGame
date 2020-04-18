// console compile line:
	// g++ -o testGame main-game.cpp animal.cpp cat.cpp dog.cpp mouse.cpp riverbank-array-two.cpp extraFunctions.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include "animal.h"
#include "dog.h"
#include "cat.h"
#include "mouse.h"
#include "riverbank-array-two.h"

using namespace std;

extern void start();
extern int returnID(string word);
extern bool checkIfMoveIsValid(string playerInput, int* boatPosition, riverbank* leftBank, riverbank* rightBank, animal* adding);
extern void moveAnimalSuccess(string playerInput, int* boatPosition, riverbank* leftBank, riverbank* rightBank, animal* adding);
extern void moveAnimalFail(string playerInput, int* boatPosition, riverbank* leftBank, riverbank* rightBank, animal* adding);
extern void pause(int dur);
extern void printBankStatus(riverbank* leftBank, riverbank* rightBank, int * boatPosition);
extern animal* animalToAdd(string playerInput, animal* puppy, animal* kitten, animal* stuart, animal* blank);
extern bool checkIfLosingCombo(riverbank* leftBank, riverbank* rightBank, dog* puppy, cat* kitten, int* boatPosition);
extern void runLosingCombo(riverbank* leftBank, riverbank* rightBank, dog* puppy, cat* kitten, int* boatPosition);
extern void clearMemory(cat* kitten, dog* puppy, mouse* stuart, int* boatPosition, riverbank* leftBank, riverbank* rightBank, dog* blank);
extern void boat(int location, animal* adding);
extern void initialBoat();
extern void rightBoat();
extern void intro();
extern void endGame(animal** a);

int main(void)
{
//********** INITIALIZATION **********//

// create animals
	cat* kitten = new cat;
	dog* puppy = new dog;
	mouse* stuart = new mouse;
	dog* blank = new dog;
	// blank animal used for passing; is a subclass since parent is pure virtual
		blank->setInitial('b');
		blank->setSpecies("blank animal");
	animal* adding;	// animal we are moving after player enters an input

// create riverbanks
	riverbank *leftBank = new riverbank;
	leftBank->initialiseNULL();
	leftBank->addAnimal(kitten);
	leftBank->addAnimal(puppy);
	leftBank->addAnimal(stuart);

	riverbank *rightBank = new riverbank;
	rightBank->initialiseNULL();

// other initializations
	string playerInput;
	int* boatPosition = new int(0);	// 0 = left, 1 = right
	

//********** PLAY THE GAME **********//

	// clearing the screen and starting the game; draw set up and rules
	start();
	intro();

	// Game will run until there are 3 animals in the right riverbank; each run of this while loop is a 'turn'
	while(rightBank->checkBank() == false)
	{
		//clears the screen 
		system("clear");

		// at the beginning of each "turn", reset the playerInput (prevent looping an animal)
		playerInput = "null";

		// print game status - what animals are on each bank + where the boat is
		printBankStatus(leftBank, rightBank, boatPosition);

		// give user a chance for input
		cout << "Which animal do you want to move? Type 'pass' to just move the boat: ";

		// while the input is invalid, keep trying to get input
		while(returnID(playerInput) == 99)
		{	
			// get input from the user
			cin >> playerInput;

			// if the player has given a valid input...
			if(returnID(playerInput) != 99)
			{
				// based on player input, store player choice as adding for it to be moved
				adding = animalToAdd(playerInput, puppy, kitten, stuart, blank);

				// if moving animal is possible, do it, then draw the boat animation
				if (checkIfMoveIsValid(playerInput, boatPosition, leftBank, rightBank, adding) == true)
				{
					moveAnimalSuccess(playerInput, boatPosition, leftBank, rightBank, adding);
					boat(*boatPosition, adding); //play the boat animation
				}
				// if not possible, explain why...
				else
					moveAnimalFail(playerInput, boatPosition, leftBank, rightBank, adding);// -- insert 'moveAnimal' function -- // -- existing 'moveAnimal' should be 'checkIfMoveIsValid' -- //

				// Check if action just done results in a game over; e.g. The cat and the mouse are together but the boat is on the otherside
				if (checkIfLosingCombo(leftBank, rightBank, puppy, kitten, boatPosition) == true)
				{
					runLosingCombo(leftBank, rightBank, puppy, kitten, boatPosition);
					// clear memory & break out of game
					clearMemory(kitten, puppy, stuart, boatPosition, leftBank, rightBank, blank);
					cout << endl << "Game closing..." << endl;
					return 0;
				}	
			}

			// else if still invalid after input, display message.
			else
			{
				cout << playerInput << " is an invalid input. Try again." << endl;
				pause(2);
				break;
			}
		}
	}

	// ending game with animations
	endGame(rightBank->returnArray()); 
	cout << endl << "Game closing..." << endl;



//********** TERMINATION **********//
	clearMemory(kitten, puppy, stuart, boatPosition, leftBank, rightBank, blank);
	return 0;
}
