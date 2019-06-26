#include "bitset.h"
#include "bitset_test_values.h"

#include <iostream>
using std::cout;
using std::endl;

#ifndef _BITSET_NOT_OPERATOR_TEST_H_
#define _BITSET_NOT_OPERATOR_TEST_H_

#define randint(min, max) rand() % max + min


void test_bitset_not_operator() {
    // Test 8 bit ints
    bool all_pass = true;
    for (size_t bitSize=1; bitSize<8192; ++bitSize) {
        bitset bs (bitSize);
        
        int8_t val = randint(val_int8_min, val_int8_max);
        int8_t res = ~val;
        
        bs.set_value(val);
        bs._NOT_();

        for (size_t i=0, l=(bitSize<sizeof(int8_t)*8)?bitSize:sizeof(int8_t)*8; i<l; ++i) {
            bool bit_at_i = res & ( (int8_t)1 << i );
            if (bs[i] != bit_at_i) {
                all_pass = false;
                cout << "Testing with bitSize=" << 8192;
                cout << " gave the following:" << endl;
                cout << "Actual: ";
                _print_bits_(res);
                cout << "Got   : ";
                bs.print();
                break;
            }
        }
    }
    if (all_pass) cout << "All tests passed!" << endl;
    else cout << "Some tests failed." << endl;
}


#endif