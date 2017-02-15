OBJS_DIR := bin/Debug
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix $(OBJS_DIR)/,$(notdir $(CPP_FILES:.cpp=.o)))
LD_FLAGS := -lSDL2 -lSDL2_image -lpthread
CPPFLAGS := -std=c++14 -MMD -Wall
INC := -Isrc -Isrc/spdlog

bin/Debug/civil-war-strategy: $(OBJ_FILES)
	g++ $(CPP_FLAGS) -o $@ $^ $(LD_FLAGS)

Debug: $(OBJ_FILES)
	g++ $(CPP_FLAGS) -o $@ $^ $(LD_FLAGS)

$(OBJS_DIR)/%.o: src/%.cpp
	g++ $(CPPFLAGS) $(INC) -c -o $@ $<

clean:
	rm $(OBJS_DIR)/*.o
-include $(OBJFILES:.o=.d)
