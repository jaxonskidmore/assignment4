#ifndef GENQUEUE_H
#define GENQUEUE_H

#include <iostream>

template <class X>
class GenQueue
{
  public:
      GenQueue(); //default constructor
      GenQueue(int maxSize); //overload constructor
      ~GenQueue();

      //core funtions
      void insert(X d); //enqueue
      X remove(); //deqeue

      //aux func
      X peek();
      bool isFull();
      bool isEmpty();
      int getSize();

      void expand(); //expands queue if it gets full


      //vars
      int front; //aka head
      int rear; //aka tail
      int mSize;
      int numElements;

      X *myQueue; //array
      X *tempQueue;

};


template <class X>
GenQueue<X>::GenQueue(){
  //defualt constructor
  myQueue = new X[128];
  mSize = 128;
  front = 0;
  rear = -1;
  numElements = 0;
}

//overload constructor
template <class X>
GenQueue<X>::GenQueue(int maxSize){
  myQueue = new X[maxSize];
  mSize = maxSize;
  front = 0;
  rear = -1;
  numElements = 0;
}

template <class X>
GenQueue<X>::~GenQueue(){
  delete myQueue;
}

template <class X>
void GenQueue<X>::insert(X d){
  if(isFull() == true){   //check if full before attempting to push /insert
    expand(); //expands queue by 10
  }
  myQueue[++rear] = d;
  ++numElements;
}

template <class X>
X GenQueue<X>::remove(){
  //error checking
  cout<<"removed " << myQueue[front] << endl;
  X c = '\0';
  c = myQueue[front];
  ++front;
  --numElements;
  return c;
}

template <class X>
X GenQueue<X>::peek(){
  return myQueue[front];
}

template <class X>
bool GenQueue<X>::isFull(){
  return (numElements == mSize);
}
template <class X>
bool GenQueue<X>::isEmpty(){
  return (numElements == 0);
}
template <class X>
int GenQueue<X>::getSize(){
  return numElements;
}

template <class X>
void GenQueue<X>::expand(){ //expands stack by 10 slots, uses temporary array
  tempQueue = new X[mSize + 10];
  for (int i = 0; i < mSize; ++i){
    tempQueue[i] = myQueue[i];
  }
  mSize += 10;
  myQueue = tempQueue;
  delete[] tempQueue;
}
#endif
