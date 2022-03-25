#include "BabyTrainScene.h"

BabyTrainScene::BabyTrainScene() : Scene(BACKGROUNDIMAGE)
{
	
}


BabyTrainScene::~BabyTrainScene()
{
	Dispose();
}

void BabyTrainScene::Dispose()
{
	//delete energyMeter;
	//delete train;
	//for (int i = 0; i < towns.size(); i++)
	//{
	//	delete towns[i];
	//	towns[i] = NULL;
	//}
	towns.clear();
	//delete proximityAlert;
	//delete timer;
}

void BabyTrainScene::Initialise(SDL_Renderer* sdlrenderer)
{
	if (previouslyStarted)
	{
		Dispose();
	}
	previouslyStarted = true;
	SetMusicName(ENVIABLEREVENGE);
	Scene::Initialise(sdlrenderer);
	train = new Train();
	train->SetPosition(171, 12);
	train->AddWayPoint(171, 12);
	train->AddWayPoint(304, 47);
	train->AddWayPoint(318, 197);
	train->AddWayPoint(345, 329);
	train->AddWayPoint(477, 350);
	train->AddWayPoint(622, 345);
	train->AddWayPoint(678, 292);
	train->AddWayPoint(704, 166);
	train->AddWayPoint(684, 60);
	train->AddWayPoint(633, -11);
	train->AddWayPoint(569, -11);
	train->AddWayPoint(519, 38);
	train->AddWayPoint(504, 124);
	train->AddWayPoint(403, 205);
	train->AddWayPoint(287, 193);
	train->AddWayPoint(192, 205);
	train->AddWayPoint(116, 204);
	train->AddWayPoint(62, 183);
	train->AddWayPoint(14, 129);
	AddRenderable(train, 4);
	//AddSprite(train, 4);
	energyMeter = new EnergyMeter();
	AddRenderable(energyMeter, 5);
	//AddSprite(energyMeter, 5);
	energyMeter->SetPosition(600, 5);
	energyMeter->SetScale(0.5f, 0.5f);
	const int townNo = 3;
	Vector2 townPositions[townNo] =
	{
		{115,125},
		{555,200},
		{200,350}
	};
	for (int i = 0; i < townNo; i++)
	{
		Town* town = new Town();
		town->SetPosition(townPositions[i]);
		AddRenderable(town, 2);
		//AddSprite(town, 2);
		
		towns.push_back(town);
		//cout << "X: " << town->GetPosition().x << "; Y: " << town->GetPosition().y << ";" << endl;
		PopulationCounter* pc = town->GetCounter();
		std::vector<NumberSprite*>* numberSprites = pc->GetNumberSprites();
		for (int i = 0; i < numberSprites->size(); i++)
		{
			AddRenderable(numberSprites->at(i), 2);
			//AddSprite(numberSprites->at(i),2);
		}
	}
	proximityAlert = AddSprite(textureManager->GetTexture(PROXIMITYALERT), 3);
	proximityAlert->SetScale(1.5, 1.5);
	proximityAlert->SetPosition(2, 2);
	timer = new Timer();
	std::vector<NumberSprite*>* digits = timer->GetNumberSprites();
	//AddSprite(timer, 2);
	for (int i = 0; i < digits->size(); i++)
	{
		AddRenderable(digits->at(i), 2);
		//AddSprite(digits->at(i), 2);
	}
	timer->SetPosition(300, 5);
	//timer->SetScale(4, 1);
}

bool BabyTrainScene::GetInput()
{
	SDL_Event event;
	SDL_Point mpos;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return false;
			case SDL_KEYDOWN:
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					return false;
				case SDLK_LSHIFT:
					if (energyMeter->GetEnergy() > 10 )
					{
						if (train->Speed())
						{
							energyMeter->DecreaseEnergy(10);
						}
					}
					else
					{
						soundManager->GetSound(ENERGYINSUFFICIENT)->Play();
					}
					break;
				case SDLK_SPACE:
					if (energyMeter->GetEnergy() >= trainEnergyRequirement)
					{
						
						for (Town* town : towns)
						{
							float dist = Misc::GetDistance(train, town);
							if (dist <= maxTrainDistance || train->CollidesWith(town))
							{
								if (town->Repopulate())
								{
									energyMeter->DecreaseEnergy(trainEnergyRequirement);
								}
								break;
							}
							//else
							//{
							//	cout << dist << endl;
							//}
						}

					}
					else
					{
						soundManager->GetSound(ENERGYINSUFFICIENT)->Play();
					}
					break;
				//case SDLK_k:
				//	//cout << "X: " << train->GetPosition().x << "; Y: " << train->GetPosition().y << ";" << endl;
				//	break;
				//case SDLK_p:
				//	for (Town* town : towns)
				//	{
				//		cout << town->GetPosition().x << ":" << town->GetPosition().y << endl;
				//	}
				//	break;
				}
			}
			case SDL_MOUSEBUTTONDOWN:
				switch (event.button.button)
				{
					case SDL_BUTTON_LEFT:
						mpos.x = event.button.x;
						mpos.y = event.button.y;
						//train->SetPosition(mpos.x-(train->GetDimensions().w/2), mpos.y-(train->GetDimensions().h/2));
						break;
				}
				break;
		default:
			break;
		}
	}
	
	return true;
}

void BabyTrainScene::Update(float deltaTime)
{
	energyMeter->RestoreEnergy(deltaTime);
	train->Update(deltaTime);
	bool proximity = false;
	int people = 0;
	for (Town* town : towns)
	{
		int p = town->GetCounter()->GetCount();
		people += p;
		town->Update();
		float dist = train->GetDistanceFrom(town);
		//float dist = Misc::GetDistance(train, town);
		if ((dist <= maxTrainDistance || train->CollidesWith(town)) && p > 0)
		{
			proximity = true;
		}
	}
	//std::cout << "People: " << people << std::endl;
	if (people < 1)
	{
		Misc::time = timer->GetCount();
		SetNextScene(GAMEOVER);
	}
	proximityAlert->SetActive(proximity&&energyMeter->GetEnergy()>=trainEnergyRequirement);
	timer->Update(deltaTime);
}