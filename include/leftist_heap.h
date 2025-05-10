#pragma once


namespace Leftist {
  struct LeftistNode {
        int val;
        LeftistNode *left;
        LeftistNode *right;
        int dist;
      explicit LeftistNode(int _val, LeftistNode *_left=nullptr, LeftistNode *_right=nullptr, int _dist=0);

      ~LeftistNode();
      LeftistNode *clone();
  };


  class leftist_heap {
        LeftistNode *root;
      public:
      leftist_heap();;
      LeftistNode * Merge(LeftistNode *node1, LeftistNode *node2);
      void Merge(leftist_heap &rhs);
      void insert(int val);
      ~leftist_heap();
      int findMin();
      void makeEmpty();
      leftist_heap(leftist_heap &rhs);
      leftist_heap &operator =(const leftist_heap & rhs);
      bool isEmpty();
      void deleteMin();
      leftist_heap &operator =(leftist_heap & rhs);
  };
}

