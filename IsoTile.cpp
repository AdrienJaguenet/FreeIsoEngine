#include "IsoTile.hpp"
#include "IsoEng.hpp"

#include <iostream>

IsoPT::IsoPT() : IsoPT("defaultTile", 0) {}

IsoPT::IsoPT(std::string name, int flags) : flags(flags)
{
	this->name = IsoEng::getTileImgPath() + name + IsoEng::getTileImgExtension();
	img = IMG_Load(this->name.c_str());
	if(img == NULL)std::cout<<"[FreeIsoEngine Error]: couldn't load file at "<<this->name<<std::endl; //error message (TODO: throw an exception)
	this->name = name;
}

IsoPT::~IsoPT()
{
	if(img != NULL)
		SDL_FreeSurface(img);
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
