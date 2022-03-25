#ifndef _GAMEOVER_H
#define _GAMEOVER_H

#include "Scene.h"
#include "Constants.h"
#include "Misc.h"

//A sub-class of "Scene" representing the "Game Over" scene of the game.
class GameOver : public Scene
{
	public:
		//Constructor method
		GameOver();
		//Destructor method
		~GameOver();
		//A method which initialises this scene using a pointer to the sdl renderer.
		void Initialise(SDL_Renderer* renderer);
	private:
		//A method which takes appropriate actions depending on the user's input and returns a boolean representing whether or not to continue running the scene.
		bool GetInput();
		//A method which is called once per frame.
		void Update(float deltaTime);
		//A sprite which is used to represent a button that restarts the game.
		Sprite* replay_button;
		//A sprite which is used to represent a button that quits the game.
		Sprite* quit_button;
		//A sprite which is used to represent a button that loads the high score screen.
		//Sprite* high_score_button;
};

#endif