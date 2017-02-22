// $Dragan Jovic <$dj47@zips.uakron.edu>
//
// palindrome.cpp: main function

#include <iostream>
#include <string>
#include <cstdlib>

#include "Queue.hpp"
#include "Queue.cpp"
#include "Stack.hpp"
#include "Stack.cpp"

using namespace std;



int main()
{
    // Variables
    string line;        // one output line by user
    int mismatch = 0;  // spots that do not match
    char letter;      // character from string
    int length;       // length of string

    bool isPalindrome(string input);


    Stack myStack;    // Stack declaration
    Queue myQueue;   // Queue declaration


    // While a string is entered on stand input and is not "q"
    do
    {
        cout << "Your input: " << endl;
        cin >> line;
        if (isPalindrome(line))
          cout << "This is a Palindrome" << endl;
        else
          cout << "This is not a Palindrome" << endl;
    }
    while ((line.length() != 0) && letter != 'q');

      // using recursion. add each character to both stack and queue
      if (!myStack.full() && !myQueue.full())
      {
        return (myStack.push(), myQueue.enqueue());
      }

    // using recursion, pop a character from stack and dequeue character from queue
    else (myStack.full() && myQueue.full())
    {
      return (myStack.pop(), myQueue.dequeue());
    }

    // if characters are not equal, output the index of the missmatch followed by std::endl


    // recursively empty the stack and queue
    

    // if both stack and queue are empty, output -1 followed by std::endl
