#include <iostream>

using namespace std;
template <class T>
class TreeNode
{
  public:
    TreeNode();
    TreeNode(T k); // k = key, which in this example is also the value(data)
    ~TreeNode(); // when creating a template class, destructor must be virtual

    T key;
    TreeNode *left;
    TreeNode *right;
};

template <class T>
TreeNode<T>::TreeNode()
{
  key = NULL;
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T k)
{
  key = k;
  left = NULL;
  right = NULL;
}


template <class T>
TreeNode<T>::~TreeNode()
{
  delete left;
  delete right;
}
