#include "forlab11.h"
/////////////// PRIVATE STRUCT //////////////
template<class T>
OneWay<T>::Elem::Elem() : next(nullptr){};

template<class T>
OneWay<T>::Elem::~Elem(){};
/////////////// PRIVATE STRUCT END ////////

///////////// CLASSS /////////////////////

template<class T>
OneWay<T>::OneWay() : len(0), head(nullptr), tail(nullptr){}

template<class T>
OneWay<T>::OneWay(const OneWay<T>& other) : len(other.len), head(nullptr), tail(nullptr){
    for (auto p = other.head; p; p = p -> next)
        push_back(p -> data);
    return;
}

template<class T>
OneWay<T>::OneWay(OneWay<T>&& other) : len(other.len), head(other.head), tail(other.tail){
    other.head = nullptr;
    other.tail = nullptr;
    other.len = 0;
}

template<class T>
OneWay<T>::~OneWay(){
    while (head){
        static Elem* iter;
        iter = head -> next;
        delete head;
        head = iter;
    }
}

template<class T>
size_t OneWay<T>::getLen() const { return len;}

template<class T>
T& OneWay<T>::front() { return head -> data;}

template<class T>
T& OneWay<T>::back() {return tail -> data;}

template<class T>
void OneWay<T>::push_back(const T& a){
    Elem* temp = new Elem{a, nullptr};
    if (head)
        tail -> next = temp;
    else
        head = temp;
    len++;
    tail = temp;
    return;
}

template<class T>
void OneWay<T>::push_front(const T& a){
    Elem* temp = new Elem{a, nullptr};
    if (head)
        temp -> next = head;
    else
        tail = temp;
    head = temp;
    len++;
    return;
}

template<class T>
void OneWay<T>::remove(size_t idx){
    if (head && idx < len){
    Elem* temp = head;
    for (int i = 0; i < idx; i++)
        temp = temp -> next;
    }
    return;
}
///////////// CLASS //////////////////
