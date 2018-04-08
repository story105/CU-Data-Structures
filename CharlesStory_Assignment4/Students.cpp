//Cpp file of Students that just declares this. Will be inherited so that can be
//Used in later CPP
#include <iostream>
#include "Student.h"

using namespace std;

Students::Students() {
    windowTime = 0;
    entryTime = 0;
    queueTime = 0;
    idleTime = 0;
}

Students::Students(int w, int e) {
    windowTime = w;
    entryTime = e;
    queueTime = 0;
    idleTime = 0;
}

Students::~Students()
{

}
