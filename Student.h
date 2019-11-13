#include "Person.h"

using namespace std;
// Student publicly inherits from Person
class Student: public Person
{
  public:
    Student();
    Student(string name, int idNum , string levelF, string major, double gradepoint, int advisor);
    ~Student();
    string getMajor();
    double getGPA();
    int getAdvisorID();
    void getInfo();


  private:
    string major;
    double gpa;
    int advisorID;

};
