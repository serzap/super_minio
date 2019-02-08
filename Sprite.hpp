#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "Graphics.hpp"

class Sprite
{
public:
	Sprite();
	Sprite(Graphics & graphics, const std::string& filePath, const std::string& name,
		int sourceX, int sourceY, int width, int height, double posX, double posY);
	virtual ~Sprite();
	virtual void update();
	void draw(Graphics& graphics, int x, int y);

private:
	SDL_Rect mSourceRect;
	SDL_Texture* mTexture;
	double mX, mY;

};

#endif