// /*Michael Kulinich
// 2328386
// kulinich@chapman.edu
// Matthew Nwerem
// 2277158
// nwere100@mail.chapman.edu

#include "Faculty.h"

Faculty::Faculty()
{
  name = " ";
  IDnumber = 0;
  levelField = " ";
  department = " ";
  studentIDs = new DoublyLinkedList<int>();
}
Faculty::Faculty(string facName, int idNum , string levelF, string depart) //fix with inheritance
{
  name = facName;
  IDnumber = idNum;
  levelField = levelF;
  department = depart;
  studentIDs = new DoublyLinkedList<int>();
}

Faculty::~Faculty()
{

}

void Faculty::addStudent(int studID)
{
  studentIDs->insertFront(studID);
}

string Faculty::getDepartment()
{
  return department;
}

void Faculty::getStudentIDs()
{
  studentIDs->printList();
}

void Faculty::getInfo()
{
  cout << "--Faculty Information--" << endl;
  cout << "Name: " << getName() << endl;
  cout << "ID Number: " << getID() << endl;
  cout << "Level: " << getLevelField() << endl;
  cout << "Department: " << getDepartment() << endl;
  cout << "Students Advising: "; getStudentIDs();
}

void Faculty::removeFacultyAdvisee(int studID)
{
    studentIDs->remove(studID);
}
