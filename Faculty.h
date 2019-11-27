#ifndef FACULTY_H
#define FACULTY_H


#include "Person.h"
#include "DoublyLinkedList.h"

using namespace std;
// Student publicly inherits from Person
class Faculty: public Person
{
  public:
    Faculty();
    Faculty(string facName, int idNum , string levelF, string depart);
    ~Faculty();

    void addStudent(int studID);
    // void removeStudent()
    string getDepartment();
    void getStudentIDs();
    void getInfo();
    void removeFacultyAdvisee(int studID);


  private:
    string department;
    DoublyLinkedList<int> *studentIDs;

};


#endif
