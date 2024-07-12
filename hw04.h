#ifndef HW04_H
#define HW04_H

#include <iostream>
#include <cstring>
#include <stdexcept>

class StringType {
public:

    StringType(); 
    StringType(const char* s);
    StringType(const StringType& s);
    StringType(StringType&& s) noexcept;
    StringType& operator=(const StringType& s);
    StringType& operator=(StringType&& s) noexcept;
    ~StringType();


    char& operator[](const int index);
    int length() const;
    int indexOf(char c) const;
    int indexOf(const StringType& pat) const;
    bool operator==(const StringType& s) const;
    StringType operator+(const StringType& s) const;
    StringType& operator+=(const StringType& s);
    StringType reverse() const;
    void print(std::ostream& out) const;
    void read(std::istream& in);


private:
    char* buffer;
    size_t capacity;
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
#endif // HW04_H
