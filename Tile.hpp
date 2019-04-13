#ifndef TILE_HPP
#define TILE_HPP

#include <utility>
#include "GameHelper.hpp"

using namespace GameHelper;

class GameController;
struct SDL_Texture;

class Tile
{
public:
	Tile(GameController& gameCtrl, SDL_Texture* tileset, Vector2D size, Vector2D tilesetPos, Vector2D pos);
	~Tile();
	void update(int elapsedTime);
	void draw();
private:
	GameController& mGameCtrl;
	SDL_Texture* mTileset;
	Vector2D mSize;
	Vector2D mTilesetPos;
	Vector2D mPos;
};

#endif
