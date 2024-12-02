SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
BIN_FILENAME = main.exe

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
EXE = $(BIN_DIR)/$(BIN_FILENAME)

CC = cc
ARGS = -lm

.PHONY: all clean run help

all: $(EXE)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CC) $^ $(ARGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)

run: $(EXE)
	$(EXE)

help: $(EXE)
	$(EXE) --help