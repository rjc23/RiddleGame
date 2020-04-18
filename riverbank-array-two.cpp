// ------ // ------ // set-up // ------ // ------ //
#include <string>
#include <iostream>
#include "riverbank-array-two.h"
#include "animal.h"

using namespace std;

// ------ // constructors & destructors // ------ //

riverbank::riverbank()
{
		bankName = new animal*[3];    // array has 3 'slots' for animal objects on the heap
		count = 0;                    // number of animals currently in the object
}

riverbank::~riverbank()
{
	delete [] bankName;  // clear the bank array from the heap
}

// ------ // ------ // getters // ------ // ------ //

// returns the array of the animals
animal** riverbank::returnArray()
{
	return bankName;
}

// checks whether the array has all 3 animals in it (will use with the while loop)
// returns true if all animals are in the array, false if not
// checks that animals are unique using their initils; dog = d cat = c mouse = m
bool riverbank::checkBank()
{
	// if there aren't 3 animal objects in the array - immediately return false
		// 'real animals' != 'animal objects'
	if (count != 3)
	{
		return false;
	}

	// if riverbank's count == 3, set up a counter
		// then, check if each array entry is a 'real animal' object
	int counter = 0;
	for (int i = 0; i < 3; i++)
	{
		if (bankName[i]->getInitial() == 'd' || bankName[i]->getInitial() == 'c' || bankName[i]->getInitial() == 'm') 
		{
			counter++;
		}
	}
	// then, if this counter reached 3 - return true
	if (counter == 3)
	{
		return true;
	}

	// in any other situation, there are not 3 real animals - return false
	return false;
}

// Prints the status of the bank or what is in the array
void riverbank::printBankStatus()
{
	// 'and counter' - finds location for "and" to be written
	int And = 0;

	for (int i = 0; i < 3; i++)
	{
		//if the animal isnt a 'blank' animal...
		if (bankName[i] != NULL)
		{
			// print species name, then increase 'and counter'
			cout << bankName[i]->getSpecies() << " ";
			And++;
			// if there is more than 1 'real animal', place 'and' before the last animal's species
			if((And == (count - 1)) && (count > 1))
			{
				cout << "and ";
			}
		} 
	}
	cout << endl;
}


// Function to check if two animals will eat each other and return a unique int if they do to show which animal ate waht
int riverbank::checkPrey()
{
	// set 'counter' to count the number of 'blank entries' in array
	int counter = 0;
	for (int i = 0; i < 3; i++)
		if (bankName[i] == NULL)
			counter++;

	// if 0 or 1 'real animals' - return 0
	if (counter == 3 || counter == 2)
			return 0;

	// if 3 'real animals' - return 3
	if (counter == 0)
			return 3;

	// remaining possibility is 2 animals - find which two animals are together...
		// store the initials of the 2 animals in this array into 'a' and 'b'
	char a;
	char b;
	int counter2 = 0;
	for (int j = 0; j < 3; j++)
	{
		if (bankName[j] != NULL)
		{
			if (counter2 == 0)
			{
				a = bankName[j]->getInitial();
				counter2++;
			}

			if (counter2 == 1)
			{
				b = bankName[j]->getInitial();
			}
		}
	}

	// if dog and cat are together - return 1 => "dog eats cat"
	if ((a == 'd' && b == 'c') || (a == 'c' && b == 'd'))
		return 1;

	// if mouse and cat are together - return 1 => "cat eats mouse"
	if ((a == 'c' && b == 'm') || (a == 'm' && b == 'c'))
		return 2;

	// any other case returns 0
	return 0;
}

// check if a certain animal is in the array - used to make sure player would take an animal only from a bank if it is on that bank
bool riverbank::checkIfExists(animal* a)
{
	// check all 3 elements of the array...
	for (int i = 0; i < 3; i++)
	{
		// and if not empty...
		if (bankName[i] != NULL)
		{
			// check if the animal in this element is the same animal as looking for, and if yes, return true
			if(bankName[i]->getInitial() == a->getInitial())
			{
				return true;
			}
		}
	}
	// if no matches with any animal in array, the input animal is not here - return false
	return false;
}

// get the 'count' state of the array
int riverbank::countAnimals()
{
	return count;
}

// ------ // ------ // setters // ------ // ------ //

// adds an animal to the ariverbank
void riverbank::addAnimal(animal* a)
{
	// cycle through elements...
	for (int i = 0; i < 3; i++)
	{
		// if this element is blank...
		if (bankName[i] == NULL)
		{
			// add that animal to this slot, and increase bank's animal 'count' state
			bankName[i] = a; 
			count++;
			break;
		}
	}
}

// completely clear out all elements of riverbank array
void riverbank::initialiseNULL()
{
	for(int i = 0; i < 3; i++)
	{
		bankName[i] = NULL;
	}
}

// removes an animal from the riverbank
void riverbank::removeAnimal(animal* a)
{
	// cycle through elements...
	for (int i = 0; i < 3; i++)
	{
		// if this element is NOT blank
		if (bankName[i] != NULL)
		{
			// check if this animal is the one we want to remove...
			if (a->getInitial() == bankName[i]->getInitial())
			{
				// if so, clear this slot and lower the bank's animal 'count' state
				bankName[i] = NULL;
				count--;
				break;
			}
		}
	}

}
