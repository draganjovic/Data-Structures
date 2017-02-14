// $Dragan Jovic  <$dj47@zips.uakron.edu>
//
// Ordered_list.hpp: Definition of the Ordered_list class

#ifndef ORDERED_LIST_HPP
#define ORDERED_LIST_HPP

#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class Ordered_list {

private:
  size_t _count;

  struct node {
    int data;
    node *next;
  };

  node *head;
  node *trail;
  node *curr;
  node *temp;

public:
  Ordered_list();  // Default Constructor
  ~Ordered_list(); // Destructor

  void insert(int insertData); // Insert Function
  void remove(int removeData); // Remove Function
  void search(int searchData); // Search Function
  bool is_empty();             // Returns true if the list is empty
  void clear();                // Removes all elements from list
  int count();                 // Returns number of elements in list
  void display();              // Display contents of list
};

#endif
