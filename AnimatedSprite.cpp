#include "AnimatedSprite.hpp"
#include "GameController.hpp"

AnimatedSprite::AnimatedSprite(GameController& gameCtrl)
: Sprite(gameCtrl)
{
}

AnimatedSprite::AnimatedSprite(GameController& gameCtrl, const std::string& filePath, const std::string& name, int sourceX, int sourceY,
	int width, int height, int posX, int posY, double timeToUpdate)
	: Sprite(gameCtrl, filePath, name, sourceX, sourceY, width, height, posX, posY)
	, mFrameIndex(0)
	, mTimeToUpdate(timeToUpdate)
	, mIsVisible(true)
	, mCurrentAnimationOnce(false)
	, mCurrentAnimation("")
	, mTimeElapsed(0.0)
{

}

AnimatedSprite::~AnimatedSprite()
{

}

void AnimatedSprite::addAnimation(int frames, int x, int y, const std::string& name, int width, int height, std::pair<int, int> offset)
{
	std::vector<SDL_Rect> rectangles;
	for (int i = 0; i < frames; ++i)
	{
		SDL_Rect newRect = { (i + x) * width, y, width, height };
		rectangles.push_back(newRect);
	}
	mAnimations.insert(std::pair<std::string, std::vector<SDL_Rect>>(name, rectangles));
	mOffsets.insert(std::pair<std::string,	std::pair<int, int>>(name, offset));
}

void AnimatedSprite::resetAnimations()
{
	mAnimations.clear();
	mOffsets.clear();
}

void AnimatedSprite::playAnimation(std::string animation, bool once)
{
	mCurrentAnimationOnce = once;
	if (mCurrentAnimation != animation)
	{
		mCurrentAnimation = animation;
		mFrameIndex = 0;
	}
}

void AnimatedSprite::setVisible(bool visible)
{
	mIsVisible = visible;
}

void AnimatedSprite::stopAnimation()
{
	mFrameIndex = 0;
	animationDone(mCurrentAnimation);
}

void AnimatedSprite::update(double elapsedTime)
{
	mTimeElapsed += elapsedTime;
	if (mTimeElapsed > mTimeToUpdate)
	{
		if (mFrameIndex + 1 < mAnimations[mCurrentAnimation].size())
		{
			++mFrameIndex;
		}
		else
		{
			if (mCurrentAnimationOnce == true)
			{
				setVisible(false);
			}
			mFrameIndex = 0;
			animationDone(mCurrentAnimation);
		}
		mTimeElapsed -= mTimeToUpdate;
	}
}

void AnimatedSprite::draw()
{
	if (mIsVisible)
	{
		SDL_Rect destRect;
		destRect.x = mX + mOffsets[mCurrentAnimation].first;
		destRect.y = mY + mOffsets[mCurrentAnimation].second;
		destRect.w = mSourceRect.w * 2;
		destRect.h = mSourceRect.h * 2;

		SDL_Rect sourceRect = mAnimations[mCurrentAnimation][mFrameIndex];
		mGameCtrl.getGraphics().drawTexture(mTexture, &sourceRect, &destRect);
	}
}
