#include "BST.h"

using namespace std;
// StudentBST publicly inherits from BST
template <class T>
class StudentBST: public BST
{
  void insert(T value);


};

template <class T>
void StudentBST<T>::insert(T value)
{
  TreeNode<T> *node = new TreeNode<T>(value);
  int studID = node.getID();

  if(root == NULL) //Then we have an empty Tree
  {
    root = studID; //Creating the beginning of a tree!!
  }

  else //time to find the correct insertion location (i.e. failed search)
  {
    TreeNode<T> *current = root;
    TreeNode<T> *parent = NULL;

    while(current != NULL)
    {
      parent  = current; //allows parent to be one above current the entire time in the Tree

      if(value < current->key) //Go down left side of remaining tree
      {
        current = current->left;

        if(current == NULL) //we found our insertion point
        {
          parent->left = node; //we do it this way to keep parent-child relationship
          break;
        }
      }

      else
      {
        current = current->right;
        if(current == NULL) //we found our insertion point
        {
          parent->right = node;
          break;
        }
      }
      // notice that we dont need to see if it is equal. This is becasue we are working with a binary search Tree
      // this will be different for other trees
    }
  }
}
