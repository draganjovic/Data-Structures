// $Dragan Jovic <$dj47@zips.uakron.edu>
//
// stack.hpp: Definition of the stack class using a linked list

#include <iostream>

#ifndef STACK_HPP
#define STACK_HPP

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

    // copy constructor
    stack(const stack<stackElem> &rhs); // rhs = right hand side

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

#endif
