/*
 * MAIN.CPP FILE - ONLY HERE FOR TESTING PURPOSES
 */


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>

#include "IsoMap.hpp"
#include "IsoTile.hpp"
#include "IsoEng.hpp"
#include "IsoCamera.hpp"

using namespace std;

int main(void)
{
	//SDL stuff
	SDL_Event event;
	SDL_Surface* screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
	if(screen == NULL) cout<<"Error while loading screen: "<<SDL_GetError()<<endl;

	//init IsoEngine
	IsoEng::setTileImgPath("");
	IsoEng::setTileImgExtension(".png");
	IsoEng::setElementImgPath("");
	IsoEng::setElementImgExtension(".png");

	//load tiles
	IsoPrototileSet prototiles;
	prototiles.addNewTile("grass", 0);
	prototiles.addNewTile("desert", 0);

	//load map
	IsoMap map(15, 15, &prototiles);

	//load protoelements
	map.addNewProtoelement("tree", 0);

	//load camera
	IsoCamera camera(100, 100);

	//miscellaneous variables used in main loop
	int timeact(0), timebef(0);
	bool done(false);

	while(! done)
	{
		timeact = SDL_GetTicks();

		//event handling
		if(timeact - timebef >= 30)
		{
			while(SDL_PollEvent(&event) )
			{
				switch(event.type)
				{
					//leave the program
					case SDL_QUIT:
						done = true;
						break;
				}
			}

			//rendering
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0) );
			map.render(screen, &camera);
			SDL_Flip(screen);
			timeact = timebef;
		}
		else SDL_Delay(30 - timeact + timebef);
	}

	//SDL stuff
	SDL_FreeSurface(screen);
	return 0;
}

