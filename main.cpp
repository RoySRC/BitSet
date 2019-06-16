#include "bitset.h"
#include <iostream>
#include <bitset>

using std::cout;
using std::endl;

#define __INDENT__(n) {for (size_t i=0; i<n; ++i) cout << " ";}
#define __PRINT_LINE__(n) {for (size_t i=0; i<n; ++i) cout << "-"; printf("\n");}
#define print_bitset(bs) {std::cout << bs.to_string<char,std::string::traits_type,std::string::allocator_type>() << '\n';}

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

void test_AND_function () {



}





int main (int argc, char** argv) {

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




// #define __BLOCK__ 0  // AND
// #define __BLOCK__ 1  // OR
// #define __BLOCK__ 2  // EQUALITY_TEST

#if __BLOCK__ == 1

    // Create a bitset with 33 bits
    bitset BS (34), XS (70);

    {
        BS._OR_(23563422);
        XS._OR_(4234237589272458);

        __INDENT__(36);
        BS.print();
        XS.print();

        __PRINT_LINE__(70);

        __INDENT__(36);
        BS._OR_ (XS);
        BS.print();
    }

    cout << endl;


    {
        __INDENT__(36);
        BS.print();
        XS.print();
        XS._OR_(BS);
        __PRINT_LINE__(70);
        XS.print();
    }


#elif __BLOCK__ == 0

    // Create a bitset with 33 bits
    bitset BS (34), XS (34);

    {
        cout << "Original Data" << endl;
        cout << "BS: ";
        BS._OR_(-1);
        BS.print();
        cout << "XS: ";
        XS._OR_(-1);
        XS.print();

        

    }

    cout << endl;


    {
        auto val = uint32_t(2147483647);
        bitset tmp(BS.size()); tmp.set_value(val); tmp.print();
        BS.print();

        BS._AND_(val);
        __PRINT_LINE__(34);
        BS.print();
    }    

#elif __BLOCK__ == 2

    #define BITSET_SIZE  70
    typedef std::bitset<BITSET_SIZE> BITSET;

    // Create a bitset with 33 bits
    bitset BS (BITSET_SIZE);

    BS._MAX_STACK_ALLOC_LIMIT = 1;

    BITSET bs;

    auto val = uint64_t(18446744073709551615);

    BS._OR_ (-1);
    bs |= -1;
    
    cout << "BS: ";
    BS.print();
    cout << "bs: ";
    print_bitset(bs);

    BS._AND_ (val);
    bs &= val;


    cout << "BS: ";
    BS.print();
    cout << "bs: ";
    print_bitset(bs);


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

#endif
}
