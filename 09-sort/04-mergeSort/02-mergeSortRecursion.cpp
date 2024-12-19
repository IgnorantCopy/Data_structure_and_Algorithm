//
// Created by Ignorant on 2024/12/19.
//

#include <iostream>
#include "../data.h"
using namespace std;

template<class T>
void merge(DataList<T> &list, const int left, const int mid, const int right) {
    auto *temp = new DataList<T>(list.size());
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right) {
        if (list[i] <= list[j]) {
            temp[k++] = list[i++];
        } else {
            temp[k++] = list[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = list[i++];
    }
    while (j <= right) {
        temp[k++] = list[j++];
    }
    for (int l = left; l <= right; l++) {
        list[l] = temp[l];
    }
    delete temp;
}

template<class T>
void mergeSortRecursion(DataList<T> &list, const int left, const int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    mergeSortRecursion(list, left, mid);
    mergeSortRecursion(list, mid + 1, right);
    merge(list, left, mid, right);
}