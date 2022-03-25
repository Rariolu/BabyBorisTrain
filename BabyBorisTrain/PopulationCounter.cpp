#include "PopulationCounter.h"


PopulationCounter::PopulationCounter()
{
	for (int i = 0; i < digitCount; i++)
	{
		NumberSprite* ns = new NumberSprite();
		ns->SetActive(true);
		numbers.push_back(ns);
	}
	digitwidth = numbers.at(numbers.size() - 1)->GetDimensions().w;
	SetPosition({ 0,0 });
}

PopulationCounter::~PopulationCounter()
{
	for (NumberSprite* numberSprite : numbers)
	{
		delete numberSprite;
		numberSprite = NULL;
	}
	numbers.clear();
}

void PopulationCounter::Update(float deltaTime)
{

}

Vector2 PopulationCounter::GetPosition()
{
	return position;
}

void PopulationCounter::SetPosition(Vector2 pos)
{
	position = pos;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		int index = i;
		int adjustment = i*digitwidth;
		numbers.at(index)->SetPosition(pos.X + adjustment, pos.Y);
	}
}

void PopulationCounter::SetPosition(float x, float y)
{
	Vector2 pos;
	pos.X = x;
	pos.Y = y;
	SetPosition(pos);
}

std::vector<NumberSprite*>* PopulationCounter::GetNumberSprites()
{
	return &numbers;
}

int PopulationCounter::GetCount()
{
	return populationCount;
}

void PopulationCounter::SetCount(int count)
{
	count = count < 0 ? 0 :
	(
		count > maxNumber ? maxNumber : count
	);
	populationCount = count;
	std::string points = BorisOperations::PadNumber(populationCount, digitCount);
	for (size_t i = 0; i < points.size(); i++)
	{
		char c = points.at(i);
		int digit = (int)c - 48;
		numbers.at(i)->SetDisplayNumber(digit);
	}
}