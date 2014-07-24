FILES=IsoEng.cpp IsoSprites.cpp IsoMapElement.cpp IsoMap.cpp SDL_misc.cpp IsoCamera.cpp
FLAGS= -Wall -Werror --std=c++11 -g

all:
	g++ $(FILES) $(FLAGS)
	mkdir binaries
	mv *.o binaries/
clean:
	rm -f *.o
