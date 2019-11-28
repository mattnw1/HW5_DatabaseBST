
#include "PersonBST.h"
#include "Student.h"
#include "Faculty.h"
#include "Person.h"
#include "Simulation.h"




using namespace std;

int main(int argc, char const *argv[])
 {
  // BST<int> *tree = new BST<int>();
  //
  //  tree->insert(5);
  //  tree->insert(55);
  //  tree->insert(51);
  //  tree->printTree();
  //  cout << "Is the tree empty?: " << tree->isEmpty() << endl;
  //  tree->deleteNode(55);
  //  tree->deleteNode(5);
  //  cout << "Is the tree empty?: " << tree->isEmpty() << endl;
  //  tree->deleteNode(51);
  //  cout << "Is the tree empty?: " << tree->isEmpty() << endl;
  //  tree->printTree();
  //
  //  Person *test1 = new Person("Matt", 12, "Frosh");
  //  cout << "testName" << test1->getName() << endl;
  //  cout << "testID" << test1->getID() << endl;
  //  cout << "testLevel" << test1->getLevelField() << endl;

   // Student *student1 = new Student("John Appleseed", 1738, "Senior", "Chemical Engineering", 3.455, 1111);
   // cout << "-----------------------------------------------------------" << endl;
   // student1->getInfo();
   // cout << "Above is a test of Student Class Methods" << endl;
   // cout << "-----------------------------------------------------------" << endl;
   //
   //
   // PersonBST<Student> *StudentTree = new PersonBST<Student>();
   // StudentTree->insert(student1->getID(), student1);
   // cout << "Print Student Tree" << endl;
   // StudentTree->printTree();
   //
   // cout << "-----------------------------------------------------------" << endl;
   // Faculty *faculty1 = new Faculty("Steve Jobs", 2000, "President", "Fowler School of Engineering");
   // PersonBST<Faculty> *FacultyTree = new PersonBST<Faculty>();
   // FacultyTree->insert(10, faculty1);
   // faculty1->addStudent(1111);
   // faculty1->addStudent(1212);
   // cout << "Print Faculty Tree" << endl;
   // FacultyTree->printTree();
   Student *student1 = new Student("John Appleseed", 1738, "Senior", "Chemical Engineering", 3.455, 2000);
   PersonBST<Student> *students = new PersonBST<Student>();
   students->insert(student1->getID(), student1);

   Faculty *faculty1 = new Faculty("Steve Jobs", 2000, "President", "Fowler School of Engineering");
   faculty1->addStudent(1738);
   PersonBST<Faculty> *facultys = new PersonBST<Faculty>();
   facultys->insert(faculty1->getID(), faculty1);










     Simulation mySim(students, facultys);
     mySim.run();



  return 0;
}
