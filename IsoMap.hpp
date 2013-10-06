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

		float m;//used in screen/mouse interaction
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
		inline void setTileProto(int x, int y, IsoPrototile* proto){if(x>=0&&x<sizex&&y>=0&&y<sizey) tiles[x][y].proto = proto;}

/*screen/mouse interaction*/
		float getXFromScreen(int cx, int cy, IsoCamera* camera);
		float getYFromScreen(int cx, int cy, IsoCamera* camera);
		void setTileFromClick(SDL_Event *event, IsoCamera* camera, IsoPrototile* proto);
};

#endif

