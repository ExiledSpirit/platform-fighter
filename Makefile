CXX      = g++
# pkg-config -cflags adds the necessary include paths
CXXFLAGS = -std=c++17 -Wall -Wextra -g -Isrc -Iinclude $(shell pkg-config --cflags raylib)
# Raylib dependency location
LDFLAGS  = $(shell pkg-config --libs raylib)

# Get .cpp files recursively
SRC     := $(shell find src -name "*.cpp")

# Map objects to the build folder
OBJ := $(patsubst src/%.cpp,build/%.o,$(SRC))
OUT := main

.PHONY: all clean

all: $(OUT)

$(OUT): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build $(OUT)

run: $(OUT)
	./$(OUT)