all:
	gcc -c -Wall IsoEng.cpp --std=c++11
	gcc -c -Wall IsoSprites.cpp --std=c++11
	gcc -c -Wall IsoMapElement.cpp --std=c++11
	gcc -c -Wall IsoMap.cpp --std=c++11
	gcc -c -Wall SDL_misc.cpp --std=c++11
	gcc -c -Wall IsoCamera.cpp --std=c++11
	mkdir binaries
	mv *.o binaries/
clean:
	rm -f *.o
