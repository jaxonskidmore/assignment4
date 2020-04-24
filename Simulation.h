#include <iostream>
#include <fstream> //file streams
#include "Window.h"
#include "Student.h"
#include "GenQueue.h"
#include "DoublyLinkedList.h"

using namespace std;

class Simulation{
  public:

    Simulation(); //creates simulation object where program will take place

    void fileRead(string fileName);

    void fileOut();

    void runSim();

    void studentToWindow();

    void countTime();

    void isIdle();  // calculated mean idle time
    void printStats(); //prints out all stats at end
    void studentInLine(); //calculate mean wait time


    int numStudents = 0;

    int windowCount = 0;
    int studentCount = 0;
    int openWindows = 0;

    void makeWindows(int windowCount);
    void makeStudent(int arrivalTime1, int timeNeeded1, bool inLine1);


    GenQueue<int> fileInput;
    GenQueue<Student*> studentQueue;    //Student Queue
    DoublyLinkedList<Window*> windowList;


    Window* newWindow;
    Student* newStudent;

    Student* tempStudent;

    int windowSize;

    float meanStudentWait = 0;
    float medianStudentWait = 0;
    float longestStudentWait = 0;

    int numStudentWaitOver10 = 0;
    int numWindowIdleOver5 = 0;

    double meanWindowIdleTime = 0;
    int longestWindowIdleTime = 0;


};
