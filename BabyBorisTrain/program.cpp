#include "BabyBorisTrainGame.h"
#include "ThreadManager.h"

BabyBorisTrainGame* babyBorisTrainGame = BabyBorisTrainGame::GetInstance();

int main(int argc, char *argv[])
{
	return babyBorisTrainGame->CreateGameWindow(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
}