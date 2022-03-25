#ifndef  _TIMER_H
#define _TIMER_H

#include<vector>
#include"Util.h"
#include"NumberSprite.h"


//A class which is used to display the current amount of Population
//that the player has accumulated.
class Timer
{
public:
	//Constructor method.
	Timer();
	//Destructor method.
	~Timer();
	//A method which returns a Vector2 value representing
	//the location of this Population counter.
	Vector2 GetPosition();
	//A method that sets the current location using a Vector value
	void SetPosition(Vector2 pos);
	//A method that sets the current location using separate x and y values.
	void SetPosition(float x, float y);
	//A method which returns a pointer to all the "NumberSprite" instances
	//associated with this Population counter.
	std::vector<NumberSprite*>* GetNumberSprites();
	//A method that is called once per frame which updates the Population
	//counter so that it accurately displays the current amount of Population.
	void Update(float deltaTime);

	int GetCount();
	void SetCount(float count);
private:
	const int digitCount = 4;
	const int maxNumber = 9999;
	float time = 0;
	//An array containing all the pointers to "NumberSprite" instances
	//that are used to display the individual digits of the Population.
	std::vector<NumberSprite*> numbers;
	//A value which represents the current location of the Population counter.
	Vector2 position;
	//A value representing the width of each digit.
	int digitwidth = 0;
};

#endif // ! _Timer_H