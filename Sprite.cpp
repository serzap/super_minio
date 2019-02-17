#include "Sprite.hpp"

Sprite::Sprite()
{

}

Sprite::Sprite(Graphics & graphics, const std::string& filePath, const std::string& name,
	int sourceX, int sourceY, int width, int height, double posX, double posY)
	: mX(posX)
	, mY(posY)
{
	mSourceRect.x = sourceX;
	mSourceRect.y = sourceY;
	mSourceRect.w = width;
	mSourceRect.h = height;

	//TODO: make texture manager and merge image and texture
	graphics.loadImage(filePath, name);
	SDL_Surface* surface = graphics.getImageByName(name);
	mTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(), surface);
}

Sprite::~Sprite()
{

}

void Sprite::draw(Graphics& graphics, int x, int y)
{
	SDL_Rect destRect = { x, y, mSourceRect.w, mSourceRect.h };
	graphics.drawTexture(mTexture, &mSourceRect, &destRect);
}

void Sprite::update(double elapsedTime)
{

}