#include "IsoMapElement.hpp"
#include <iostream>

IsoPME::IsoPME(std::string name, int flags) : flags(flags)
{
	this->name = IsoEng::getElementImgPath() + name + IsoEng::getElementImgExtension();
	img = IMG_Load(this->name.c_str());
	if(img == NULL)std::cout<<"[FreeIsoEngine Error]: couldn't load file at "<<this->name<<std::endl; //error message (TODO: throw an exception)
	this->name = name;
}

IsoPME::~IsoPME()
{
	if(img != NULL) SDL_FreeSurface(img);
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

