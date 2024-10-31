//
// Created by Ignorant on 2024/10/31.
//

#include "01-string.h"
#include <iostream>
using namespace std;

String::String(int size): maxSize(size){
    c = new char[maxSize + 1];
    c[0] = '\0';
}

String::String(const char *init) {
    int length = strlen(init);
    maxSize = max(length, defaultSize);
    c = new char[maxSize + 1];
    len = length;
    strcpy(c, init);
}

String::String(const String &str) {
    maxSize = str.maxSize;
    len = str.len;
    c = new char[maxSize + 1];
    strcpy(c, str.c);
}

String String::operator()(int pos, int n) {
    String temp;
    if (pos >= 0 && n > 0 && pos + n <= maxSize) {
        if (pos + n > len) {
            n = len - pos;
        }
        temp.len = n;
        for (int i = 0, j = pos; i < n; i++, j++) {
            temp.c[i] = c[j];
        }
        temp.c[n] = '\0';
    } else {
        temp.len = 0;
        temp.c[0] = '\0';
    }
    return temp;
}

String &String::operator=(const String &str) {
    if (this != &str) {
        delete[] c;
        c = new char[str.maxSize + 1];
        len = str.len;
        maxSize = str.maxSize;
        strcpy(c, str.c);
    }
    return *this;
}

char &String::operator[](int index) {
    if (index < 0 || index >= len) {
        cerr << "Error: index out of range" << endl;
        exit(1);
    }
    return c[index];
}

String &String::operator+=(String &str) {
    int newLen = len + str.len;
    if (newLen > maxSize) {
        maxSize = newLen;
        char *newC = new char[maxSize + 1];
        strcpy(newC, c);
        delete[] c;
        c = newC;
    }
    strcat(c, str.c);
    len = newLen;
    c[len] = '\0';
    return *this;
}

int *String::getNext() {
    int *next = new int[len];
    next[0] = -1;
    int j = 0;
    int k = -1;
    while (j < len) {
        if (k == -1 || c[j] == c[k]) {
            j++;
            next[j] = ++k;
        } else {
            k = next[k];
        }
    }
    return next;
}

int String::find(String &substr, int k) const {
    int *next = substr.getNext();
    int i = 0;
    int j = k;
    while (i < substr.len && j < len) {
        if (i == -1 || substr.c[i] == c[j]) {
            i++;
            j++;
        } else {
            i = next[i];
        }
    }
    delete[] next;
    if (i < substr.len) {
        return -1;
    }
    return j - substr.len;
}