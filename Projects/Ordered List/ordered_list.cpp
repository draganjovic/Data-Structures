// $Dragan Jovic <$dj47@zips.uakron.edu>
//
// Ordered_list.hpp: Implementation of the Ordered_list class

#include "ordered_list.hpp"

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;


Ordered_list::Ordered_list() // Set all pointers to NULL (head, current, and temp)
{
    
    head = NULL;
    trail = NULL;
    curr = NULL;
    temp = NULL;
}

Ordered_list::~Ordered_list() // Destructor
{

}

void Ordered_list::insert(int insertData)
{
    node* newNode = new node
    {
        insertData = insertData,
        newNode = NULL
    };
    
    // empty list
    if (head == NULL)
    {
        head = newNode;
        
    }
    else
    {
        node* curr = head;
        node* trail = NULL;
        
        // Traverse list to find insert location
        while(curr != NULL)
        {
            if(curr->data > newNode->data)
            {
                break;
            }
            else
            {
                trail = curr;
                curr = curr->next;
            }
        }
        
        // insert at head
        if(curr == head)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
        
        // insert after the head
            newNode->next = curr;
            trail->next = newNode;
        }
        
    }
    
}


void Ordered_list::remove(int removeData) // Pass in data that will be stored in "removeData"
{
    node* deleteptr = NULL; // Create node pointer
    temp = head;
    curr = head;
    
    while(curr != NULL && curr->data != removeData)
    {
        temp = curr;
        curr = curr->next;
    }
    // Check to see if current pointer is pointing at anything
    if(curr == NULL)
    {
        // cout << removeData << " was not found in the list\n";
        delete deleteptr; // Takes care of memory leaks
    }
    else // Node was found, and so it will be deleted
    {
        deleteptr = curr;
        curr = curr->next; // Advances our curr pointer to "next" node
        temp->next = curr;
        delete deleteptr;
        // cout << "The value " << removeData << " was deleted\n";
    }
}


void Ordered_list::display()
{
    curr = head;
    while (curr != NULL)
    {
        cout << "[" << curr->data << "]";
        curr = curr->next;
    }
    
    cout <<  endl;
}

void Ordered_list::search(int searchData)
{
    node* searchptr = NULL;
    temp = head;
    curr = head;
    
    while (curr != NULL && curr->data != searchData)
    {
        temp = curr;
        curr = curr->next;
    }
    if(curr != NULL)
    {
        searchptr = curr;
        curr = curr->next;
        cout << "-" << searchptr << " Found";
    }
    else
    {
        cout << "N/A";
        
    }
}

void Ordered_list::clear()
{
    if (!head)
    {
        return;
    }
    
    node* temp = head;
    while(temp)
    {
        head = temp->next;
        delete temp;
        temp = head;
    }
}

bool Ordered_list::is_empty()
{
    return count() == 0;
}

int Ordered_list::count()
{
    node* curr = head;
    curr = head;
    int _count = 0;
    
    while( curr != NULL)
    {
        _count++;
        curr = curr->next;
    }
    return _count;
}






































