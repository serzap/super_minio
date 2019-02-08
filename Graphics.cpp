#include "Graphics.hpp"

Graphics::Graphics()
{
	SDL_CreateWindowAndRenderer(640, 480, 0, &mWindow, &mRenderer);
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	SDL_SetWindowTitle(mWindow, "Super Minio");
}

Graphics::~Graphics()
{
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

void Graphics::loadImage(const std::string & filePath, const std::string& imageName)
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

SDL_Surface* Graphics::getImageByName(const std::string & name)
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

void Graphics::drawTexture(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle)
{
	SDL_RenderCopy(mRenderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::updateScreen()
{
	SDL_RenderPresent(mRenderer);
}

void Graphics::clearScreen()
{
	SDL_RenderClear(mRenderer);
}

bool Graphics::isImageInList(const std::string & name)
{
	return mImageList.count(name) > 0;
}