//
// Created by Ignorant on 2024/12/19.
//

#include <iostream>
#include "../data.h"
using namespace std;

template<class T>
void selectSort(DataList<T> &list, const int left, const int right) {
    for (int i = left; i < right; i++) {
        int minIndex = i;
        for (int j = i + 1; j <= right; j++) {
            minIndex = (list[j] < list[minIndex]) ? j : minIndex;
        }
        if (minIndex!= i) {
            list.swap(i, minIndex);
        }
    }
}

template<class T>
void selectSort(DataList<T> &list) {
    selectSort(list, 0, list.size() - 1);
}
