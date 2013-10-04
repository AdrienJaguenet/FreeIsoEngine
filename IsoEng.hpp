#ifndef ISOENG_HPP_INCLUDED
#define ISOENG_HPP_INCLUDED

#include <string>
#include <SDL/SDL.h>

class IsoEng
{
	private:
		static std::string isotile_img_path;//prototile images will be loaded from here
		static std::string isotile_img_extension;//file extension of the protile images
		
	public:
		IsoEng();
		~IsoEng();
		inline static void setTileImgPath(std::string path){isotile_img_path = path;}
		inline static void setTileImgExtension(std::string extension){isotile_img_extension = extension;}
		inline static std::string getTileImgPath() {return isotile_img_path;}
		inline static std::string getTileImgExtension() {return isotile_img_extension;}
};

#endif
