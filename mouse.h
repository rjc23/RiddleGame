// guards
#ifndef MOUSE_H
#define MOUSE_H

#include <string>
#include "animal.h"

class mouse : public animal
{
	//*States*				// private, since each species of animal doesn't have a subclass
							// mouse has no unique states
	//*Behaviours*
	public:					
		//*Constructors*
		mouse();								// create a mouse

		//*getters*
		std::string makeSound(int repeats);	// make a mouse sound with number of repeats
		void drawAnimal(int frame);			// draw the mouse, an integer represents which 'picture' to draw
		
		//*setters*
		
		//*destructors*
		~mouse();
};

#endif
