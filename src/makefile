OBJS = main.cpp GameController.cpp GameController.h IRenderable.h
OBJ_NAME = ../bin/cws
COMPILE_FLAGS = -std=c++14
LINKER_FLAGS= -lSDL2 -lSDL2_image

all: $(OBJS)
	g++ $(OBJS) $(COMPILE_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

