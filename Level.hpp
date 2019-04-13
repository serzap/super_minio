#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "Graphics.hpp"
#include "Tile.hpp"
#include "Tileset.hpp"
#include "GameHelper.hpp"
#include <vector>

using namespace GameHelper;

//TODO: replace includes with forward declarations in headers

class GameController;
class Level
{
public:
	Level(GameController& gameCtrl, std::string mapName, Vector2D spawnPoint);
	~Level();

	void update(int elapsedTime);
	void draw();

private:
	GameController& mGameCtrl;
	std::string mMapName;
	Vector2D mSpawnPoint;
	Vector2D mMapSize;
	Vector2D mTileSize;
	SDL_Texture* mBackgroundTexture;

	std::vector<Tile> mTileList;
	Tileset mTileset;

	void loadMap(std::string mapName);
};

#endif