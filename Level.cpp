#include "Level.hpp"
#include "GameController.hpp"

Level::Level(GameController& gameCtrl, std::string mapName, std::pair<int, int> spawnPoint)	
	: mGameCtrl(gameCtrl)
	, mMapName(mapName)
	, mSpawnPoint(spawnPoint)
	, mSize(0,0)
{
	loadMap(mapName);
}

Level::~Level()
{
}

void Level::update(int elapsedTime)
{
}

void Level::draw()
{
	SDL_Rect sourceRect = { 0, 0, 32, 32 };
	SDL_Rect destRect;
	for (int x = 0; x < mSize.first; x += 32)
	{
		for (int y = 0; y < mSize.second; y += 32)
		{
			destRect.x = x;
			destRect.y = y;
			destRect.w = 32;
			destRect.h = 32;
			mGameCtrl.getGraphics().drawTexture(mBackgroundTexture, &sourceRect, &destRect);
		}
	}
}

void Level::loadMap(std::string mapName)
{
	mBackgroundTexture = mGameCtrl.getTextureManager().createTextureFromImage("background");
	mSize = std::make_pair(1280, 960);
}

