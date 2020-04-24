#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include "Student.h"

using namespace std;

class Window{
  public:
    Window();
    Window(bool isOpen, Student* currStudent1);
    ~Window();

    void StudentToWindow(Student* currStudent1);
    void StudentDone();


    bool isOpen;
    Student *currStudent;
};
#endif
