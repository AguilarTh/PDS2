CC=g++
CFLAGS=-std=c++11 -Wall
OBJ_DIR=build
SRC_DIR=src 
ENTIDADES_DIR=src/entidades
TARGET=vpl_execution
INCLUDE_DIR=include 

all: ${TARGET}

${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}

$(OBJ_DIR)/Circulo.o: $(INCLUDE_DIR)/Circulo.hpp $(ENTIDADES_DIR)/Circulo.cpp ${OBJ_DIR}
	$(CC) $(CFLAGS) -c $(ENTIDADES_DIR)/Circulo.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Circulo.o 

$(OBJ_DIR)/Ponto.o: $(INCLUDE_DIR)/Ponto.hpp $(ENTIDADES_DIR)/Ponto.cpp ${OBJ_DIR}
	$(CC) $(CFLAGS) -c $(ENTIDADES_DIR)/Ponto.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Ponto.o 

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/Ponto.hpp $(INCLUDE_DIR)/Circulo.hpp ${OBJ_DIR}
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o 

${TARGET}: $(OBJ_DIR)/main.o $(OBJ_DIR)/Ponto.o $(OBJ_DIR)/Circulo.o 
	$(CC) $(OBJ_DIR)/main.o $(OBJ_DIR)/Ponto.o $(OBJ_DIR)/Circulo.o -o ${TARGET}


