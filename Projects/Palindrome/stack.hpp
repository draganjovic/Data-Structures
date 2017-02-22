// $Dragan Jovic <$dj47@zips.uakron.edu>
//
// stack.hpp: Definition of the stack class

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

const int MAX = 100;

class Stack{

  private:

      int top; // top of stack
      char items[MAX];

  public:
      Stack(); // constructor
      ~Stack(); // destructor

      void push(int in); // push function
      void pop(); // pop function

      bool empty(); // check if stack is empty
      bool full(); // check if stack is full

      int size(); // gets the current size of stack

};

  #endif
