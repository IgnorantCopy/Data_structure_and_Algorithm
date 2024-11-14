//
// Created by Ignorant on 2024/11/14.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_02_LINKEDSET_H
#define DATA_STRUCTURE_AND_ALGORITHM_02_LINKEDSET_H

#include <iostream>
using namespace std;

template<class T>
class SetNode {
    T data;
    SetNode<T> *next = nullptr;
public:
    SetNode() = default;
    explicit SetNode(const T &data, SetNode<T> *next = nullptr): data(data), next(next) {}
};

template<class T>
class LinkedSet {
    SetNode<T> *first = nullptr;
    SetNode<T> *last = nullptr;
public:
    LinkedSet();
    LinkedSet(LinkedSet<T> &other);
    ~LinkedSet();
    void makeEmpty();
    bool add(const T &data);
    bool remove(const T &data);
    bool contains(const T &data) const;
    LinkedSet<T>& operator=(const LinkedSet<T> &other);
    LinkedSet<T> operator+(const LinkedSet<T> &other) const;
    LinkedSet<T> operator*(const LinkedSet<T> &other) const;
    LinkedSet<T> operator-(const LinkedSet<T> &other) const;
    bool operator==(const LinkedSet<T> &other) const;
    bool getMin(T &data) const;
    bool getMax(T &data) const;
    bool subset(LinkedSet<T> &other);
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_02_LINKEDSET_H
