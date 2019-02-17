#include "Sprite.hpp"
#include "GameController.hpp"

Sprite::Sprite(GameController& gameCtrl)
	: mGameCtrl(gameCtrl)
{

}

Sprite::Sprite(GameController& gameCtrl, const std::string& imageName,
	int sourceX, int sourceY, int width, int height, int posX, int posY)
	: mGameCtrl(gameCtrl)
	, mX(posX)
	, mY(posY)
{
	mSourceRect.x = sourceX;
	mSourceRect.y = sourceY;
	mSourceRect.w = width;
	mSourceRect.h = height;

	mTexture = mGameCtrl.getTextureManager().createTextureFromImage(imageName);
}

Sprite::~Sprite()
{

}

void Sprite::draw()
{
	SDL_Rect destRect = { mX, mY, mSourceRect.w, mSourceRect.h };
	mGameCtrl.getGraphics().drawTexture(mTexture, &mSourceRect, &destRect);
}

void Sprite::update(double elapsedTime)
{

}