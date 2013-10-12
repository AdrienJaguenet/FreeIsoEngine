#ifndef ISOMAP_ELEMENT_HPP_INCLUDED
#define ISOMAP_ELEMENT_HPP_INLCUDED

#include <string>
#include <vector>
#include "IsoEng.hpp"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class IsoPME
{
	protected:
		SDL_Surface* img;
		std::string name;
		int flags;
	public:
		IsoPME(std::string name, int flags);
		~IsoPME();
		inline int getImgHeight() {return img->h;}
		inline int getImgWidth() {return img->w;}
		inline SDL_Surface* getImg() {return img;}
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
