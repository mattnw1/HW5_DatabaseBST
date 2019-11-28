
#include "PersonBST.h"
#include "Student.h"
#include "Faculty.h"
#include "Person.h"
#include "Simulation.h"




using namespace std;

int main(int argc, char const *argv[])
 {
   PersonBST<Student> *students = new PersonBST<Student>();
   PersonBST<Faculty> *facultys = new PersonBST<Faculty>();
   Simulation mySim(students, facultys);
     mySim.run();



  return 0;
}
