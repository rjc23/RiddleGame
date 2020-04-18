// console compile line:
	// WITHOUT BOAT
	//g++ -o testGame main-game.cpp animal.cpp cat.cpp dog.cpp mouse.cpp riverbank-array-two.cpp extraFunctions.cpp 
	// WITH BOAT
	// g++ -o testGame main-game.cpp animal.cpp cat.cpp dog.cpp mouse.cpp riverbank-array-two.cpp extraFunctions.cpp boat.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include "animal.h"
#include "dog.h"
#include "cat.h"
#include "mouse.h"
#include "riverbank-array-two.h"

using namespace std;

extern int returnID(string word);
extern void moveAnimal(string playerInput, int* boatPosition, riverbank* leftBank, riverbank* rightBank, animal* adding);
extern void pause(int dur);
extern void boat(int location);
extern void initialBoat();
extern void playEnd(animal** a, )

int main(void)
{
//********** INITIALIZATION **********//
	// create animals
		cat* kitten = new cat;
		dog* puppy = new dog;
		mouse* stuart = new mouse;

	// create banks
		riverbank *leftBank = new riverbank;
		leftBank->initialiseNULL();
		leftBank->addAnimal(kitten);
		leftBank->addAnimal(puppy);
		leftBank->addAnimal(stuart);

		riverbank *rightBank = new riverbank;
		rightBank->initialiseNULL();

	// other initializations
		animal* adding;			// animal we are moving after player enters an input
		// bool gameOver = false;	// don't need, can remove later
		string playerInput;
		// 0 = boat on leftBank, 1 = boat on rightBank	//	can only add an animal to opposite bank and remove from current bank
		int* boatPosition = new int;	
		*boatPosition = 0;
	
	

//********** PLAY THE GAME **********//
	system("clear");
	cout << "Game starting..." << endl << endl;
	pause(2);
	system("clear");
	initialBoat();
	// each run of this loop is a "turn"
	while(rightBank->checkBank() == false)	// check if a gameOver
	{
		// at the beginning of each "turn", reset the playerInput (prevent looping an animal)
		playerInput = "null";

		// print game status
			// print left bank info
				cout << "There are " << leftBank->countAnimals() << " animals on the Left Bank. ";
				// if there is at least 1 animal on the bank...
				if(leftBank->countAnimals() != 0)
				{
					// if there is exactly 1 animal...
					if(leftBank->countAnimals() == 1)
					{
						cout << "It is the ";
					}
					// if there are 1+ animals...
					else
					{
						cout << "They are ";
					}
					// regardless, list the animal(s)
					leftBank->printBankStatus();
				}
				cout << endl;

			// print right bank info
				cout << "There are " << rightBank->countAnimals() << " animals on the Right Bank. ";
				// if there is at least 1 animal on the bank...
				if(rightBank->countAnimals() != 0)
				{
					// if there is exactly 1 animal...
					if(rightBank->countAnimals() == 1)
					{
						cout << "It is the ";
					}
					// if there are 1+ animals...
					else
					{
						cout << "They are ";
					}
					// regardless, list the animal(s)
					rightBank->printBankStatus();
				}
				cout << endl;

			// print/draw boat info
				cout << "The boat is currently on the ";
				if(*boatPosition == 0)
				{
					cout << "Left Bank." << endl;
				}
				else
				{
					cout << "Right Bank." << endl;
				}

			cout << endl;



		// give user a chance for input
			cout << "Type an animal name to place that animal into the boat and send it to the other side, or PASS to move an empty boat." << endl;
			// while an invalid input
			while(returnID(playerInput) == 99)
			{	
				//geting input from the user
				cin >> playerInput;

				//if the player has given a valid input, proceed
				if(returnID(playerInput) != 99)
				{
					if(returnID(playerInput) == 1)
						adding = puppy;
					else if(returnID(playerInput) == 2)
						adding = kitten;
					else if (returnID(playerInput) == 3)
						adding = stuart;
					else if (returnID(playerInput) == 4)
						adding = stuart;	// placeholder, shouldn't use this value but gauntees an 'adding' for proceeding function

					moveAnimal(playerInput, boatPosition, leftBank, rightBank, adding);
					boat(*boatPosition);
				}
				//else if still invalid after input, display message.
				else
				{
					cout << playerInput << " is an invalid input. Try again." << endl;
				}
			}
		

		// check if a game winning or losing combination (ie gameover) OR if game will go for another turn/loop

			// TEST ONLY - force gameOver after 1 move
				//gameOver = true;

	}

	cout << endl << "Game closing..." << endl;

	playEnd(rightBank->returnArray(), )



//********** TERMINATION **********//
	//deleting memory allocated
	delete kitten;
	delete puppy;
	delete stuart;
	delete boatPosition;
	delete leftBank;
	delete rightBank;
	return 0;
}
