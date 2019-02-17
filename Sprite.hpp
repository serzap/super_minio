#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "Graphics.hpp"

class GameController;
class Sprite
{
public:
	Sprite(GameController& gameCtrl);
	Sprite(GameController& gameCtrl, const std::string& filePath, const std::string& name,
		int sourceX, int sourceY, int width, int height, int posX, int posY);
	virtual ~Sprite();
	virtual void update(double elapsedTime);
	virtual void draw();

protected:
	GameController& mGameCtrl;
	SDL_Rect mSourceRect;
	SDL_Texture* mTexture;
	int mX, mY;
};

#endif