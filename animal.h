// guards
#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class animal
{
	//*States*											// protected, since child inherets from parent
	protected:				
		char initial;									// first letter of species name for easier input
		std::string species; 							// whole species name (cat, dog, mouse)
	//*Behaviours*										// behaviours are public, since they allow the dev. to control states safely
	public:					
		//*Constructors*
		animal();										// default constructor to allow creation of children classes
		animal(char aInitial, std::string aSpecies);	// this constructor could be subject to change if we add more characteristics, or we could use setters

		//*getters*
		char getInitial();								// could use for searching what is stored at a pointer
		std::string getSpecies();						// mainly used for displaying to player

		// 2 pure virtual getters, therefore this class is abstract
		virtual std::string makeSound(int repeats) = 0;
		virtual void drawAnimal(int frame) = 0;

		//*setters*										// used to create 'blank' animal
		void setInitial(char aInitial);
		void setSpecies(std::string aSpecies);
		
		//*destructors*
		~animal();
};

#endif
