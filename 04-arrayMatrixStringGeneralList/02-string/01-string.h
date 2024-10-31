//
// Created by Ignorant on 2024/10/31.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_01_STRING_H
#define DATA_STRUCTURE_AND_ALGORITHM_01_STRING_H

#include <cstring>

const int defaultSize = 128;

class String {
    char *c;
    int len = 0;
    int maxSize = defaultSize;
public:
    explicit String(int size = defaultSize);
    explicit String(const char *init);
    String(const String &str);
    ~String() { delete[]c; }
    [[nodiscard]] int length() const { return len; }
    String operator()(int pos, int n);
    bool operator==(const String &str) const { return strcmp(c, str.c) == 0; }
    bool operator!=(const String &str) const { return strcmp(c, str.c)!= 0; }
    bool operator!() const { return len == 0; }
    String& operator=(const String& str);
    String& operator+=(String& str);
    char& operator[](int index);
    int* getNext();
    int find(String& substr, int k) const;
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_01_STRING_H
