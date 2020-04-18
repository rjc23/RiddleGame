#include <iostream>
#include <string>
#include <cstdlib>
#include "animal.h"
#include "dog.h"
#include "cat.h"
#include "mouse.h"
#include "riverbank-array-two.h"

using namespace std;



//********** PAUSE Function **********//

void pause(int dur)
{
	int temp = time(NULL) + dur;
	while(temp > time(NULL));
}

//********** start Function **********//

void start()
{
	string dots = ".";
	// run 3 frames of 'loading animation'
	for (int i = 0; i < 3; i++)
	{
		system("clear");
		cout << "Game starting" << dots << endl << endl;
		dots.append(".");
		pause(1);
	}
}


//********** Introduction Function **********//


void intro()
{
	system("clear");
	// print introduction & rules to game.
	cout << "Welcome to the Riverbank Riddle" << endl << endl;
	cout << "The Riddle:" << endl; 
	cout << "A man has to take a dog, a cat, and a mouse across a river. He can only take one of the animals across at a time. If he takes the mouse, the dog will eat the cat. If he takes the dog, the cat will eat the mouse." << endl << endl << endl;
	
	// ask the player if they want to play the game?
	cout << "Continue: (y/n)" << endl;
	char beginGameInput = 'g';
	// as long as the player hasn't answered
	while(beginGameInput != 'y' || beginGameInput != 'n')
	{
		if (beginGameInput == 'y')
			break;

		if (beginGameInput == 'n')
		{
			cout << "too bad - you're playing!" << endl;
			pause(3);
			beginGameInput= 'y';
			break;
		}
	cin >> beginGameInput;
	}

	system("clear");
	cout << "How does he get the three animals across the river?" << endl;
	pause(5);
	system("clear");
}


//********** return ID Function **********//

// this function will take a user's input string and return an integer.
	// will accept any casing
	// 1 = dog; 2 = cat; 3 = mouse; 4 = successful_pass; 99 = failed_entry
int returnID(string word)
{
	// length of the word that was passed in
	int len = word.length();
	// Number of 'valid words' (pass is counted as an animal here)
	const int noOfAnimals = 4;
	// string of all 'valid words'
	string animals[noOfAnimals] = {"dog", "cat", "mouse", "pass"};
	// different counters needed
	int counter;
	int animalID = 1;

	// iterate over every word in the animals[] array
	for (int k = 0; k < noOfAnimals; k++)
	{
		counter = 0;

		// if the length of the word passed in matches the length of the k'th animal in the animals array 
		if (len == animals[k].length())
		{
			// for each character in the word...
			for (int i = 0; i < len; i++)
			{
				// if any letter in the word entered is uppercase, change it to lowercase
				if (isupper(word[i]))
				{
					word[i] = tolower(word[i]);
				}

				// if any character in the word passed in does not match the character in the word of the animals array, then the counter increases by 1
				if (word[i] != animals[k][i])
				{
					counter++;
				}
			}

			// if the word matches the word that is in the array, return animalID
			if (counter == 0)
			{
				return animalID;
			}
		}

		// animalID + 1 as we are moving onto the next animal in the array
		animalID++;
	}
	// if input doesn't match any valid word, return 99
	return 99;
}



//********** Move Animal Functions **********//

// function to move boat from 1 bank to another and move an animal (if any)
bool checkIfMoveIsValid(string playerInput, int* boatPosition, riverbank* leftBank, riverbank* rightBank, animal* adding)
{
	// 4 runs, since for valid words (cat, dog, mouse, pass)...
	for(int i = 1; i <= 4; i++)
	{
		// if a valid word...
		if(returnID(playerInput) == i)
		{
			// pass is always a legal move...
			if(i == 4)
				return true;

			// else, if not a pass, if is boat is on the left AND the animal entered is on the left bank, then return true
			else if (*boatPosition == 0 && leftBank->checkIfExists(adding) == true)
				return true;

			// else, do the same test for right bank
			else if (*boatPosition == 1 && rightBank->checkIfExists(adding) == true)
				return true;
		}
	}

	// any other possibility, declare move as illigal
	return false;
}

void moveAnimalSuccess(string playerInput, int* boatPosition, riverbank* leftBank, riverbank* rightBank, animal* adding)
{
	// 4 runs, since for valid words for this case (cat, dog, mouse, pass)...
	for(int i = 1; i <= 4; i++)
	{
		//if a valid word...
		if(returnID(playerInput) == i)
		{
			// if is on left move those animals
			if (*boatPosition == 0)
			{
				// if entered cat/dog/mouse, swap the bank the animal is on...
				if(i != 4 && leftBank->checkIfExists(adding) == true)
				{
					leftBank->removeAnimal(adding);
					rightBank->addAnimal(adding);
				}

				// then, as long as any valid input (inc. pass) was given, move the boat to the other side.
				 *boatPosition = 1;
			}

			// else, the boat must be on right bank...
			else if (*boatPosition == 1)
			{
				// if entered cat/dog/mouse, swap the bank the animal is on...
				if(i != 4 && rightBank->checkIfExists(adding) == true)
				{
					leftBank->addAnimal(adding);
					rightBank->removeAnimal(adding);
				}

				// then, as long as any valid input (inc. pass) was given, move the boat to the other side.
				*boatPosition = 0;
			}
		}
	}
}

void moveAnimalFail(string playerInput, int* boatPosition, riverbank* leftBank, riverbank* rightBank, animal* adding)
{
	// 3 runs, since for valid words for this case (cat, dog, mouse)...
	for(int i = 1; i <= 3; i++)
	{
		//if a valid word...
		if(returnID(playerInput) == i)
		{
			// if is on left move those animals
			if (*boatPosition == 0 && leftBank->checkIfExists(adding) == false)
			{
				cout << "The " << adding->getSpecies() << " is on the other bank." << endl;
				pause(2);
			}

			// else, the boat must be on right bank...
			else if (*boatPosition == 1 && rightBank->checkIfExists(adding) == false)
			{
				cout << "The " << adding->getSpecies() << " is on the other bank." << endl;
				pause(2);
			}
		}
	}
}

//********** All Boat Functions **********//

// increase distance from left side of screen
string extend(string a)
{
	a.append("       ");
	return a;
}
// decrease distance from left side of screen
string remove(string a)
{
	a.erase(1, 7);
	return a;
}


// boat docked on left bank drawing
void initialBoat()
{
	cout << "     Left Riverbank       Right Riverbank" << endl << endl;
	cout  << "            |"<< endl;
	cout  << "           /|        "<< endl;
	cout  << "          / |\\"<< endl;
	cout  << "         /  | \\"<< endl;
	cout  << "        /   || \\"<< endl;
	cout  << "       /    | | \\"<< endl;
	cout  << "      /     | |  \\"<< endl;
	cout  << "     /      | |   \\"<< endl;
	cout  << "    /       ||     \\"<< endl;
	cout  << "   /        /       \\"<< endl;
	cout  << "  /________/         \\"<< endl;
	cout  << "  ________/_________--/"<< endl;
	cout  << "  \\                  /"<< endl;
	cout  << "   \\________________/"<< endl << endl;
}

// boat docked on right bank drawing; used when *boatPosition == 1

void rightBoat()
{
	cout << "     Left Riverbank       Right Riverbank" << endl << endl;
	cout  << "                                 |"<< endl;
	cout  << "                                /|        "<< endl;
	cout  << "                               / |\\"<< endl;
	cout  << "                              /  | \\"<< endl;
	cout  << "                             /   || \\"<< endl;
	cout  << "                            /    | | \\"<< endl;
	cout  << "                           /     | |  \\"<< endl;
	cout  << "                          /      | |   \\"<< endl;
	cout  << "                         /       ||     \\"<< endl;
	cout  << "                        /        /       \\"<< endl;
	cout  << "                       /________/         \\"<< endl;
	cout  << "                       ________/_________--/"<< endl;
	cout  << "                       \\                  /"<< endl;
	cout  << "                        \\________________/"<< endl << endl;
}


// moving boat drawing; includes drawing animal sound of the animal currently in boat (ie adding)

void boat(int location, animal* adding)
{
	string a;               // spacing variable (distance from left)
	int frameCounter = 1;        // counter so that every second frame makes sound, not every frame

	// depending on side the boat starts on, set the appropriate spacing variable
	if(location == 1)
		a = " ";
	else if (location == 0)
		a = "                      ";

	// for 4 frames...
	for(int i = 0; i < 4; i ++)
	{
		// clear ready for new frame
		system("clear");
		// draw the start of the boat
		cout << "     Left Riverbank       Right Riverbank" << endl << endl;
		cout <<  a << "           |"<< endl;
		cout <<  a << "          /|        "<< endl;
		cout <<  a << "         / |\\"<< endl;
		cout <<  a << "        /  | \\"<< endl;
		cout <<  a << "       /   || \\"<< endl;
		cout <<  a << "      /    | | \\"<< endl;
		cout <<  a << "     /     | |  \\"<< endl;
		cout <<  a << "    /      | |   \\"<< endl;
		cout <<  a << "   /       ||     \\"<< endl;
		cout <<  a << "  /        /       \\"<< endl;
		cout <<  a << " /________/         \\"<< endl;
		cout <<  a << " ________/_________--/"<< endl;
		cout <<  a << " \\    ";
		// if animal inside the boat isn't the blank/pass, then print the animal sound every 2 frames
		if(adding->getInitial() != 'b')
		{
			if(frameCounter%2 == 0)
				cout << adding->makeSound(2) << "!";
			else 
				cout << "          ";
		}

		// else the boat is on a pass run (containing blank), then just use normal boat interior
		else
			cout << "          ";

		// regardless of above, finish drawing boat
		cout << "    /"<< endl;
		cout <<  a << "  \\________________/"<< endl;

		// depending on what direction the boat is moving, adjust the spacing variable
		if(location == 1)
			a = extend(a);
		if(location == 0)
			a = remove(a);

		// before moving onto next 'frame' increase the frameCounter & pause
		frameCounter++;
		pause(1);
	}
}



//********** Print Bank Status **********//

void printBankStatus(riverbank* leftBank, riverbank* rightBank, int * boatPosition)
{
	// draw the boat on the appropriate bank
	if(*boatPosition == 0)
		initialBoat();
	else if (*boatPosition == 1)
		rightBoat();

	// print left bank info
		if (leftBank->countAnimals() == 1)
			cout << "There is " << leftBank->countAnimals() << " animal ";
		else
			cout << "There are " << leftBank->countAnimals() << " animals ";; 

		cout << "on the Left Bank." << endl;
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
				cout << "They are the ";
			}
			// regardless, list the animal(s)
			leftBank->printBankStatus();
		}
		cout << endl;

	// print left bank info
		if (rightBank->countAnimals() == 1)
			cout << "There is " << rightBank->countAnimals() << " animal ";
		else
			cout << "There are " << rightBank->countAnimals() << " animals ";; 

		cout << "on the Right Bank." << endl;

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
				cout << "They are the ";
			}
			// regardless, list the animal(s)
			rightBank->printBankStatus();
		}
		cout << endl;

}


//********** check if there is a losing combination Function **********//
//i.e. the dog and the cat are together and the boat is on the opposite riverbank

// check if a game losing combination two animals on the OPPOSITE bank than the player would eat each other
bool checkIfLosingCombo(riverbank* leftBank, riverbank* rightBank, dog* puppy, cat* kitten, int* boatPosition)
{
	// if those 2 animals on opposite bank are cat+dog (returns 1 from checkPrey)
	if ((leftBank->checkPrey() == 1 && *boatPosition == 1) || (rightBank->checkPrey() == 1 && *boatPosition == 0))
		return true;

	// else if those 2 animals on opposite bank are cat+dog (returns 1 from checkPrey)
	else if ((leftBank->checkPrey() == 2 && *boatPosition == 1) || (rightBank->checkPrey() == 2 && *boatPosition == 0))
		return true;

	// otherwise, this is not a gameOver and return false
	return false;
}

void runLosingCombo(riverbank* leftBank, riverbank* rightBank, dog* puppy, cat* kitten, int* boatPosition)
{
	if ((leftBank->checkPrey() == 1 && *boatPosition == 1) || (rightBank->checkPrey() == 1 && *boatPosition == 0))
	{
		// draw 2 frames of the dog animation
		for(int j = 1; j <=2; j++)
		{
			system("clear");
			puppy->drawAnimal(j);
			pause(1);
		}
		// print game over message
		cout << "You Lose! The dog ate the cat!" << endl;
		pause(2);
	}

	else if ((leftBank->checkPrey() == 2 && *boatPosition == 1) || (rightBank->checkPrey() == 2 && *boatPosition == 0))
	{
		for(int j = 1; j <=2; j++)
		{
			system("clear");
			kitten->drawAnimal(j);
			pause(1);
		}
		// print game over message
		cout << "You Lose! The cat ate the mouse!" << endl;
		pause(2);
	}

	// // tossed immediate pass = lose

	// else if ((leftBank->checkPrey() == 3 && *boatPosition == 1) || (rightBank->checkPrey() == 3 && *boatPosition == 0))
	// {
	//     for(int j = 1; j <=2; j++)
	//     {
	//         system("clear");
	//         kitten->drawAnimal(j);
	//         pause(1);
	//     }
	//     cout << "The cat ate the mouse!" << endl;
	//     pause(1);

	//     for(int j = 1; j <=2; j++)
	//     {
	//         system("clear");
	//         puppy->drawAnimal(j);
	//         pause(1);
	//     }
	//     cout << "The dog ate the cat!" << endl;
	//     pause(1); 

	//     cout << "You Lose! The cat ate the mouse then the dog ate the cat!" << endl;
	//     return true;
	// }
}

//********** Animal to Add Function **********//


// basically uses the input from the player and returns the animal it corresponds to
animal* animalToAdd(string playerInput, animal* puppy, animal* kitten, animal* stuart, animal* blank)
{
	if(returnID(playerInput) == 1)
		return puppy;
	else if(returnID(playerInput) == 2)
		return kitten;
	else if (returnID(playerInput) == 3)
		return stuart;
	else
		return blank; // placeholder, shouldn't use this value but guantees an 'adding' for proceeding function
} 

void endGame(animal** riverbank)
{
	system("clear");

	pause(1);
	cout<<"OHH SHIT!! DID YOU JUST WIN??"<<endl;
	pause(2);
	system("clear");
	cout<<"Seems like you actually transported the animals, without the animals eating each other!!!"<<endl;
	pause(2);
	cout<<endl;
	cout<<"CONGRATULATIONS!!"<<endl;
	cout<<endl;
	pause(2);
	cout<<"The following animals on the other side of the river bank are:"<<endl;
	pause(3);

	// play animations of all 3 animals
	for(int i = 0; i < 3; i++)
	{
		// draw 2 frames
		for(int j = 1; j <=2; j++)
		{
			system("clear");
			cout << "A " << riverbank[i]->getSpecies() << endl << endl;
			riverbank[i]->drawAnimal(j);
			pause(1);
		}
	}
}


//********** TERMINATION **********//

// deleting memory allocated
void clearMemory(cat* kitten, dog* puppy, mouse* stuart, int* boatPosition, riverbank* leftBank, riverbank* rightBank, dog* blank)
{
	delete kitten;
	delete puppy;
	delete stuart;
	delete boatPosition;
	delete leftBank;
	delete rightBank;
	delete blank;
}
