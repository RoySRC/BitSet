#include "bitset.h"
#include <iostream>
#include <bitset>

using std::cout;
using std::endl;

#define __INDENT__(n) {for (size_t i=0; i<n; ++i) cout << " ";}
#define __PRINT_LINE__(n) {for (size_t i=0; i<n; ++i) cout << "-"; printf("\n");}
#define print_bitset(bs) { \
    std::cout << bs.to_string<char,std::string::traits_type,std::string::allocator_type>() << '\n';\
}



/*-----------------------------------------------------------------
* Values to test the bitset on
/*-----------------------------------------------------------------*/ 
// 8 bit integers
int8_t val_int8_min = -128;
int8_t val_int8_max = 127;
uint8_t val_uint8_min = 0;
uint8_t val_uint8_max = 255;

// 16 bit integers
int16_t val_int16_max = 32767;
int16_t val_int16_min = -32768;
uint16_t val_uint16_max = 65535;
uint16_t val_uint16_min = 0;

// 32 bit integers
int32_t val_int32_max = 2147483647;
int32_t val_int32_min = -2147483648;
uint32_t val_uint32_max = 4294967295;
uint32_t val_uint32_min = 0;

// 64 bit integers
int64_t val_int64_max = 9223372036854775807;
int64_t val_int64_min = -9223372036854775808;
uint64_t val_uint64_max = 18446744073709551615;
uint64_t val_uint64_min = 0;
/*-----------------------------------------------------------------*/





int main (int argc, char** argv) {
    // Testing the NOT operator
}
