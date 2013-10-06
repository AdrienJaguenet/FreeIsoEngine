#include "IsoEng.hpp"

std::string IsoEng::isotile_img_path = "";
std::string IsoEng::isotile_img_extension = "";

IsoEng::IsoEng()
{
	SDL_Init(SDL_INIT_VIDEO);
}

IsoEng::~IsoEng()
{
	SDL_Quit();
}

