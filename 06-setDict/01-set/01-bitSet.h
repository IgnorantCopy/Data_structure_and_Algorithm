//
// Created by Ignorant on 2024/11/14.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_01_BITSET_H
#define DATA_STRUCTURE_AND_ALGORITHM_01_BITSET_H

#include <iostream>
using namespace std;

const int defaultSize = 100;

class BitSet {
    int setSize = 0;
    int vectorSize = 0;
    unsigned short *bitVector;
    
public:
    explicit BitSet(int size = defaultSize);
    BitSet(const BitSet &bitSet);
    ~BitSet() { delete[] bitVector; }
    
    void set(int x);
    void clear();
    bool remove(int x);
    [[nodiscard]] bool contains(int x) const;
    BitSet& operator=(const BitSet &bitSet);
    BitSet operator+(const BitSet &bitSet);   // 并集
    BitSet operator-(const BitSet &bitSet);   // 差集
    BitSet operator*(const BitSet &bitSet);   // 交集
    bool operator==(const BitSet &bitSet) const;
    bool operator!=(const BitSet &bitSet) const;
    [[nodiscard]] bool subset(const BitSet &bitSet) const;
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_01_BITSET_H
