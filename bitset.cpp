#include "bitset.h"

bitset::bitset (size_t nb_bits) {
    nb_bits_ = nb_bits;
    bit_array_size = 1 + nb_bits / WORD_LEN;
    bit_array = new TYPE [bit_array_size] ();
}

bitset::bitset (const bitset& rhs) {
    nb_bits_ = rhs.nb_bits_;
    bit_array_size = rhs.bit_array_size;
    bit_array = new TYPE [bit_array_size] ();

    // perform the copy operation
    memcpy (bit_array, rhs.bit_array, sizeof(TYPE)*bit_array_size) ;
}

bitset::~bitset () {
    if (bit_array) {
        delete [] bit_array;
        bit_array = NULL;
    }
}

void bitset::set (size_t i) {
    bit_array[i/WORD_LEN] |= 1 << (i % WORD_LEN);
}

void bitset::unset (size_t i) {
    bit_array[i/WORD_LEN] &= ~(1 << (i % WORD_LEN));
}

bool bitset::operator[] (size_t i) {
    return bit_array[i/WORD_LEN] & (1 << (i % WORD_LEN));
}

bool bitset::at (size_t i) const  {
    return bit_array[i/WORD_LEN] & (1 << (i % WORD_LEN));
}

void bitset::_OR_ (const TYPE rhs) {
    bit_array[0] |= rhs;
}

void bitset::_OR_ (const bitset& rhs) {

}

template <typename t>
void bitset::_OR_ (const t rhs) {

}

template <typename t>
void bitset::_OR_ (const t rhs, size_t offset) {
    
}

void bitset::print() const {
    printf("[ ");
    for (int i=nb_bits_-1; i>=0; --i) {
        cout << this->at(i) << " ";
    }
    printf("]\n");
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