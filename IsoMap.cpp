#include "IsoMap.hpp"
#include <iostream>

IsoMap::IsoMap() : IsoMap(25, 25, NULL) {}

IsoMap::IsoMap(int sizex, int sizey) :  IsoMap(sizex, sizey, NULL){}

IsoMap::IsoMap(int sizex, int sizey, IsoPrototileSet* prototiles) : sizex(sizex), sizey(sizey), prototiles(prototiles)
{
	tiles = new IsoTile*[sizex];
	for(int i(0); i < sizex; ++i) tiles[i] = new IsoTile[sizey];

	for(int i(0); i < sizex; ++i)
	{
		for(int j(0); j < sizey; ++j)
		{
			tiles[i][j].proto = prototiles->getDefaultTile();
		}
	}
}

IsoMap::~IsoMap()
{
	for(int i(0); i < sizex; ++i) delete tiles[i];
	delete tiles;
}

void IsoMap::render(SDL_Surface* screen, IsoCamera* camera)
{
	SDL_Rect tilePos;//used in rendering
	for(int i(0); i < sizex; ++i)
	{
		for(int j(0); j < sizey; ++j)
		{
			tilePos.x = (i * prototiles->getDefaultTileWidth()  / 2) + (j * prototiles->getDefaultTileWidth() / 2) + camera->getX();
			tilePos.y = (i * prototiles->getDefaultTileHeight() / 2) - (j * prototiles->getDefaultTileHeight() / 2) + camera->getY();
			SDL_BlitSurface(tiles[i][j].proto->getImgSurface(), NULL, screen, &tilePos);
		}
	}
}

