// ------ // ------ // set-up // ------ // ------ //
#include <string>
#include <iostream>
#include "mouse.h"

using namespace std;

// ------ // constructors & destructors // ------ //

mouse::mouse() : animal()
{
	initial = 'm';
	species = "Mouse";

}

mouse::~mouse()
{
	// nothing to be added
};

// ------ // ------ // getters // ------ // ------ //

string mouse::makeSound(int repeats)
{
	// initialize output - will give no string for 0 repeats
	string squeak = "";
	// extend squeak string with animal's sound once per repeat
	for(int i = 0; i < repeats; i++)
	{
		squeak = squeak + "Skrr";
		// if going for another loop, add a space
		if(i+1 != repeats)
		{
			squeak = squeak + " ";
		}
	}
	return squeak;
}

void mouse::drawAnimal(int frame)
{
	if(frame == 1)					// if frame 1, draw animal
	{
		cout << "                    ___" << endl;
		cout << "           _  _  .-'   '-." << endl;
		cout << "          (.)(.)/         \\  " << endl;
		cout << "           /@@             ;          /   " << endl;
		cout << "          o_\\\\-mm-......-mm`~~~~~~~~~' " << endl;
	}

	else if (frame == 2)			// if frame 2, draw animal + print its sound
	{
		cout << "                    ___" << endl;
		cout << "           _  _  .-'   '-." << endl;
		cout << "          (.)(.)/         \\  " << endl;
		cout << makeSound(1) << "   _\\  /@@             ;          /   " << endl;
		cout << "        / o_\\\\-mm-......-mm`~~~~~~~~~' " << endl;
	}
}

// ------ // ------ // setters // ------ // ------ //
