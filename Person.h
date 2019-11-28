#ifndef PERSON_H
#define PERSON_H

// /*Michael Kulinich
// 2328386
// kulinich@chapman.edu
// Matthew Nwerem
// 2277158
// nwere100@mail.chapman.edu

#include <iostream>

using namespace std;
class Person
{
  public:
    Person();
    Person(string name, int idNum , string levelF);
    ~Person();
    string getName();
    int getID();
    string getLevelField();
    string getInfo();


  protected:
    string name;
    int IDnumber;
    string levelField;
};

#endif
