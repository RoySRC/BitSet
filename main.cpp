#include "bitset.h"
#include <iostream>
#include <bitset>

using std::cout;
using std::endl;

#define __INDENT__(n) {for (size_t i=0; i<n; ++i) cout << " ";}

bool check_bitset_or () {
    bitset B1 (48), B2 (48); // B1 == B2
    bitset B3 (48), B4 (24); // B3 >  B4
    bitset B5 (12), B6 (24); // B5 < B6

    /*
     * Test to make sure that the _OR_ function works
     * with positive values that are within the number 
     * of bits specified.
     */

    #define B1V 83191688200720
    #define B2V 411769882798669
    #define B3V 490221118249070
    #define B4V 14681142
    #define B5V 5643
    #define B6V 9932558

    B1._OR_ (B1V);
    B2._OR_ (B2V);
    B3._OR_ (B3V);
    B4._OR_ (B4V);
    B5._OR_ (B5V);
    B6._OR_ (B6V);

    B1.print();
    B1.value_print();

    for (size_t i=0; i<B1.size(); --i) {
        bool rhs = (B1V & (1<<i));
        if ( B1[i] != rhs ) {
            cout << "Error" << ": ";
            cout << B1[i] << " != " << rhs << endl;
        }
    }


    /*
     * Test to make sure that the _OR_ function works
     * with negative values that are within the number 
     * of bits specified.
     */

    #undef B1V
    #undef B2V
    #undef B3V
    #undef B4V
    #undef B5V
    #undef B6V

    #define B1V -83191688200720
    #define B2V -411769882798669
    #define B3V -490221118249070
    #define B4V -14681142
    #define B5V -5643
    #define B6V -9932558

    B1._OR_ (B1V);
    B2._OR_ (B2V);
    B3._OR_ (B3V);
    B4._OR_ (B4V);
    B5._OR_ (B5V);
    B6._OR_ (B6V);

    return true;
}

int main (int argc, char** argv) {

    #define BITSET_SIZE  70
    typedef std::bitset<BITSET_SIZE> BITSET;

    // Create a bitset with 33 bits
    bitset BS (BITSET_SIZE);

    BS._MAX_STACK_ALLOC_LIMIT = 1;

    BITSET bs;

    auto val = uint64_t(18446744073709551615);
    BS._OR_ (val);
    bs |= val;


    std::string mystring =
    bs.to_string<char,std::string::traits_type,std::string::allocator_type>();
    std::cout << "bs: " << mystring << '\n';

    cout << "BS: ";
    BS.print();



    for (size_t i=0,r=1; i<BITSET_SIZE; ++i) {
        if (bs[i] != BS[i]) {
            cout << "ERROR: Bit mismatch" << endl;

            cout << "i=" << i << endl;
            cout << "bs["<<i<<"] = "<<bs[i] << endl;
            cout << "BS["<<i<<"] = "<<BS[i] << endl;
            
            r=0;
        }
        if (r==0) {
            cout << "ERROR: Bit mismatch" << endl;
            break;
        }
        if (i+1==BITSET_SIZE) {
            cout << "TEST PASSED" << endl;
        }
    }

}
