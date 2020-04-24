#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
#include <stdexcept>
#include "ListNode.h"

using namespace std;

template <class X>
class DoublyLinkedList
{
/*private:
  ListNode<X> *front;  //sentinel node for beginning of list
  ListNode<X> *back;   //sentinel node for end of list
  unsigned int size; */
public:
  ListNode<X> *front;  //sentinel node for beginning of list
  ListNode<X> *back;   //sentinel node for end of list
  unsigned int size;

  DoublyLinkedList();
  ~DoublyLinkedList();
  void insertFront(X Data);
  void insertBack(X data);
  X removeFront();
  X removeBack();
  int getSize();
  bool empty();
  X remove(X key);

};
class ListEmpty : public runtime_error {
public:
  ListEmpty(const string& err) : runtime_error(err) {};
};
class KeyNotFound : public runtime_error {
public:
  KeyNotFound(const string& err) : runtime_error(err) {};
};

template <class X>
DoublyLinkedList<X>::DoublyLinkedList() {
  size = 0;
  front = new ListNode<X>();
  back = new ListNode<X>();
  front->next = back;
  back->prev = front;
}

template <class X>
DoublyLinkedList<X>::~DoublyLinkedList() {
  while(!empty()) {removeFront();}
  front = NULL;
  back = NULL;
}

template <class X>
bool DoublyLinkedList<X>::empty() {
  return size == 0;
}
template <class X>
int DoublyLinkedList<X>::getSize() {
  return size;
}
template <class X>
void DoublyLinkedList<X>::insertFront(X data) {
  ListNode<X>* node = new ListNode<X>(data);
  front->next->prev = node;
  node->next = front->next;
  node->prev = front;
  front->next = node;
  size++;
}

template <class X>
void DoublyLinkedList<X>::insertBack(X data) {
  ListNode<X>* node = new ListNode<X>(data);
  back->prev->next = node;
  node->prev = back->prev;
  node->next = back;
  back->prev = node;
  size++;
}

template <class X>
X DoublyLinkedList<X>::removeFront() {
  ListNode<X>* node = front->next;
  //check if empty
  if (front->next == back) {
    throw ListEmpty("removeFront from empty list!");
  }
  node->next->prev = node->prev;
  node->prev->next = node->next;
  node->next = NULL;
  node->prev = NULL;
  X temp = node -> data;
  delete node;
  size--;
  return temp;
}

template <class X>
X DoublyLinkedList<X>::removeBack() {
  ListNode<X>* node = back->prev;
  //check if empty
  if (back->prev == front) {
    throw ListEmpty("removeBack from empty list!");
  }
  node->prev->next = back;
  back->prev = node->prev;
  X temp = node->data;
  node->prev = NULL;
  node->next = NULL;
  delete node;
  size--;
  return temp;
}

template <class X>
X DoublyLinkedList<X>::remove(X key) { //search for data and remove it
  ListNode<X>* curr = front;
  while(curr->data != key) {
    curr = curr->next;
    if(curr == NULL) {  //key not found
      throw KeyNotFound("Key not Found!");
    }
  }
  curr->next->prev = curr->prev;
  curr->prev->next = curr->next;
  X temp = curr->data;
  curr->next = NULL;
  curr->prev = NULL;
  delete curr;
  size--;

  return temp;
}
#endif
