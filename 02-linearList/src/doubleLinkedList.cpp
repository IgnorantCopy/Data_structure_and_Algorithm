//
// Created by Ignorant on 2024/9/19.
//

#include "../inc/doubleLinkedList.h"
#include <iostream>
using namespace std;


void DoubleLinkedList::clear() {
    Node *current = head;
    while (current != nullptr) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

Node *DoubleLinkedList::search(int data) {
    Node *current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

Node *DoubleLinkedList::locate(int index) {
    if (index < 0 || index >= size) {
        cerr << "Error: Index out of range." << endl;
        return nullptr;
    }
    Node *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

bool DoubleLinkedList::insert(int data, int index) {
    if (index < 0 || index > size) {
        cerr << "Error: Index out of range." << endl;
        return false;
    }
    if (isEmpty()) {
        head = new Node(data);
        tail = head;
        size++;
        return true;
    }
    if (index == 0) {
        auto *newNode = new Node(data);
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
        size++;
        return true;
    }
    if (index == size) {
        auto *newNode = new Node(data);
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
        size++;
        return true;
    }
    Node *current = locate(index - 1);
    auto *newNode = new Node(data);
    newNode->next = current->next;
    newNode->previous = current;
    current->next = newNode;
    newNode->next->previous = newNode;
    size++;
    return true;
}

bool DoubleLinkedList::remove(int data, int index) {
    if (index < 0 || index >= size) {
        cerr << "Error: Index out of range." << endl;
        return false;
    }
    if (isEmpty()) {
        return false;
    }
    if (index == 0) {
        if (head->data == data) {
            Node *temp = head;
            head = head->next;
            if (head != nullptr) {
                head->previous = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
            size--;
            return true;
        }
        return false;
    }
    if (index == size - 1) {
        if (tail->data == data) {
            Node *temp = tail;
            tail = tail->previous;
            if (tail != nullptr) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
            delete temp;
            size--;
            return true;
        }
        return false;
    }
    Node *current = locate(index);
    if (current->data == data) {
        current->previous->next = current->next;
        current->next->previous = current->previous;
        delete current;
        size--;
        return true;
    }
    return false;
}

void DoubleLinkedList::sort() {
    if (isEmpty()) {
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            Node *iNode = locate(i);
            Node *jNode = locate(j);
            if (iNode->data > jNode->data) {
                int temp = iNode->data;
                iNode->data = jNode->data;
                jNode->data = temp;
            }
        }
    }
}