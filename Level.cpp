#include "Level.hpp"
#include "GameController.hpp"

#include "tinyxml2.h"
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace tinyxml2; 

Level::Level(GameController & gameCtrl, std::string mapName, Vector2D spawnPoint)
	: mGameCtrl(gameCtrl)
	, mMapName(mapName)
	, mSpawnPoint(spawnPoint)
	, mMapSize(0,0)
	, mTileset()
{
	loadMap(mapName);
}

Level::~Level()
{
}

void Level::update(int elapsedTime)
{
}

void Level::draw()
{
	for (int i = 0; i < mTileList.size(); ++i)
	{
		mTileList.at(i).draw();
	}
}

//TODO: move to separate class XMLParser
void Level::loadMap(std::string mapName)
{
	/*Temp map
	mBackgroundTexture = mGameCtrl.getTextureManager().createTextureFromImage("background");
	mSize = std::make_pair(1280, 960);
	*/

	//Load the map file
	XMLDocument mapXMLDoc;
	std::stringstream ss;
	ss << mapName << ".tmx";
	auto mapRes = mapXMLDoc.LoadFile(ss.str().c_str());

	//TODO: make LOGGER class
	if (XMLError::XML_SUCCESS != mapRes)
	{
		std::cout << "Error during load map file" << std::endl;
		std::cout << ss.str() << std::endl;
	}

	XMLElement* mapElement = mapXMLDoc.FirstChildElement("map");

	int mapWidth, mapHeight;
	mapElement->QueryIntAttribute("width", &mapWidth);
	mapElement->QueryIntAttribute("height", &mapHeight);
	mMapSize = { mapWidth, mapHeight };


	int tileWidth, tileHeight;
	mapElement->QueryIntAttribute("tilewidth", &tileWidth);
	mapElement->QueryIntAttribute("tileheight", &tileHeight);
	mTileSize = { tileWidth, tileHeight };

	//loading the tileset
	int colInTileset = 0;
	XMLElement* tilesetElement = mapElement->FirstChildElement("tileset");
	if (tilesetElement != NULL)
	{
		int firstgid;
		tilesetElement->QueryIntAttribute("firstgid", &firstgid);

		std::stringstream sourceStringStream;
		const char* tilesetSource = tilesetElement->Attribute("source");
		sourceStringStream << tilesetSource;
		XMLDocument tilesetXMLDoc;
		auto tilesetRes = tilesetXMLDoc.LoadFile(sourceStringStream.str().c_str());
		if (XMLError::XML_SUCCESS != tilesetRes)
		{
			std::cout << "Error during load tileset file" << std::endl;
			std::cout << sourceStringStream.str() << std::endl;
		}
		auto tlsElement = tilesetXMLDoc.FirstChildElement("tileset");
		if (tlsElement == nullptr)
		{
			std::cout << "parse tileset unsuccessfully" << std::endl;
		}
	    tlsElement->QueryIntAttribute("columns", &colInTileset);
		const char* imageSource_cstr = tlsElement->FirstChildElement("image")->Attribute("source");
		std::string imageSource(imageSource_cstr);
		mGameCtrl.getTextureManager().loadImage(imageSource, imageSource);
		SDL_Texture* texture = mGameCtrl.getTextureManager().createTextureFromImage(imageSource);
		mTileset = Tileset(firstgid, texture);
	}

	//loading the layers
	XMLElement* layerElement = mapElement->FirstChildElement("layer");
	if (layerElement != NULL)
	{
		while (layerElement)
		{
			//loading the data element
			XMLElement* dataElement = layerElement->FirstChildElement("data");
			if (dataElement != NULL)
			{
				//loading the tile element
				XMLElement* tileElement = dataElement->FirstChildElement("tile");
				if (tileElement != NULL)
				{
					int tileCnt = 0;
					while (tileElement)
					{
						//build each individual tile here
						//if gid doesn't exist, no tile should be drawn, continue loop
						if (tileElement->Attribute("gid") == NULL)
						{
							++tileCnt;
							if (tileElement->NextSiblingElement("tile"))
							{
								tileElement = tileElement->NextSiblingElement("tile");
								continue;
							}
							else
							{
								break;
							}
						}
						else
						{
							int gid = 0;
							tileElement->QueryIntAttribute("gid", &gid);
							//calculate tile position on the map
							int xTilePosOnMap = 0;
							int yTilePosOnMap = 0;
							xTilePosOnMap = tileCnt % mapWidth;
							xTilePosOnMap *= tileWidth;
							yTilePosOnMap += tileHeight * (tileCnt / mapWidth);
							Vector2D tilePosOnMap(xTilePosOnMap, yTilePosOnMap);

							//calculate tile position in the tileset
							gid -= 1;
							int xTilePosInTileset = 0;
							int yTilePosInTileset = 0;
							xTilePosInTileset = gid % colInTileset;
							xTilePosInTileset *= tileWidth;
							yTilePosInTileset = tileHeight * (gid / colInTileset);
							Vector2D tilePosInTileset(xTilePosInTileset, yTilePosInTileset);

							Tile currTile(mGameCtrl, mTileset.getTexture(), Vector2D(tileWidth, tileHeight), tilePosInTileset, tilePosOnMap);

							mTileList.push_back(currTile);
							++tileCnt;
						}

						tileElement = tileElement->NextSiblingElement("tile");
					}
				}
			}
			layerElement = layerElement->NextSiblingElement("layer");
		}
	}
}

