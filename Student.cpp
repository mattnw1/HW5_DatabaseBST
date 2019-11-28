#include "Student.h"

// /*Michael Kulinich
// 2328386
// kulinich@chapman.edu
// Matthew Nwerem
// 2277158
// nwere100@mail.chapman.edu

Student::Student()
{
  name = " ";
  IDnumber = 0;
  levelField = " ";
  major = " ";
  gpa = 0.0;
  advisorID = 0;
}
Student::Student(string studname, int idNum , string levelF, string maj, double gradepoint, int advisor) //fx with inheritance
{
  name = studname;
  IDnumber = idNum;
  levelField = levelF;
  major = maj;
  gpa = gradepoint;
  advisorID = advisor;
}
Student::~Student()
{

}

string Student::getMajor()
{
  return major;
}

double Student::getGPA()
{
  return gpa;
}
int Student::getAdvisorID()
{
  return advisorID;
}

void Student::setAdvisor(int facID){
    advisorID = facID;
}


void Student::getInfo()
{
  cout << "--Student Information--" << endl;
  cout << "Name: " << getName() << endl;
  cout << "ID Number: " << getID() << endl;
  cout << "Level: " << getLevelField() << endl;
  cout << "Major: " << getMajor() << endl;
  cout << "GPA: " << getGPA() << endl;
  cout << "Advisor ID: " << getAdvisorID() << endl;
}
