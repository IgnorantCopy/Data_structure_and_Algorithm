//
// Created by Ignorant on 2024/10/24.
//

#include "01-sparseMatrixTriple.h"
#include <iostream>

template<class E>
SparseMatrix<E>::SparseMatrix(int s, int m, int n): capacity(s), rows(m), cols(n) {
    triples = new Triple<E>[capacity];
}

template<class E>
bool SparseMatrix<E>::add(int r, int c, E d) {
    if (isFull()) {
        return false;
    }
    triples[size++] = {r, c, d};
    return true;
}

template<class E>
bool SparseMatrix<E>::get(int r, int c, E& d) const {
    if (isEmpty()) {
        return false;
    }
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (triples[i].row == r && triples[i].col == c) {
            d = triples[i].data;
            return true;
        }
    }
    return false;
}

template<class E>
bool SparseMatrix<E>::set(int r, int c, E d) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        return false;
    }
    for (auto &triple: triples) {
        if (triple.row == r && triple.col == c) {
            triple.data = d;
            return true;
        }
    }
    return add(r, c, d);
}

template<class E>
void SparseMatrix<E>::toString() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            E d;
            if (get(i, j, d)) {
                std::cout << d << " ";
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
}

template<class E>
SparseMatrix<E>& SparseMatrix<E>::T() {
    qsort(triples, size, sizeof(Triple<E>[0]), [](const void* a, const void* b) {
        const auto* ta = (const Triple<E>*)a;
        const auto* tb = (const Triple<E>*)b;
        if (ta->col != tb->col) {
            return ta->col - tb->col;
        }
        return ta->row - tb->row;
    });
    return *this;
}

template<class E>
SparseMatrix<E>& SparseMatrix<E>::transpose() {
    if (isEmpty()) {
        return *this;
    }
    int *rowIndex = new int[rows];
    int *colIndex = new int[size];
    for (int i = 0; i < rows; i++) {
        rowIndex[i] = 0;
    }
    for (int j = 0; j < size; j++) {
        colIndex[j] = 0;
    }
    int count = 0;
    for (int i = 0; i < size; i++) {
        int r = triples[i].row;
        int c = triples[i].col;
        rowIndex[r]++;
        colIndex[count++] = c;
    }
    auto *newTriples = new Triple<E>[capacity];
    int length = 0;
    int temp = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rowIndex[i]; j++) {
            int c = colIndex[temp];
            newTriples[length++] = {c, i, triples[temp].data};
            temp++;
        }
    }
    delete[] triples;
    triples = newTriples;
    delete[] rowIndex;
    delete[] colIndex;
    return *this;
}

template<class E>
SparseMatrix<E>& SparseMatrix<E>::multiply(const SparseMatrix &other) {
    if (cols != other.rows) {
        std::cerr << "Error: matrix size not match" << std::endl;
        return *this;
    }
    
}

template<class E>
SparseMatrix<E>& SparseMatrix<E>::add(const SparseMatrix<E> &other) {
    if (rows != other.rows || cols != other.cols) {
        std::cerr << "Error: matrix size not match" << std::endl;
        return *this;
    }
    for (const auto &otherTriple: other.triples) {
        bool found = false;
        for (auto &triple: triples) {
            if (triple->row == otherTriple.row && triple->col == otherTriple.col) {
                triple->data += otherTriple.data;
                found = true;
                break;
            }
        }
        if (!found) {
            add(otherTriple.row, otherTriple.col, otherTriple.data);
        }
    }
    return *this;
}
