//#include "Timer.h"
//
//
//
//Timer::Timer() : Sprite(texturemanager->GetTexture("0"))
//{
//	SetActive(true);
//}
//
//
//Timer::~Timer()
//{
//}
//
//void Timer::Update(float deltaTime)
//{
//	time += deltaTime/20;
//	if (time != prevTime)
//	{
//		int ti = round(time);
//		string text = BorisOperations::PadNumber(ti, 8);
//		Texture* t;
//		if (!(t = texturemanager->GetTexture(text)))
//		{
//			t = FontManager::GetInstance()->GetFont(CONSOLAS)->CreateTextTexture(BorisOperations::String_to_LPCSTR(text), SOLID);
//		}
//		texturemanager->AddTexture(text, t);
//		prevTime = time;
//		SetTexture(t);
//	}
//}

#include "Timer.h"


Timer::Timer()
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

Timer::~Timer()
{
	for (NumberSprite* numberSprite : numbers)
	{
		delete numberSprite;
		numberSprite = NULL;
	}
	numbers.clear();
}

void Timer::Update(float deltaTime)
{
	float t = deltaTime / 20;
	SetCount(time + t);
}

Vector2 Timer::GetPosition()
{
	return position;
}

void Timer::SetPosition(Vector2 pos)
{
	position = pos;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		int index = i;
		int adjustment = i*digitwidth;
		numbers.at(index)->SetPosition(pos.X + adjustment, pos.Y);
	}
}

void Timer::SetPosition(float x, float y)
{
	Vector2 pos;
	pos.X = x;
	pos.Y = y;
	SetPosition(pos);
}

std::vector<NumberSprite*>* Timer::GetNumberSprites()
{
	return &numbers;
}

int Timer::GetCount()
{
	return time;
}

void Timer::SetCount(float count)
{
	count = count < 0 ? 0 :
		(
			count > maxNumber ? maxNumber : count
			);
	time = count;
	std::string points = BorisOperations::PadNumber(round(time), digitCount);
	for (size_t i = 0; i < points.size(); i++)
	{
		char c = points.at(i);
		int digit = (int)c - 48;
		numbers.at(i)->SetDisplayNumber(digit);
	}
}