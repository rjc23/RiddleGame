// 'guards' to prevent redeclaration of Panda class
#ifndef RIVERBANK_H
#define RIVERBANK_H

#include <string>
#include "animal.h"

// no namespaces in include file!!!

// Class definition
class riverbank
{
 	animal** bankName;
 	int count;

 	public:
 	//Constructors
 	riverbank();

 	//returns the array of the animal*
	animal** returnArray();

	//adds an animal to the animal array
	void addAnimal(animal* a);

	//adds a null pointer to the array
	void initialiseNULL();

	//subtracts an animal to the animal array
	void removeAnimal(animal* a);

	//Prints the status of the bank or what is in the array
	void printBankStatus();

	//checks whether the array has all the animals in it (will use with the while loop)
	bool checkBank();

	//checks to see whether there is an animal that will eat the other animal on a riverbank
	int checkPrey();

	//returns the amount of animals in the riverbank
	int countAnimals();

	//checks to see if an animal exists in the array
	bool checkIfExists(animal* a);


 	//Destructor
 	~riverbank();
};

#endif
