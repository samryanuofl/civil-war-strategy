CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS := -lSDL2 -lSDL2_image
CPPFLAGS := -std=c++14 -MMD

bin/Debug/civil-war-strategy: $(OBJ_FILES)
	g++ $(CPP_FLAGS) -o $@ $^ $(LD_FLAGS)

obj/%.o: src/%.cpp
	g++ $(CPPFLAGS) -c -o $@ $<

clean:
	rm obj/*.o
-include $(OBJFILES:.o=.d)
