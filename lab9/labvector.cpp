#include "labvector.h"

Vector::Vector(int n) : len(n), vect(n ? new int[n]() : nullptr){}

Vector::Vector(const Vector& other) : len(other.len), vect (other.len ? new int[other.len]() : nullptr){
    for(int i = 0; i < len; i++)
        vect[i] = other[i];
}

Vector::Vector(Vector&& other) noexcept : len(other.len), vect(other.vect){
    other.len = 0;
    other.vect = nullptr;
}

Vector::~Vector(){
    len = 0;
    delete[] vect;
}

size_t Vector::getLen() const{ return len; }

int& Vector::operator[](size_t idx){ return vect[idx]; }
const int& Vector::operator[](size_t idx) const { return vect[idx]; }

Vector& Vector::operator=(const Vector& other){
        if (this != &other) {
            delete[] vect;
            len = other.len;
            vect = len ? new int[len] : nullptr;
            for (int i = 0; i < len; i++) vect[i] = other.vect[i];
        }
        return *this;
}

Vector& Vector::operator=(Vector&& other) noexcept {
    if (this != &other) {
        delete[] vect;
        vect = other.vect;
        len = other.len;
        other.vect = nullptr;
        other.len = 0;
    }
    return *this;
}

std::ostream& operator<< (std::ostream& os, const Vector& obj){
    for(size_t i = 0; i < obj.getLen(); i++)
        os << obj[i] << " ";
    return os;
}

std::istream& operator>> (std::istream& is, Vector& obj){
    for (size_t i = 0; i < obj.getLen(); i++)
        is >> obj[i];
    return is;
}