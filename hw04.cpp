#include <hw04.h> 
#include <hw04f.cpp> 

// write more test functions here
// ...

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