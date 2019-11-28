#ifndef DOUBLYLISTNODE_H
#define DOUBLYLISTNODE_H

// /*Michael Kulinich
// 2328386
// kulinich@chapman.edu
// Matthew Nwerem
// 2277158
// nwere100@mail.chapman.edu

#include <iostream>

using namespace std;

template<class T>
class DoublyListNode{
  public:
    T data;
    DoublyListNode *next; //pointer to the next ListNode
    DoublyListNode *prev; //pointer to the prev ListNode (used for doublyLL)

    //Constructor and Destructor
    DoublyListNode();
    DoublyListNode(T d);
    ~DoublyListNode();

};
template<class T>
DoublyListNode<T>::DoublyListNode(){}

template<class T>
DoublyListNode<T>::DoublyListNode(T d)
{
  data = d;
  next = NULL; //nullptr
  prev = NULL;
}

template<class T>
DoublyListNode<T>::~DoublyListNode()
{
  next = NULL;
  prev = NULL;

}

#endif
