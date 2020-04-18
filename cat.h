// guards
#ifndef CAT_H
#define CAT_H

#include <string>
#include "animal.h"

class cat : public animal
{
	//*States*								// private, since each species of animal doesn't have a subclass
	std::string eats;						// animal the cat eats
	//*Behaviours*
	public:					
		//*Constructors*
		cat();								// create a cat

		//*getters*
		std::string makeSound(int repeats);	// make a cat sound with number of repeats
		void drawAnimal(int frame);			// draw the cat, an integer represents which 'picture' to draw
		
		//*setters*
		
		//*destructors*
		~cat();
};

#endif
