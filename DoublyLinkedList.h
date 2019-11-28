#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H



#include "DoublyListNode.h"
#include <iostream>

using namespace std;
template<class T>
class DoublyLinkedList
{
  // private:
  //   DoublyListNode *front;
  //   DoublyListNode *back;
  //   usigned int size;

  public:
    DoublyListNode<T> *front;
    DoublyListNode<T> *back;
    unsigned int size;
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertFront(T d);
    void insertBack(T *d);
    T* removeFront();
    T removeBack();
  //  int deletePos(int pos);// aka removeAt()
    int find(T d); //aka contains()
    DoublyListNode<T>* remove(T d); // aka int key

    //helper functions
    bool isEmpty();
    void printList();
    unsigned int getSize();

};


template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  size = 0;
  front = NULL; // nullptr
  back = NULL;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while(!isEmpty())
    {
        removeFront();
    }
    //delete front;
    //delete back;
}

template<class T>
unsigned int DoublyLinkedList<T>::getSize()
{
  return size;
}

template<class T>
void DoublyLinkedList<T>::printList()
{
    if(isEmpty())
        cout << "Empty List" << endl;
    else
    {
        DoublyListNode<T> *current = front;
        while(current != NULL)
        {
            cout << current->data << ", ";
            current = current->next;
        }
        cout << endl;
    }
}

template<class T>
void DoublyLinkedList<T>::insertFront(T d)
{
  DoublyListNode<T> *node = new DoublyListNode<T>(d);
  if(size == 0)//empty list
  {
    back = node;
  }
  else //not empty
  {
    node->next = front;
    front->prev = node;
    front = node;
  }
  front = node;
  ++size;
}

template<class T>
void DoublyLinkedList<T>::insertBack(T *d)
{
  DoublyListNode<T> *node = new DoublyListNode<T>(d);
  if(size == 0)//empty list
  {
    //we have an empty list
    front = node;
  }
  else //not empty
  {
    back->next = node;
    node ->prev = back;
  }
  back = node;
  ++size;
}


template<class T>
T* DoublyLinkedList<T>::removeFront()
{
    //check if empty before attempting to remove
    if(isEmpty())
    {
        cout << "list is empty" << endl;
        exit(1);
    }

    DoublyListNode<T> *ft = front; // temp var to allow for us to remove this list node later

    //if there is only one element in the list, also special cases
    if(size == 1)// or if front == back or if front->next == NULL
    {
      //front == back or front ->next ==nullptr
      //it's the one node in the list
      back == NULL;
    }
    else
    {
      //we have more than one element in the List
      front->next->prev = NULL; // front->next, then his previous, is equal to null
      /*
      essentially the new fronts pointer to prev is being assigned null which
      is good b/c the fronts previous should be null
      */

      front = front->next; //update the front and have it point to next pointer
      T *temp = ft->data; // temp variable to store data that will be removed
      ft->next = NULL; //set the temp front to point to NULL
      delete ft;
      --size;

      return temp; //this is the value you removed
    }
  }

template<class T>
T DoublyLinkedList<T>::removeBack()
{
    //check if empty before attempting to remove
    if(isEmpty())
    {
        cout << "List Empty" << endl;
        exit(1);
    }

    DoublyListNode<T> *ft = back;
    if(size == 1)
    {
      //front == back or front ->next ==nullptr
      //it's the one node in the list
      front == NULL;
    }
    else
    {
        //we have more than one element in the List
        back->prev->next = NULL; //the pointer (prev) to front is null
    }
    back = back->prev;
    T temp = ft->data;
    ft->prev = NULL;
    delete ft;
    --size;
    return temp;
}


// for this remove function, we return an address to the listNode
template<class T>
 DoublyListNode<T>* DoublyLinkedList<T>::remove(T d) // aka int key, the value you are searching for
 {
   //can also use find method to make it shorter

   //check if list is not empty before attempting to remove, you do it

   //now time to find the value
  DoublyListNode<T> *curr = front; //this will allow you to go through and check every list node for the value

  while(curr->data != d)
  {
    // this finds the actual node
    curr = curr-> next; // move to next value
    if(curr == NULL)//we did not find the value/ListNode
    {
      return NULL;
    }
  }

  // If it gets here, then we have found the node

  // Check if the node is the insert
  if(curr == front)
  {
    front = curr->next;
  }
  else //it is not the front
  {
    curr->prev->next = curr->next; //currents prevous next (which is current) now changes to currents next
    //prep to delete current and change pointers to appropiate ones
  }

  if(curr == back){
    back = curr->prev;
  }
  else // its not the back
  {
    //update pointer  the next Node from curr should point its prev to Node previous to curr
    curr->next->prev = curr->prev;
  }
  curr->next = NULL;
  curr->prev = NULL;
  size--;

  return curr;
  //at this point, the current is returned, and no longer in the linked list

 }


template<class T>
int DoublyLinkedList<T>::find(T d)
{
  int idx = 0;
  DoublyListNode<T> *curr = front;

  while(curr != NULL){
    if(curr->data == d)
    {
      //we found the value we were looking for
      break;
    }
    idx++;
    curr = curr->next;
  }

  if(curr == NULL)
  { //we did not find the value
    idx = -1;
  }
  return idx;
}

template<class T>
bool DoublyLinkedList<T>::isEmpty()
{
    return (size == 0);
}

#endif

//
// int DoublyLinkedList<T>::deletePos(int pos){ // find the index and remove
//
//   int idx = 0; //index
//   ListNode *curr = front;
//   ListNode *pre = front; //bc when we delete, we need pre->next to point to  curr->next, skipping curr
//   while(idx != pos){
//     prev = curr;
//     curr = curr->next;
//     idx++;
//   }
//
//   //we have found the poistion of the node to be deleted, hopefully our pointers are in the ocrrect position
//
//   prev->next = curr->next;
//   curr->next = NULL;
//   int temp = curr->data;
//   delete curr;
//   size--;
//
//   return temp;
// }
