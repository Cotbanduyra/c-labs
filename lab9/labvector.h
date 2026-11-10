#pragma once
#include <iostream>

class Vector{
private:
    int* vect;
    size_t len;
public:
    Vector(int n = 0);
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    ~Vector();

    size_t getLen() const;

    int& operator[] (size_t idx);
    const int& operator[](size_t idx) const;
    Vector& operator= (const Vector& other);
    Vector& operator= (Vector&& other) noexcept;
};

std::ostream& operator<< (std::ostream& os, const Vector& obj);
std::istream& operator>> (std::istream& os, Vector& obj);