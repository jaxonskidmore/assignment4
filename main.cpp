#include "DoublyLinkedList.h"
#include "GenQueue.h"
#include "Student.h"
#include "Window.h"
#include "Simulation.h"


using namespace std;


int main(int argc, char** argv) { /*
  DoublyLinkedList<int> a;
  int n = 10;
  for (int i = 0; i < 10; ++i) {
    a.insertFront(n+1);
    n *= 2;
    a.insertBack(n);
  }
  cout<< a.remove(1280)<<endl;
  for (int i = 0; i < 9; ++i) {
    cout << a.removeBack() << endl;
    cout << a.removeFront() << endl;
  }


  GenQueue<char> *q = new GenQueue<char>(10);

  q->insert('r');
  q->insert('e');
  q->insert('n');
  q->insert('e');

  cout << "peek :" << q->peek() << endl;
  cout << "remove :" << q->remove() << endl;
  cout<< "inserting P,D,P into queue" << endl;

  q->insert('P');
  q->insert('D');
  q->insert('P');

  cout << "purgin queue" << endl;
  while(!q->isEmpty()){
    cout << "remove " << q->remove() << endl;
  }

  Student *connor = new Student(15, false);


  Window window1;
  cout << window1.isOpen <<endl;

  window1.StudentToWindow(connor);

  cout << window1.isOpen <<endl;

  window1.StudentDone();

  cout << window1.isOpen <<endl;
*/
 string fileName = argv[1];                   //this bit of code takes file input and puts it into a queue
 Simulation sim;
 sim.fileRead(fileName);
 //sim.fileOut();

 sim.runSim();
 sim.studentToWindow();
cout<< "file input size " << sim.fileInput.getSize() << endl;
 cout << "fileinput peek " << sim.fileInput.peek()<<endl;
 cout << "window size " << sim.windowList.getSize() << endl;
 cout << "student queue size " << sim.studentQueue.getSize()<< endl;
 sim.printStats();
 return 0;
}
