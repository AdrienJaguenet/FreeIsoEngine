#include "SDL_misc.hpp"

SDL_Surface* crop_surface(SDL_Surface* sprite_sheet, Sint16 x, Sint16 y, Uint16 width, Uint16 height)
{
    SDL_Surface* surface = SDL_CreateRGBSurface(sprite_sheet->flags, width, height, sprite_sheet->format->BitsPerPixel, sprite_sheet->format->Rmask, sprite_sheet->format->Gmask, sprite_sheet->format->Bmask, sprite_sheet->format->Amask);
    SDL_Rect rect = {x, y, width, height};
    SDL_BlitSurface(sprite_sheet, &rect, surface, 0);
    return surface;
}
