// $Dragan Jovic <$dj47@zips.uakron.edu>
//
// stack.hpp: Definition of the stack class using a linked list

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

template <class stackElem>
class stack
{
  public:

    // Constructor
    stack()
    {
      topPtr = NULL;
    }
    ~stack(); // destructor

    // copy constructor - rhs = right hand side
    stack(const stack<stackElem> &rhs);

    // assignment operator (overloaded)
    stack<stackElem> & operator = (const stack<stackElem> &rhs);

    // push function
    void push(const stackElem &value);

    // pop function
    void pop();

    // place top value for item if stack is empty
    stackElem top() const;

    // test to see if stack is empty
    bool empty() const;

    // test to see if stack is full
    bool full() const;

    // clear function
    void clear();

  private:

  class stackNode
  {
  	public:
  		stackElem data;
  		stackNode *next;
  		stackNode(const stackElem &value, stackNode *link = NULL)
        {
            data=value; next=link;
        }
  };

  	  stackNode * topPtr;
};

// Creates a copy
template <class stackElem>
stack<stackElem>::stack(const stack<stackElem> & rhs)
{
	topPtr = NULL;

	*this = rhs;
}

// Deletes all nodes from the list
template <class stackElem>
stack<stackElem>::~stack()
{
	clear();
}

// Overload of assignment operator
template <class stackElem>
stack<stackElem> & stack<stackElem>::operator=(const stack &rhs)
{
	clear();
	stackNode *p1;
	stackNode *ptr;

	p1 = rhs.topPtr;

	if( p1 != NULL)
	{
		topPtr = new stackNode(p1 -> data);
		ptr = topPtr;
		p1 = p1 -> next;
	}

	while(p1 != NULL)
	{
		ptr -> next = new stackNode(p1 -> data);
		p1 = p1 -> next;
		ptr = ptr -> next;
	}
	return *this;
}

// push function
template <class stackElem>
void stack<stackElem>::push(const stackElem &value)
{
	topPtr = new stackNode(value, topPtr);
}

// pop function
template <class stackElem>
void stack<stackElem>::pop()
{
	stackNode *p;

	if(topPtr != NULL)
	{
		p = topPtr;
		topPtr = topPtr -> next;
		delete p;
	}
}

// top function (places value on top if there is no top)
template <class stackElem>
stackElem stack<stackElem>::top() const
{
	if(topPtr != NULL)
	{
		return topPtr -> data;
	}
}

// test to see if stack is empty
template <class stackElem>
bool stack<stackElem>::empty() const
{
	if(topPtr == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// test to see if stack is full
template <class stackElem>
bool stack<stackElem>::full() const
{
	if(topPtr != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// clear function
template <class stackElem>
void stack<stackElem>::clear()
{
	stackNode *p = topPtr;

	while(topPtr != NULL)
	{
		topPtr = topPtr -> next;
		delete p;
		p = topPtr;
	}
}

#endif
