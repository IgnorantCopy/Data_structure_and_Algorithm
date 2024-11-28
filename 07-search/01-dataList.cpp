//
// Created by Ignorant on 2024/11/21.
//

#include "01-dataList.h"

template<class E, class K>
dataList<E, K>::dataList(dataList<E, K> &other) {
    capacity = other.capacity;
    size = other.size;
    head = new E[capacity];
    for (int i = 0; i < size; i++) {
        head[i] = other.head[i];
    }
}

template<class E, class K>
K dataList<E, K>::getKey(int index) const {
    if (index < 0 || index >= size) {
        cerr << "Index out of range" << endl;
        return K();
    }
    return head[index].key;
}

template<class E, class K>
void dataList<E, K>::setKey(int index, K k) {
    if (index < 0 || index >= size) {
        cerr << "Index out of range" << endl;
        return;
    }
    head[index].key = k;
}

template<class E, class K>
bool dataList<E, K>::insert(E &ele) {
    if (size == capacity) {
        return false;
    }
    head[size++].ele = ele;
    return true;
}

template<class E, class K>
bool dataList<E, K>::remove(K key, E &ele) {
    int i = search(key);
    if (i == size) {
        return false;
    }
    ele = head[i].ele;
    head[i] = head[--size];
    return true;
}

template<class E, class K>
int dataList<E, K>::search(K key) const {
    head[size].key = key;
    int i = 0;
    for (; i < size && head[i].key != key; i++);
    return i;
}
