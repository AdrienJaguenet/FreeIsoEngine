#include "IsoMap.hpp"
#include <iostream>

IsoMap::IsoMap() : IsoMap(25, 25, NULL) {}

IsoMap::IsoMap(int sizex, int sizey) :  IsoMap(sizex, sizey, NULL){}

IsoMap::IsoMap(int sizex, int sizey, IsoPT_Manager* pt_manager) : sizex(sizex), sizey(sizey), pt_manager(pt_manager), nframe(0), lastframetime(0), thisframetime(0)
{
	if(pt_manager == NULL)
	{
		std::cout<<"[Free IsoEngine warning]: instantiated an IsoMap with NULL pt_manager set pointer. Expect a memory error."<<std::endl;
	}

	tiles = new IsoTile*[sizex];
	for(int i(0); i < sizex; ++i) tiles[i] = new IsoTile[sizey];

	for(int i(0); i < sizex; ++i)
	{
		for(int j(0); j < sizey; ++j)
		{
			tiles[i][j].proto = pt_manager->getDefaultTile();
			tiles[i][j].frameid = 0;
		}
	}

	m = (float) pt_manager->getDefaultTileHeight() / (float) pt_manager->getDefaultTileWidth();
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
	SDL_Rect elmPos;
	IsoMapElement* element(NULL);
	int tile_h(pt_manager->getDefaultTileHeight() ), tile_w(pt_manager->getDefaultTileWidth() );
	for(int i(0); i < sizex; ++i)
	{
		for(int j(sizey - 1); j >= 0; --j)
		{
			//draw the tile
			tilePos.x = (i * tile_w / 2) + (j * tile_w / 2) + camera->getX();
			tilePos.y = (i * tile_h / 2) - (j * tile_h / 2) + camera->getY();
			tiles[i][j].proto->render(screen, &tilePos, tiles[i][j].frameid);
			if(nframe % 50 == 0)tiles[i][j].frameid++;
		}
	}
	for(unsigned int k(0); k < map_elements.size(); ++k)
	{
		element = map_elements[k];
		elmPos.x = (int) (element->posX * (tile_w / 2) + element->posY * (tile_w / 2) + camera->getX() + element->proto->getImgWidth()  );
		elmPos.y = (int) (element->posX * (tile_h / 2) - element->posY * (tile_h / 2) + camera->getY() - element->proto->getImgHeight() );
                map_elements[k]->proto->render(screen, &elmPos);
	}
	nframe++;
}

float IsoMap::getXFromScreen(int cx, int cy, IsoCamera* camera)
{
	return ((float) cy - (float) camera->getY() - ( (float) pt_manager->getDefaultTileHeight() / 2.0) + m * ( (float)cx - (float) camera->getX() ) )
						/
			(float) pt_manager->getDefaultTileHeight();
}

float IsoMap::getYFromScreen(int cx, int cy, IsoCamera* camera)
{
	return (m * ( (float)cx - (float) camera->getX() ) + ( (float) pt_manager->getDefaultTileHeight() / 2.0) + (float) camera->getY() - (float) cy)
						/
			(float) pt_manager->getDefaultTileHeight();
}

void IsoMap::setTileFromClick(SDL_Event *event, IsoCamera* camera, IsoPT* proto)
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
	for(unsigned int i(0); i < map_elements.size(); ++i)
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


