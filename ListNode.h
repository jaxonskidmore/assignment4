#include <iostream>
#include <stdexcept>

using namespace std;

template <class X>
class ListNode {
public:
    ListNode();
    ListNode(X d);
    ~ListNode();
    X data;
    ListNode<X> *next;
    ListNode<X> *prev;
};
template <class X>
ListNode<X>::ListNode() {
  next = NULL;
  prev = NULL;
}
template <class X>
ListNode<X>::ListNode(X d) {
  data = d;
  next = NULL;
  prev = NULL;
}

//no delete in node destructor
template <class X>
ListNode<X>::~ListNode() {
  next = NULL;
  prev = NULL;
}
