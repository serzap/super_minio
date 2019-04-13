#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include "SDL.h"
#include "SDL_image.h"
#include <map>
#include <string>

class GameController;
class TextureManager
{
//TODO: reduce coupling (dependency only with Graphics)
public:
	TextureManager(GameController& gameCtrl);
	~TextureManager();

	void loadAllImages();
	SDL_Texture* createTextureFromImage(const std::string imageName);
	void loadImage(const std::string & filePath, const std::string& imageName);

private:
	SDL_Surface* getImageByName(const std::string& name);
	bool isImageInList(const std::string & name);

private:
	GameController& mGameCtrl;
	std::map<std::string, SDL_Surface*> mImageList;
};

#endif