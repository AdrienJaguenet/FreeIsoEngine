#ifndef ISOCAMERA_HPP_INCLUDED
#define ISOCAMERA_HPP_INCLUDED

class IsoCamera
{
	private:
		int posX; //x view shifting of the camera (in pixels)
		int posY; //y view shifting of the camera (in pixels)
	public:
		IsoCamera();
		~IsoCamera();
		IsoCamera(int x, int y);
		inline void setX(int x){posX = x;}
		inline void setY(int y){posY = y;}
		inline int getX() {return posX;}
		inline int getY() {return posY;}
		void centerOnTile(int x, int y);
};

#endif
