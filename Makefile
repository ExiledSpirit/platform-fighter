# Compiler and flags
CXX      = g++
CXXFLAGS = -Iinclude -std=c++17 -Wall -Wextra -g
LDFLAGS  = -Llib -lraylib -lgdi32 -lwinmm

# Sources / objects
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=build/%.o)

OUT = main.exe

default: $(OUT)

$(OUT): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

build/%.o: src/%.cpp
	@if not exist build mkdir build
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /Q build\*.o 2>nul
	del /Q $(OUT) 2>nul
