#ifndef ISOSPRITES_HPP_INCLUDED
#define ISOSPRITES_HPP_INCLUDED

#include <SDL/SDL.h>
#include <vector>
#include <string>
#include <iostream>

class IsoSprite
{
	protected:
		std::string name;
		bool delimg;
		SDL_Surface* img;
		int loadImg();
	public:
		IsoSprite(std::string name, bool delimg = true);
		IsoSprite(std::string name, SDL_Surface* sfc, bool delimg = false);
		~IsoSprite();
		virtual inline void render(SDL_Surface* screen, SDL_Rect* pos, unsigned int frameid = 0, unsigned int time = 0)
                {SDL_BlitSurface(img, NULL, screen, pos);}
                
                virtual inline int getImgHeight(){return img->h;}
                virtual inline int getImgWidth(){return img->w;}

		inline std::string getName(){return name;} const
		inline bool willDeleteImg(){return delimg;} const
		inline void toggleImgDeletion(bool _delimg){delimg = _delimg;}
};

class IsoSprite_Animated : public IsoSprite
{
	protected:
		unsigned int fps;
		unsigned int nframes;
		unsigned int framesize;
		bool horizAnim;
	public:
		IsoSprite_Animated(std::string name, unsigned int fps, unsigned int nframes , bool delimg = true);
		IsoSprite_Animated(std::string name, SDL_Surface* sfc, unsigned int fps, unsigned int nframes, bool delimg);
                virtual inline int getImgHeight(){return horizAnim ? img->h : framesize;}
                virtual inline int getImgWidth(){return horizAnim ? framesize : img->w;}
                virtual void render(SDL_Surface* screen, SDL_Rect* pos, unsigned int frameid = 0, unsigned int time = 0);
};

#endif
