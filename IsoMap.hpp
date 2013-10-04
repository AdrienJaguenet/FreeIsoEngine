#ifndef ISOMAP_HPP_INCLUDED
#define ISOMAP_HPP_INCLUDED

#include<SDL/SDL.h>
#include<vector>

#include "IsoTile.hpp"
#include "IsoCamera.hpp"

class IsoMap
{
	protected:
		IsoPrototileSet *prototiles;
		IsoTile **tiles; //2D array of tiles
		int sizex;
		int sizey;
	public:
		IsoMap();
		IsoMap(int sizex, int sizey);
		IsoMap(int sizex, int sizey, IsoPrototileSet *prototiles);
		~IsoMap();
		//renders the map on a screen
		void render(SDL_Surface* screen, IsoCamera* camera);


/*getters - doesn't need any explanation*/
		inline int getSizeX() const {return sizex;}
		inline int getSizeY() const {return sizey;}
		inline IsoPrototileSet* getPrototileSet() const {return prototiles;}
/*modifiers*/
};

#endif

