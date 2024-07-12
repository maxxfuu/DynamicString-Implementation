
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
        std::cout << "After move, str2: " << str2 << std::endl; // Check str2 after move

        StringType str4("world");
        str4 = str1;
        std::cout << "Copy assignment operator: " << str4 << std::endl;


        // Testing move assignment operator
        StringType str5("example");
        str5 = std::move(str4);
        std::cout << "Move assignment operator: " << str5 << std::endl;
        std::cout << "After move, str4: " << str4 << std::endl; // Check str4 after move

        // Testing index operator
        char& charAt = str1[1];
        std::cout << "Index operator: " << charAt << std::endl;

        // Testing length function
        int length = str1.length();
        std::cout << "Length: " << length << std::endl;

        // Testing indexOf(char)
        int index = str1.indexOf('e');
        std::cout << "Index of 'e': " << index << std::endl;

        // Testing indexOf(StringType)
        StringType str6("lo");
        index = str1.indexOf(str6);
        std::cout << "Index of \"lo\": " << index << std::endl;

        // Testing equality operator
        bool isEqual = (str1 == str5);
        std::cout << "Equality operator (str1 == str5): " << isEqual << std::endl;

        // Testing concatenation operator
        StringType str7 = str1 + str5;
        std::cout << "Concatenation operator: " << str7 << std::endl;

        // Testing concatenation assignment operator
        str1 += str5;
        std::cout << "Concatenation assignment operator: " << str1 << std::endl;

        // Testing reverse function
        StringType reversedStr = str1.reverse();
        std::cout << "Reverse: " << reversedStr << std::endl;

        // Test printing
        std::cout << "Print: " << str1 << std::endl;

    
    } catch (const std::exception& e) {

    }

    return 0; 
}