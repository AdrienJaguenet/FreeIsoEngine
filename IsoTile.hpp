#ifndef ISO_TILE_HPP_INCLUDED
#define ISO_TILE_HPP_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <vector>
#include <string>

class IsoPrototile
{
	protected:
		SDL_Surface* img;
		std::string name;
		int flags;
	public:
		IsoPrototile();
		IsoPrototile(std::string name, int flags);
		~IsoPrototile();
		inline int getImgHeight() const {return img->h;} 
		inline int getImgWidth() const {return img->w;}
		inline SDL_Surface* getImgSurface() const {return img;}
};

typedef struct
{
	IsoPrototile *proto; /*prototile linked*/
} IsoTile;

class IsoPrototileSet //can load prototiles from files
{
	public:
		std::vector<IsoPrototile*> prototiles;

		IsoPrototileSet();
		IsoPrototileSet(std::string path);//path to the file to load prototiles (probably an xml file)
		~IsoPrototileSet();

		inline IsoPrototile* getDefaultTile() {return prototiles[0];}
		inline int getDefaultTileHeight() {return prototiles[0]->getImgHeight();}
		inline int getDefaultTileWidth() {return prototiles[0]->getImgWidth();}
		void addNewTile(std::string name, int flags);
};

#endif
