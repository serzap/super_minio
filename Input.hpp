#ifndef INPUT_HPP
#define INPUT_HPP

#include "SDL.h"
#include <map>

class GameController;
class Input
{
public:
	Input(GameController& gameCtrl);
	~Input();
	void beginNewFrame();
	void keyUpEvent(const SDL_Event& event);
	void keyDownEvent(const SDL_Event& event);

	bool wasKeyPressed(SDL_Scancode key);
	bool wasKeyReleased(SDL_Scancode key);
	bool isKeyHeld(SDL_Scancode key);
private:
	GameController& mGameCtrl;
	std::map<SDL_Scancode, bool> mHeldKeys;
	std::map<SDL_Scancode, bool> mPressedKeys;
	std::map<SDL_Scancode, bool> mReleasedKeys;
};

#endif