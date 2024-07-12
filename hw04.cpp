
// write more test functions here
#include "hw04.h"

// Write all these testing functions and add more of your own
// follow the example and write a function to test each method.
// Name each of these functions so they clearly indicate what they
// are testing
int main() {

    try { 
        StringType defautString; 
        std::cout << "Default Constructor" << std::endl; 

        StringType str1("hello");
        std::cout << "Constructor with C-string: " << str1 << std::endl;
        
    } catch (const std::exception& e) {

    }

    return 0; 
}