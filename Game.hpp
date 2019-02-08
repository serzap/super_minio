#ifndef GAME_HPP
#define GAME_HPP

#include "Graphics.hpp"
#include "Sprite.hpp"
#include "Input.hpp"

class Game
{
public:
	Game();
	~Game();

private:
	void gameLoop();
	void draw(Graphics& graphics);
	void update(double elapsedTime);

	Sprite mPlayer;
};

#endif 