#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"

// /*Michael Kulinich
// 2328386
// kulinich@chapman.edu
// Matthew Nwerem
// 2277158
// nwere100@mail.chapman.edu

using namespace std;
// Student publicly inherits from Person
class Student: public Person
{
  public:
    Student();
    Student(string studname, int idNum , string levelF, string major, double gradepoint, int advisor);
    ~Student();
    string getMajor();
    double getGPA();
    int getAdvisorID();
    void getInfo();
    void setAdvisor(int facID);


  private:
    string major;
    double gpa;
    int advisorID;

};

#endif
