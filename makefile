CC=g++
CSTD_WARN_FLAGS=-Wall #-Wattributes -Wreturn-type -Wshift-count-overflow
CSTD_FLAGS= $(CSTD_WARN_FLAGS) -std=c++11
OPT_FLAGS=-O3 -march=native



all: main.o
	$(CC) $(CSTD_FLAGS) $(OPT_FLAGS) main.o -o main

main.o: main.cpp bitset.h bitset_not_operator_test.h
	$(CC) $(CSTD_FLAGS) $(OPT_FLAGS) -c ./main.cpp -o ./main.o

clean:
	rm -rf ./*.o ./main
