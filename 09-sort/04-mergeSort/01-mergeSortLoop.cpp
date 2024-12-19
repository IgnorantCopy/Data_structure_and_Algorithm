//
// Created by Ignorant on 2024/12/19.
//

#include <iostream>
#include "../data.h"
using namespace std;


template<class T>
void merge(DataList<T> &list1, DataList<T> &list2, const int left, const int mid, const int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right) {
        if (list1[i] <= list1[j]) {
            list2[k++] = list1[i++];
        } else {
            list2[k++] = list1[j++];
        }
    }
    while (i <= mid) {
        list2[k++] = list1[i++];
    }
    while (j <= right) {
        list2[k++] = list1[j++];
    }
}

template<class T>
void mergePass(DataList<T> &list1, DataList<T> &list2, const int len) {
    int n = list1.size();
    int left = 0;
    while (left + 2 * len <= n - 1) {
        merge(list1, list2, left, left + len - 1, left + 2 * len - 1);
        left += 2 * len;
    }
    if (left + len <= n - 1) {
        merge(list1, list2, left, left + len - 1, n - 1);
    } else {
        for (int i = left; i < n; i++) {
            list2[i] = list1[i];
        }
    }
}

template<class T>
void mergeSortLoop(DataList<T> &list) {
    int n = list.size();
    DataList<T> temp(n);
    int len = 1;
    while (len < n) {
        mergePass(list, temp, len);
        len *= 2;
        mergePass(temp, list, len);
        len *= 2;
    }
}