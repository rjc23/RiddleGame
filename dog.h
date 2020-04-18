// guards
#ifndef DOG_H
#define DOG_H

#include <string>
#include "animal.h"

class dog : public animal
{
	//*States*								// private, since each species of animal doesn't have a subclass
	std::string eats;						// animal the dog eats
	//*Behaviours*
	public:					
		//*Constructors*
		dog();								// create a dog

		//*getters*
		std::string makeSound(int repeats);	// make a dog sound with number of repeats
		void drawAnimal(int frame);			// draw the dog, an integer represents which 'picture' to draw
		
		//*setters*
		
		//*destructors*
		~dog();
};

#endif
