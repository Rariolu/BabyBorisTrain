#include "NumberSprite.h"

NumberSprite::NumberSprite() : Sprite(texturemanager->GetTexture("0"))
{
	SetActive(true);
}

NumberSprite::~NumberSprite()
{

}

int NumberSprite::GetDisplayNumber()
{
	return displayNumber;
}

void NumberSprite::SetDisplayNumber(int num)
{
	displayNumber = num;
	SetTexture(texturemanager->GetTexture(BorisOperations::Int_to_LPCSTR(num)));
}