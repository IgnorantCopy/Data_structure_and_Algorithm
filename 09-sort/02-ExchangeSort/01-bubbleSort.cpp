//
// Created by Ignorant on 2024/12/13.
//

#include <iostream>
#include "../data.h"
using namespace std;

template<class T>
void bubbleSort(DataList<T> &list, const int left, const int right) {
    for (int i = left; i <= right; i++) {
        for (int j = left; j <= right - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                list.swap(list[j], list[j + 1]);
            }
        }
    }
}

template<class T>
void bubbleSort(DataList<T> &list) {
    bubbleSort(list, 0, list.length() - 1);
}
