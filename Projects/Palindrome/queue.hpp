// $Dragan Jovic <$dj47@zips.uakron.edu>
//
// queue.hpp: Definition of the queue class

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

template <class Type>
class queue
{
  public:

  	queue();  // Constructor
       ~queue(); // destructor

         // Copy constructor
  	 queue(const queue<Type> &rhs); // rhs = right hand side

  	 // assignment operator (overloaded)
  	 queue<Type> & operator=(const queue<Type> &rhs);

	 // enqueue function
	 void enqueue(const Type &item);

	 // dequeue function
	 void dequeue();

	  // front function (places value to front if there is no front)
	 Type front() const;

	 // clear function
	 void clear();

	 // test to see if queue is empty
	 bool isEmpty() const;

	 // test to see if queue is full
	 bool isFull() const;

  private:

	class queueNode
	{
	  public:
  		Type data;
  		queueNode *next;
  		queueNode() {next= NULL;}
  		queueNode(Type initData, queueNode *link = NULL)
        {
          data=initData; next=link;
        }
	};

	    queueNode *frontPtr, *rearPtr;
};

// Constructor
template <class Type>
queue<Type>::queue()
{
  frontPtr = NULL;
  rearPtr = NULL;
}

// Copy constructor
template <class Type>
queue<Type>::queue(const queue<Type> &rhs)
{
  frontPtr = NULL;
  rearPtr = NULL;

  *this = rhs;
}

// destructor
template <class Type>
queue<Type>::~queue()
{
  clear();
}

// Overload of assignment operator
template <class Type>
queue<Type> & queue<Type>::operator=(const queue &rhs)
{
  clear();
  queueNode *p1;
  queueNode *ptr;

  p1 = rhs.frontPtr;

  if(p1 != NULL)
  {
   frontPtr = new queueNode(p1 -> data);
   ptr = frontPtr;
   p1 = p1 -> next;
 }

 while(p1 != NULL)
 {
   ptr -> next = new queueNode(p1 -> data);
   p1 = p1 -> next;
   ptr = ptr -> next;
 }
 return *this;
}


// enqueue function
template <class Type>
void queue<Type>::enqueue(const Type &item)
{
  if(frontPtr != NULL)
  {
   rearPtr -> next = new queueNode(item);
   rearPtr = rearPtr -> next;
 }
 else
 {
   rearPtr = new queueNode(item);
   frontPtr = rearPtr;
 }
}


// dequeue function
template <class Type>
void queue<Type>::dequeue()
{
  queueNode *p;

  if(frontPtr != NULL)
  {
    p = frontPtr;
    frontPtr = frontPtr -> next;
    delete p;

    if(rearPtr == p)
      rearPtr = NULL;

      // delete p;
  }
}


// front function (places value to front if there is no front)
template <class Type>
Type queue<Type>::front() const
{
  if(frontPtr != NULL)
   return frontPtr -> data;
}


// clear function
template <class Type>
void queue<Type>::clear()
{
  queueNode *p1 = frontPtr;
  while (frontPtr != NULL)
  {
    frontPtr = frontPtr -> next;
    delete p1;
    p1 = frontPtr;
  }
}


// test to see if queue is empty
template <class Type>
bool queue<Type>::isEmpty() const
{
  if(frontPtr == NULL)
    return true;
  else
    return false;
}


// test to see if queue is full
template <class Type>
bool queue<Type>::isFull() const
{
  if (frontPtr != NULL)
    return true;
  else
    return false;
}

#endif
