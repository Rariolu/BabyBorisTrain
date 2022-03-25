#ifndef _BABYTRAINSCENE_H
#define _BABYTRAINSCENE_H

#include "Constants.h"
#include "Scene.h"
#include "EnergyMeter.h"
#include "Town.h"
#include "Train.h"
#include "Timer.h"

class BabyTrainScene : public Scene
{
	public:
		BabyTrainScene();
		~BabyTrainScene();
		void Initialise(SDL_Renderer* sdlrenderer);
	private:
		bool GetInput();
		void Update(float deltaTime);
		float trainEnergyRequirement = 75;
		float maxTrainDistance = 80;
		EnergyMeter* energyMeter;
		Train* train;
		std::vector<Town*> towns;
		Sprite* proximityAlert;
		Timer* timer;
		bool previouslyStarted = false;
		void Dispose();
		
};

#endif