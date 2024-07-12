#include "hw04.h"

StringType::StringType() : buffer(nullptr), capacity(0) {}


StringType::StringType(const char* s) {
        // strdup(s) returns a newly pointer to a newly duplicated string. 
        if (s) { 
            buffer = strdup(s); 
            capacity = strlen(s); 
        } else { 
            *this = StringType(); // Use Default Constructor if s is a null-pointer. 
        }
    }

StringType::StringType (const StringType& s) {
        buffer = strdup(s.buffer); 
        capacity = s.capacity; 
    }

StringType::StringType (StringType&& s) noexcept 
        : buffer(s.buffer), capacity(s.capacity) {
        s.buffer = nullptr; // resetting to indicate that it no longer owns resources. 
        s.capacity = 0; 
    }

StringType& StringType::operator=(const StringType& s) {
    if (this != &s) { 
        free(buffer); 
        buffer = strdup(s.buffer); 
        capacity = s.capacity;
    }
    return *this; 
}

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

    int StringType::indexOf(char c) const {
        // you fill in
        for (int i = 0; i < capacity; i++) { 
            if(buffer[i] == c) {
                return i; 
            } 
        }
        return -1; 
    }


    int StringType::indexOf(const StringType& pat) const {
        //          strstr( "string var", objs buffer ) 
        char *ptr = strstr(buffer, pat.buffer);
        if (ptr) { 
            // subtraction of pointer arithmetic to find the index. 
            return ptr - buffer; 
        } 
        return -1; 
        
    }

    bool StringType::operator==(const StringType& s) const {
        if (strcmp(buffer, s.buffer) == 0) { 
            return true; 
        } 
        return false; 
    }

    StringType StringType::operator+(const StringType& s) const {
        
        size_t newCapacity = capacity + s.capacity;
        char* newBuffer = new char[newCapacity + 1]; 
        strcpy(newBuffer, s.buffer);                // strcpy(pointer to destination, pointer to source) 
        strcat(newBuffer, this->buffer);            // strcat(pointer to destination, pointer to source) 
        StringType newString(newBuffer); 
        delete[] newBuffer; 
        return newString;
        
    }

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

    void StringType::print(std::ostream& out) const {
        if (buffer) {
            out << buffer;
        } else {
            out << "(empty)";  // print empty for StringObjecfs that have been moved. 
        }
    }

    void StringType::read(std::istream& in) {
        std::string temp; 
        in >> temp; 
        *this = StringType(temp.c_str()); 
    }

    StringType::~StringType() {
        if (buffer) {
            free(buffer);
        } 
    }



