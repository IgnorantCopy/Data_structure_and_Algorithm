//
// Created by Ignorant on 2024/11/14.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_03_UFSET_H
#define DATA_STRUCTURE_AND_ALGORITHM_03_UFSET_H

#include <iostream>
using namespace std;

const int defaultSize = 100;

class UFSet {
    int *parent;
    int size = defaultSize;
public:
    explicit UFSet(int size = defaultSize);
    ~UFSet() { delete[] parent; }
    UFSet& operator=(const UFSet& other);
    
    void Union(int root1, int root2);   // 将 root2 连接到 root1 下面
    int Find(int x);    /// 查找根节点
    void UnionBySize(int root1, int root2);
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_03_UFSET_H
