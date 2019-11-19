#include <iostream>


using namespace std;
template <class T>
class PersonTreeNode
{
  public:
    PersonTreeNode();
    PersonTreeNode(int k, T *v); // k = key, which in this example is also the value(data)
    ~PersonTreeNode(); // when creating a template class, destructor must be virtual

    int key;
    T *value;
    PersonTreeNode *left;   //might have to make this   PersonTreeNode<T>
    PersonTreeNode *right;
};

template <class T>
PersonTreeNode<T>::PersonTreeNode()
{
  key = 0;
  value = NULL;
  left = NULL;
  right = NULL;
}

template <class T>
PersonTreeNode<T>::PersonTreeNode(int k, T *v)
{
  key = k;
  value = v;
  left = NULL;
  right = NULL;
}


template <class T>
PersonTreeNode<T>::~PersonTreeNode()
{
  delete left;
  delete right;
}
