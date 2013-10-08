#include "IsoMapElement.hpp"
#include <iostream>

IsoProtoMapElement::IsoProtoMapElement(std::string name, int flags) : flags(flags)
{
	this->name = IsoEng::getElementImgPath() + name + IsoEng::getElementImgExtension();
	img = IMG_Load(this->name.c_str());
	if(img == NULL)std::cout<<"[FreeIsoEngine Error]: couldn't load file at "<<this->name<<std::endl; //error message (TODO: throw an exception)
	this->name = name;
}

IsoProtoMapElement::~IsoProtoMapElement()
{
	if(img != NULL) SDL_FreeSurface(img);
}

