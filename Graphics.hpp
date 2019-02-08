#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "SDL.h"
#include "SDL_image.h"
#include <map>
#include <string>
#include <iostream>

class Graphics
{
public:
	Graphics();
	~Graphics();

	void loadImage(const std::string & filePath, const std::string& imageName);
	SDL_Surface* getImageByName(const std::string& name);
	void drawTexture(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);
	void updateScreen();
	void clearScreen();

	SDL_Renderer* getRenderer() const;
private:
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;

	std::map<std::string, SDL_Surface*> mImageList;

	bool isImageInList(const std::string & name);
};

inline SDL_Renderer* Graphics::getRenderer() const
{
	return mRenderer;
}

#endif