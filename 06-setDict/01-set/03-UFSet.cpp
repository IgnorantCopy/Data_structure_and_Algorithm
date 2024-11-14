//
// Created by Ignorant on 2024/11/14.
//

#include "03-UFSet.h"

UFSet::UFSet(int size) {
    this->size = size;
    this->parent = new int[size];
    for (int i = 0; i < size; i++) {
        parent[i] = -1;
    }
}

UFSet &UFSet::operator=(const UFSet &other) {
    if (this != &other) {
        delete[] parent;
        size = other.size;
        parent = new int[size];
        for (int i = 0; i < size; i++) {
            parent[i] = other.parent[i];
        }
    }
    return *this;
}

int UFSet::Find(int x) {
    if (parent[x] < 0) {
        return x;
    }
    return Find(parent[x]);
}

void UFSet::Union(int root1, int root2) {
    parent[root1] += parent[root2];
    parent[root2] = root1;
}

void UFSet::UnionBySize(int root1, int root2) {
    int temp = parent[root1] + parent[root2];
    if (parent[root2] < parent[root1]) {
        parent[root1] = root2;
        parent[root2] = temp;
    } else {
        parent[root2] = root1;
        parent[root1] = temp;
    }
}
