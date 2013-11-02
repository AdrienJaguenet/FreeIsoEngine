#ifndef ISOMAP_ELEMENT_HPP_INCLUDED
#define ISOMAP_ELEMENT_HPP_INLCUDED

#include <string>
#include <vector>
#include "IsoEng.hpp"
#include "IsoSprites.hpp"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class IsoPME
{
	protected:
                IsoSprite* sprite;
		std::string name;
		int flags;
	public:
		IsoPME(IsoSprite* sprite, std::string name, int flags);
		~IsoPME();
		inline int getImgHeight() {return sprite->getImgHeight();}
		inline int getImgWidth() {return sprite->getImgWidth();}
                inline void render(SDL_Surface *screen, SDL_Rect* pos, unsigned int frameid = 0, unsigned int time = 0)
                {sprite->render(screen, pos, frameid, time);}
};

class IsoPME_Animated : IsoPME
{
	protected:
	public:
		IsoPME_Animated();
		~IsoPME_Animated();
};

typedef struct
{
	IsoPME* proto;
	float posX;
	float posY;
}IsoMapElement;

class IsoPME_Manager
{
	protected:
		std::vector<IsoPME*> _PMEs;
	public:
		IsoPME_Manager();
		~IsoPME_Manager();
		inline void addPME(IsoPME* pme){_PMEs.push_back(pme);};
		inline void deleteLastPME(){_PMEs.pop_back();};
};

#endif
