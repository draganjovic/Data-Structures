#include "Node.hpp"
#include <algorithm>
#include <vector>
using namespace std;

#ifndef _PQ_HPP_
#define _PQ_HPP_

class PriorityQueue
{
    vector<Node*> keys;
    void heapify(int low, int high);
    void swimUp(int low, int high);

public:
    PriorityQueue(){}

    /*Insert a new item into the priority queue*/
    void push(Node* item);

    /*Get the maximum element from the priority queue*/
    void pop();

    Node* top();

    int size() const { return keys.size(); }

    /*Just for testing*/
    void print();
};


#endif