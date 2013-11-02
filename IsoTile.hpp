#ifndef ISO_TILE_HPP_INCLUDED
#define ISO_TILE_HPP_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <vector>
#include <string>
#include <iostream>
#include "IsoSprites.hpp"

class IsoPT
{
	protected:
                IsoSprite* sprite;
		std::string name;
		int flags;
	public:
		IsoPT(IsoSprite* sprite, std::string name, int flags);
		~IsoPT();
		inline int getImgHeight() const {return sprite != NULL ? sprite->getImgHeight() : 0;} 
		inline int getImgWidth() const {return sprite != NULL ? sprite->getImgWidth() : 0;}
		inline void render(SDL_Surface* screen, SDL_Rect* pos, unsigned char frameid = 0, unsigned char time = 0) const {sprite->render(screen, pos, frameid, time);}
};

typedef struct
{
	unsigned char frameid;//used for animated tiles
	IsoPT *proto; /*prototile linked*/
} IsoTile;

class IsoPT_Manager
{
	protected:
		IsoPT* defaultTile;//used for rendering purposes, should have the same size as all the other tiles used
		std::vector<IsoPT*> _PTs;
	public:
		IsoPT_Manager(IsoPT* defaultTile);
		~IsoPT_Manager();
		void inline addTile(IsoSprite* sprite, std::string name, int flags){_PTs.push_back(new IsoPT(sprite, name, flags) );}
		void inline addTile(IsoPT* pt) {_PTs.push_back(pt);}
		inline int getDefaultTileHeight(){return defaultTile == NULL ? _PTs[0]->getImgHeight() : defaultTile->getImgHeight(); }
		inline int getDefaultTileWidth(){return defaultTile == NULL ? _PTs[0]->getImgWidth() : defaultTile->getImgWidth(); }
		inline IsoPT* getDefaultTile(){return defaultTile == NULL ? _PTs[0] : defaultTile;}
};

#endif
