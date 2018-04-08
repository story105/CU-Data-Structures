#include <iostream>
#include <string>
#include "Student.h"
#include "GenQueue.h"

using namespace std;

class Simulation {
    private:
        int type; //Imported File Line Type (Student/Time/Clock)
        int entryTime;
        int timeAtWindow;
        int numSect; //Number of Students at each tick
        int MedianAvgCnt; //Median of element count (array)
        int idleTiming; //Idle timing array count

    public:
        Simulation();
        ~Simulation();

        bool importFile(string file); //for a read file

        //Keep Track of Global Time
        bool timeTracker(int time);
        double meanTime(); //Operation for student
        double medianTime();
        int longestTime();
        int overTenTime();

        double meanIdleTime(); //operations for registrat
        int longestIdleTime();
        int idleOverFiveTime();

        //will initialize array of students atwindow
        Students **windowArray;
        GenQueue <Students*> studentQueue;    //Student Queue

        GenQueue <int> waitStats;
        GenQueue <int> idleStats;

        int *medianArrary;
        int *idleArray;

        int totalWindows;
        int totalStudents;
};
