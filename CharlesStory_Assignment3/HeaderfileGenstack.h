//Charles Story Assignment 3 Headerfile

#include <iostream>
#include <stack>
#include <string>
//TEMPLATE ARRAY BASED STACK .h SHOULD ALL BE IN ONE FILE
using namespace std;
template <class G>
class GenStack
{
private:

  public:
    GenStack(int maxSize);
    ~GenStack();

    // bool isPaired(G a, G b);

    void push(G data);
    G pop(); //return type is char
    G peek();

    int isFull(); //int?
    int isEmpty();

    int size;
    int top;

    G *myArray; //If you know starting point of pointer, all indexes after eachother
    G *tempArray; //Not sure yet if I need a tempArray
};

//Constructor below
template <class G>
GenStack<G>::GenStack(int maxSize){
  myArray = new G[maxSize];
  size = maxSize;
  top = -1;
  tempArray = new G[size]; //max basically
}
template <class G>
GenStack<G>::~GenStack(){
  delete []myArray;
  delete []tempArray;
  cout << "Stack destroyed. Good job team, get ready for the next one." << endl;
}

template <class G>
void GenStack<G>::push(G data){
  if (isFull() == true){
    //Add to this array to allocate memory?
    push(data); //does this loop forever
  } //Or 1
  else{
  myArray[++top] = data;
  }
}

template <class G>
G GenStack<G>::peek(){
  if (top == -1){
    return 0;
  }
  else {
    return myArray[top];
  }
}

template <class G>
G GenStack<G>::pop(){
  if (isEmpty() == true) { //is true...
    cout << "Current stack is empty" << endl;
    return false;
  }
  else{
  return myArray[top--]; //cuts out the top after returning its value
  }
}

template <class G>
int GenStack<G>::isFull(){
  return (top == size-1);
}

template <class G>
int GenStack<G>::isEmpty(){
  return (top == -1); //top is still negative
}

/*
template <class G> //Se if this works in Main
bool GenStack<G>::isPaired(char first, char second){
  if (first == '(' && second == ')'){
    return true;
  }
  else if (first == '{' && second == '}'){
    return true;
  }
  else if (first == '[' && second == ']'){
    return true;
  }
  else {
    return false;
  }
}
*/
