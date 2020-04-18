#include <iostream>
#include "animal.h"
#include "cat.h"
#include "riverbank-array-two.h"

using namespace std;

int main(void)
{
	riverbank A;
	riverbank B;

	A.initialiseNULL();
	B.initialiseNULL();

	animal* dog = new animal('d', "dog");
	cat* Cat = new cat;
	animal* mouse = new animal('m', "mouse");

	A.addAnimal(dog);
	A.addAnimal(Cat);
	A.addAnimal(mouse);

	cout << Cat->makeSound(1) << endl;

	A.printBankStatus();

	if (A.checkBank() == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	A.removeAnimal(Cat);

	A.printBankStatus();

	if (A.checkBank() == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;



	return 0;
}
