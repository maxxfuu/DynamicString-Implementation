#ifndef HW04_H
#define HW04_H

#include <iostream>
#include <cstring>
#include <stdexcept>

class StringType {
public:
    // Default constructor
    StringType();

    // Constructor with one parameter
    StringType(const char* s);

    // Copy constructor
    StringType(const StringType& s);

    // Move constructor
    StringType(StringType&& s) noexcept;

    // Copy assignment operator
    StringType& operator=(const StringType& s);

    // Move assignment operator
    StringType& operator=(StringType&& s) noexcept;

    // Destructor
    ~StringType();

    // Operator [] for accessing character at index
    char& operator[](const int index);

    // Length of the string
    int length() const;

    // Find index of first occurrence of char c
    int indexOf(char c) const;

    // Find index of first occurrence of pattern
    int indexOf(const StringType& pat) const;

    // Equality operator
    bool operator==(const StringType& s) const;

    // Concatenation operator
    StringType operator+(const StringType& s) const;

    // Concatenation assignment operator
    StringType& operator+=(const StringType& s);

    // Reverse the string
    StringType reverse() const;

    // Print the string
    void print(std::ostream& out) const;

    // Read a word from the input
    void read(std::istream& in);


private:
    char* buffer;
    size_t capacity;
};

// I/O operators
inline std::ostream& operator<<(std::ostream& out, const StringType& str) {
    str.print(out);
    return out;
}

inline std::istream& operator>>(std::istream& in, StringType& str) {
    str.read(in);
    return in;
}

#endif // HW04_H
