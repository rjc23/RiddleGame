// ------ // ------ // set-up // ------ // ------ //
#include <string>
#include <iostream>
#include "dog.h"

using namespace std;

// ------ // constructors & destructors // ------ //

dog::dog() : animal()
{
	initial = 'd';
	species = "Dog";
	eats = "cat";
}

dog::~dog()
{
	// nothing to be added
};

// ------ // ------ // getters // ------ // ------ //

string dog::makeSound(int repeats)
{
	// initialize output - will give no string for 0 repeats
	string bark = "";
	// extend bark string with animal's sound once per repeat
	for(int i = 0; i < repeats; i++)
	{
		bark = bark + "Woof";
		// if going for another loop, add a space
		if(i+1 != repeats)
		{
			bark = bark + " ";
		}
	}
	return bark;
}

void dog::drawAnimal(int frame)
{
	if(frame == 1)					// if frame 1, draw animal
	{
		cout << "    ╱▏      ▕╲▕╲" << endl;
		cout << "    ▏▏      ▕▏▔▔╲" << endl;
		cout << "    ▏╲      ╱ ▔ ▔╲" << endl;
		cout << "    ╲▏▔▔▔▔▔▔╯╯╰┳━━▀" << endl;
		cout << "     ▏╯╯╯╯╯╯╯╯╱┃" << endl;
		cout << "     ┃┏┳┳━━━┫┣┳┃" << endl;
		cout << "     ┃┃┃┃   ┃┃┃┃" << endl;
		cout << "     ┗┛┗┛   ┗┛┗┛" << endl;
	}
	
	else if (frame == 2)			// if frame 2, draw animal + print its sound
	{
		cout << "    ╱▏      ▕╲▕╲" << endl;
		cout << "    ▏▏      ▕▏▔▔╲" << endl;
		cout << "    ▏╲      ╱ ▔ ▔╲" << endl;
		cout << "    ╲▏▔▔▔▔▔▔╯╯╰┳━━▀" << endl;
		cout << "     ▏╯╯╯╯╯╯╯╯╱┃ / | \\" << endl;
		cout << "     ┃┏┳┳━━━┫┣┳┃  " << makeSound(1) << endl;
		cout << "     ┃┃┃┃   ┃┃┃┃" << endl;
		cout << "     ┗┛┗┛   ┗┛┗┛" << endl;
	}
}

// ------ // ------ // setters // ------ // ------ //
