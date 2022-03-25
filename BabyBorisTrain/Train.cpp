#include "Train.h"

Train::Train() : Sprite(texturemanager->GetTexture(TRAIN))
{
	SetActive(true);
}

Train::~Train()
{

}

void Train::AddWayPoint(float x, float y)
{
	AddWayPoint({ x,y });
}

void Train::AddWayPoint(Vector2 position)
{
	waypoints.push_back(position);
}

Vector2 Train::NextWayPoint()
{
	return waypoints[waypointIndex%waypoints.size()];
}

Vector2 Train::PrevWayPoint()
{
	return waypoints[(waypointIndex - 1) % waypoints.size()];
}

void Train::Update(float deltaTime)
{
	float mult = 0.25;
	if (speed)
	{
		speedRemaining -= deltaTime;
		mult = 3;
		if (speedRemaining < 0)
		{
			speed = false;
		}
	}
	currentTime += (deltaTime*mult);
	LerpPosition(NextWayPoint(), currentTime / timedelay < 1 ? currentTime / timedelay : 1);
	//Vector2 newPos = Misc::Lerp(PrevWayPoint(), NextWayPoint(), currentTime/timedelay < 1 ? currentTime/timedelay : 1);
	//SetPosition(newPos.X, newPos.Y);
	if (Misc::GetDistance(Misc::GetFloatRect(GetPosition()), { NextWayPoint().X,NextWayPoint().Y }) <= maxDistance)
	{
		currentTime = 0;
		waypointIndex++;
	}
}

bool Train::Speed()
{
	if (!speed)
	{
		speedRemaining = 5;
		speed = true;
		SoundManager::GetInstance()->GetSound(ENERGYINSUFFICIENT)->Play();
		return true;
	}
	return false;
}