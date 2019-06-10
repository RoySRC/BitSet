CC=g++
CSTD_FLAGS=-std=c++11
OPT_FLAGS=-O3 



all: bitset.o main.o
	$(CC) $(CSTD_FLAGS) $(OPT_FLAGS) bitset.o main.o -o main

main.o: main.cpp
	$(CC) $(CSTD_FLAGS) $(OPT_FLAGS) -c ./main.cpp -o ./main.o

bitset.o: bitset.h bitset.cpp
	$(CC) $(CSTD_FLAGS) $(OPT_FLAGS) -c ./bitset.cpp -o ./bitset.o

clean:
	rm -rf ./*.o ./main