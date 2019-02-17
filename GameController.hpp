#ifndef GAME_HPP
#define GAME_HPP

#include "Graphics.hpp"
#include "Input.hpp"
#include "Player.hpp"

class GameController
{
public:
	GameController();
	~GameController();

	Input& getInput();
	Graphics& getGraphics();
	Player& getPlayer();

private:
	void gameLoop();
	void draw();
	void update(double elapsedTime);

	Graphics mGraphics;
	Input mInput;
	Player mPlayer;
};

inline Input& GameController::getInput()
{
	return mInput;
}

inline Graphics& GameController::getGraphics()
{
	return mGraphics;
}

inline Player& GameController::getPlayer()
{
	return mPlayer;
}
#endif 