#ifndef ISO_TILE_HPP_INCLUDED
#define ISO_TILE_HPP_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <vector>
#include <string>
#include <iostream>

class IsoPT
{
	protected:
		SDL_Surface* img;
		std::string name;
		int flags;
	public:
		IsoPT();
		IsoPT(std::string name, int flags);
		~IsoPT();
		virtual inline int getImgHeight() const {return img != NULL ? img->h : 0;} 
		virtual inline int getImgWidth() const {return img != NULL ? img->w : 0;}
		inline SDL_Surface* getImgSurface() const {return img;}
		virtual inline void render(SDL_Surface* screen, SDL_Rect* rect, unsigned char unused = 0, unsigned char unused2 = 0) const {SDL_BlitSurface(img, NULL, screen, rect);}
};

class IsoPT_Animated : public IsoPT
{
	protected:
		unsigned char animationspeed;//in frames per second
		unsigned int framesize;
		unsigned char nframes;
		bool horizAnim;
	public:
		IsoPT_Animated(std::string name, int flags, unsigned int animationspeed, unsigned int nframes);
		~IsoPT_Animated();
		void render(SDL_Surface* screen, SDL_Rect* rect, unsigned char frameid = 0, unsigned char unused = 0) const;

		virtual inline int getImgHeight() const {return horizAnim ? img->h : framesize;}
		virtual inline int getImgWidth() const {return horizAnim ? framesize : img->w;}
};

typedef struct
{
	unsigned char frameid;//used for animated tiles
	IsoPT *proto; /*prototile linked*/
} IsoTile;

class IsoPT_Manager
{
	protected:
		IsoPT* defaultTile;//used for rendering purposes, should have the same size as all the other tiles used
		std::vector<IsoPT*> _PTs;
	public:
		IsoPT_Manager(IsoPT* defaultTile);
		~IsoPT_Manager();
		void inline addTile(std::string name, int flags){_PTs.push_back(new IsoPT(name, flags) );}
		void inline addTile(IsoPT* pt) {_PTs.push_back(pt);}
		inline int getDefaultTileHeight(){return defaultTile == NULL ? _PTs[0]->getImgHeight() : defaultTile->getImgHeight(); }
		inline int getDefaultTileWidth(){return defaultTile == NULL ? _PTs[0]->getImgWidth() : defaultTile->getImgWidth(); }
		inline IsoPT* getDefaultTile(){return defaultTile == NULL ? _PTs[0] : defaultTile;}
};

#endif
