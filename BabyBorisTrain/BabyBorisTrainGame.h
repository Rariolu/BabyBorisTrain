#ifndef _BABYBORISTRAINGAME_H
#define _BABYBORISTRAINGAME_H

#include "Game.h"
#include "BabyTrainScene.h"
#include "GameOver.h"

class BabyBorisTrainGame : public Game
{
	public:
		BabyBorisTrainGame();
		~BabyBorisTrainGame();
		static BabyBorisTrainGame* GetInstance();
		void Run();
		void ResourceSetup(SDL_Renderer* sdlrenderer);
	private:
		static BabyBorisTrainGame* _instance;
};

#endif