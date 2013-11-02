#include "IsoTile.hpp"
#include "IsoEng.hpp"
#include "SDL_misc.hpp"

#include <iostream>

IsoPT::IsoPT(IsoSprite *sprite, std::string name, int flags) : sprite(sprite), name(name), flags(flags)
{}

IsoPT::~IsoPT()
{
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
