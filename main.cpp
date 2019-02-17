#define SDL_MAIN_HANDLED
#include "GameController.hpp"

int main()
{
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_EVERYTHING);
	GameController game;
	return 0;
}