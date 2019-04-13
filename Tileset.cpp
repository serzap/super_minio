#include "Tileset.hpp"

Tileset::Tileset()
	: mID(-1)
	, mTexture(nullptr)
{
}

Tileset::Tileset(int id, SDL_Texture * texture)
	: mID(id)
	, mTexture(texture)
{
}

Tileset::~Tileset()
{
}
