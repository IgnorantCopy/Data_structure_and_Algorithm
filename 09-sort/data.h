//
// Created by Ignorant on 2024/12/12.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_DATA_H
#define DATA_STRUCTURE_AND_ALGORITHM_DATA_H

#include <iostream>
using namespace std;


const int defaultSize = 100;


template<class T>
class Element {
public:
    T key;
    
    Element() = default;
    explicit Element(T k) : key(k) {}
    
    bool operator==(const Element<T>& other) const { return key == other.key; }
    bool operator<=(const Element<T>& other) const { return key <= other.key; }
    bool operator>=(const Element<T>& other) const { return key >= other.key; }
    bool operator<(const Element<T>& other) const { return key < other.key; }
    bool operator>(const Element<T>& other) const { return key > other.key; }
    
    Element<T>& operator=(const Element<T>& other) { key = other.key; return *this; }
};


template<class T>
class DataList {
    Element<T>* data;
    int size = 0;
    int capacity = defaultSize;
public:
    explicit DataList(int cap = defaultSize): data(new Element<T>[cap]), capacity(cap) {}
    ~DataList() { delete[] data; }
    
    [[nodiscard]] int length() const { return size; }
    void swap(Element<T> &a, Element<T> &b) const;
    Element<T>& operator[](int index);
    int partition1(int left, int right);
    int partition2(int left, int right);
};


#endif //DATA_STRUCTURE_AND_ALGORITHM_DATA_H
