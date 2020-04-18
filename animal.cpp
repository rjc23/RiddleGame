// ------ // ------ // set-up // ------ // ------ //
#include <string>
#include "animal.h"

using namespace std;

// ------ // constructors & destructors // ------ //

animal::animal()
{
	// default constructor to be left empty. Only used for making sublcasses
}

animal::animal(char aInitial, string aSpecies)
{
	initial = aInitial;
	species = aSpecies;
}

animal::~animal()
{
	// leave blank for now
}

// ------ // ------ // getters // ------ // ------ //

char animal::getInitial()
{
	return initial;
}

string animal::getSpecies()
{
	return species;
}

// // makeSound is pure virtual
// string animal::makeSound(int repeats){}

// ------ // ------ // setters // ------ // ------ //

void animal::setInitial(char aInitial)
{
	initial = aInitial;
}

void animal::setSpecies(string aSpecies)
{
	species = aSpecies;
}
