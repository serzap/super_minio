#include "GameController.hpp"

using namespace GameHelper;

GameController::GameController()
	: mInput(*this)
	, mGraphics(*this)
	, mTextureManager(*this)
	, mPlayer(*this)
{
	gameLoop();
}

GameController::~GameController()
{

}

void GameController::gameLoop()
{
	SDL_Event event;
	double previous = SDL_GetTicks();
	double lag = 0.0;

	while (true)
	{
		double current = SDL_GetTicks();
		double elapsed = current - previous;
		previous = current;
		lag += elapsed;

		mInput.beginNewFrame();
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.repeat == 0)
				{
					mInput.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP)
			{
				mInput.keyUpEvent(event);
			}
			if (event.type == SDL_QUIT)
			{
				return;
			}
		}

		if (mInput.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true)
		{
			return;
		}
		else if (mInput.isKeyHeld(SDL_SCANCODE_LEFT) == true)
		{
			mPlayer.moveLeft();
		}
		else if (mInput.isKeyHeld(SDL_SCANCODE_RIGHT) == true)
		{
			mPlayer.moveRight();
		}

		if (!mInput.isKeyHeld(SDL_SCANCODE_LEFT) && !mInput.isKeyHeld(SDL_SCANCODE_RIGHT))
		{
			mPlayer.stopMoving();
		}

		while (lag >= GameHelper::TIME_PER_FRAME)
		{
			update(TIME_PER_FRAME);
			lag -= TIME_PER_FRAME;
			draw();
		}
	}
}

void GameController::draw()
{
	mGraphics.clearScreen();
	mPlayer.draw();
	mGraphics.updateScreen();
}

void GameController::update(double elapsedTime)
{
	mPlayer.update(elapsedTime);
}