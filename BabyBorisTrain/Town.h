#ifndef _TOWN_H
#define _TOWN_H

#include "Person.h"
#include "PopulationCounter.h"
#include "Misc.h"

class Town : public Sprite
{
	public:
		Town();
		~Town();
		PopulationCounter* GetCounter();
		bool Repopulate();
		void SetPosition(Vector2 pos);
		void Update();
	private:
		int deathProb = 500;
		int mult = 2;
		Vector2 position = { 0,0 };
		Vector2 pcRelativePosition = { 20,0 };
		//vector<Person*> people;
		PopulationCounter* populationCounter;
};

#endif