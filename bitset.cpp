#include "bitset.h"

bitset::bitset (size_t nb_bits) {
    nb_bits_ = nb_bits;
    bit_array_size = 1 + nb_bits / WORD_LEN;
    bit_array = new TYPE [bit_array_size] ();
}

bitset::~bitset () {
    delete [] bit_array;
    bit_array = NULL;
}

void bitset::set (size_t i) {
    
}

void bitset::print() const {
    printf("[");
    for (size_t i=0; i<nb_bits_; ++i) {
        if (bit_array[i / WORD_LEN] & (1 << (i % WORD_LEN))) printf("%d", 1);
        else printf("%d", 0);
        if (i+1 != nb_bits_) printf(", ");
    }
    printf("]\n");
}