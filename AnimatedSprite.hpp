#ifndef ANIMATED_SPRITE_HPP
#define ANIMATED_SPRITE_HPP

#include "Sprite.hpp"
#include <vector>

class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite(GameController& gameCtrl);
	AnimatedSprite(GameController& gameCtrl, const std::string& filePath, const std::string& name, int sourceX, int sourceY,
		int width, int height, int posX, int posY, double timeToUpdate);
	~AnimatedSprite();

	void update(double elapsedTime) override;
	void draw() override;

protected:
	double mTimeToUpdate;
	bool mCurrentAnimationOnce;
	std::string mCurrentAnimation;

	void addAnimation(int frames, int x, int y, const std::string& name, int width, int height, std::pair<int, int> offset);
	void resetAnimations();
	void stopAnimation();
	void setVisible(bool visible);
	virtual void animationDone(std::string currentAnimation) = 0;
	virtual void setupAnimations() = 0;
	void playAnimation(std::string animation, bool once = false);

private:
	std::map<std::string, std::vector<SDL_Rect>> mAnimations;
	std::map<std::string, std::pair<int, int>> mOffsets;

	int mFrameIndex;
	double mTimeElapsed;
	bool mIsVisible;
};

#endif