//
// Created by Ignorant on 2024/12/13.
//

#include <iostream>
#include "../data.h"
using namespace std;

template<class T>
void shellSort(DataList<T> &list, const int left, const int right) {
    Element<T> temp;
    int gap = right - left + 1;
    do {
        gap /= 2;
        for (int i = left + gap; i <= right; i++) {
            if (list[i] < list[i - gap]) {
                temp = list[i];
                int j = i - gap;
                while (j >= left && list[j] > temp) {
                    list[j + gap] = list[j];
                    j -= gap;
                }
                list[j + gap] = temp;
            }
        }
    } while (gap > 1);
}

template<class T>
void shellSort(DataList<T> &list) {
    shellSort(list, 0, list.length() - 1);
}