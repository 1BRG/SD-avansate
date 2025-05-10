#pragma once
#include <vector>

class heap {
    std::vector<int> elements;
public:
    heap();;
    void heapify( int n, int i);
    void buildHeap();
    void Merge(heap &rhs);
    void insert(int val);
    int findMin();
    void makeEmpty();
    heap(const heap& other);
    bool isEmpty();
    void deleteMin();
};
