#include "EnergyMeter.h"

EnergyMeter::EnergyMeter() : Sprite(TextureManager::getInstance()->GetTexture(ENERGYMETERFULL))
{
	SetActive(true);
}

EnergyMeter::~EnergyMeter()
{

}

void EnergyMeter::SetAbsoluteScale(float x, float y)
{
	SetAbsoluteScale({ x,y });
}

void EnergyMeter::SetAbsoluteScale(Vector2 scale)
{
	ResetScale();
	SetScale(scale.X/2,scale.Y/2);
}

void EnergyMeter::ResetScale()
{
	SetScale(1 / GetScale().X, 1 / GetScale().Y);
}

float EnergyMeter::GetEnergy()
{
	return energy;
}

void EnergyMeter::SetEnergy(float e)
{
	energy = e;
	SetAbsoluteScale(energy / 100, 0.5);
	if (prevEnergy != energy)
	{
		if (!full && energy >= necessaryEnergy)
		{
			full = true;
			SetTexture(texturemanager->GetTexture(ENERGYMETERFULL));
		}
		else if (full && energy < necessaryEnergy)
		{
			full = false;
			SetTexture(texturemanager->GetTexture(ENERGYMETER));
		}
		prevEnergy = energy;
	}
}

void EnergyMeter::DecreaseEnergy(float e)
{
	float n = energy - e;
	SetEnergy(n >= 0.01? n : 0.01);
}

void EnergyMeter::RestoreEnergy(float delta)
{
	float e = energy + delta*mult;
	SetEnergy(e <= 100 ? e : 100);
}