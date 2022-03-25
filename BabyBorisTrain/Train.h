#ifndef _TRAIN_H
#define _TRAIN_H

#include "Sprite.h"
#include "Constants.h"
#include "Misc.h"

class Train : public Sprite
{
	public:
		Train();
		~Train();
		void AddWayPoint(float x, float y);
		void AddWayPoint(Vector2 position);
		void Update(float deltaTime);
		bool Speed();
	private:
		bool speed = false;
		float speedRemaining = 0;
		float timedelay = 12.5;
		float currentTime = 0;
		float maxDistance = 2;
		Vector2 PrevWayPoint();
		Vector2 NextWayPoint();
		int waypointIndex = 1;
		std::vector<Vector2> waypoints;
};

#endif