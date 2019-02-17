#include "Sprite.hpp"
#include "GameController.hpp"

Sprite::Sprite(GameController& gameCtrl)
	: mGameCtrl(gameCtrl)
{

}

Sprite::Sprite(GameController& gameCtrl, const std::string& filePath, const std::string& name,
	int sourceX, int sourceY, int width, int height, int posX, int posY)
	: mGameCtrl(gameCtrl)
	, mX(posX)
	, mY(posY)
{
	mSourceRect.x = sourceX;
	mSourceRect.y = sourceY;
	mSourceRect.w = width;
	mSourceRect.h = height;

	//TODO: make texture manager and merge image and texture
	mGameCtrl.getGraphics().loadImage(filePath, name);
	SDL_Surface* surface = mGameCtrl.getGraphics().getImageByName(name);
	mTexture = SDL_CreateTextureFromSurface(mGameCtrl.getGraphics().getRenderer(), surface);
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