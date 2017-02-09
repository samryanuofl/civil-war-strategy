OBJS = main.cpp GameController.cpp SpriteInfo.cpp 
HEADERS = GameController.h SpriteInfo.h IRenderable.h
OBJ_NAME = civil-war-strategy
BIN_FOLDER = ../bin/
COMPILE_FLAGS = -std=c++14
LINKER_FLAGS= -lSDL2 -lSDL2_image

Debug: $(OBJS)
	g++ -g $(OBJS) $(COMPILE_FLAGS) $(LINKER_FLAGS) -o $(BIN_FOLDER)/Debug/$(OBJ_NAME)

all: $(OBJS)
	g++ $(OBJS) $(COMPILE_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

