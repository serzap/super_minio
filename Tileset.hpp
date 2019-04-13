#ifndef TILESET_HPP
#define TILESET_HPP

#include "SDL.h"

class Tileset
{
public:
	Tileset();
	Tileset(int id, SDL_Texture* texture);
	~Tileset();

	SDL_Texture* getTexture();
private:
	int mID;
	SDL_Texture* mTexture;
};

inline SDL_Texture* Tileset::getTexture()
{
	return mTexture;
}

#endif