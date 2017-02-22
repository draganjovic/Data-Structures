// $Dragan Jovic <$dj47@zips.uakron.edu>
//
// queue.cpp: Implementation of the queue class

#include "queue.hpp"

#include <iostream>

// Default constructor
Queue::Queue()
{
    front = 0;
    rear = -1;
    num__of_elements = 0;
}

// Destructor
Queue::~Queue() {}

// Add element at back of queue
void Queue::enqueue(int data)
{
    if((full()))
    {
        return;
    }
    else
    {
        rear = (rear + 1) % MAX_ELEMENTS;
        my_queue[rear] = data;
        num__of_elements = num__of_elements + 1;
    }
}

// Remove element at front of queue
void Queue::dequeue()
{
    if(!empty())
    {
        front = (front + 1) % MAX_ELEMENTS;
        num__of_elements--;
    }
}

// Function that checks if queue is empty
bool Queue::empty()
{
    return (num__of_elements == 0);
}

// Function that checks if queue is full
bool Queue::full()
{
    return (num__of_elements == MAX_ELEMENTS);
}

// Function that gets the current size of the queue
int Queue::size()
{
    return (num__of_elements);
}
