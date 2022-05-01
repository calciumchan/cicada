#this make file is basiclaly just a copy of the one on the lazyfoo tutorials

OBJS = *.c
CC = gcc
COMPILER_FLAGS = -w
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
OBJ_NAME = game

all : $(OBJS)
	clear && $(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME) && ./$(OBJ_NAME)

