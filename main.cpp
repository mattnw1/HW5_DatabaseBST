#include "BST.h"

using namespace std;

int main(int argc, char const *argv[])
 {

  BST<int> *tree = new BST<int>();
  // BST *tree2;

   tree->insert(5);
   tree->insert(55);
   tree->printTree();
   cout << "is the tree empty: " << tree->isEmpty() << endl;
   tree->deleteNode(55);
   tree->deleteNode(5);
   cout << "is the tree empty: " << tree->isEmpty() << endl;
   tree->printTree();

  return 0;
}
