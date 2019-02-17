#include "Input.hpp"
#include "GameController.hpp"

Input::Input(GameController& gameCtrl)
	:mGameCtrl(gameCtrl)
{

}

Input::~Input()
{

}

void Input::beginNewFrame()
{
	mPressedKeys.clear();
	mReleasedKeys.clear();
}

void Input::keyDownEvent(const SDL_Event& event)
{
	mPressedKeys[event.key.keysym.scancode] = true;
	mHeldKeys[event.key.keysym.scancode] = true;
}

void Input::keyUpEvent(const SDL_Event& event)
{
	mReleasedKeys[event.key.keysym.scancode] = true;
	mHeldKeys[event.key.keysym.scancode] = false;
}


bool Input::wasKeyPressed(SDL_Scancode key)
{
	return mPressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key)
{
	return mReleasedKeys[key];
}

bool Input::isKeyHeld(SDL_Scancode key)
{
	return mHeldKeys[key];
}