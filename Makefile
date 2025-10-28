PROJECT_NAME = game
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = bin/game

CC = C:\raylib\w64devkit\bin\g++
CFLAGS = -Wall -std=c++17 -O2 -I$(RAYLIB_PATH)/src -Iinclude
LDFLAGS = -LC:/raylib/raylib/src -lraylib -lopengl32 -lgdi32 -lwinmm -Iinclude

ifeq ($(PLATFORM_OS),Windows_NT)
    # --- Windows / MinGW / w64devkit ---
    CC := C:\raylib\w64devkit\bin\g++
    RAYLIB_PATH := C:/raylib/raylib
    LIBS := -LC:/raylib/raylib/src -lraylib -lopengl32 -lgdi32 -lwinmm -Iinclude
    RM := del /Q
    MKDIR := mkdir
    SEP := \\
else
    # --- Linux ---
    CC := g++
    RAYLIB_PATH := /usr/include
    LIBS := -lraylib -lm -lpthread -ldl -lrt -lGL -lX11
    RM := rm -f
    MKDIR := mkdir -p
    SEP := /
endif

# Find all source files (one or two subfolders deep)
SRC := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*/*.cpp) $(wildcard $(SRC_DIR)/*/*/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

all: $(BIN_DIR)/$(PROJECT_NAME)

$(BIN_DIR)/$(PROJECT_NAME): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $@ $(LIBS)
	@echo "✅ Build complete: $@"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "🧹 Cleaned."

run:
	$(TARGET)

.PHONY: all clean run