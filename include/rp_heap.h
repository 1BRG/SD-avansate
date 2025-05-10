//
// Created by Gabriel on 5/5/2025.
//

#include <vector>
#include <math.h>
#include <stack>
#ifndef RP_HEAP_H
#define RP_HEAP_H

namespace RP {
    struct Node {
        int val, rank;
        Node *left = nullptr, *next = nullptr, *parent = nullptr;

        Node(const int x): val(x), rank(0), left(nullptr), next(nullptr), parent(nullptr) {
        };
    };

    class rp_heap {
        Node *head;
        int heapSize;
        void insertBucket(std::vector<Node *> &bucket, Node *nod);


        int bucket_size() const ;
        void insert_root(Node *nod);
        Node *link(Node *x, Node *y);

    public:
        rp_heap() : head(nullptr), heapSize(0) {
        }
        bool empty() const;
        int size() const;
        const int top() const;
        Node *push(const int val);
        Node *get_head();
        void decrease(Node *nod, int val);
        void clear();
        void merge(rp_heap &b);
        void pop();

        void pop(Node *nod);
        ~rp_heap();
    };
}

#endif //RP_HEAP_H