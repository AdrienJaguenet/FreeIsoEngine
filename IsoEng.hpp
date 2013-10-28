#ifndef ISOENG_HPP_INCLUDED
#define ISOENG_HPP_INCLUDED

#include <string>
#include <SDL/SDL.h>
#include <iostream>

class IsoEng
{
	private:
		static std::string isoeng_img_path;//prototile images will be loaded from here
		static std::string isoeng_img_extension;//file extension of the protile images
		
	public:
		IsoEng();
		~IsoEng();
		inline static void setImgPath(std::string path){isoeng_img_path = path;}
		inline static void setImgExtension(std::string extension){isoeng_img_extension = extension;}
		inline static std::string getImgPath() {return isoeng_img_path;}
		inline static std::string getImgExtension() {return isoeng_img_extension;}
		inline static void printErr(std::string string){std::cout<<"[IsoEng error]: "<<string<<std::endl;}
};

#endif
