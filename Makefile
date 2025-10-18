PROJECT_NAME = game
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

RAYLIB_PATH = C:/raylib/raylib

CC = C:\raylib\w64devkit\bin\g++
CFLAGS = -Wall -std=c++17 -O2 -I$(RAYLIB_PATH)/src -Iinclude
LDFLAGS = -LC:/raylib/raylib/src -lraylib -lopengl32 -lgdi32 -lwinmm -Iinclude

# Find all source files (one or two subfolders deep)
SRC := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*/*.cpp) $(wildcard $(SRC_DIR)/*/*/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

all: $(BIN_DIR)/$(PROJECT_NAME)

$(BIN_DIR)/$(PROJECT_NAME): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
	@echo "✅ Build complete: $@"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "🧹 Cleaned."

.PHONY: all clean
