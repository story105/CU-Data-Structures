#include <iostream>
using namespace std;

class GenStack
{
  public:
    GenStack();
    GenStack(int maxSize);
    ~GenStack();

    void push(char d);
    char pop(); //return type is char
    char peek();

    bool isFull();
    bool isEmpty();

    int size;
    int top;

    char *myArray; //If you know starting point of pointer, all indexes after eachother
};
