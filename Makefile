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
LOGDATE = $(shell date +"%b/%d at %kh:%Mm")
EXE = 

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDE_FOLDER)

# all: comp run

make: $(OBJ)
	$(CC) $(CXXFLAGS) -o $(BIN_FOLFER)$(TARGET) $(OBJ)


	
run:
	$(BIN_FOLFER)main
	# $(EXE) -i ./input/1.tst.i -o ./output/output1.txt -m 4 -s 5


gen_doxygen:
	doxygen $(CONFIG_FOLDER)Doxyfile