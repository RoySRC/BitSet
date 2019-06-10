#include "bitset.h"
#include <iostream>
#include <bitset>

using std::cout;
using std::endl;

int main (int argc, char** argv) {

    // Create a bitset with 33 bits
    bitset BS (33);
    
    BS.set(1);
    BS.print();


    // std::bitset<33> bs;
    // bs.set(0, true);
    // std::string mystring =
    // bs.to_string<char,std::string::traits_type,std::string::allocator_type>();
    // std::cout << "mystring: " << mystring << '\n';


}
