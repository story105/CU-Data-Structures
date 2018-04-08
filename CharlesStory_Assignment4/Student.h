#include <iostream>
//Simply students header class for all necessary counters we need
using namespace std;

class Students {
    private:

    public:
        Students();
        Students(int w, int e); //Window and ntry
        ~Students();

        int windowTime;
        int entryTime;
        int queueTime;
        int idleTime;
};
