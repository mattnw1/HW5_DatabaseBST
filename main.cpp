#include "BST.h"
#include "PersonBST.h"
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

   Student *student1 = new Student("John Appleseed", 1738, "Senior", "Chemical Engineering", 3.455, 1111);
   cout << "-----------------------------------------------------------" << endl;
   student1->getInfo();
   cout << "Above is a test of Student Class Methods" << endl;
   cout << "-----------------------------------------------------------" << endl;


   PersonBST<Student> *StudentTree = new PersonBST<Student>();
   StudentTree->insert(55, student1);
   cout << "Print Student Tree" << endl;
   StudentTree->printTree();

   Faculty *faculty1 = new Faculty("Steve Jobs", 2000, "President", "Fowler School of Engineering");
   PersonBST<Faculty> *FacultyTree = new PersonBST<Faculty>();
   FacultyTree->insert(10, faculty1);
   cout << "Print Faculty Tree" << endl;
   FacultyTree->printTree();







  return 0;
}
