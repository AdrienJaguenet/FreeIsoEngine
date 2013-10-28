#include "IsoTile.hpp"
#include "IsoEng.hpp"
#include "SDL_misc.hpp"

#include <iostream>

IsoPT::IsoPT() : IsoPT("defaultTile", 0) {}

IsoPT::IsoPT(std::string name, int flags) : flags(flags)
{
	this->name = IsoEng::getTileImgPath() + name + IsoEng::getTileImgExtension();
	img = IMG_Load(this->name.c_str());
	if(img == NULL)std::cout<<"[FreeIsoEngine Error]: couldn't load file at "<<this->name<<std::endl; //error message (TODO: throw an exception)
	this->name = name;
}

IsoPT_Animated::IsoPT_Animated(std::string name, int flags, unsigned int animationspeed, unsigned int nframes) : IsoPT(name, flags), animationspeed(animationspeed), nframes(nframes)
{
	horizAnim = (img->h <= img->w);//see if the animation is horizontally or vertically drawn
	framesize = horizAnim ? img->w / nframes : img->h / nframes;//size (in pixels) of each frame inside the main one
}

void IsoPT_Animated::render(SDL_Surface* screen, SDL_Rect* rect, unsigned char frameid, unsigned char unused) const
{
	frameid %= nframes;
	SDL_Rect img_rect;
	if(horizAnim)
	{
		img_rect.x = frameid * framesize;
		img_rect.y = 0;
		img_rect.w = framesize;
		img_rect.h = img->h;
	}
	else
	{
		img_rect.x = 0;
		img_rect.y = frameid * framesize;
		img_rect.w = img->w;
		img_rect.h = framesize;
	}
	SDL_BlitSurface(img, &img_rect, screen , rect);
}

IsoPT::~IsoPT()
{
	if(img != NULL)
		SDL_FreeSurface(img);
}

IsoPT_Manager::IsoPT_Manager(IsoPT* defaultTile) : defaultTile(defaultTile) {}

IsoPT_Manager::~IsoPT_Manager()
{
	delete defaultTile;
	for(unsigned int i(0); i < _PTs.size(); ++i)
	{
		delete _PTs[i];
		_PTs.pop_back();
	}
}
