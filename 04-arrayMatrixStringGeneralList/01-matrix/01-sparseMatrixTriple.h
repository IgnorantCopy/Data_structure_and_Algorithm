//
// Created by Ignorant on 2024/10/24.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_01_SPARSEMATRIXTRIPLE_H
#define DATA_STRUCTURE_AND_ALGORITHM_01_SPARSEMATRIXTRIPLE_H

template<class E>
struct Triple {
    int row = 0;
    int col = 0;
    E data = 0;
};

template<class E>
class SparseMatrix {
    Triple<E> *triples = nullptr;
    int capacity = 0;
    int size = 0;
    int cols = 0;
    int rows = 0;
public:
    explicit SparseMatrix(int s, int m, int n);
    ~SparseMatrix() { delete[] triples; }
    
    [[nodiscard]] bool isEmpty() const { return size == 0; }
    [[nodiscard]] bool isFull() const { return size == capacity; }
    [[nodiscard]] int length() const { return size; }
    bool add(int r, int c, E d);
    bool get(int r, int c, E &d) const;
    bool set(int r, int c, E d);
    void toString() const;
    
    SparseMatrix& T();
    SparseMatrix& transpose();
    SparseMatrix& multiply(const SparseMatrix &other);
    SparseMatrix& add(const SparseMatrix &other);
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_01_SPARSEMATRIXTRIPLE_H
