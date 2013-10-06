#include "IsoMap.hpp"
#include <iostream>

IsoMap::IsoMap() : IsoMap(25, 25, NULL) {}

IsoMap::IsoMap(int sizex, int sizey) :  IsoMap(sizex, sizey, NULL){}

IsoMap::IsoMap(int sizex, int sizey, IsoPrototileSet* prototiles) : sizex(sizex), sizey(sizey), prototiles(prototiles)
{
	if(prototiles == NULL)
	{
		std::cout<<"[Free IsoEngine warning]: instantiated an IsoMap with NULL prototiles set pointer. Expect a memory error."<<std::endl;
	}

	tiles = new IsoTile*[sizex];
	for(int i(0); i < sizex; ++i) tiles[i] = new IsoTile[sizey];

	for(int i(0); i < sizex; ++i)
	{
		for(int j(0); j < sizey; ++j)
		{
			tiles[i][j].proto = prototiles->getDefaultTile();
		}
	}

	m = (float) prototiles->getDefaultTileHeight() / (float) prototiles->getDefaultTileWidth();
}

IsoMap::~IsoMap()
{
	for(int i(0); i < sizex; ++i) delete tiles[i];
	delete tiles;
}

void IsoMap::render(SDL_Surface* screen, IsoCamera* camera)
{
	//render
	SDL_Rect tilePos;//used in rendering
	for(int i(0); i < sizex; ++i)
	{
		for(int j(sizey - 1); j >= 0; --j)
		{
			tilePos.x = (i * prototiles->getDefaultTileWidth()  / 2) + (j * prototiles->getDefaultTileWidth() / 2) + camera->getX();
			tilePos.y = (i * prototiles->getDefaultTileHeight() / 2) - (j * prototiles->getDefaultTileHeight() / 2) + camera->getY();
			SDL_BlitSurface(tiles[i][j].proto->getImgSurface(), NULL, screen, &tilePos);
		}
	}
}

float IsoMap::getXFromScreen(int cx, int cy, IsoCamera* camera)
{
	return ((float) cy - (float) camera->getY() - ( (float) prototiles->getDefaultTileHeight() / 2.0) + m * ( (float)cx - (float) camera->getX() ) ) 
						/
			(float) prototiles->getDefaultTileHeight();
}

float IsoMap::getYFromScreen(int cx, int cy, IsoCamera* camera)
{
	return (m * ( (float)cx - (float) camera->getX() ) + ( (float) prototiles->getDefaultTileHeight() / 2.0) + (float) camera->getY() - (float) cy) 
						/
			(float) prototiles->getDefaultTileHeight();
}

void IsoMap::setTileFromClick(SDL_Event *event, IsoCamera* camera, IsoPrototile* proto)
{
	float x( getXFromScreen(event->button.x, event->button.y, camera) );
	float y( getYFromScreen(event->button.x, event->button.y, camera) );
	if(x >= 0 && y >= 0 && x < sizex && y < sizey) tiles[(int)x][(int)y].proto = proto;
}

