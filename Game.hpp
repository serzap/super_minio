#ifndef GAME_HPP
#define GAME_HPP

#include "Graphics.hpp"
#include "Input.hpp"
#include "Player.hpp"

class Game
{
public:
	Game();
	~Game();

private:
	void gameLoop();
	void draw(Graphics& graphics);
	void update(double elapsedTime);

	Player mPlayer;
};

#endif 