#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "IsoSprites.hpp"
#include "IsoEng.hpp"

IsoSprite::IsoSprite(std::string name, bool delimg) : name(name), delimg(delimg)
{
	loadImg();
}

IsoSprite::IsoSprite(std::string name, SDL_Surface* surface, bool delimg) : name(name), delimg(delimg), img(img)
{
}

IsoSprite::~IsoSprite()
{
	if(delimg) SDL_FreeSurface(img);
}

int IsoSprite::loadImg()
{
	std::string lname = IsoEng::getImgPath() + name + IsoEng::getImgExtension();
	img = IMG_Load(lname.c_str());
	if(img == NULL)
	{
		IsoEng::printErr("Couldn't load image at \"" + lname + "\"");
		return 0;
	}
	return 1;
}

IsoSprite_Animated::IsoSprite_Animated(std::string name, unsigned int fps, unsigned int nframes, bool delimg) : IsoSprite(name, delimg), fps(fps), nframes(nframes)
{
	if(img != NULL)
	{
		horizAnim = img->h <= img->w;
		framesize = horizAnim ? img->w / nframes : img->h / nframes;
	}
}

IsoSprite_Animated::IsoSprite_Animated(std::string name, SDL_Surface* surface, unsigned int fps, unsigned int nframes, bool delimg = true) : name(name), delimg(delimg), fps(fps), nframes(nframes)
{
	horizAnim = img->h <= img->w;
	framesize = horizAnim ? img->w / nframes : img->h / nframes;
}


