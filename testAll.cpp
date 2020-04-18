// Use this to complile tests
// g++ -o testAll testAll.cpp animal.cpp cat.cpp dog.cpp mouse.cpp riverbank-array-two.cpp extraFunctions.cpp

//********** NAMESPACE & INCLUDE FILES **********//

using namespace std;

#include <iostream>
#include <string>
#include <cstdlib>
#include "animal.h"
#include "dog.h"
#include "cat.h"
#include "mouse.h"
#include "riverbank-array-two.h"

extern int returnID(string word);
extern void checkIfMoveIsValid(string playerInput, int* boatPosition, riverbank* leftBank, riverbank* rightBank, animal* adding);
extern void pause(int dur);

extern void boat(int location, animal* adding);
extern void initialBoat();
extern void rightBoat();

//********** MAIN PROGRAM **********//

int main(void)
{
	cout << endl << "==== ==== ==== ==== ====" << endl << "Program starts here" << endl << "==== ==== ==== ==== ====" << endl;

	//********** Testing creating all the animals **********//

	//Testing creating an animal and setting it's initial and species

	cout << endl << "TESTING ANIMALS" << endl << endl;

	// constructor and getter tests
	cout << "Test: create each animal with its default sub-class constructor, then use its getters." << endl;
	
	cat* kitten = new cat;
	cout << kitten->getSpecies() << " has the initial " << kitten->getInitial() << ". Its goes " << kitten->makeSound(2) <<endl << endl;

	dog* puppy = new dog;
	cout << puppy->getSpecies() << " has the initial " << puppy->getInitial() << ". Its goes " << puppy->makeSound(2)<<endl << endl;

	mouse* stuart = new mouse;
	cout << stuart->getSpecies() << " has the initial " << stuart->getInitial() << ". Its goes " << stuart->makeSound(2)<<endl << endl;

	// setter tests
	cout << "Test animal setters:" << endl;
	cat* fakecat = new cat;
	cout << "1st - create a cat with default constructor, then use its getters..." << endl;
	cout << fakecat->getSpecies() << " has the initial " << fakecat->getInitial() << ". Its goes " << fakecat->makeSound(2) <<endl << endl;
	cout << "2nd - replace this cat's states with parent class's setters, then call its getters again." << endl;
	fakecat->setInitial('W');
	fakecat->setSpecies("Blue Whale");
	cout << "The new initial and species are:" << endl << fakecat->getInitial() << " and " << fakecat->getSpecies() << endl;


	//********** Testing returnID function **********//

	// test player inputs
	cout << endl << "TESTING RETURN ID FUNCTION" << endl << endl;
	cout << "Return IDs are used when converting a player input into the game." << endl;
	cout << "// 1 = dog; 2 = cat; 3 = mouse; 4 = successful_pass; 99 = failed_entry" << endl;
	cout << endl;

	cout << "Test different casing of the same word." << endl;
	cout << "input = Dog // expected_result = 1 // actual_result = " << returnID("dog") << endl;
	cout << "input = DOg // expected_result = 1 // actual_result = " << returnID("dOg") << endl;
	cout << "input = DoG // expected_result = 1 // actual_result = " << returnID("doG") << endl;
	cout << "input = DOG // expected_result = 1 // actual_result = " << returnID("DOG") << endl;
	cout << endl;

	cout << "Test all other valid words." << endl;
	cout << "input = Cat // expected_result = 2 // actual_result = " << returnID("Cat") << endl;
	cout << "input = Mouse // expected_result = 3 // actual_result = " << returnID("Mouse") << endl;
	cout << "input = Pass // expected_result = 4 // actual_result = " << returnID("Pass") << endl;
	cout << endl;

	cout << "Test unrecognised words/symbols." << endl;
	cout << "input = Blah // expected_result = 99 // actual_result = " << returnID("Blah") << endl;
	cout << "input = Frog // expected_result = 99 // actual_result = " << returnID("Frog") << endl;
	cout << "input = cats // expected_result = 99 // actual_result = " << returnID("cats") << endl;
	cout << "input = >.< // expected_result = 99 // actual_result = " << returnID(">.<") << endl;
	cout << endl;

	//********** Testing riverbank class and its functions **********//

	cout << endl << "TESTING RIVERBANK CLASS" << endl << endl;
	// default riverbank constructor
	riverbank A;

	// test initialiseNULL()
	A.initialiseNULL();
	animal** a = A.returnArray();
	cout << "Testing initialiseNULL() function" << endl;
	cout << "// if it prints NULL three times, the function works" << endl;
	cout << "// NULL = empty entry in i'th element of array" << endl;
	cout << "actual_result = ";
	for(int i = 0; i < 3; i++)
		if (a[i]==NULL)
			cout << "NULL" << " ";
	cout << endl << endl;

	cout << "Testing checkPrey() function" << endl;
	cout << "// 0 = empty bank, impossible for this bank to cause Game Over" << endl;
	cout << "expected_result = 0" << endl;
	cout << "actual_result = " << A.checkPrey();
	cout << endl << endl;

	//testing adding animals to the array and the print function
	cout << "Testing addAnimal() function" << endl;
	cout << "// adding cat, then dog, then mouse to riverbank array" << endl;
	A.addAnimal(kitten);
	A.addAnimal(puppy);
	A.addAnimal(stuart); 
	cout << "expected_result = Cat Dog and Mouse" << endl;
	cout << "actual_result = ";
	A.printBankStatus();

	// testing the make sound function (polymorphism)
	cout << endl << "Testing makeSound() function" << endl;
	cout << "// tests polymorphism // array[i]->makeSound(5 repeats)" << endl;
	cout << "actual_result = " << endl;
	animal** b = A.returnArray();
	for(int j = 0; j < 3; j++)
	{
		cout << b[j]->makeSound(5) << endl;
	} 
	

	cout << endl << "Testing checkPrey() function" << endl;
	cout << "// 3 = full bank, impossible for this bank to cause Game Over" << endl;
	cout << "expected_result = 3" << endl;
	cout << "actual_result = " << A.checkPrey() << endl;
	cout << endl;


	//if all animals are in the array, returns true
	cout << "Testing checkBank() function on full array" << endl;
	cout << "// true = full array; false = there is a null/empty element(s)" << endl;
	cout << "expected_result = true" << endl;
	if (A.checkBank() == true)
		cout << "actual_result = true" << endl << endl;

	//testing removing animals to the array
	cout << "Testing removeAnimal() function - removing a dog" << endl;
	A.removeAnimal(puppy);
	cout << "expected_result = Cat and Mouse" << endl;
	cout << "actual_result = ";
	A.printBankStatus();

	cout << endl << "Testing checkPrey() function on array with Cat and Mouse" << endl;
	cout << "// 1 = dog eats cat // 2 = cat eats mouse" << endl;
	cout << "expected_result = 2" << endl;
	cout << "actual_result = " << A.checkPrey() << endl;

	cout << "// as a true/false case..." << endl;
	cout << "expected_result = true" << endl;
	if (A.checkPrey() == 2)
		cout << "actual_result = true" << endl;

	cout << endl << "Testing checkBank() function on partly full array" << endl;
	cout << "expected_result = false" << endl;
	if (A.checkBank() == false)
		cout << "actual_result = false" << endl << endl;

	cout << "Testing checkIfExists() function on array with Cat and Mouse (searching for cat)" << endl;
	cout << "// purpose: ensure can 'collect' cat if cat DOES exist in this bank" << endl;
	cout << "expected_result = true" << endl;
	if (A.checkIfExists(kitten) == true)
		cout << "actual_result = true" << endl << endl;


	cout << "Testing checkIfExists() function on array with Cat and Mouse (searching for dog)" << endl;
	cout << "// purpose: ensure can't 'collect' dog if dog isn't in this bank" << endl;
	cout << "expected_result = false" << endl;
	if (A.checkIfExists(puppy) == false)
		cout << "actual_result = false" << endl;

	// ********** Testing drawing sizes **********//

	cout << "Do you want to test the drawing animations" << endl << "CAUTION: Clears above tests!" << endl << "(y/n)" << endl;
	// set up for animations...
	char choice = 'a';
	A.addAnimal(puppy);

	// until the tester enters a valid choice, keep prompting
	while(choice != 'y' && choice != 'n')
	{
		cin >> choice;
	}

	if (choice == 'y')
	{
		// play animations of all 3 animals
		animal** arrayTest = A.returnArray();
		for(int i = 0; i < 3; i++)
		{
			// draw 2 frames
			for(int j = 1; j <=2; j++)
			{
				system("clear");
				cout << "A " << arrayTest[i]->getSpecies() << endl << endl;
				arrayTest[i]->drawAnimal(j);
				pause(1);
			}
		}

		// play a boat loop
		initialBoat();
		boat(0, kitten);
		rightBoat();
		boat(1, kitten);
	}

	else if(choice == 'n')
	{
		cout << "Drawing animation test skipped." << endl;
	}

	
	//********** termination **********//

	//deleting memory allocated
	delete kitten;
	delete puppy;
	delete stuart;
	delete fakecat;		// used during setter tests

	cout << endl << "==== ==== ==== ==== ====" << endl << "Program ends here" << endl << "==== ==== ==== ==== ====" << endl;
	
	return 0;
}

