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
EXE = $(BIN_FOLFER)main

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDE_FOLDER)

all: comp run

comp: $(OBJ) 
	$(CC) $(CXXFLAGS) -o $(BIN_FOLFER)$(TARGET) $(OBJ)

gen_doxygen:
	doxygen $(CONFIG_FOLDER)Doxygen
	
# run:
# 	$(EXE) -i ./input/1.tst.i -o ./output/output1.txt -m 4 -s 5
# 	$(EXE) -i ./input/2.tst.i -o ./output/output2.txt -m 4 -s 5
# 	$(EXE) -i ./input/3.tst.i -o ./output/output3.txt -m 4 -s 5
# 	$(EXE) -i ./input/4.tst.i -o ./output/output4.txt -m 4 -s 5
# 	$(EXE) -i ./input/5.tst.i -o ./output/output5.txt -m 4 -s 5
# 	$(EXE) -i ./input/6.tst.i -o ./output/output6.txt -m 4 -s 5
# 	$(EXE) -i ./input/7.tst.i -o ./output/output7.txt -m 4 -s 5
# 	$(EXE) -i ./input/8.tst.i -o ./output/output8.txt -m 4 -s 5
# 	$(EXE) -i ./input/9.tst.i -o ./output/output9.txt -m 4 -s 5
# 	$(EXE) -i ./input/10.tst.i -o ./output/output10.txt -m 4 -s 5

# clean: 
# 	@rm -rf $(OBJ_FOLDER)* $(BIN_FOLFER)* $(TARGET)
# 	@rm -rf $(OUTPUT_FOLDER)* 
# 	rm -rf gmon.out
# 	rm -rf gprof.txt
# 	clear
	
# git:
# 	git add .
# 	@echo "your commit text: "; \
#     read AGE ;\
# 	git commit -m "Update $(LOGDATE) - $$AGE"
# 	git push
