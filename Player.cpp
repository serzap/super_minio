#include "Player.hpp"
#include "GameController.hpp"

namespace PLAYER_CONSTANTS
{
	const double WALK_SPEED = 0.2;
}

Player::Player(GameController& gameCtrl)
	: AnimatedSprite(gameCtrl, "main_char", 0, 0, 16, 16, 100, 100, 100)
	, mDx(0.0)
	, mDy(0.0)
	, mDir(GameHelper::RIGHT)
{
	setupAnimations();
	playAnimation("IdleRight");
}

Player::~Player()
{

}

void Player::setupAnimations()
{
	addAnimation(1, 0, 0, "IdleLeft", 16, 16, std::make_pair(0, 0));
	addAnimation(1, 0, 16, "IdleRight", 16, 16, std::make_pair(0, 0));
	addAnimation(3, 0, 0, "RunLeft", 16, 16, std::make_pair(0, 0));
	addAnimation(3, 0, 16, "RunRight", 16, 16, std::make_pair(0, 0));
}

void Player::animationDone(std::string currentAnimation)
{

}

void Player::moveLeft()
{
	mDx = -PLAYER_CONSTANTS::WALK_SPEED;
	playAnimation("RunLeft");
	mDir = GameHelper::LEFT;
}

void Player::moveRight()
{
	mDx = PLAYER_CONSTANTS::WALK_SPEED;
	playAnimation("RunRight");
	mDir = GameHelper::RIGHT;
}

void Player::stopMoving()
{
	mDx = 0.0;
	playAnimation(mDir == GameHelper::RIGHT ? "IdleRight" : "IdleLeft");
}
void Player::update(double elapsedTime)
{
	mX += static_cast<int>(mDx * elapsedTime);
	AnimatedSprite::update(elapsedTime);
}

void Player::draw()
{
	AnimatedSprite::draw();
}