//
// Created by Ignorant on 2024/9/12.
//

#include "../inc/sequentialList.h"

using namespace std;

template<class T, class E>
void SequentialList<T, E>::resize() {
    if (len == maxSize) {
        maxSize *= 2;
        auto *newData = new E[maxSize];
        if (newData == nullptr) {
            cerr << "Memory allocation failed!" << endl;
            exit(1);
        }
        for (int i = 0; i < len; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
}

template<class T, class E>
SequentialList<T, E>::SequentialList(int size) {
    if (size > 0) {
        maxSize = size;
        len = 0;
        data = new E[maxSize];
        if (data == nullptr) {
            cerr << "Memory allocation failed!" << endl;
            exit(1);
        }
    }
}

template<class T, class E>
SequentialList<T, E>::SequentialList(const SequentialList<T, E> &other) {
    maxSize = other.size();
    len = other.length();
    data = new E[maxSize];
    if (data == nullptr) {
        cerr << "Memory allocation failed!" << endl;
        exit(1);
    }
    for (int i = 0; i < len; i++) {
        data[i] = other.getData[i];
    }
}

template<class T, class E>
int SequentialList<T, E>::search(T &key) const {
    for (int i = 0; i < len; i++) {
        if (data[i] == key) {
            return i;
        }
    }
    return -1;
}

template<class T, class E>
bool SequentialList<T, E>::insert(int index, E element) {
    if (index < 0 || index > len) {
        return false;
    }
    if (len == maxSize) {
        resize();
    }
    for (int i = len - 1; i >= index; i--) {
        data[i + 1] = data[i];
    }
    data[index] = element;
    len++;
    return true;
}

template<class T, class E>
bool SequentialList<T, E>::remove(int index, E &element) {
    if (index < 0 || index >= len || len == 0) {
        return false;
    }
    element = data[index];
    for (int i = index; i < len; i++) {
        data[i] = data[i + 1];
    }
    len--;
    return true;
}

template<class T, class E>
SequentialList<T, E>& SequentialList<T, E>::unionList(SequentialList<T, E> &list1, SequentialList<T, E> &list2) {
    int len1 = list1.length();
    int len2 = list2.length();
    auto *newList = new SequentialList<T, E>(len1 + len2);
    for (int i = 0; i < len1; i++) {
        newList->insert(i, list1.getData[i]);
    }
    for (int i = 0; i < len2; i++) {
        E element = list2.getData[i];
        if (newList->search(element) == -1) {
            newList->insert(len1 + i, element);
        }
    }
    return *newList;
}

template<class T, class E>
SequentialList<T, E>& SequentialList<T, E>::intersectionList(SequentialList<T, E> &list1, SequentialList<T, E> &list2) {
    int len1 = list1.length();
    int len2 = list2.length();
    auto *newList = new SequentialList<T, E>(max(len1, len2));
    for (int i = 0; i < len1; i++) {
        newList->insert(i, list1.getData[i]);
    }
    for (int i = 0; i < len2; i++) {
        E element = list2.getData[i];
        if (newList->search(element) == -1) {
            newList->remove(i, element);
        }
    }
    return *newList;
}