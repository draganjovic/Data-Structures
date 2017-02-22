// $Dragan Jovic <$dj47@zips.uakron.edu>
//
// stack.cpp: Implementation of the stack class

#include "stack.hpp"

#include <iostream>

// Default constructor
Stack::Stack()
{
    top = -1;
}

// Destructor
Stack::~Stack()
{

}

// push function
void Stack::push(int in)
{
    if (full()) {return;}
    else
    {
        top++;
        items[top] = in;
    }
}

// pop function
void Stack::pop()
{
    if (top == 0)
    {
        top--;
    }
}

// Function that checks if stack is empty
bool Stack::empty()
{
    return (top == -1);
}

// Function that checks if stack is full
bool Stack::full()
{
    return ( top == MAX - 1);
}

// Function that gets the current size of the stack
int Stack::size()
{
    return ( top + 1 );
}
