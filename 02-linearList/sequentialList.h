//
// Created by Ignorant on 2024/9/12.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_SEQUENTIALLIST_H
#define DATA_STRUCTURE_AND_ALGORITHM_SEQUENTIALLIST_H

#include <iostream>

const int defaultSize = 100;

template<class T, class E>
class SequentialList {
protected:
    int len = 0;
    int maxSize = defaultSize;
    E *data = nullptr;
    void resize();  // 扩容函数
public:
    SequentialList (int size = defaultSize);
    SequentialList (const SequentialList<T, E> &other);
    ~SequentialList() { delete[] data; };
    
    int size() const { return maxSize; }
    int length() const { return len; }
    int search(T &key) const;        // 查找元素
    bool insert(int index, E element);      // 插入元素
    bool remove(int index, E &element);     // 删除元素
    bool isEmpty() const { return len == 0; }
    SequentialList<T, E>& unionList(SequentialList<T, E> &list1, SequentialList<T, E> &list2);
    SequentialList<T, E>& intersectionList(SequentialList<T, E> &list1, SequentialList<T, E> &list2);
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_SEQUENTIALLIST_H
