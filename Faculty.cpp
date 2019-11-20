#include "Faculty.h"

Faculty::Faculty()
{
  name = " ";
  IDnumber = 0;
  levelField = " ";
  department = " ";
  DoublyLinkedList<int> *studentIDs;
}
Faculty::Faculty(string facName, int idNum , string levelF, string depart)
{
  name = facName;
  IDnumber = idNum;
  levelField = levelF;
  department = depart;
  DoublyLinkedList<int> *studentIDs;
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
