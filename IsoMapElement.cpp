#include "IsoMapElement.hpp"
#include <iostream>

IsoPME::IsoPME(IsoSprite* sprite, std::string name, int flags) : sprite(sprite), name(name), flags(flags)
{
}

IsoPME::~IsoPME()
{
}

IsoPME_Manager::IsoPME_Manager()
{
}

IsoPME_Manager::~IsoPME_Manager()
{
	for(unsigned int i(0); i < _PMEs.size(); ++i)
	{
		delete _PMEs[i];
		_PMEs.pop_back();
	}
}

