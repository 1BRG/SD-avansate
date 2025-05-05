//
// Created by Gabriel on 5/5/2025.
//

#include "../include/rp_heap.h"

#include <iostream>
#include <stdexcept>


bool rp_heap::empty() const {
        return heapSize == 0;
    }

    int rp_heap::size() const {
        return heapSize;
    }

    const int rp_heap::top() const {
        if (head)
            return head->val;
       std::cout << "rp_heap::top() on empty heap";
    }

    void rp_heap::insert_root(Node *nod) {
        if (head == nullptr) {
            head = nod;
            head->next = head;
        } else {
            nod->next = head->next;
            head->next = nod;
            if (nod->val < head->val)
                head = nod;
        }
    }

    Node * rp_heap::push(const int val) {
        Node *nod = new Node{val};
        insert_root(nod);
        heapSize++;
        return nod;
    }

    int rp_heap::bucket_size() const {
        return ceil(log2(heapSize + 1) + 2);
    }

    Node *rp_heap::link(Node *x, Node *y) {
        if (y == nullptr)
            return x;
        if (y->val < x->val)
            std::swap(x, y);
        y->parent = x;
        if (x->left) {
            y->next = x->left;
            y->next->parent = y;
        }
        x->left = y;
        x->rank = y->rank + 1;
        return x;
    }

    void rp_heap::decrease(Node *nod, int val) {
        if (val < nod->val)
            nod->val = val;
        else return;
        if (nod == head)
            return;
        if (nod->parent == nullptr) {
            if (nod->val < head->val)
                head = nod;
        } else {
            Node *tata = nod->parent;
            if (nod == tata->left) {
                tata->left = nod->next;
                if (tata->left)
                    tata->left->parent = tata;
            } else {
                tata->next = nod->next;
                if (tata->next)
                    tata->next->parent = tata;
            }

            nod->next = nod->parent = nullptr;
            nod->rank = (nod->left) ? nod->left->rank + 1 : 0;

            insert_root(nod);

            if (tata->parent == nullptr)
                tata->rank = (tata->left) ? tata->left->rank + 1 : 0;
            else {
                while (tata->parent) {
                    int leftRank = (tata->left) ? tata->left->rank : -1;
                    int rightRank = (tata->next) ? tata->next->rank : -1;

                    ///type 2 rank reduction
                    int rank = (abs(leftRank - rightRank) > 1)
                                   ? std::max(leftRank, rightRank)
                                   : std::max(leftRank, rightRank) + 1;

                    if (rank >= tata->rank)
                        break;
                    tata->rank = rank;
                    tata = tata->parent;
                }
            }
        }
    }

    void rp_heap::clear() {
    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    last->next = nullptr;
    std::stack<Node*> q;
    q.push(head);
        while (!q.empty()) {
            Node *nod = q.top();
            q.pop();
            if (nod->left)
                q.push(nod->left);
            if (nod->next)
                q.push(nod->next);
            delete nod;
        }
        head = nullptr;
        heapSize = 0;
    }

    void rp_heap::pop() {
        if (empty())
            return;
        std::vector<Node *> bucket(bucket_size(), nullptr);
        /// fii devin radacini
        for (Node *nod = head->left; nod;) {
            Node *next = nod->next;
            nod->next = nullptr;
            nod->parent = nullptr;
            insertBucket(bucket, nod);
            nod = next;
        }

        /// se proceseaza radacinile
        for (Node *nod = head->next; nod != head;) {
            Node *next = nod->next;
            nod->next = nullptr;
            insertBucket(bucket, nod);
            nod = next;
        }

        head = nullptr;
        for (auto nod: bucket)
            if (nod)
                insert_root(nod);
        heapSize --;
    }

void rp_heap::pop(Node *nod) {
        if (empty() || nod == nullptr)
            return;
        decrease(nod, -1000000005);
        pop();
    }

    void rp_heap::insertBucket(std::vector<Node *> &bucket, Node *nod) {
        while (bucket[nod->rank]) {
            Node *rival = bucket[nod->rank];
            bucket[nod->rank] = nullptr;
            nod = link(nod, rival);
        }
        bucket[nod->rank] = nod;
    }
rp_heap:: ~rp_heap() {
        clear();
    }