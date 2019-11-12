#include "TreeNode.h"

template <class T>
class BST
{
  private:
    TreeNode<T> *root; //

  public:
    BST();
    ~BST();

    bool search(T value); //search that returns bool if the value is there or not
    void insert(T value);

    // Delete placeholder
    bool deleteNode(T key);

    // Helper Functions
    bool isEmpty();
    TreeNode<T> *getMin(); //returns pointer to the node
    TreeNode<T> *getMax();
    TreeNode<T> *getSuccessor(TreeNode<T> *node);
    void printTree(); //can use preorder, postorder, inorder
    void recursivePrint(TreeNode<T> *node);
    void RemoveSubtree(TreeNode<T> *node);
};

template <class T>
BST<T>::BST()
{
  root = NULL; //empty Tree
}

template <class T>
BST<T>::~BST()
{
  RemoveSubtree(root);
}

template <class T>
bool BST<T>::isEmpty()
{
  return(root == NULL);
}

template <class T>
void BST<T>::recursivePrint(TreeNode<T> *node)
{
  if (node == NULL)
  {
    return;
  }

  //In Order Traversal// Up to us if we wanna change it
  recursivePrint(node->left);
  cout << node->key << endl;
  recursivePrint(node->right);
}

template <class T>
void BST<T>::printTree()
{
  recursivePrint(root);
}

template <class T>
TreeNode<T> *BST<T>::getMax()
{
  TreeNode<T> *current = root; //starting point

  if(current == NULL) //empty tree
  {
    //nothing to traverse
    return NULL;
  }

  while(current->right != NULL)
  {
    current = current->right;
  }
  return (current); //another way ---> return &(current-key);
}

template <class T>
TreeNode<T> *BST<T>::getMin()
{
  TreeNode<T> *current = root; //starting point

  if(current == NULL) //empty tree
  {
    //nothing to traverse
    return NULL;
  }

  while(current->left != NULL)
  {
    current = current->left;
  }
  return (current); //another way ---> return &(current-key);
}


template <class T>
void BST<T>::insert(T value)
{
  TreeNode<T> *node = new TreeNode<T>(value);

  if(root == NULL) //Then we have an empty Tree
  {
    root = node; //Creating the beginning of a tree!!
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

template <class T>
bool BST<T>::search(T value)
{
  if(root == NULL)
  {
    return false; // empty tree
  }

  else //tree no empty, lets search
  {
    TreeNode<T> *current = root;

    while(current->key != value)  //while they key isnt the value, lets search
    {
      if (value < current->key)
        current = current->left;

      else
        current = current->right;

      if (current == NULL) //we didnt find the value
        return false;
    }
  }
  return true;
}

template <class T>
bool BST<T>::deleteNode(T value)
{
  if (root == NULL)
    return false;

  TreeNode<T> *current = root;
  TreeNode<T> *parent = root;
  bool isLeft = true; // determines whether we are at the left child or not


  while(current->key != value)  //while they key isnt the value, lets search
  {
    parent = current; //update, need to know parent so we can update the pointer
    if (value < current->key)
    {
      isLeft = true;
      current = current->left;
    }

    else
    {
      isLeft = false;
      current = current->right;
    }

    if (current == NULL) //we didnt find the value
      return false;
  }
  // If we make it here, then we have found the node that needs to be deleted
  // Time to check our different cases

  //No Children Case
  if (current->left == NULL && current->right == NULL)
  {
    if(current == root)
    {
      root = NULL;
    }

    else if (isLeft)
    {
      parent->left = NULL;
    }

    else
    {
      parent ->right = NULL;
    }
  }

  // Node to be deleted has one child, we need to determine if child is left or right and proceed
  else if(current->right == NULL) //has no right child
  {
    if(current == root)
    {
      root = current->left;
    }

    else if(isLeft)
    {
      parent->left = current->left;
    }

    else
    {
      parent->right = current->left;
    }
  }

  else if(current->left == NULL) //has no left child
  {
    if(current == root)
    {
      root = current->right;
    }

    else if(isLeft)
    {
      parent->left = current->right;
    }

    else
    {
      parent->right = current->right;
    }
  }

  else // the node to be deleted has 2 Children
  {
    TreeNode<T> *successor = getSuccessor(current);
    if(current == root)
    {
      root = successor;
    }
    else if (isLeft)
    {
      parent->left = successor;
    }

    else
    {
      parent->right = successor;
    }

    successor->left = current->left; //current is the node thats getting deleted. its left node is reassigned to the successors
  }
  return true;
}


//We have stated that we want the successor to be the closest number that is larger than the number to be deleted
//ie current->right, and then alllll the way current->left to the closest number to the number that was deleted
template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d) //d is node to be deleted
{
  TreeNode<T> *sp = d; //sp is successor's parent and is initialized to d
  TreeNode<T> *successor = d;
  TreeNode<T> *current = d->right; //start one right

  while(current!= NULL) //one right all the way left
  {
    sp = successor;
    successor = current;
    current = current->left;
  }

  if(successor!= d->right) //successor is a descendant of the right child
  {
    //Update pointers
    sp->left = successor->right; //the new successors child will become the child of the node previously above successors
    successor->right = d->right; //new successors child is what his parent used to be
    current = current->left;
  }
  return successor;
}

template <class T>
void BST<T>::RemoveSubtree(TreeNode<T> *node)
{
  if(node != NULL)
  {
    if(node->left != NULL)
    {
      RemoveSubtree(node->left);
    }
    if(node->right != NULL)
    {
      RemoveSubtree(node->right);
    }
    cout << "Remove node containing " << node->key << endl;
    delete node;
  }
}
