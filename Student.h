#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student{
  public:
    Student();
    Student(int arrivalTime1, int timeNeeded1, bool inLine1);
    ~Student();

    void sumOfTime();

    int arrivalTime;
    int timeNeeded; //time needed at window
    int totalTime;  // total time in simulation -- calculate at end, add up time needed + waittime
    int waitTime;   //total time - time needed ----starts at 0
    bool inLine;


};
#endif
