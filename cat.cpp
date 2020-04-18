// ------ // ------ // set-up // ------ // ------ //
#include <string>
#include <iostream>
#include "cat.h"

using namespace std;

// ------ // constructors & destructors // ------ //

cat::cat() : animal()
{
	initial = 'c';
	species = "Cat";
	eats = "mouse";
}

cat::~cat()
{
	// nothing to be added
}

// ------ // ------ // getters // ------ // ------ //

string cat::makeSound(int repeats)
{
	// initialize output - will give no string for 0 repeats
	string cry = "";
	// extend cry string with animal's sound once per repeat
	for(int i = 0; i < repeats; i++)
	{
		cry = cry + "Meow";
		// if going for another loop, add a space
		if(i+1 != repeats)
		{
			cry = cry + " ";
		}
	}
	return cry;
}

void cat::drawAnimal(int frame)
{
	if(frame == 1)					// if frame 1, draw animal
	{
		cout << "      ╱╲    ╱╲  ╭━╮" << endl; 
		cout << "     ╱╱╲╲__╱╱╲╲ ╰╮┃" << endl;
		cout << "     ▏┏┳╮ ╭┳┓ ▕  ┃┃" << endl;
		cout << "     ▏╰┻┛▼┗┻╯ ▕  ┃┃" << endl;
		cout << "     ╲  ╰┻╯   ╱▔▔ ┃" << endl;
		cout << "      ╰━┳━━━ ╯    ┃" << endl;
		cout << "        ┃┏┓┣━━┳┳┓┃" << endl;
		cout << "        ┗┛┗┛  ┗┛┗┛" << endl;
	}
	
	else if (frame == 2)			// if frame 2, draw animal + print its sound
	{
		cout << "      ╱╲    ╱╲  ╭━╮" << endl; 
		cout << "     ╱╱╲╲__╱╱╲╲ ╰╮┃" << endl;
		cout << "     ▏┏┳╮ ╭┳┓ ▕  ┃┃" << endl;
		cout << "  _  ▏╰┻┛▼┗┻╯ ▕  ┃┃" << endl;
		cout << "     ╲  ╰┻╯   ╱▔▔ ┃" << endl;
		cout << "  /  |╰━┳━━━ ╯    ┃" << endl;
		cout << " " << makeSound(1) << "   ┃┏┓┣━━┳┳┓┃" << endl;
		cout << "        ┗┛┗┛  ┗┛┗┛" << endl;
	}
}

// ------ // ------ // setters // ------ // ------ //
