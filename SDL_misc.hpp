#ifndef SDL_MISC_HPP_INCLUDED
#define SDL_MISC_HPP_INCLUDED

#include <SDL/SDL_image.h>

//a function I found on the web
SDL_Surface* crop_surface(SDL_Surface* sprite_sheet, Sint16 x, Sint16 y, Uint16 width, Uint16 height);

#endif
