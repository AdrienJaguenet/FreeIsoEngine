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

	for(int i (0); i < protoelements.size(); ++i) delete protoelements[i];
	protoelements.pop_back();
}

void IsoMap::render(SDL_Surface* screen, IsoCamera* camera)
{
	//render
	SDL_Rect tilePos;//used in rendering
	SDL_Rect elmPos;
	IsoMapElement* element(NULL);
	int currentElm(0), k(0), done(false), tile_h(prototiles->getDefaultTileHeight() ), tile_w(prototiles->getDefaultTileWidth() );
	for(int i(0); i < sizex; ++i)
	{
		for(int j(sizey - 1); j >= 0; --j)
		{
			//draw the tile
			tilePos.x = (i * tile_w / 2) + (j * tile_w / 2) + camera->getX();
			tilePos.y = (i * tile_h / 2) - (j * tile_h / 2) + camera->getY();
			SDL_BlitSurface(tiles[i][j].proto->getImgSurface(), NULL, screen, &tilePos);
		}
	}
	for(int k(0); k < map_elements.size(); ++k)
	{
		element = map_elements[k];
		elmPos.x = (int) (element->posX * (tile_w / 2) + element->posY * (tile_w / 2) + camera->getX() + (element->proto->getImgWidth() ) );
		elmPos.y = (int) (element->posX * (tile_h / 2) - element->posY * (tile_h / 2) + camera->getY() - element->proto->getImgHeight() );
		SDL_BlitSurface(map_elements[k]->proto->getImg(), NULL, screen, &elmPos);
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

void IsoMap::placeElement(IsoMapElement* element)
{
	if(map_elements.size() == 0)
	{
		map_elements.push_back(element);
		return;
	}
	for(int i(0); i < map_elements.size(); ++i)
	{
		if(map_elements[i]->posX <= element->posY)
		{
			if(i < map_elements.size() - 1)
			{
				if(map_elements[i + 1]->posX > element->posX)
				{
					if(map_elements[i]->posY <= element->posY && map_elements[i + 1]->posY > element->posY)
					{
						map_elements.insert(map_elements.begin() + i, element);
						return;
					}
				}
			}
			else if(map_elements[i]->posY <= element->posY)
			{
				map_elements.push_back(element);
				return;
			}
			else
			{
				map_elements.insert(map_elements.begin() + i, element);
				return;
			}
		}
	}
	map_elements.push_back(element);
}


