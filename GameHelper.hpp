#ifndef GAME_HELPER_HPP
#define GAME_HELPER_HPP

namespace GameHelper
{
	const double FPS = 60;
	const double TIME_PER_FRAME = (1.0 / FPS) * 1000;

	enum Direction
	{
		RIGHT,
		LEFT,
		UP,
		DOWN,
	};

	struct Vector2D
	{
		Vector2D() : x(0), y(0) {}
		Vector2D(int x, int y) : x(x), y(y) {}

		int x;
		int y;
	};
}

#endif