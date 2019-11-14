#include "Student.h"

Student::Student()
{
  name = " ";
  IDnumber = 0;
  levelField = " ";
  major = " ";
  gpa = 0.0;
  advisorID = 0;
}
Student::Student(string studname, int idNum , string levelF, string maj, double gradepoint, int advisor)
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