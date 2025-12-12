CXX      = g++
CXXFLAGS = -I"$(CURDIR)/include" -std=c++17 -Wall -Wextra -g
LDFLAGS  = -L"$(CURDIR)/lib" -lraylib -lgdi32 -lwinmm

SRC_WIN := $(shell dir /s /b "$(CURDIR)\src\*.cpp" 2>nul)
SRC     := $(subst \,/,$(SRC_WIN))

# Convert absolute src path -> relative src path for OBJ mapping:
SRC_REL := $(patsubst $(CURDIR)/%,%,$(SRC))

OBJ := $(patsubst src/%.cpp,build/%.o,$(SRC_REL))
OUT := main.exe

default: $(OUT)

$(OUT): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

build/%.o: src/%.cpp
	@if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@if exist build rmdir /S /Q build
	@if exist $(OUT) del /Q $(OUT)
