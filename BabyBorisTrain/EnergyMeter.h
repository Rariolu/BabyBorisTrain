#ifndef _ENERGYMETER_H
#define _ENERGYMETER_H

#include "Sprite.h"
#include "Constants.h"

class EnergyMeter : public Sprite
{
	public:
		EnergyMeter();
		~EnergyMeter();
		void SetAbsoluteScale(float x, float y);
		void SetAbsoluteScale(Vector2 scale);
		void ResetScale();
		float GetEnergy();
		void SetEnergy(float e);
		void DecreaseEnergy(float e);
		void RestoreEnergy(float delta);
	private:
		float mult = 0.6;
		float prevEnergy = 100;
		float energy = 100;
		const float necessaryEnergy = 75;
		bool full = true;
};

#endif