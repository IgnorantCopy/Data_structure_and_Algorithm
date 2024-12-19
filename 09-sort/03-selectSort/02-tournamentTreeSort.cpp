//
// Created by Ignorant on 2024/12/19.
//

#include <iostream>
#include "../data.h"
using namespace std;

const int INF = INT_MAX;

template<class T>
int winner(int i, int j, T *tree, int n) {
    int u = i >= n ? i : tree[i];
    int v = j >= n? j : tree[j];
    return tree[u] <= tree[v] ? u : v;
}

template<class T>
T createTree(DataList<T> &list, T *tree, const int left, const int n) {
    for (int i = 0; i < n; i++) {
        tree[i + n] = list[left + i].key;
    }
    for (int i = 2 * n - 1; i > 1; i -= 2) {
        int j = i / 2;
        tree[j] = winner(i, i - 1, tree, n);
    }
    T result = tree[tree[1]];
    tree[tree[1]] = INF;
    return result;
}

template<class T>
T reconstruction(T *tree, const int n) {
    T index = tree[1];
    while (index > 1) {
        int i = index / 2;
        int j = index / 2;
        if (i % 2 == 0) {
            j -= 1;
        } else {
            j += 1;
        }
        tree[j] = winner(i, j, tree, n);
        index = j;
    }
    T result = tree[tree[1]];
    tree[tree[1]] = INF;
    return result;
}

template<class T>
void tournamentTreeSort(DataList<T> &list, const int left, const int right) {
    int n = right - left + 1;
    auto *tree = new T[2 * n];
    T pivot = createTree(list, tree, left, n);
    for (int i = 0; i < n; i++) {
        list[left + i] = pivot;
        pivot = reconstruction(tree, n);
    }
    delete[] tree;
}

template<class T>
void tournamentTreeSort(DataList<T> &list) {
    tournamentTreeSort(list, 0, list.size() - 1);
}