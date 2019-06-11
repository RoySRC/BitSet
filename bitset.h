// The rightmost entry is the least significant bit, while the
// leftmost entry is the most significant bit.

#include <iostream>
#include <cstdlib>
#include <cstring>

using std::cout;
using std::endl;

#ifndef _BITSET_H_
#define _BITSET_H_


class bitset {

    typedef uint32_t TYPE;

    size_t nb_bits_ = 0; /* Number of bits in the bitset */
    TYPE* bit_array = NULL; /* Array used to store the bits */
    size_t bit_array_size = 0; /* Size of the bit array */
    const size_t WORD_LEN = sizeof(TYPE) * 8;


public:

    bitset (size_t nb_bits) ;
    bitset (const bitset& rhs);
    ~bitset () ;

    // setters
    void set   (size_t i);
    void unset (size_t i);

    void _OR_ (const TYPE rhs);
    void _OR_ (const bitset& rhs);

    bool operator[] (size_t i);
    bool at (size_t i) const;

    void print() const;
    void value_print() const;

    // Getters
    inline size_t size() const { return nb_bits_; }
    inline size_t len()  const { return size();   }


};


#endif