#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "AnimatedSprite.hpp"
#include "GameHelper.hpp"

class Player : public AnimatedSprite
{
public:
	Player();
	Player(Graphics& graphics, double x, double y);

	~Player();

	void draw(Graphics& graphics);
	void update(double elapsedTime);

	void animationDone(std::string currentAnimation) override;
	void setupAnimations() override; 

	void moveRight();
	void moveLeft();
	void stopMoving();

private:
	double mDx, mDy;
	GAME_HELPER::Direction mDir;
};

#endif 