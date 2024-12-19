//
// Created by Ignorant on 2024/12/12.
//

#include <iostream>
#include "../data.h"
using namespace std;

template<class T>
void insertSort(DataList<T>& list, int left, int right) {
    Element<T> temp;
    for (int i = left + 1; i <= right; i++) {
        if (list[i] < list[i - 1]) {
            temp = list[i];
            int j;
            for (j = i - 1; j >= left && list[j] > temp; j--) {
                list[j + 1] = list[j];
            }
            list[j + 1] = temp;
        }
    }
}

template<class T>
void insertSort(DataList<T>& list) {
    insertSort(list, 0, list.length() - 1);
}
