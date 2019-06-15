CC=g++
CSTD_WARN_FLAGS=-Wall -Wattributes -Wreturn-type -Wshift-count-overflow
CSTD_FLAGS= $(CSTD_WARN_FLAGS) -std=c++11
OPT_FLAGS=-O3 



all: main.o
	$(CC) $(CSTD_FLAGS) $(OPT_FLAGS) bitset.o main.o -o main

main.o: main.cpp bitset.o
	$(CC) $(CSTD_FLAGS) $(OPT_FLAGS) -c ./main.cpp -o ./main.o

bitset.o: bitset.h bitset.cpp
	$(CC) $(CSTD_FLAGS) $(OPT_FLAGS) -c ./bitset.cpp -o ./bitset.o

clean:
	rm -rf ./*.o ./main
