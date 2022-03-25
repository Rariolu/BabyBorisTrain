#include "Misc.h"

CSRand* Misc::rand = new CSRand();
int Misc::time = 0;

float Misc::Lerp(float a, float b, float f)
{
	return a + f*(b - a);
}

Vector2 Misc::Lerp(Vector2 a, Vector2 b, float f)
{
	float x = Lerp(a.X, b.X, f);
	float y = Lerp(a.Y, b.Y, f);
	return {x, y};
}

float Misc::GetDistance(Sprite* s1, Sprite* s2)
{
	//return GetDistance(s1->GetCentre(), s2->GetCentre());
	return GetDistance(s1->GetPosition(), s2->GetPosition());
}

FloatRect Misc::GetFloatRect(SDL_Rect sdlrect)
{
	return{ (float)sdlrect.x,(float)sdlrect.y, (float)sdlrect.w, (float)sdlrect.h };
}

float Misc::GetDistance(SDL_Rect a, SDL_Rect b)
{
	return GetDistance(GetFloatRect(a), GetFloatRect(b));
}

float Misc::GetDistance(FloatRect a, FloatRect b)
{
	float xdist = (a.X- b.X);
	float ydist = (a.Y - b.Y);
	return sqrt(pow(xdist, 2) + pow(ydist, 2));
}

float Misc::GetDistance(SDL_Point a, SDL_Point b)
{
	float xdist = (a.x - b.x);
	float ydist = (a.y - b.y);
	return sqrt(pow(xdist, 2) + pow(ydist, 2));
}