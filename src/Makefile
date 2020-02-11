OBJS = main.cpp Game.cpp Game.hpp TextureManager.cpp TextureManager.hpp GameObject.hpp GameObject.cpp Map.cpp Map.hpp ECS.cpp ECS.hpp

OBJ_Name = SDLMain

build-windows: $(OBJS)
	g++ $(OBJS) -IC:\Users\nico\Development\x86_64-w64-mingw32\include -L C:\Users\nico\Development\x86_64-w64-mingw32\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2_image -lSDL2 -o $(OBJ_Name)
	$(OBJ_Name).exe

clean :
	rm $(OBJ_Name).exe

build-osx: 
	g++ $(OBJS) -I include -L lib -l SDL2-2.0.0 -l SDL2_image-2.0.0
	./a.out

.PHONY: setup-windows setup-osx
