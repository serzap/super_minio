#include "TextureManager.hpp"
#include "GameController.hpp"

TextureManager::TextureManager(GameController& gameCtrl)
	: mGameCtrl(gameCtrl)
{
	//INFO: should call before creating sprites
	loadAllImages();
}

TextureManager::~TextureManager()
{

}

void TextureManager::loadImage(const std::string & filePath, const std::string& imageName)
{
	if (false == isImageInList(imageName))
	{
		SDL_Surface* image = IMG_Load(filePath.c_str());
		if (image)
		{
			mImageList[imageName] = image;
		}
		else
		{
			std::cout << "Image is not loaded. Probably wrong path" << std::endl;
		}
	}
	else
	{
		std::cout << "Image with the same name is already exists" << std::endl;
	}
}

void TextureManager::loadAllImages()
{
	//player image
	loadImage("test_main_char_sheet.png", "main_char");
	loadImage("test_background_tileset.png", "background");
}

SDL_Surface* TextureManager::getImageByName(const std::string & name)
{
	if (true == isImageInList(name))
	{
		return mImageList[name];
	}
	else
	{
		std::cout << "No image found" << std::endl;
		return NULL;
	}
}

bool TextureManager::isImageInList(const std::string & name)
{
	return mImageList.count(name) > 0;
}

SDL_Texture* TextureManager::createTextureFromImage(const std::string imageName)
{
	SDL_Surface* surface = getImageByName(imageName);
	return SDL_CreateTextureFromSurface(mGameCtrl.getGraphics().getRenderer(), surface);
}