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

#include "bitset_not_operator_test.h"



int main (int argc, char** argv) {
    // Testing the NOT operator
    // test_bitset_not_operator();

    bitset bs (48);
    bs.set_value(202335968067588);
    bs.print();

    bs.lshift(3);
    bs.print();
}
