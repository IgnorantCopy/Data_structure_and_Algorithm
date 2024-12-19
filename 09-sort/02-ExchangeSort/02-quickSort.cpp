//
// Created by Ignorant on 2024/12/13.
//

#include <iostream>
#include "../data.h"
using namespace std;

template<class T>
void quickSort(DataList<T> &list, const int left, const int right) {
    if (left < right) {
        int pivot = list.partition2(left, right);
        quickSort(list, left, pivot - 1);
        quickSort(list, pivot + 1, right);
    }
}
