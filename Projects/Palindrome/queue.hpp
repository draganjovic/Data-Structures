// $Dragan Jovic <$dj47@zips.uakron.edu>
//
// queue.hpp: Definition of the queue class

#include <iostream>

#ifndef QUEUE_HPP
#define QUEUE_HPP

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

#endif
