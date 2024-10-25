
all:
	echo you can use this target if you do not know yet about all of this crap


















.PHONY: clean
filenameToEXE = Game
filenameToDebugEXE = DebugGame
pathLib ?= lib
pathInc ?= include
pathsrc := src
Essentials ?= -I$(pathInc) -L$(pathLib)
Link :=  -lraylib -lopengl32 -lgdi32 -lwinmm
header = src/Headers
ObjectsLink = $(wildcard *.o)
CC = g++
ccfile = *.cpp
run: CPPLinker
	$(CC) -o $(filenameToEXE) $(ObjectsLink) $(Essentials) $(Link)
	make clean
debug: CPPLinkerWithDebug
	$(CC) -o $(filenameToDebugEXE) $(ObjectsLink) $(Essentials) $(Link)
	make clean
	gdb $(filenameToDebugEXE)
CPPLinker: 
	$(CC) -c $(pathsrc)/$(ccfile) $(Essentials) -I$(header)
CPPLinkerWithDebug:
	$(CC) -c -g $(pathsrc)/$(ccfile) $(Essentials) -I$(header)

clean:
	rm $(ObjectsLink)
