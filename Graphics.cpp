#include "Graphics.hpp"
#include "GameController.hpp"

Graphics::Graphics(GameController& gameCtrl)
	:mGameCtrl(gameCtrl)
{
	SDL_CreateWindowAndRenderer(640, 512, 0, &mWindow, &mRenderer);
	SDL_SetWindowTitle(mWindow, "Super Minio");
}

Graphics::~Graphics()
{
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

void Graphics::drawTexture(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle)
{
	SDL_RenderCopy(mRenderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::updateScreen()
{
	SDL_RenderPresent(mRenderer);
}

void Graphics::clearScreen()
{
	SDL_RenderClear(mRenderer);
}
