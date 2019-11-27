/*
Michael kulinich
2328386
kulinich@chapman.edu
CPSC350-01
Assignment 3
This is the general stack implementation
*/


#include <iostream>
#include "StackEmpty.cpp"

using namespace std;


template<class E>
class GenStack
{
  public:
    GenStack();//constructor
    GenStack(int maxSize);//overloaded constructor
    ~GenStack();//destructor

    void push(E d);
    E pop() throw(StackEmpty);
    E peek() throw(StackEmpty);

    bool isFull();
    bool isEmpty();
    int getSize();

    int size;
    int top;
    E *myArray;  //or E* myArray

};


template<class E>
GenStack<E>::GenStack()
{
  //initialization of default values
  myArray = new E[128];
  size = 128;
  top = -1;
}

template<class E>
GenStack<E>::GenStack(int maxSize)
{
  myArray = new E[maxSize];
  size = maxSize;
  top = -1;
}

template<class E>GenStack<E>::~GenStack()
{
 // delete[]myArray;
}

template<class E>
void GenStack<E>::push(E d)
{
    cout << "Check 1 Inside push\n";
  if(isFull()){
    //create a temporary array double the size of the original
    E *temp = new E[size*2]; //should I use new?
    for(int i = 0; i < size; ++i){
      temp[i] = myArray[i]; //set the values from myArray to the temp
    }
    delete[] myArray; // delete myArray in order to avoid memory leaks
    myArray = temp;
    size *= 2;
  }
  cout << "Check 2 Inside push\n";

  myArray[++top] = d;
  cout << "Check 3 Inside push\n";

}

template<class E>
E GenStack<E>::pop() throw(StackEmpty)
{
  try {
    if(isEmpty())
    {
      throw(StackEmpty("Exception, The stack is Empty\n"));
    }
  }
    catch (StackEmpty& e){
      cout << e.getMessage();
      exit(1);
    }
  return myArray[top--];
}

template<class E>
int GenStack<E>::getSize(){
  return size;
}

template<class E>
E GenStack<E>::peek() throw(StackEmpty)
{
  try {
    if(isEmpty())
    {
      throw(StackEmpty("Exception, The stack is Empty\n"));
    }
  }
    catch (StackEmpty& e){
      cout << e.getMessage();
      exit(1);
    }
  return myArray[top];
}

template<class E>
bool GenStack<E>::isFull()
{
  return(top == size -1);
}

template<class E>
bool GenStack<E>::isEmpty()
{
  return (top == -1);
}
