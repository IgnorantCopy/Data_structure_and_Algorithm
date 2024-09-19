//
// Created by Ignorant on 2024/9/19.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_LINKEDLIST_H
#define DATA_STRUCTURE_AND_ALGORITHM_LINKEDLIST_H

template<class T> class LinkedList;

template<class T>
class Node {
    friend class LinkedList<T>;
private:
    T data;
    Node<T> *next;
public:
    Node() = default;
    explicit Node(const T &data, Node<T> *next = nullptr): data(data), next(next) {}
    ~Node() = default;
};

template<class T>
class LinkedList {
private:
    Node<T> *head = new Node<T>;
    int len = 0;
public:
    LinkedList() = default;
    LinkedList(LinkedList<T> &other);
    ~LinkedList() { clear(); }
    
    void clear();
    int length() const { return len; }
    Node<T>* search(T data);
    Node<T>* locate(int index);
    T* getData(int index);
    void setData(int index, T &data);
    bool insert(int index, T &data);
    bool remove(int index, T &data);
    bool isEmpty() const { return len == 0; }
    Node<T>* getHead() const { return head->next; }
    void setHead(Node<T>* head) { this->head = head; }
    Node<T>* reverse(Node<T>* head);
    void sort();
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_LINKEDLIST_H
