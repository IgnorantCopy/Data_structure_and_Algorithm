//
// Created by Ignorant on 2024/12/12.
//

#include "data.h"

template<class T>
void DataList<T>::swap(Element<T> &a, Element<T> &b) const {
    Element<T> temp = a;
    a = b;
    b = temp;
}

template<class T>
Element<T> &DataList<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("DataList index out of range");
    }
    size = max(size, index + 1);
    return data[index];
}

template<class T>
int DataList<T>::partition1(const int left, const int right) {
    int pivotPos = left;
    Element<T> pivot = data[pivotPos];
    for (int i = left + 1; i <= right; i++) {
        if (data[i] < pivot) {
            pivotPos++;
            if (pivotPos != i) {
                swap(data[pivotPos], data[i]);
            }
        }
    }
    // swap(data[pivotPos], pivot);
    data[left] = data[pivotPos];
    data[pivotPos] = pivot;
    return pivotPos;
}

template<class T>
int DataList<T>::partition2(const int left, const int right) {
    int l = left;
    int r = right;
    Element<T> pivot = data[left];
    while (l < r) {
        for (; l < r && data[r] >= pivot; r--);
        if (l < r) {
            data[l] = data[r];
            l++;
        }
        for (; l < r && data[l] < pivot; l++);
        if (l < r) {
            data[r] = data[l];
            r--;
        }
    }
    data[l] = pivot;
    return l;
}
