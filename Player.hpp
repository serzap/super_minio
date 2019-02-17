#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "AnimatedSprite.hpp"
#include "GameHelper.hpp"

class Player : public AnimatedSprite
{
public:
	Player(GameController& gameCtrl);

	~Player();

	void draw() override;
	void update(double elapsedTime) override;

	void moveRight();
	void moveLeft();
	void stopMoving();

protected:
	void animationDone(std::string currentAnimation) override;
	void setupAnimations() override;

private:
	double mDx, mDy;
	GameHelper::Direction mDir;
};

#endif 