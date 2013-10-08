#ifndef ISOMAP_ELEMENT_HPP_INCLUDED
#define ISOMAP_ELEMENT_HPP_INLCUDED

#include <string>
#include "IsoEng.hpp"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class IsoProtoMapElement
{
	private:
		SDL_Surface* img;
		std::string name;
		int flags;
	public:
		IsoProtoMapElement(std::string name, int flags);
		~IsoProtoMapElement();
		inline int getImgHeight() {return img->h;}
		inline int getImgWidth() {return img->w;}
		inline SDL_Surface* getImg() {return img;}
};

typedef struct
{
	IsoProtoMapElement* proto;
	float posX;
	float posY;
}IsoMapElement;

#endif
