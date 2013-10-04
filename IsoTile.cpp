#include "IsoTile.hpp"
#include "IsoEng.hpp"

#include <iostream>

IsoPrototile::IsoPrototile() : IsoPrototile("defaultTile", 0) {}

IsoPrototile::IsoPrototile(std::string name, int flags) : flags(flags)
{
	this->name = IsoEng::getTileImgPath() + name + IsoEng::getTileImgExtension();
	img = IMG_Load(this->name.c_str());
	if(img == NULL)std::cout<<"[FreeIsoEngine Error]: couldn't load file at "<<this->name<<std::endl; //error message (TODO: throw an exception)
	this->name = name;
}

IsoPrototile::~IsoPrototile()
{
	if(img != NULL)
		SDL_FreeSurface(img);
}

IsoPrototileSet::IsoPrototileSet() {}

IsoPrototileSet::~IsoPrototileSet() {};

void IsoPrototileSet::addNewTile(std::string name, int flags)
{
	prototiles.push_back(new IsoPrototile(name, flags) );
}

