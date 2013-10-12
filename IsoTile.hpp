#ifndef ISO_TILE_HPP_INCLUDED
#define ISO_TILE_HPP_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <vector>
#include <string>

class IsoPT
{
	protected:
		SDL_Surface* img;
		std::string name;
		int flags;
	public:
		IsoPT();
		IsoPT(std::string name, int flags);
		~IsoPT();
		inline int getImgHeight() const {return img->h;} 
		inline int getImgWidth() const {return img->w;}
		inline SDL_Surface* getImgSurface() const {return img;}
};

typedef struct
{
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
		void inline addTile(std::string name, int flags){_PTs.push_back(new IsoPT(name, flags) );}
		inline int getDefaultTileHeight(){return defaultTile == NULL ? _PTs[0]->getImgHeight() : defaultTile->getImgHeight(); }
		inline int getDefaultTileWidth(){return defaultTile == NULL ? _PTs[0]->getImgWidth() : defaultTile->getImgWidth(); }
		inline IsoPT* getDefaultTile(){return defaultTile == NULL ? _PTs[0] : defaultTile;}
};

#endif
