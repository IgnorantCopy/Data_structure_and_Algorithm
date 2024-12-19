//
// Created by Ignorant on 2024/12/19.
//

#include <iostream>
#include "../data.h"
using namespace std;

template<class T>
void shiftDown(DataList<T> &list, const int start, const int end) {
    int i = start;
    int j = 2 * i + 1;      // left child
    Element<T> *temp = list[i];
    while (j <= end) {
        if (j < end && list[j] < list[j + 1]) {
            j++;
        }
        if (temp >= list[j]) {
            break;
        } else {
            list[i] = list[j];
            i = j;
            j = 2 * i + 1;
        }
    }
    list[i] = temp;
}

template<class T>
void heapSort(DataList<T> &list) {
    int n = list.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        shiftDown(list, i, n - 1);
    }
    for (int i = n - 1; i >= 1; i--) {
        list.swap(0, i);
        shiftDown(list, 0, i - 1);
    }
}
