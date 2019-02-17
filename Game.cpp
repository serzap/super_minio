#include "Game.hpp"

namespace
{
	const double FPS = 60;
	const double TIME_PER_FRAME = (1.0 / FPS) * 1000;
}

Game::Game()
	: mPlayer()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	gameLoop();
}

Game::~Game()
{

}

void Game::gameLoop()
{
	Graphics graphics;
	Input input;
	SDL_Event event;

	mPlayer = Player(graphics, 100, 100);

	double previous = SDL_GetTicks();
	double lag = 0.0;

	while (true)
	{
		double current = SDL_GetTicks();
		double elapsed = current - previous;
		previous = current;
		lag += elapsed;

		input.beginNewFrame();
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.repeat == 0)
				{
					input.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP)
			{
				input.keyUpEvent(event);
			}
			if (event.type == SDL_QUIT)
			{
				return;
			}
		}

		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true)
		{
			return;
		}
		else if (input.isKeyHeld(SDL_SCANCODE_LEFT) == true)
		{
			mPlayer.moveLeft();
		}
		else if (input.isKeyHeld(SDL_SCANCODE_RIGHT) == true)
		{
			mPlayer.moveRight();
		}

		if (!input.isKeyHeld(SDL_SCANCODE_LEFT) && !input.isKeyHeld(SDL_SCANCODE_RIGHT))
		{
			mPlayer.stopMoving();
		}

		while (lag >= TIME_PER_FRAME)
		{
			update(TIME_PER_FRAME);
			lag -= TIME_PER_FRAME;
			draw(graphics);
		}
	}
}

void Game::draw(Graphics& graphics)
{
	graphics.clearScreen();
	mPlayer.draw(graphics);
	graphics.updateScreen();
}

void Game::update(double elapsedTime)
{
	mPlayer.update(elapsedTime);
}