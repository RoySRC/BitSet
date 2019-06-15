#include "bitset.h"


void bitset::print() const {
    // printf("[ ");
    for (size_t i=0; i<nb_bits_; ++i) {
        cout << this->at(nb_bits_-1-i) ;
    }
    printf("\n");
}

/*
 * Print the value that is stored in every entry
 * of the bit_array
 */
void bitset::value_print() const {
    printf("[ ");
    for (size_t i=0; i<bit_array_size; ++i) {
        cout << bit_array[i] << " " ;
    }
    printf("]\n");
}

bitset& bitset::operator >> (const size_t i) {
    return *this;
}

