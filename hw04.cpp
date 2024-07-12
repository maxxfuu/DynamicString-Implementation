
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
        std::cout << "Constructor using C-string:" << str1 << std::endl;  

        StringType str2 = str1;
        std::cout << "Copy constructor: " << str2 << std::endl;

        StringType str3 = std::move(str2);
        std::cout << "Move constructor: " << str3 << std::endl;

    
    } catch (const std::exception& e) {

    }

    return 0; 
}