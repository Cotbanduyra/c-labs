#pragma once
#include <iostream>

template<class T>
class OneWay{
private:
    struct Elem{
        T data;
        Elem* next;
        Elem();
        ~Elem();
    };
    Elem* head;
    Elem* tail;
    size_t len;
public:
    OneWay();
    OneWay(const OneWay<T>& other);
    OneWay(OneWay<T>&& other) noexcept;
    ~OneWay();

    size_t getLen() const;
    T& front();
    T& back();

    void push_back(cosnt T& a);
    void push_front(const T& a);

    void remove(size_t idx);
    int find(bool (*usl)(T a));
    T max();

    T& operator[](size_t idx);
    const T& operator[](size_t idx) const;
};

template<class T>
std::ostream& operator<< (std::ostream& os, const OneWay<T>& obj);


template<class T>
std::istream& operator>> (std::istream& os, OneWay<T>& obj);