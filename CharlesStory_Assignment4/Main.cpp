/*Charlie Story and Alex Alvertos
Assignment 4 Registrar
4/4/2018
*/
#include <iostream>
#include <string>
#include "assignment4.h" //I RENAMED THISFILE ! AND THE INCLUDE AUTOMATICALLY UPDATED

using namespace std;

int main(int argc, char** argv) {
    Simulation s; //sets up an instance

    //error catch
    if(argc < 2) {
        cout << "ERROR: enter a valid file input\n" << endl;
    }

    //else
    else if(argc >= 2) {
        string file = argv[1];

        int currTime = 0;
        int openWindows = 0;

        bool running = true;

        //Run file import is valid
        if(s.importFile(file)) {
            while(running) {
                if(s.studentQueue.isEmpty()) {  //It's odd, studentQueue is highlighted red...
                    int temp = 0;

                    for(int i = 0; i < s.totalWindows; ++i) {
                        if((s.windowArray[i]->windowTime) < 1) {
                            temp++;
                        }
                    }
                    if(temp == s.totalWindows) {
                        running = false;
                    }
                }
                // Moves Students to Window if can after checking all windows
                for(int i = 0; i < s.totalWindows; ++i) {
                    if(s.windowArray[i]->windowTime < 1) {
                        if(!s.studentQueue.isEmpty()) {
                            Students* student = s.studentQueue.vFront(); //Assigns new to front (same as back)

                            if(student->entryTime <= currTime) {
                                if(s.windowArray[i]->idleTime > 0) {
                                    s.idleStats.enqueue(s.windowArray[i]->idleTime);
                                }
                                //Move from Queue to Window Array (so much effort)
                                s.windowArray[i] = s.studentQueue.dequeue();
                                s.waitStats.enqueue(s.windowArray[i]->queueTime);
                            }
                        }
                    }
                }
                //Increment time Tracker (per "tick") in the Simulation
                currTime++;
                s.timeTracker(currTime);
            }
            //check for idle windows!
            for(int i = 0; i < s.totalWindows; ++i) {
                if(s.windowArray[i]->idleTime > 0) {
                    s.idleStats.enqueue(s.windowArray[i]->idleTime);
                }
            }
//at end...
            cout << "\nSTUDENT Calculations: " << endl;
            cout << "Mean student wait time: " << s.meanTime() << endl;
            cout << "Median student wait time: " << s.medianTime() << endl;
            cout << "Longest student wait time: " << s.longestTime() << endl;
            cout << "The number of students waiting over ten minutes: " << s.overTenTime() << endl;
            cout << "Mean window idle time: " << s.meanIdleTime() << endl;
            cout << "Longest window idle time: " << s.longestIdleTime() << endl;
            cout << "Number of windows idle for over five minutes: " << s.idleOverFiveTime() << "\n" << endl;
        }
    }
    return 0; //you know... Im not even really sure why we have return 0 at the end. Is this whole thing void?
    //Or does it like... keep the program from just running in the background by literally exiting.
}
