//
// Created by Ignorant on 2024/9/19.
//

#include "../inc/circleList.h"
#include <iostream>
using namespace std;

void CircleList::clear() {
    Node *current = head;
    do {
        Node *temp = current;
        current = current->next;
        delete temp;
    } while (current != head);
    head = nullptr;
    size = 0;
}

Node* CircleList::search(int data) {
    Node *current = head;
    do {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    } while (current != head);
    return nullptr;
}

Node *CircleList::locate(int index) {
    if (isEmpty()) {
        cout << "Error: list is empty." << endl;
        return nullptr;
    } else if (index >= size) {
        index = index % size;
    } else if (index < 0) {
        index = (index % size) + size;
    }
    Node *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

void CircleList::add(int data) {
    auto *newNode = new Node(data);
    if (isEmpty()) {
        head = newNode;
        head->next = head;
    } else {
        Node *current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head->next;
    }
}

void CircleList::remove(int index) {
    Node *previous = locate(index - 1);
    Node *current = previous->next;
    previous->next = current->next;
    delete current;
}