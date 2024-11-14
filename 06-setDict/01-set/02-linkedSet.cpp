//
// Created by Ignorant on 2024/11/14.
//

#include "02-linkedSet.h"

template<class T>
LinkedSet<T>::LinkedSet() {
    this->first = new SetNode<T>;
    this->last = this->first;
}

template<class T>
LinkedSet<T>::LinkedSet(LinkedSet<T> &other) {
    this->first = new SetNode<T>;
    SetNode<T> *p = other.first->next;
    while (p!= nullptr) {
        this->add(p->data);
        p = p->next;
    }
}

template<class T>
LinkedSet<T>::~LinkedSet() {
    makeEmpty();
    delete this->first;
}

template<class T>
void LinkedSet<T>::makeEmpty() {
    SetNode<T> *p = this->first->next;
    while (p != nullptr) {
        SetNode<T> *q = p;
        p = p->next;
        delete q;
    }
    this->first->next = nullptr;
    this->last = this->first;
}

template<class T>
bool LinkedSet<T>::add(const T &data) {
    if (this->contains(data)) {
        return false;
    }
    auto *newNode = new SetNode<T>(data);
    auto *temp = this->first;
    while (temp->next != nullptr) {
        if (temp->next->data > newNode->data) {
            break;
        }
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        this->last->next = newNode;
        this->last = newNode;
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return true;
}

template<class T>
bool LinkedSet<T>::remove(const T &data) {
    auto *temp = this->first;
    while (temp->next != nullptr) {
        if (temp->next->data == data) {
            auto *p = temp->next;
            temp->next = temp->next->next;
            if (p == this->last) {
                this->last = temp;
            }
            delete p;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template<class T>
bool LinkedSet<T>::contains(const T &data) const {
    auto *temp = this->first;
    while (temp->next != nullptr) {
        if (temp->next->data == data) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template<class T>
LinkedSet<T> &LinkedSet<T>::operator=(const LinkedSet<T> &other) {
    if (this != &other) {
        makeEmpty();
        SetNode<T> *p = other.first->next;
        while (p != nullptr) {
            this->add(p->data);
            p = p->next;
        }
    }
    return *this;
}

template<class T>
LinkedSet<T> LinkedSet<T>::operator+(const LinkedSet<T> &other) const {
    LinkedSet<T> result;
    SetNode<T> *p = this->first->next;
    while (p != nullptr) {
        result.add(p->data);
        p = p->next;
    }
    p = other.first->next;
    while (p != nullptr) {
        result.add(p->data);
        p = p->next;
    }
    return result;
}

template<class T>
LinkedSet<T> LinkedSet<T>::operator*(const LinkedSet<T> &other) const {
    LinkedSet<T> result;
    SetNode<T> *p = this->first->next;
    while (p != nullptr) {
        if (other.contains(p->data)) {
            result.add(p->data);
        }
        p = p->next;
    }
    return result;
}

template<class T>
LinkedSet<T> LinkedSet<T>::operator-(const LinkedSet<T> &other) const {
    LinkedSet<T> result;
    SetNode<T> *p = this->first->next;
    while (p != nullptr) {
        if (!other.contains(p->data)) {
            result.add(p->data);
        }
        p = p->next;
    }
    return result;
}

template<class T>
bool LinkedSet<T>::operator==(const LinkedSet<T> &other) const {
    SetNode<T> *temp1 = this->first->next;
    SetNode<T> *temp2 = other.first->next;
    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->data != temp2->data) {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (temp1 != nullptr || temp2 != nullptr) {
        return false;
    }
    return true;
}

template<class T>
bool LinkedSet<T>::getMin(T &data) const {
    if (this->first->next == nullptr) {
        return false;
    }
    data = this->first->next->data;
    return true;
}

template<class T>
bool LinkedSet<T>::getMax(T &data) const {
    if (this->last == nullptr) {
        return false;
    }
    data = this->last->data;
    return true;
}

template<class T>
bool LinkedSet<T>::subset(LinkedSet<T> &other) {
    SetNode<T> *temp = other->first->next;
    while (temp != nullptr) {
        if (!this->contains(temp->data)) {
            return false;
        }
    }
    return true;
}
