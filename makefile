CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix src/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS := -lSDL2 -lSDL_image
CPPFLAGS := -std=c++14


civil-war-strategy: $(OBJ_FILES)
	g++ $(CPP_FLAGS) $(LD_FLAGS) -o $@ $^

obj/%.o: src/%.cpp
	g++ $(CPP_FLAGS) -c -o $@ $<
