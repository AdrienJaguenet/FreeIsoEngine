#ifndef ISOSPRITES_HPP_INCLUDED
#define ISOSPRITES_HPP_INCLUDED

#include <SDL/SDL.h>
#include <vector>
#include <string>
#include <iostream>

class IsoSprite
{
	protected:
		bool delimg;
		SDL_Surface* img;
		std::string name;
		int loadImg();
	public:
		IsoSprite(std::string name, bool delimg = true);
		IsoSprite(std::string name, SDL_Surface* sfc, bool delimg = false);
		~IsoSprite();
		virtual void render(SDL_Surface* screen, SDL_Rect* pos, unsigned int frameid = 0) = 0;

		virtual SDL_Surface* getImg(unsigned int frameid = 0) = 0;
		virtual void loadNewImg(std::string name) = 0;

		inline std::string getName(){return name;} const
		inline bool willDeleteImg(){return delimg;} const
		inline void toggleImgDeletion(bool _delimg){delimg = _delimg;}
};

class IsoSprite_Animated : protected IsoSprite
{
	protected:
		unsigned int fps;
		unsigned int nframes;
		unsigned int framesize;
		bool horizAnim;
	public:
		IsoSprite_Animated(std::string name, unsigned int fps, unsigned int nframes , bool delimg = true);
		IsoSprite_Animated(std::string name, SDL_Surface* sfc, unsigned int fps, unsigned int nframes, bool delimg = false);
};

#endif
