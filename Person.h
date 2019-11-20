#ifndef PERSON_H
#define PERSON_H

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
