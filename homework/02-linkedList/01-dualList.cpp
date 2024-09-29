//
// Created by Ignorant on 2024/9/29.
//

#include <iostream>
using namespace std;

class Node {
    friend class DualList;
    
    int data;
    int id;
    Node *next = nullptr;
    Node *prev = nullptr;
public:
    Node(int data, int id): data(data), id(id) {}
};

class DualList {
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;
    int count = 0;
public:
    DualList() = default;
    ~DualList() { clear(); }
    
    void clear() {
        Node *current = head;
        while (current) {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    int length() const { return size; }
    bool isEmpty() const { return size == 0; }
    
    Node *getNode(int id) const {
        Node *current = head;
        while (current) {
            if (current->id == id) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
    
    void insertLeft(int data) {
        auto *node = new Node(data, ++count);
        if (isEmpty()) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        size++;
    }
    
    void insertRight(int data) {
        auto *node = new Node(data, ++count);
        if (isEmpty()) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        size++;
    }
    
    void remove(int id) {
        Node *node = getNode(id);
        if (node == nullptr) {
            return;
        }
        if (node == head && node == tail) {
            head = nullptr;
            tail = nullptr;
        } else if (node == head) {
            head = node->next;
            head->prev = nullptr;
        } else if (node == tail) {
            tail = node->prev;
            tail->next = nullptr;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        delete node;
        size--;
    }
    
    void insertLeft(int data, int id) {
        Node *node = getNode(id);
        if (node == nullptr) {
            return;
        }
        if (node == head) {
            insertLeft(data);
        } else {
            auto *newNode = new Node(data, ++count);
            newNode->next = node;
            newNode->prev = node->prev;
            node->prev->next = newNode;
            node->prev = newNode;
            size++;
        }
    }
    
    void insertRight(int data, int id) {
        Node *node = getNode(id);
        if (node == nullptr) {
            return;
        }
        if (node == tail) {
            insertRight(data);
        } else {
            auto *newNode = new Node(data, ++count);
            newNode->prev = node;
            newNode->next = node->next;
            node->next->prev = newNode;
            node->next = newNode;
            size++;
        }
    }
    
    void print() const {
        Node *current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int m = 0;
    cin >> m;
    auto list = DualList();
    for (int i = 0; i < m; i++) {
        string op;
        int data = 0;
        int id = 0;
        cin >> op;
        switch (op[0]) {
            case 'L':
                cin >> data;
                list.insertLeft(data);
                break;
            case 'R':
                cin >> data;
                list.insertRight(data);
                break;
            case 'D':
                cin >> id;
                list.remove(id);
                break;
            case 'I':
                cin >> id >> data;
                if (op[1] == 'L') {
                    list.insertLeft(data, id);
                } else {
                    list.insertRight(data, id);
                }
                break;
            default:
                break;
        }
    }
    list.print();
    return 0;
}
