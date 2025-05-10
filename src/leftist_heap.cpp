
#include "../include/leftist_heap.h"

#include <future>
#include <stack>

namespace Leftist {


  inline LeftistNode::LeftistNode(int _val, LeftistNode *_left, LeftistNode *_right, int _dist):
      val(_val),
      left(_left),
      right(_right),
      dist(_dist) {}

  inline LeftistNode::~LeftistNode() {
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
  }

  LeftistNode * LeftistNode::clone() {
    return new LeftistNode(val, left?left->clone():nullptr,
                           right?right->clone():nullptr, dist);
  }

  leftist_heap::leftist_heap() {
    root=nullptr;
  }

  LeftistNode * leftist_heap::Merge(LeftistNode *node1, LeftistNode *node2) {
    if (node1==nullptr )
      return node2;
    if (node2==nullptr )
      return node1;
    if (node1->val < node2->val) {
      std::swap(node1, node2);
    }
    if (node1->left==nullptr) {
      node1->left=node2;
      return node1;
    }
    node1->right=Merge(node1->right, node2);
    if (node1->left->dist<node1->right->dist) {
      std::swap(node1->left,node1->right);
    }
    node1->dist=node1->right->dist+1;
    return node1;
  }

  void leftist_heap::Merge(leftist_heap &rhs) {
    if (this == &rhs)
      return;
    root = Merge(root, rhs.root);
    rhs.root = nullptr;
  }

  void leftist_heap::insert(int val) {
    root=Merge(new LeftistNode(val),root);
  }

  leftist_heap::~leftist_heap() {
    makeEmpty();
  }

  int leftist_heap::findMin() {
    return root->val;
  }

  void leftist_heap::makeEmpty() {
    if (!root) return;
    std::stack<LeftistNode*> st;
    st.push(root);
    // Rupe legăturile ca să nu mai fie recursivitate în destructor
    root = nullptr;
    while (!st.empty()) {
      LeftistNode* cur = st.top(); st.pop();
      if (cur->left)  st.push(cur->left);
      if (cur->right) st.push(cur->right);
      // Dezactivează destructorul recursiv
      cur->left = cur->right = nullptr;
      delete cur;
    }
  }

  leftist_heap::leftist_heap(leftist_heap &rhs) {
    root = nullptr;
    *this = rhs;
  }

  leftist_heap & leftist_heap::operator=(const leftist_heap &rhs) {
    if (this != &rhs)
    {
      makeEmpty();
      root = rhs.root->clone();
    }
    return *this;
  }

  bool leftist_heap::isEmpty() {
    return root == nullptr;
  }

  void leftist_heap::deleteMin() {
    LeftistNode *oldRoot = root;
    root = Merge(root->left, root->right);
    oldRoot->left = nullptr;
    oldRoot->right = nullptr;
    delete oldRoot;
  }

  leftist_heap & leftist_heap::operator=(leftist_heap &rhs) {
    if (this != &rhs)
    {
      makeEmpty();
      if (!rhs.isEmpty()) {
        root = rhs.root->clone();
      }
    }
    return *this;
  }
}
