// /*Michael Kulinich
// 2328386
// kulinich@chapman.edu
// Matthew Nwerem
// 2277158
// nwere100@mail.chapman.edu

#include "Person.h"

  Person::Person()
  {
    name = " ";
    IDnumber = 0;
    levelField = " ";
  }

  Person::Person(string personName, int idNum , string levelF)
  {
    name = personName;
    IDnumber = idNum;
    levelField = levelF;
  }

  Person::~Person()
  {

  }
  string Person::getName()
  {
    return name;
  }

  int Person::getID()
  {
    return IDnumber;
  }

  string Person::getLevelField()
  {
    return levelField;
  }
