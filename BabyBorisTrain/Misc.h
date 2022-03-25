#ifndef _MISC_H
#define _MISC_H

#include "Sprite.h"
#include "CSRand.h"

class Misc
{
	public:
		static int time;
		static float Lerp(float a, float b, float f);
		static Vector2 Lerp(Vector2 a, Vector2 b, float f);
		static float GetDistance(Sprite* s1, Sprite* s2);
		static FloatRect GetFloatRect(SDL_Rect sdlrect);
		static float GetDistance(SDL_Rect sdlrect, SDL_Rect b);
		static float GetDistance(FloatRect a, FloatRect b);
		static float GetDistance(SDL_Point a, SDL_Point b);
		static CSRand* rand;
};

#endif