#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "SDL.h"
#include "SDL_image.h"
#include <map>
#include <string>
#include <iostream>

class GameController;
class Graphics
{
public:
	Graphics(GameController& gameCtrl);
	~Graphics();

	void drawTexture(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);
	void updateScreen();
	void clearScreen();

	SDL_Renderer* getRenderer() const;
private:
	GameController& mGameCtrl;
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
};

inline SDL_Renderer* Graphics::getRenderer() const
{
	return mRenderer;
}

#endif