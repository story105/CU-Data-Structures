#include <iostream>
#include "GenQueue.h"

using namespace std;

int main(int argc, char** argv){

  GenQueue myQueue(13);

  myQueue.insert('F');
  myQueue.insert('u');
  myQueue.insert('c');
  myQueue.insert('k');
  myQueue.insert(' ');
  myQueue.insert('m');
  myQueue.insert('y');
  myQueue.insert(' ');
  myQueue.insert('l');
  myQueue.insert('i');
  myQueue.insert('f');
  myQueue.insert('e');

  while (!myQueue.isEmpty()){
    for (int z = 0; z <= myQueue.getSize();z++){
      cout << myQueue.peep() << endl;
      myQueue.remove();
    }
  }
  cout << "finished!" << endl;
  return 0;

}
