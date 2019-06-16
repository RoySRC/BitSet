/*
 *  This bitset class stores bits in a bit array. Element
 *  zero of the bit array are the least significant bits,
 *  while the last element of the bit array is the most
 *  significant bit.
 * 
 *  The print function prints the bits of the elements of
 *  the bit array reading from the last element of the bit 
 *  array to the first.
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <alloca.h>
#include <math.h>

using std::cout;
using std::endl;

#ifndef _BITSET_H_
#define _BITSET_H_


#define __forceinline__ __attribute__((always_inline))


class bitset {

    typedef uint32_t TYPE;

    size_t nb_bits_ = 0; /* Number of bits in the bitset */
    size_t nb_bytes_ = 0; /* Number of bytes in the bit array */
    TYPE* bit_array = NULL; /* Array used to store the bits */
    size_t bit_array_size = 0; /* Number of elts. in the bit array */
    const size_t WORD_LEN = sizeof(TYPE) * 8;
    bool stack_storage = false;


public:

    size_t _MAX_STACK_ALLOC_LIMIT = 1024; /* bits */

    __forceinline__ bitset (size_t nb_bits) {
        nb_bits_ = nb_bits;
        bit_array_size = 1 + nb_bits / WORD_LEN;
        nb_bytes_ = sizeof(TYPE) * bit_array_size;

        if (bit_array_size <= _MAX_STACK_ALLOC_LIMIT/WORD_LEN) {
            bit_array = (TYPE*)alloca(nb_bytes_);
            memset(bit_array, 0, nb_bytes_);
            stack_storage = true;
        } else {
            bit_array = new TYPE [bit_array_size] ();
            stack_storage = false;
        }
    }

    __forceinline__ bitset (const bitset& rhs) {
        nb_bits_ = rhs.nb_bits_;
        bit_array_size = rhs.bit_array_size;
        nb_bytes_ = sizeof(TYPE) * bit_array_size;

        bit_array = new TYPE [bit_array_size] ();

        // perform the copy operation
        memcpy (bit_array, rhs.bit_array, nb_bytes_) ;
    }

    __forceinline__ ~bitset () {
        if (bit_array && !stack_storage) {
            delete [] bit_array;
            bit_array = NULL;
        }
    }


    __forceinline__ void set (size_t i) { 
        bit_array[i/WORD_LEN] |=  (1 << (i % WORD_LEN));
    }

    template <typename T>
    __forceinline__ void set_value (T val) { 
        _OR_(val);
    }

    __forceinline__ void unset (size_t i) {
        bit_array[i/WORD_LEN] &= ~(1 << (i % WORD_LEN));
    }
    
    __forceinline__ void reset () {
        memset(bit_array, 0, sizeof(TYPE)*bit_array_size);
    }


    bitset& operator >> (const size_t i);

    template <typename t>
    inline void _OR_ (const t& rhs) {
        const size_t NB_BITS_RHS = (sizeof(rhs)*8);
        const bool   SIGN_BIT_SET = signbit(rhs);
        size_t EXT_IDX = 0; // keep track of what elt. of the bitarray
                            // to start sign extending from.

        if (NB_BITS_RHS % WORD_LEN == 0) { /* for {32, 64}%32 */

            // k keeps track of the nb_bits of rhs processed
            for (size_t i=0,k=0; i<bit_array_size && k<NB_BITS_RHS; ++i,k+=WORD_LEN) {
                bit_array[i] |= rhs >> i*WORD_LEN;
                EXT_IDX = i+1;
            }

        } else if (NB_BITS_RHS % WORD_LEN < WORD_LEN) {

            bit_array[0] |= TYPE(rhs);
            EXT_IDX = 1;

        }

        if (SIGN_BIT_SET) {
            for (size_t i=EXT_IDX; i<bit_array_size; ++i) {
                bit_array[i] |= TYPE(-1);
            }
        }

        bit_array[bit_array_size-1] &= ~(TYPE(-1) << (nb_bits_ % WORD_LEN));
        // bit_array[bit_array_size-1] &= TYPE(pow(2, nb_bits_ % WORD_LEN)-1);

    }    

    template <typename t>
    inline void _AND_ (const t& rhs) {
        const size_t NB_BITS_RHS = (sizeof(rhs)*8);
        const bool   SIGN_BIT_SET = signbit(rhs);
        size_t EXT_IDX = 0;

        if (NB_BITS_RHS % WORD_LEN == 0) { /* for {32, 64}%32 */

            // k keeps track of the nb_bits of rhs processed
            for (size_t i=0,k=0; i<bit_array_size && k<NB_BITS_RHS; ++i,k+=WORD_LEN) {
                bit_array[i] &= rhs >> i*WORD_LEN;
                EXT_IDX = i+1;
            }

        } else if (NB_BITS_RHS % WORD_LEN < WORD_LEN) {

            bit_array[0] &= TYPE(rhs);
            EXT_IDX = 1;

        }

        if (!SIGN_BIT_SET) {
            
            for (size_t i=EXT_IDX; i<bit_array_size; ++i) 
                bit_array[i] &= TYPE(0);
                
        }

        bit_array[bit_array_size-1] &= ~(TYPE(-1) << (nb_bits_ % WORD_LEN));
        // bit_array[bit_array_size-1] &= TYPE(pow(2, nb_bits_ % WORD_LEN)-1);

    }

    template <typename T>
    inline void _NOT_ (const T& rhs) {
        cout << __FILE__ << ":" << __LINE__ << ":";
        cout <<  "Function needs implementation" << endl;
    }

    inline void lshift (const size_t val) {
        cout << __FILE__ << ":" << __LINE__ << ":";
        cout <<  "Function needs implementation" << endl;
    }

    inline void rshift (const size_t val) {
        cout << __FILE__ << ":" << __LINE__ << ":";
        cout <<  "Function needs implementation" << endl;
    } 

    /*
     * Accessors
     */

    __forceinline__ bool operator[] (const size_t i) const {
        return at(i);
    }
    
    __forceinline__ bool at (const size_t i) const {
        return bit_array[i/WORD_LEN] & (1 << (i % WORD_LEN));
    }

    void print() const;
    void value_print() const;

    // Getters
    __forceinline__ size_t size() const { return nb_bits_; }
    __forceinline__ size_t len()  const { return size();   }


};

/*
 * Template specializations
 */

template <>
inline void bitset::_OR_ (const bitset& rhs) {
    if (rhs.nb_bits_ == nb_bits_) {
        
        for (size_t i=0; i<bit_array_size; ++i) {
            bit_array[i] |= rhs.bit_array[i];
        }
    
    } else if (nb_bits_ < rhs.nb_bits_) {
        
        for (size_t i=0; i<bit_array_size; ++i) { 
            bit_array[i] |= rhs.bit_array[i];
        }
  
        bit_array[bit_array_size-1] &= ~(TYPE(-1) << (nb_bits_ % WORD_LEN));

    } else if (nb_bits_ > rhs.nb_bits_) {

        for (size_t i=0; i<rhs.bit_array_size; ++i) {
            bit_array[i] |= rhs.bit_array[i];
        }

    } 
}

template <>
inline void bitset::_OR_ (const double& rhs) {
    cout << __FILE__ << ":" << __LINE__ << ":function not implemented" << endl;
}

template <>
inline void bitset::_AND_ (const bitset& rhs) {
    cout << __FILE__ << ":" << __LINE__ << endl;
    if (rhs.nb_bits_ == nb_bits_) {
        
        for (size_t i=0; i<bit_array_size; ++i) {
            bit_array[i] &= rhs.bit_array[i];
        }
    
    } else if (nb_bits_ < rhs.nb_bits_) {
        
        for (size_t i=0; i<bit_array_size; ++i) { 
            bit_array[i] &= rhs.bit_array[i];
        }
  
        bit_array[bit_array_size-1] &= ~(TYPE(-1) << (nb_bits_ % WORD_LEN));

    } else if (nb_bits_ > rhs.nb_bits_) {

        for (size_t i=0; i<rhs.bit_array_size; ++i) {
            bit_array[i] &= rhs.bit_array[i];
        }

    } 
}

#endif