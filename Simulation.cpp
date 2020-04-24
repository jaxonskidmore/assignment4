#include <iostream>
#include "Simulation.h"
#include "Student.h"
#include "Window.h"
using namespace std;


Simulation::Simulation(){   //initialize these based on file input

}

void Simulation::fileRead(string fileName){
  ifstream fin; //creation of ifstream class object
  string line = "";
  fin.open(fileName);
    while (fin) {     //reads in input from text file given from user
      getline(fin, line);
      for(int i = 0; i < line.length(); ++i){
        if(line.length() == 1){
          char a = line[i];  //changes the file input from char to integers
          int ia = a - '0';
          fileInput.insert(ia);
        }
        if(line.length() > 1){
          int test = stoi(line);
          fileInput.insert(test);
          break;
        }
      }
    }
}
void Simulation::fileOut(){   //not used just for testing
  cout << "purgin queue" << endl;
  while(!fileInput.isEmpty()){
    cout << "remove " << fileInput.remove() << endl;
  }
}

void Simulation::makeWindows(int windowCount){    //makes # of windows, this is used in runSim()
  for(int i = 0; i < windowCount; ++i){
      newWindow = new Window();
    //  windowList.insertFront(newWindow);
      ++openWindows;
  }
}

void Simulation::runSim(){ //fills window list and student queue based on input
  int count = 0;
  while(!fileInput.isEmpty()){
    if(count == 0){
      makeWindows(fileInput.peek());
      fileInput.remove();
      ++count;
    }
    if(count == 1){
      int timeArrival = 0;
      int timeNeeded = 0;
      timeArrival = fileInput.peek();
      fileInput.remove();
      numStudents = fileInput.peek();
      fileInput.remove();
      for(int i = 0; i < numStudents; ++i){
        timeNeeded = fileInput.peek();
        fileInput.remove();
        newStudent = new Student(timeArrival, timeNeeded, true);
        studentQueue.insert(newStudent);
        }
      continue;
      }
      break;
  }
}

void Simulation::studentToWindow(){     //students go to open window and are removed from studentQueue
  while(!studentQueue.isEmpty()){     //need to figure out clock here and how to finish after windows are first filled
    for(int i = 0; i < openWindows; ++i){
      if (newWindow[i].isOpen){
        Student *tempStudent = studentQueue.peek();
        newWindow[i].currStudent = tempStudent;
        newWindow[i].isOpen = false;
        studentQueue.remove();

      }
      else{
        studentInLine();
      }

    } /*
    for(int i = 0; i < openWindows; ++i){
      if(newWindow[i].isOpen == false){
        int addToSum = newWindow[i].currStudent->timeNeeded - newWindow[i].currStudent->arrivalTime;
        newWindow[i].currStudent = NULL;
        newWindow[i].isOpen = true;
      }
    } */
  }
}

void Simulation::isIdle(){      //i think we might be looking at the time thing the wrong way but idk
  for(int i = 0; i < windowCount; ++i){
    if(newWindow[i].isOpen)
      ++meanWindowIdleTime;
  }
}
/*
void Simulation::countTime(){ //method to increment the time
  for(int i = 0; i < windowCount; ++i){
  }
  timeNeeded++;
    if(newWindow[i]->studentToWindow(){
      Student* studentToWindow = newWindow[i]->StudentDone();
    }
}
*/

void Simulation::studentInLine(){
  int studentsWaiting = studentQueue.getSize();
  ++meanStudentWait;
}

void Simulation::printStats(){
  //cout << "mean idle window time " << meanWindow

  //windowCount << endl;
  cout << "mean student wait time " << meanStudentWait/numStudents << endl; //calc mean
}

/*
int Simulation::longestWindowIdleTime(){ //method to calc longest window idle time
  int max = 0;
  for(int i = 0; i < windowSize; ++i) {
    if(idle[i] > max);
    idle[i] = max;
  }
  cout << "The longest window idle time: " << max << endl;

}
int Simulation::longestStudentWait(){ //method to calc longest student wait
  int studentWait = 0;
  for(int i = 0; i < student; ++i) {
    if(student[i] > max);
    student[i] = max;
  }
  cout << "The longest student wait time: " << max << endl;

}

int Simulation::numStudentWaitOver10(){ //method to calc numStudentWaitOver10
  int waitOver10 = 0;
  for(int i = 0; i < student; ++i) {
    if(student[i] > 10;
    waitOver10++;
  }
  cout << "The number of student wait over 10 is: " << waitOver10 << endl;

}

int Simulation::numWindowIdleOver5(){ //method to calc longest window idle time
  int idleOver5 = 0;
  for(int i = 0; i < windowSize; ++i) {
    if(idle[i] > max);
    idleOver5++;;
  }
  cout << "The number of windows idles over 5 is: " << idleOver5 << endl;

}
int Simulation::medianStudentWait(){
}
*/
