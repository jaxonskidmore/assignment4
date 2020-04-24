#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(){
  timeNeeded = 0;
  waitTime = 0;
  inLine = true;
}

Student::Student(int arrivalTime1, int timeNeeded1, bool inLine1){
  arrivalTime = arrivalTime1;
  timeNeeded = timeNeeded1;
  waitTime = 0;
  inLine = inLine1;
}

Student::~Student(){
  //delete Student;
}


void Student::sumOfTime(){
  totalTime = timeNeeded + waitTime;
}
