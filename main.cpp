#include "BST.h"
#include "Student.h"

using namespace std;

int main(int argc, char const *argv[])
 {

  BST<int> *tree = new BST<int>();

   tree->insert(5);
   tree->insert(55);
   tree->insert(51);
   tree->printTree();
   cout << "Is the tree empty?: " << tree->isEmpty() << endl;
   tree->deleteNode(55);
   tree->deleteNode(5);
   cout << "Is the tree empty?: " << tree->isEmpty() << endl;
   tree->deleteNode(51);
   cout << "Is the tree empty?: " << tree->isEmpty() << endl;
   tree->printTree();

   Person *test1 = new Person("Matt", 12, "Frosh");
   cout << "testName" << test1->getName() << endl;
   cout << "testID" << test1->getID() << endl;
   cout << "testLevel" << test1->getLevelField() << endl;

   Student *student1 = new Student("John Appleseed", 1738, "Senior", "Chemical Engineering", 3.455, 1111);
   cout << "-----------------------------------------------------------" << endl;
   student1->getInfo();

  return 0;
}
