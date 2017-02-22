// $Dragan Jovic <$dj47@zips.uakron.edu>
//
// queue.hpp: Definition of the queue class

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

const int MAX_ELEMENTS = 100;

class Queue{

  private:

      int my_queue[MAX_ELEMENTS];

      int front; // front of the queue
      int rear; // back of the queue
      int num__of_elements; // number of elements in queue

  public:
      Queue();  // constructor
      ~Queue(); // destructor

      void enqueue(int data);  // add element at back
      void dequeue(); // remove element at front

      bool empty(); // check if queue is empty
      bool full(); // check if queue is full

      int size(); // gets the current size of queue

};

#endif
