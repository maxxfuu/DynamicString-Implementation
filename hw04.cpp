#include "hw04.h"
#include "hw04f.cpp"


// write more test functions here


// Write all these testing functions and add more of your own
// follow the example and write a function to test each method.
// Name each of these functions so they clearly indicate what they
// are testing
StringType copyConstructorTest(StringType l) {
    return l;
}

void testReverse() {
    std::ifstream in("input.txt");
    StringType l;
while (in >> l) {
    std::cout << copyConstructorTest(l)
            << " " << l.length() << " "
            << l.reverse() << std::endl;
    }
}

int main() {


    // This try/catch will catch any exception thrown by
    // StringType::error() while calling test functions.
    try {
        testReverse();
        // put more test function calls here written just above
    }
    catch (int i) {
        std::cout << "Got an exception: " << i << std::endl;
    }

    // std::cerr << "Net memory allocated at program end: "
    //      << NumAllocations << std::endl;
    // std::cerr << " (should be zero... "
    //      << "positive = mem leak, negative = duplicate delete)\n";
    return 0;
}