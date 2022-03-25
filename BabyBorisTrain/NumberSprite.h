#ifndef _NUMBERSPRITE_H
#define _NUMBERSPRITE_H

#include "Sprite.h"

//A sub-class of "Sprite" which is used to display a single digit.
class NumberSprite : public Sprite
{
	public:
		//Constructor method.
		NumberSprite();
		//Destructor method.
		~NumberSprite();
		//Get the number that is currently being displayed.
		int GetDisplayNumber();
		//Set the number that is currently being displayed.
		void SetDisplayNumber(int num);
	private:
		//The number that is currently being displayed.
		int displayNumber = 0;
};

#endif