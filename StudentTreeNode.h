// #include <iostream>
// #include "TreeNode.h"
//
// using namespace std;
//
// template <class T>
// class StudentTreeNode : public TreeNode<int> {
//   public:
//     StudentTreeNode();
//     StudentTreeNode(int k, T *v); // k = key, which in this example is also the value(data)
//     ~StudentTreeNode(); // when creating a template class, destructor must be virtual
//     T *value;
//     StudentTreeNode *left;
//     StudentTreeNode *right;
//
// };
//
// template <class T>
// StudentTreeNode<T>::StudentTreeNode()
// {
//   // value = NULL;
//   // key = NULL;
//   // left = NULL;
//   // right = NULL;
// }
//
// template <class T>
// StudentTreeNode<T>::StudentTreeNode(int k, T *v) : TreeNode<int>(k) {
//   value = v;
//   left = NULL;
//   right = NULL;
// }
//
//
// template <class T>
// StudentTreeNode<T>::~StudentTreeNode()
// {
//   // delete left;
//   // delete right;
// }
