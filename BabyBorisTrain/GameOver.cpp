#include "GameOver.h"

GameOver::GameOver() : Scene(GAMEOVERBACKGROUND)
{

}

GameOver::~GameOver()
{
	Scene::~Scene();
}

void GameOver::Initialise(SDL_Renderer* renderer)
{
	//SetMusicName("gameover");
	Scene::Initialise(renderer);
	replay_button = AddSprite(textureManager->GetTexture(REPLAY), 1);
	replay_button->SetActive(true);
	replay_button->SetPosition(100, 150);
	quit_button = AddSprite(textureManager->GetTexture(QUIT), 1);
	quit_button->SetActive(true);
	quit_button->SetPosition(100, 330);

	//high_score_button = AddSprite(textureManager->GetTexture("save_high_score"), 1);
	//high_score_button->SetActive(true);
	//high_score_button->SetPosition(600, 350);

	//if (!textureManager->GetTexture("lblPoints"))
	//{
	//	textureManager->AddTexture("lblPoints", fontmanager->GetFont("Consolas")->CreateTextTexture("Points", SOLID));
	//}
	//Sprite* lblPoints = AddSprite(textureManager->GetTexture("lblPoints"), 5);
	//lblPoints->SetPosition(400, 350);
	//lblPoints->SetActive(true);
	Sprite* lblScore = AddSprite(fontmanager->GetFont(CONSOLAS)->CreateTextTexture(std::to_string(Misc::time).c_str(), SOLID), 5);
	lblScore->SetPosition(400, 400);
	lblScore->SetActive(true);
}

bool GameOver::GetInput()
{
	SDL_Event event;
	SDL_Point mpos;
	while (SDL_PollEvent(&event))
	{
		mpos.x = event.button.x;
		mpos.y = event.button.y;
		if (event.type == SDL_QUIT)
		{
			return false;
		}
		switch (event.type)
		{
		case SDL_KEYDOWN:
		{
			switch (event.key.keysym.sym)
			{
				case SDLK_ESCAPE:
					return false;
			}
		}
		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				if (replay_button->Clicked(&mpos))
				{
					soundManager->GetSound(CLICK)->Play();
					Util::GetInstance()->Reset();
					SetNextScene(BabyTrainSceneName);
					return false;
				}
				if (quit_button->Clicked(&mpos))
				{
					soundManager->GetSound(CLICK)->Play();
					BorisOperations::WaitForMusicToStop();
					return false;
				}
				//if (high_score_button->Clicked(&mpos))
				//{
				//	SetNextScene("highscore");
				//	soundManager->GetSound("click")->Play();
				//	return false;
				//}
				break;
			}
			break;
		}
	}
	return true;
}

void GameOver::Update(float deltaTime)
{

}