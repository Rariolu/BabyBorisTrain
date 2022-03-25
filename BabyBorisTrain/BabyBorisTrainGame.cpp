#include "BabyBorisTrainGame.h"

BabyBorisTrainGame* BabyBorisTrainGame::_instance = NULL;

BabyBorisTrainGame::BabyBorisTrainGame()
{

}

BabyBorisTrainGame::~BabyBorisTrainGame()
{

}

BabyBorisTrainGame* BabyBorisTrainGame::GetInstance()
{
	if (!_instance)
	{
		return _instance = new BabyBorisTrainGame();
	}
	return _instance;
}

void BabyBorisTrainGame::Run()
{
	Game::Run(BabyTrainSceneName);
}

void BabyBorisTrainGame::ResourceSetup(SDL_Renderer* sdlrenderer)
{
	FontManager* fontManager = FontManager::GetInstance();
	Font* consolas = new Font("Fonts\\consolaz.ttf", 50, sdlrenderer);
	Font* calibri = new Font("Fonts\\calibri.ttf", 50, sdlrenderer, { 136,0,21,255 }, { 255,255,255,255 });
	fontManager->AddFont(CONSOLAS, consolas);
	fontManager->AddFont(CALIBRI, calibri);

	TextureManager* textureManager = TextureManager::getInstance();
	//textureManager->SetRenderer(sdlrenderer);
	textureManager->AddTexture(BACKGROUNDIMAGE, "Textures\\backgroundNew.png");
	textureManager->AddTexture(PERSON, "Textures\\person.png");
	textureManager->AddTexture(ENERGYMETER, "Textures\\EnergyMeter.png");
	textureManager->AddTexture(TRAIN, "Textures\\train.png");
	textureManager->AddTexture(TOWN, "Textures\\town.png");
	textureManager->AddTexture(PROXIMITYALERT, "Textures\\proximityAlert.png");
	textureManager->AddTexture(GAMEOVERBACKGROUND, "Textures\\game_over_screen.png");
	textureManager->AddTexture(REPLAY, "Textures\\replay.png");
	textureManager->AddTexture(QUIT, "Textures\\quit.png");
	textureManager->AddTexture(ENERGYMETERFULL, "Textures\\EnergyMeterFull.png");
	
	for (int i = 0; i < 10; i++)
	{
		//Create an "LPCSTR" representation of the value of "i".
		LPCSTR name = BorisOperations::Int_to_LPCSTR(i);
		//Add a texture to the texturemanager which is created using the "Consolas" font and the value of "name".
		textureManager->AddTexture(name, fontManager->GetFont(CONSOLAS)->CreateTextTexture(name, SOLID));
	}

	SoundManager* soundmanager = SoundManager::GetInstance();
	//Load various sound files and add them to the sound manager in order to reference them later.
	soundmanager->AddSound(CLICK, "Sounds\\mouse_click.wav", SFX);
	soundmanager->AddSound(REPOPULATE, "Sounds\\Repopulate.wav",SFX);
	soundmanager->AddSound(ENERGYINSUFFICIENT, "Sounds\\energyInsufficient.wav",SFX);
	soundmanager->AddSound(ENVIABLEREVENGE, "Sounds\\Enviable Revenge.mp3",MUSIC);

	SceneManager* sceneManager = SceneManager::GetInstance();
	sceneManager->AddScene(BabyTrainSceneName, new BabyTrainScene());
	sceneManager->AddScene(GAMEOVER, new GameOver());

}