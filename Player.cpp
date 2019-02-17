#include "Player.hpp"

namespace PLAYER_CONSTANTS
{
	const double WALK_SPEED = 0.2;
}

Player::Player()
{

}

Player::Player(Graphics& graphics, double x, double y)
	: AnimatedSprite(graphics, "test_sprite_sheet.png", "hero", 0, 0, 16, 16, x, y, 100)
	, mDx(0.0)
	, mDy(0.0)
	, mDir(GAME_HELPER::RIGHT)
{
	graphics.loadImage("test_sprite_sheet.png", "hero");
	setupAnimations();
	playAnimation("RunRight");
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
	mDir = GAME_HELPER::LEFT;
}

void Player::moveRight()
{
	mDx = PLAYER_CONSTANTS::WALK_SPEED;
	playAnimation("RunRight");
	mDir = GAME_HELPER::RIGHT;
}

void Player::stopMoving()
{
	mDx = 0.0;
	playAnimation(mDir == GAME_HELPER::RIGHT ? "IdleRight" : "IdleLeft");
}
void Player::update(double elapsedTime)
{
	mX += mDx * elapsedTime;
	AnimatedSprite::update(elapsedTime);
}

void Player::draw(Graphics& graphics)
{
	AnimatedSprite::draw(graphics, mX, mY);
}