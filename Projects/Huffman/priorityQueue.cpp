#include "priorityQueue.hpp"

void PriorityQueue::push(Node* item)
{
    keys.push_back(item);
    swimUp(0, keys.size() - 1);
}

void PriorityQueue::pop()
{
    int n = keys.size() - 1;
    swap(keys[0], keys[n]);
    keys.pop_back();
    heapify(0, n-1);
}

Node* PriorityQueue::top() {
    return keys[0];
}

void PriorityQueue::print()
{
    int size = keys.size();
    for (int i = 0; i < size; ++i)
        cout << *keys[i] << "   ";
    cout << endl;
}

void PriorityQueue::swimUp(int low, int high)
{
    int child = high;
    while (child > low) {
        int parent = (child-1) / 2;
        /*if child is smaller than parent we need to swap*/
        if (keys[child]->compareTo(*keys[parent]) < 0)
        {
           swap(keys[child], keys[parent]);

            /*Make parent index the child and shift towards left*/
            child = parent;
        }
        else {
            break;
        }
    }
}

void PriorityQueue::heapify(int low, int high)
{
    int root = low;
    while ((root*2)+1 <= high) {
        int leftChild = (root * 2) + 1;
        int rightChild = leftChild + 1;
        int min_index = root;
        /*Check if root is greater than left child*/
        if (keys[min_index]->compareTo(*keys[leftChild]) > 0) {
            min_index = leftChild;
        }
        /*If right child exists check if it is less than current root*/
        if ((rightChild <= high) && (keys[min_index]->compareTo(*keys[rightChild]) > 0)) {
            min_index = rightChild;
        }
        /*Make the biggest element of root, left and right child the root*/
        if (min_index != root) {
            swap(keys[root], keys[min_index]);
            /*Keep shifting right and ensure that min_index satisfies
            heap property aka left and right child of it is smaller than
            itself*/
            root = min_index;
        }
        else {
            break;
        }
    }
}