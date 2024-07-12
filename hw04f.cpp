#include "hw04.h"

StringType::StringType() : buffer(nullptr), capacity(0) {}


StringType::StringType(const char* s) {
        // strdup(s) returns a newly pointer to a newly duplicated string. 
        buffer = strdup(s); 
        capacity = strlen(s); 
    }

    // copy constructor for a StringType, must make a deep copy
    // of s for this. (you can use strdup() you wrote)
StringType::StringType (const StringType& s) {
        buffer = strdup(s.buffer); 
        capacity = s.capacity; 
    }

    // move constructor
StringType::StringType (StringType&& s) noexcept : buffer(nullptr), capacity(s.capacity) {
        s.buffer = nullptr; // resetting to indicate that it no longer owns resources. 
        s.capacity = 0; 
    }

    // assigns this StringType from StringType s (perform deep assignment)
    // remember, both this and s have been previously constructed
    // so they each have storage pointed to by buf
StringType& StringType::operator=(const StringType& s) {
    if (this != &s) { 
        free(buffer); 
        buffer = strdup(s.buffer); 
        capacity = s.capacity;
    }
    return *this; 
}

    // move assignment operator overload
StringType& StringType::operator=(StringType&& s) noexcept {
        // you fill in
        if (this != &s) { 
            free(buffer); 
            buffer = s.buffer; 
            capacity = s.capacity; 
            s.buffer = nullptr; 
            capacity = 0; 
        }
        return *this; 
    }

    // return a reference to the char at position index, 0 is
    // the first element and so on
    
char& StringType::operator[](const int index) {
    // The only constraint is that the index must be in bounds. 
    if (index < 0 || index >= capacity) {
        throw std::out_of_range("Index out of bounds"); 
    }
    return buffer[index]; 
}


int StringType::length() const {
    return capacity; 
}

    // returns the index of the first occurrence of c in this StringType
    // indices range from 0 to length()−1
    // returns −1 if the character c is not in this StringType
    int StringType::indexOf(char c) const {
        // you fill in
        for (int i = 0; i < capacity; i++) { 
            if(buffer[i] == c) {
                return i; 
            } 
        }
        return -1; 
    }

    // returns the index of the first occurrence of pat in this StringType
    // indices range from 0 to length()−1
    // returns −1 if the character string pat is not in this StringType
    // write and use strstr() to implement this function

    int StringType::indexOf(const StringType& pat) const {
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
    bool StringType::operator==(const StringType& s) const {
        if (strcmp(buffer, s.buffer) == 0) { 
            return true; 
        } 
        return false; 
    }


    // concatenates this and s to make a new StringType
    // e.g., ”abc”+”def” returns ”abcdef”
    // write and use strdup() to implement this function,
    // it should allocate a new array then call strcpy()
    // and strcat()
    StringType StringType::operator+(const StringType& s) const {
        
        size_t newCapacity = capacity + s.capacity;
        char* newBuffer = new char[newCapacity + 1]; 
        strcpy(newBuffer, s.buffer);                // strcpy(pointer to destination, pointer to source) 
        strcat(newBuffer, this->buffer);            // strcat(pointer to destination, pointer to source) 
        StringType newString(newBuffer); 
        delete[] newBuffer; 
        return newString;
        
    }

    // concatenates s on to end of this
    // e.g., s = ”abc”; s+=”def” now s is ”abcdef”
    // use strdup()
    StringType& StringType::operator+=(const StringType& s) {
        size_t newCapacity = capacity + s.capacity; 
        char* newBuffer = new char[newCapacity]; 
        strcpy(newBuffer, buffer); 
        strcat(newBuffer, s.buffer); 
        free(buffer); 
        buffer = newBuffer; 
        capacity = newCapacity; 
        
        return *this; 


    }

    // returns another StringType that is the reverse of this StringType
    // e.g., s = ”abc”; s.reverse() returns ”cba”
    // write strrev(char* dest, char* src) like strcpy() but
    // copies the reverse of src into dest, then use it
    StringType StringType::reverse() const {
        char* reverse = new char[capacity + 1]; 
        for (int i = 0; i < capacity; i++) { 
            reverse[i] = buffer[capacity - 1 - i]; 
        }
        reverse[capacity] = '\0'; // normal quotation marks won't work when writing the null-character.  
        StringType reversedString(reverse); 
        delete[] reverse; 
        return reversedString; 

    }

    // prints out this StringType to the ostream out
    void StringType::print(std::ostream& out) const {
        out << buffer; 
    }

    // reads a word from the istream in and this StringType
    // becomes the same as the characters in that word
    // use getline() to implement read()
    void StringType::read(std::istream& in) {
        std::string temp; 
        in >> temp; 
        *this = StringType(temp.c_str()); 
    }

    // destruct a StringType, must free up each node in the head list
    StringType::~StringType() {
        free(buffer); 
    }


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
