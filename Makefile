# Variáveis do compilador
CC = g++
CXXFLAGS = -std=c++17 -Wall -g

# Pastas
BIN_FOLDER 		= ./bin/
DOC_FOLDER		= ./doc/
INCLUDE_FOLDER 	= ./include/
LIB_FOLDER		= ./lib/
OBJ_FOLDER 		= ./obj/
SRC_FOLDER 		= ./src/
TEST_FOLDER		= ./test/
CONFIG_FOLDER		= ./config/

# Arquivos source, objs e headers
MAIN = main
TARGET = main
SRC = $(wildcard $(SRC_FOLDER)*.cpp)
OBJ = $(patsubst $(SRC_FOLDER)%.cpp, $(OBJ_FOLDER)%.o, $(SRC))

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDE_FOLDER)

all: make run

make: $(TSTs)
	$(CC) $(CXXFLAGS) -o $(BIN_FOLFER)$(TARGET) $(OBJ)
	
run:
	$(BIN_FOLFER)main

gen_doxygen:
	doxygen $(CONFIG_FOLDER)Doxyfile