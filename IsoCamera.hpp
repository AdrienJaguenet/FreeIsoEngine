#ifndef ISOCAMERA_HPP_INCLUDED
#define ISOCAMERA_HPP_INCLUDED

/**
 Camera used in map rendering.
 */

class IsoCamera
{
	private:
		int posX; /*!<x view shifting of the camera (in pixels)*/
		int posY; /*!<y view shifting of the camera (in pixels)*/
	public:
		IsoCamera();/*!<Default constructor. Sets both posX and posY to 0.*/
		~IsoCamera();/*!<Default destructor. Does nothing.*/
		IsoCamera(int x /*!<Initial X position of camera*/
			, int y /*!<Initial Y position of camera*/);
		inline void setX(int x){posX = x;}
		inline void setY(int y){posY = y;}
		inline int getX() {return posX;}
		inline int getY() {return posY;}
		void centerOnTile(int _x, int _y);//<Not written yet, don't call it.
};

#endif
