//
// Created by Ignorant on 2024/12/13.
//

#include <iostream>
#include "../data.h"
using namespace std;

template<class T>
void binaryInsertSort(DataList<T> &list, const int left, const int right) {
    Element<T> temp;
    for (int i = left + 1; i <= right; i++) {
        temp = list[i];
        int l = left;
        int r = i - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (temp < list[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        for (int j = i - 1; j >= l; j--) {
            list[j + 1] = list[j];
        }
        list[l] = temp;
    }
}

template<class T>
void binaryInsertSort(DataList<T> &list) {
    binaryInsertSort(list, 0, list.length() - 1);
}
