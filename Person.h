#include <iostream>

using namespace std;
class Person
{
  public:
    Person(string name, int idNum , string levelF);
    ~Person();
    string getName();
    int getID();
    string getLevelField();
    string getInfo();


  private:
    string name;
    int IDnumber;
    string levelField;
};
