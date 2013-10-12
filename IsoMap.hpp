#ifndef ISOMAP_HPP_INCLUDED
#define ISOMAP_HPP_INCLUDED

#include<SDL/SDL.h>
#include<vector>

#include "IsoTile.hpp"
#include "IsoCamera.hpp"
#include "IsoMapElement.hpp"

class IsoMap
{
	protected:
		int sizex;
		int sizey;

		//proto-things
		IsoPME_Manager* pme_manager;
		IsoPT_Manager* pt_manager;

		//other stuff
		IsoTile **tiles; //2D array of tiles
		std::vector<IsoMapElement*> map_elements;

		float m;//used in screen/mouse interaction
	public:
		IsoMap();
		IsoMap(int sizex, int sizey);
		IsoMap(int sizex, int sizey, IsoPT_Manager *pt_manager);
		~IsoMap();
		//renders the map on a screen
		void render(SDL_Surface* screen, IsoCamera* camera);

/*work with proto-things managers*/
		inline void setPME_Manager(IsoPME_Manager *manager){pme_manager = manager;}
		inline void setPT_Manager(IsoPT_Manager *manager){pt_manager = manager;}

/*getters - doesn't need any explanation*/
		inline int getSizeX() const {return sizex;}
		inline int getSizeY() const {return sizey;}
/*modifiers*/	
		inline void setTileProto(int x, int y, IsoPT* proto){if(x>=0&&x<sizex&&y>=0&&y<sizey) tiles[x][y].proto = proto;}
		void placeElement(IsoMapElement* element);

/*screen/mouse interaction*/
		float getXFromScreen(int cx, int cy, IsoCamera* camera);
		float getYFromScreen(int cx, int cy, IsoCamera* camera);
		void setTileFromClick(SDL_Event *event, IsoCamera* camera, IsoPT* proto);
};

#endif

