all:
	g++ -c -Wall main.cpp IsoMap.cpp IsoTile.cpp IsoEng.cpp IsoCamera.cpp -std=c++11
	g++ -o isotest main.o IsoMap.o IsoTile.o IsoEng.o IsoCamera.o -lSDL -lSDL_image -lm
clean:
	rm -f *.o
