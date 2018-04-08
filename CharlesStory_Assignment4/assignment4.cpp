#include <iostream>
#include <fstream>
#include <string>
#include <queue> //These exist and HELP SO MUCH
#include <algorithm>
#include <sstream>
#include "assignment4.h" //Eveen this changed when I renamed the file!

using namespace std;

Simulation::Simulation() {
    type = 1;
    entryTime = 0;
    timeAtWindow = 0;

    numSect = 0;
    MedianAvgCnt = 0;
    idleTiming = 0;

    totalWindows = 0;
    totalStudents = 0;
}

Simulation::~Simulation() {
    delete [] windowArray;
    delete [] idleArray;
    delete [] medianArrary;
}

bool Simulation::importFile(string file) {
    string line;
    int lineNum = 1;

    ifstream inputStream;
    inputStream.open(file.c_str());

    try {
        getline(inputStream, line);
        totalWindows = atoi(line.c_str());

        windowArray = new Students*[totalWindows];

        for (int i = 0; i < totalWindows; ++i) {
            Students* student = new Students();
            windowArray[i] = student;
        }

        lineNum++;
    }
    catch (exception e) { //Odd error
        cout << "error occurred" << endl;
        return false;
    }

    while (getline(inputStream, line)) { //if file open
        switch (type) {
            //Clock Ticks inscrease
            case(1): { //This was a v helpful suggestion (Ive never tried switch before)
                try {
                    entryTime = atoi(line.c_str());
                    type++;
                    lineNum++;
                }
                catch (exception e) {
                    cout << "error occurred" << endl;
                    return false;
                }
                break;
            }
            //Number of Students case
            case(2): {
                try {
                    if (line != "") {
                        numSect = atoi(line.c_str());

                        for (int i = 0; i < numSect; ++i) {
                            getline(inputStream, line);
                            lineNum++;

                            try {
                                timeAtWindow = atoi(line.c_str());
                            }
                            catch (exception e) {
                                cout << "error occurred" << endl;
                                return false;
                            }

                            totalStudents++;

                            Students* student = new Students(timeAtWindow, entryTime); //variables are passed in

                            studentQueue.enqueue(student);
                        }
                        type--;
                    }
                }
                catch(exception e) {
                    cout << "error occurred" << endl; //Could specify error but just copy paste works
                    return false;
                }

                break;
            }
            default:
                break;
        }
    }
    return true;
}

bool Simulation::timeTracker(int t) {
    for (int i = 0; i < totalWindows; ++i) {
        if (windowArray[i]->windowTime > 0) {
            //Decreases when Student at Window
            windowArray[i]->windowTime--;
        }
        else {
            //Increases when Student not at Window (idletime)
            windowArray[i]->idleTime++;
        }
    }

    if (!studentQueue.isEmpty()) {
        ListNode<Students*> *curr = studentQueue.front;

        while(curr != NULL) {
            if(curr->data->entryTime < t) {
                curr->data->queueTime += 1;
            }
            curr = curr->next;
        }
    }
    return true;
}

double Simulation::meanTime() {
    ListNode <int> *curr = waitStats.front;

    double mnWait = 0;
    double sum = 0;
    double counter = 0;

    while (curr != NULL) {
        sum += curr->data;
        curr = curr->next;
        counter++;
    }
    if (counter == 0) {
        return 0;
    }
    mnWait = sum / counter;
    return mnWait;
}

double Simulation::medianTime() {
    ListNode <int> *curr = waitStats.front;

    double medWait = 0;
    MedianAvgCnt = 0;

    while (curr != NULL) {
        curr = curr->next;
        MedianAvgCnt++;
    }

    if (MedianAvgCnt == 0) {
        return 0;
    }
    else {
        medianArrary = new int[MedianAvgCnt];
        curr = waitStats.front; //Iterate through the wait

        for(int i = 0; i < MedianAvgCnt; ++i) {
            medianArrary[i] = curr->data;
            curr = curr->next;
        }

        //Function from ALGORITHM Library - puts values into ASCENDING order
        sort(medianArrary, medianArrary + MedianAvgCnt);
        //For Odd Numbers
        if(MedianAvgCnt % 2 == 1) {
            double d = 0;
            int r = 0;

            r = (MedianAvgCnt/2) + 1;
            d = medianArrary[r];

            return d;
        }
        else {
            double d = 0;
            int a = 0;
            int z = 0;

            a = MedianAvgCnt/2;
            z = (MedianAvgCnt/2) + 1;

            if(medianArrary[z] == 0) {
                return 0;
            }

            d = double(medianArrary[a])/double(medianArrary[z]);

            return d;
        }
    }
}

int Simulation::longestTime() {
    if (MedianAvgCnt == 0) {
        return 0;
    }
    else {
        return medianArrary[MedianAvgCnt - 1];
    }
}

int Simulation::overTenTime() {
    if (MedianAvgCnt == 0) {
        return 0;
    }
    else {
        int temp = 0;

        for (int i = 0; i < MedianAvgCnt; ++i) {
            if (medianArrary[i] > 10) {
                ++temp;
            }
        }
        return temp;
    }
}

double Simulation::meanIdleTime() {
    ListNode <int> *curr = idleStats.front;

    double idleTime = 0;
    double sum = 0;
    double counter = 0;

    while (curr != NULL) {
        sum += curr->data;
        curr = curr->next;

        counter++;
    }

    if (counter == 0) {
        return 0;
    }

      idleTime = sum / counter;
    return idleTime;
}

int Simulation::longestIdleTime() {
    ListNode <int> *curr = idleStats.front;

    idleTiming = 0;

    while (curr != NULL) {
        curr = curr->next;
        idleTiming++;
    }

    idleArray = new int[idleTiming];

    curr = idleStats.front;

    for (int i = 0; i < idleTiming; ++i) {
        idleArray[i] = curr->data;
        curr = curr->next;
    }

    sort (idleArray, idleArray + idleTiming);

    return (idleArray[idleTiming - 1]);
}

int Simulation::idleOverFiveTime() {
    int temp = 0;

    for (int i = 0; i < idleTiming; ++i) {
        if (idleArray[i] > 5) {
            ++temp;
        }
    }

    return temp;
}
