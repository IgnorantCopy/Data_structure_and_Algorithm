//
// Created by Ignorant on 2024/11/21.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_01_DATALIST_H
#define DATA_STRUCTURE_AND_ALGORITHM_01_DATALIST_H

#include <iostream>
using namespace std;

const int defaultSize = 100;

template<class E, class K>
class dataList;

template<class E, class K>
class dataNode {
    friend class dataList<E, K>;
    
    K key;
    E ele;
public:
    dataNode(): key(0) {}
    explicit dataNode(K k): key(k) {}
    dataNode(K k, E e): key(k), ele(e) {}
    
    K getKey() const { return key; }
    void setKey(K k) { key = k; }
};

template<class E, class K>
class dataList {
protected:
    dataNode<E, K> *head;
    int size = 0;
    int capacity = defaultSize;
public:
    explicit dataList(int cap = defaultSize): capacity(cap) { head = new dataNode<E, K>[capacity]; }
    dataList(dataList<E, K> &other);
    virtual ~dataList() { delete[] head; }
    
    [[nodiscard]] virtual int length() const { return size; }
    virtual K getKey(int index) const;
    virtual void setKey(int index, K k);
    virtual bool insert(E &ele);
    virtual bool remove(K key, E &ele);
    virtual int search(K key) const;
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_01_DATALIST_H
