#include "GenStack.h"

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  GenStack myStack(10);

  myStack.push('C');
  myStack.push('h');
  myStack.push('a');
  myStack.push('r');
  myStack.push('l');
  myStack.push('e');
  myStack.push('s');

  cout << "Popping: " << myStack.pop() << endl;
  cout << "Peekaboo! " << myStack.peek() << endl;
  
  while (!myStack.isEmpty())
  {
    cout << "Popping it all: " << myStack.pop() << endl;
  }

    return 0;
}
