#include "Town.h"

Town::Town() : Sprite(texturemanager->GetTexture(TOWN))
{
	populationCounter = new PopulationCounter();
	SetScale(0.5, 0.5);
	SetActive(true);
	//populationCounter->SetCount(5);
	populationCounter->SetCount(BorisOperations::RandomNumber(20, 200));
}

Town::~Town()
{
	delete populationCounter;
}

PopulationCounter* Town::GetCounter()
{
	return populationCounter;
}

bool Town::Repopulate()
{
	int count = populationCounter->GetCount();
	populationCounter->SetCount(count*mult);
	if (count)
	{
		deathProb *= 0.55;
		soundmanager->GetSound(REPOPULATE)->Play();
	}
	return count;
}

void Town::SetPosition(Vector2 pos)
{
	Sprite::SetPosition(pos.X, pos.Y);
	populationCounter->SetPosition(pos.X+pcRelativePosition.X,pos.Y + pcRelativePosition.Y);
}

void Town::Update()
{
	if (!Misc::rand->Next(deathProb))
	{
		int count = populationCounter->GetCount();
		if (count - 1 >= 0)
		{
			populationCounter->SetCount(count-1);
		}
	}
}