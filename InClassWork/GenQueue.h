#include <iostream>

using namespace std;

class GenQueue{

  public:
  GenQueue();
  GenQueue(int maxSize);
  ~GenQueue();

  void insert(char data);
  char remove();
  char peep(); //based on data

  bool isFull();
  bool isEmpty();
  int getSize();

  int size;
  int front;
  int rear;
  int numElements;

  char *myQueue;
};
