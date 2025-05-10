#include "../include/heap.h"

#include <stdexcept>

heap::heap() {
  //to be easy to work with it
  elements.push_back(-1);
}

void heap::heapify(int n, int i) {
  int smallest = i;
  int left = 2 * i;
  int right = 2 * i + 1;

  if (left <= n && elements[left] > elements[smallest])
    smallest = left;

  if (right <= n && elements[right] > elements[smallest])
    smallest = right;

  if (smallest != i) {
    std::swap(elements[i], elements[smallest]);
    heapify( n, smallest);
  }
}

void heap::buildHeap() {
  int n = elements.size() - 1; // because index 0 is unused
  for (int i = n / 2; i >= 1; --i) {
    heapify(n, i);
  }
}

void heap::Merge(heap &rhs) {
  for (int i=1;i<=rhs.elements.size()-1;i++) {
    elements.push_back(rhs.elements[i]);
  }
  buildHeap();
}

void heap::insert(int val) {
  elements.push_back(val);
  int index=elements.size()-1;
  while (index!=1&&elements[index]>elements[index/2]) {
    std::swap(elements[index], elements[index/2]);
    index/=2;
  }
}

int heap::findMin() {
  if (isEmpty())
    throw std::out_of_range("Heap is empty");
  return elements[1];
}

void heap::makeEmpty() {
  elements.clear();
  elements.push_back(-1);
}

heap::heap(const heap &other) {
  this->elements=other.elements;
}

bool heap::isEmpty() {
  if (elements.size() == 1)
    return true;
  return false;
}

void heap::deleteMin() {
  if (isEmpty())
    throw std::out_of_range("Heap is empty");

  std::swap(elements[1], elements[elements.size()-1]);
  elements.pop_back();
  heapify( elements.size()-1,1);
}
