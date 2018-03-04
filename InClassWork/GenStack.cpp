#include "GenStack.h"
#include <iostream>

using namespace std;

GenStack::GenStack() //initialize default constructor
{}

GenStack::GenStack(int maxSize) //overloaded constructor
{
  myArray = new char[maxSize]; //dynamic memory allocation, means delete at end.
  int size = maxSize;
  top = -1; //hmmmm could do 0
}

GenStack::~GenStack() //initialize default constructor
{
  delete [] myArray;  //delete the array, THEN the variable
  //delete myArray; should work too
  cout << "myArray is now spacedust" << endl;
}

void GenStack::push(char d) //name of ya class is prefixed the :: function
{
  //implement Error checking (if full, don't add) throw stackFullExeption
  myArray[++top] = d;

}

char GenStack::pop()
{
  //Check if it's empty
  return myArray[top--];
}

char GenStack::peek()
{
  if (isEmpty() == false){
    return myArray[top];
  }
  else {
    cout << "There's nothing to peek at" << endl;
  }
}

bool GenStack::isFull()
{
  return (size-1 == top);
}

bool GenStack::isEmpty()
{
  return (top == -1);
}
