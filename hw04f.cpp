#include <iostream> 
#include <fstream> 

class StringType {

public:
    // one parameter constructor constructs this object from a c-string
    // s (s is an array of char terminated by ’\0’)
    // parameter s, defaults to the empty string ””
    // write and use strdup() to implement this constructor,
    // it allocates a new array, then uses strcpy() to copy
    // chars from array s to the new array

    // Constructor with 1 parameter 
    StringType (const char* s = "") {
        // strdup(s) returns a newly pointer to a newly duplicated string. 
        buffer = strdup(s); 
        capacity = strlen(s); 
    }

    // copy constructor for a StringType, must make a deep copy
    // of s for this. (you can use strdup() you wrote)
    StringType (const StringType& s) {
        buffer = strdup(s.buffer); 
        capacity = s.capacity; 
    }

    // move constructor
    StringType (StringType&& s) noexcept : buffer(nullptr), capacity(s.capacity) {
        s.buffer = nullptr; // resetting to indicate that it no longer owns resources. 
        s.capacity = 0; 
    }

    // assigns this StringType from StringType s (perform deep assignment)
    // remember, both this and s have been previously constructed
    // so they each have storage pointed to by buf
    StringType& operator=(const StringType& s) {
        if (this != &s) { 
            free(buffer); 
            buffer = strdup(s.buffer); 
            capacity = s.capacity;
        }
        return *this; 
    }

    // move assignment operator overload
    StringType& operator=(StringType&& s) noexcept {
        // you fill in
        if (this != &s) { 
            free(buffer); 
            buffer = s.buffer; 
            capacity = s.capacity; 
            s.buffer = nullptr; 
            capacity = 0; 
        }
    }

    // return a reference to the char at position index, 0 is
    // the first element and so on
    
    char& operator[](const int index) {
        // The only constraint is that the index must be in bounds. 
        if (index < 0 || index >= capacity) {
            throw std::out_of_range("Index out of bounds"); 
        }
        return buffer[index]; 
    }

    int length() const {
        return capacity; 
    }

    // returns the index of the first occurrence of c in this StringType
    // indices range from 0 to length()−1
    // returns −1 if the character c is not in this StringType
    int indexOf(char c) const {
        // you fill in
        for (int i = 0; i < capacity; i++) { 
            if(buffer[i] == c) {
                return i; 
            } else { 
                return -1; 
            }
        }
    }

    // returns the index of the first occurrence of pat in this StringType
    // indices range from 0 to length()−1
    // returns −1 if the character string pat is not in this StringType
    // write and use strstr() to implement this function

    int indexOf(const StringType& pat) const {
        //          strstr( "string var", objs buffer ) 
        char *ptr = strstr(buffer, pat.buffer);
        if (ptr) { 
            // subtraction of pointer arithmetic to find the index. 
            return ptr - buffer; 
        } 
        return -1; 
        
    }

    // true if both StringType objects contain the same chars
    // in same position. e.g., ”abc”==”abc” returns true
    // write and use strcmp() to implement this function
    bool operator==(const StringType& s) const {
        if (strcmp(buffer, s.buffer) == 0) { 
            return true; 
        } else { 
            return false; 
        }
    }

    // concatenates this and s to make a new StringType
    // e.g., ”abc”+”def” returns ”abcdef”
    // write and use str2dup() to implement this function,
    // it should allocate a new array then call strcpy()
    // and strcat()
    StringType operator+(const StringType& s) const {
        
    }

    // concatenates s on to end of this
    // e.g., s = ”abc”; s+=”def” now s is ”abcdef”
    // use str2dup()
    StringType& operator+=(const StringType& s) {
        // you fill in
    }

    // returns another StringType that is the reverse of this StringType
    // e.g., s = ”abc”; s.reverse() returns ”cba”
    // write strrev(char* dest, char* src) like strcpy() but
    // copies the reverse of src into dest, then use it
    StringType reverse() const {
        // you fill in
    }

    // prints out this StringType to the ostream out
    void print(std::ostream& out) const {
        // you fill in
    }

    // reads a word from the istream in and this StringType
    // becomes the same as the characters in that word
    // use getline() to implement read()
    void read(std::istream& in) {
        // you fill in
    }

    // destruct a StringType, must free up each node in the head list
    ~StringType() {
        // you fill in
    }

private:
    char* buffer;
    int capacity; // or better: size_t capacity
};

// these two I/O methods are complete as long as you define
// print and read methods correctly
inline std::ostream& operator<<(std::ostream& out, const StringType& str) {
    str.print(out);
    return out;
}

inline std::istream& operator>>(std::istream& in, StringType& str) {
    str.read(in);
    return in;
}

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