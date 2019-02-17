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
}

#endif