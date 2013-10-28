#include "IsoEng.hpp"

std::string IsoEng::isoeng_img_path = "";
std::string IsoEng::isoeng_img_extension = "";

IsoEng::IsoEng()
{
	SDL_Init(SDL_INIT_VIDEO);
}

IsoEng::~IsoEng()
{
	SDL_Quit();
}

