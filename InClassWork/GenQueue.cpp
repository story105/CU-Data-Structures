#include <iostream>
#include "GenQueue.h"

using namespace std;

GenQueue::GenQueue(){
  //up to us
}

GenQueue::GenQueue(int maxSize){ //overloaded and default diff?
  myQueue = new char [maxSize]; //need data type =char
  size = maxSize;
  front = 0;
  rear = -1;

  numElements = 0;
} //sets it up as zero

GenQueue::~GenQueue(){
 //what does he mean figure out?
 delete [] myQueue;
}

void GenQueue::insert(char data){
  //error handling
  if (rear == size -1){ //circular Queue!
    rear = -1;
  }
  myQueue[++rear] = data; //because it started at -1
  numElements++;
}

char GenQueue::remove(){
  //check if it's empty
  if (front == size){
    front = 0;
  }

  char c = '\0'; //null character (declaring so he can store it)
  c = myQueue[front]; //evaluate and increment AFTER post
  ++front;

  --numElements;

}

char GenQueue::peep(){
  return myQueue[front];
}

bool GenQueue::isFull(){
  return (numElements == size); //THIS == IS NECESSARY
}

bool GenQueue::isEmpty(){
  return (numElements == 0);
}

int GenQueue::getSize(){
  return numElements; //go home lets do this as a main
}
