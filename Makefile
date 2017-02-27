CC		=g++
CFLAGS	=-Wall -g -Wextra
EXEC	=ptrace
FILES	=./PixelTracer.cpp ./Board.cpp
OBJECTS	=colour.o pixelTracer.o screenUtils.o utils.o
LINK	=-lSDL
SDL		=`pkg-config --cflags --libs sdl`

all: build

build: $(OBJECTS)
	$(CC) $(CFLAGS) src/ptrace.cpp bin/colour.o bin/pixelTracer.o bin/screenUtils.o bin/utils.o $(SDL) -o $(EXEC) -I./include $(LINK)

colour.o: src/colour.cpp include/colour.hpp
	$(CC) $(CFLAGS) src/colour.cpp -c -o bin/colour.o -I./include $(LINK)

pixelTracer.o: src/pixelTracer.cpp include/pixelTracer.hpp
	$(CC) $(CFLAGS) src/pixelTracer.cpp -c -o bin/pixelTracer.o -I./include $(LINK)
	
screenUtils.o: src/screenUtils.cpp include/screenUtils.hpp
	$(CC) $(CFLAGS) src/screenUtils.cpp -c -o bin/screenUtils.o -I./include $(LINK)

utils.o: src/utils.cpp include/utils.hpp
	$(CC) $(CFLAGS) src/utils.cpp -c -o bin/utils.o -I./include $(LINK)

clean:
	rm $(EXEC)

clobber:
	rm bin/*.o $(EXEC)
