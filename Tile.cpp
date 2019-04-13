#include "Tile.hpp"
#include "GameController.hpp"
#include <SDL.h>

Tile::Tile(GameController & gameCtrl, SDL_Texture * tileset, Vector2D size, Vector2D tilesetPos, Vector2D pos)
	: mGameCtrl(gameCtrl)
	, mTileset(tileset)
	, mSize(size)
	, mTilesetPos(tilesetPos)
	, mPos(pos)
{
}

Tile::~Tile()
{
}

void Tile::update(int elapsedTime)
{
}

void Tile::draw()
{
	SDL_Rect srcRect = { mTilesetPos.x, mTilesetPos.y, mSize.x, mSize.y };
	SDL_Rect destRect = { mPos.x, mPos.y, mSize.x, mSize.y };
	mGameCtrl.getGraphics().drawTexture(mTileset, &srcRect, &destRect);
}
