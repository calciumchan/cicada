#this make file is basiclaly just a copy of the one on the lazyfoo tutorials

OBJS = *.cpp cicada/*.cpp
CC = g++
COMPILER_FLAGS = -w
LINKER_FLAGS = -lSDL2
OBJ_NAME = cicadatest

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

