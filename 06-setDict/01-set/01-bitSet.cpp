//
// Created by Ignorant on 2024/11/14.
//

#include "01-bitSet.h"

BitSet::BitSet(int size) {
    this->vectorSize = size;
    this->bitVector = new unsigned short[vectorSize];
    this->setSize = 0;
}

BitSet::BitSet(const BitSet &bitSet) {
    this->vectorSize = bitSet.vectorSize;
    this->bitVector = new unsigned short[vectorSize];
    this->setSize = bitSet.setSize;
    for (int i = 0; i < vectorSize; i++) {
        this->bitVector[i] = bitSet.bitVector[i];
    }
}

void BitSet::set(const int x) {
    if (x < 0 || x >= vectorSize) {
        return;
    }
    this->bitVector[x] = 1;
    this->setSize++;
}

void BitSet::clear() {
    for (int i = 0; i < vectorSize; i++) {
        this->bitVector[i] = 0;
        this->setSize = 0;
    }
}

bool BitSet::remove(const int x) {
    if (x < 0 || x >= vectorSize) {
        return false;
    }
    this->bitVector[x] = 0;
    this->setSize--;
    return true;
}

bool BitSet::contains(const int x) const {
    if (x < 0 || x >= vectorSize) {
        return false;
    }
    return this->bitVector[x] == 1;
}



bool BitSet::subset(const BitSet &bitSet) const {
    if (this->setSize != bitSet.setSize) {
        return false;
    }
    for (int i = 0; i < vectorSize; i++) {
        if (this->bitVector[i] & !bitSet.bitVector[i]) {
            return false;
        }
    }
    return true;
}

BitSet &BitSet::operator=(const BitSet &bitSet) {
    if (this != &bitSet) {
        this->vectorSize = bitSet.vectorSize;
        delete[] this->bitVector;
        this->bitVector = new unsigned short[vectorSize];
        this->setSize = bitSet.setSize;
        for (int i = 0; i < vectorSize; i++) {
            this->bitVector[i] = bitSet.bitVector[i];
        }
    }
    return *this;
}

BitSet BitSet::operator+(const BitSet &bitSet) {
    BitSet result(max(this->vectorSize, bitSet.vectorSize));
    for (int i = 0; i < result.vectorSize; i++) {
        if (i < this->vectorSize && i < bitSet.vectorSize) {
            result.bitVector[i] = this->bitVector[i] | bitSet.bitVector[i];
        } else if (i < this->vectorSize) {
            result.bitVector[i] = this->bitVector[i];
        } else if (i < bitSet.vectorSize) {
            result.bitVector[i] = bitSet.bitVector[i];
        }
        if (result.bitVector[i] == 1) {
            result.setSize++;
        }
    }
    return result;
}

BitSet BitSet::operator-(const BitSet &bitSet) {
    BitSet result(max(this->vectorSize, bitSet.vectorSize));
    for (int i = 0; i < result.vectorSize; i++) {
        if (i < this->vectorSize && i < bitSet.vectorSize) {
            if (this->bitVector[i] & bitSet.bitVector[i]) {
                result.bitVector[i] = 0;
            } else {
                result.bitVector[i] = this->bitVector[i];
            }
        } else if (i < this->vectorSize) {
            result.bitVector[i] = this->bitVector[i];
        }
        if (result.bitVector[i] == 1) {
            result.setSize++;
        }
    }
    return result;
}

BitSet BitSet::operator*(const BitSet &bitSet) {
    BitSet result(this->vectorSize);
    for (int i = 0; i < result.vectorSize; i++) {
        if (i < bitSet.vectorSize) {
            result.bitVector[i] = this->bitVector[i] & bitSet.bitVector[i];
            if (result.bitVector[i] == 1) {
                result.setSize++;
            }
        } else {
            result.bitVector[i] = 0;
        }
    }
    return result;
}

bool BitSet::operator==(const BitSet &bitSet) const {
    if (this->vectorSize != bitSet.vectorSize) {
        return false;
    }
    for (int i = 0; i < vectorSize; i++) {
        if (this->bitVector[i] != bitSet.bitVector[i]) {
            return false;
        }
    }
    return true;
}

bool BitSet::operator!=(const BitSet &bitSet) const{
    return !(*this == bitSet);
}