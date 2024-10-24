//
// Created by Ignorant on 2024/10/24.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_02_PRIORITYQUEUE_H
#define DATA_STRUCTURE_AND_ALGORITHM_02_PRIORITYQUEUE_H

template<class E>
class PriorityQueue {
    E *elements;
    int capacity = 0;
    int size = 0;
    void adjust();
public:
    explicit PriorityQueue(int size_ = 50);
    ~PriorityQueue() { delete[] elements; }
    
    bool insert(E ele);
    bool remove(E &ele);
    bool getFront(E &ele);
    void makeEmpty() { size = 0; }
    [[nodiscard]] bool isEmpty() const { return size == 0; }
    [[nodiscard]] bool isFull() const { return size == capacity; }
    [[nodiscard]] int length() const { return size; }
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_02_PRIORITYQUEUE_H
