#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "Graphics.hpp"

//TODO: replace includes with forward declarations in headers
//TODO: replace std::pair with vector class

class GameController;
class Level
{
public:
	Level(GameController& gameCtrl, std::string mapName, std::pair<int, int> spawnPoint);
	~Level();

	void update(int elapsedTime);
	void draw();

private:
	GameController& mGameCtrl;
	std::string mMapName;
	std::pair<int, int> mSpawnPoint;
	std::pair<int, int> mSize;
	SDL_Texture * mBackgroundTexture;

	void loadMap(std::string mapName);
};


#endif