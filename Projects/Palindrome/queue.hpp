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


	   //Description: put item on the rear of the queue
	void enqueue(const Type &item);


	   //Description: take the value from the front of the queue if not empty
	void dequeue();


	   //Description: returns the value at the front of the queue if not empty
	Type front() const;


	   //Description: empty out the queue by deleting all the nodes
	void clear();


	   //Description: checks to see if the queue is empty
	bool isEmpty() const;


	   //Description: checks to see if the queue is full
	bool isFull() const;

private:

	class queueNode
	{
	public:
		Type data;
		queueNode *next;
		queueNode() {next= NULL;}
		queueNode(Type initData, queueNode *link = NULL) {data=initData; next=link;}
	};

	queueNode *frontPtr, *rearPtr;
};


#endif
