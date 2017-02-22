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

class Palindrome
{

  public:
    void check_string();
    bool isPalindrome(string input);
};

  void Palindrome::check_string()
  {
      string line;        // one output line by user

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
      while ((line.length() != 0));
  }

  bool Palindrome::isPalindrome(string input)
  {
      Stack my_stack;
      Queue my_queue;
      char letter;  // one char from input string
      int mismatch = 0; // number of spots that mismatched
      int i;  // Index for input string

      for (i = 0; i < input.length(); i++)
      {
        letter = input.at(i);
        if (std::isalpha(letter))
        {
            my_queue.enqueue(letter);
            my_stack.push(letter);
        }
      }
      while (!my_queue.empty())
      {
          if (my_queue.dequeue() == my_stack.pop())
          {
              cout << "The characters are not equal." << endl;
              mismatch++;
          }
      }
      return (mismatch == 0);
}


        // using recursion. add each character to both stack and queue


    // using recursion, pop a character from stack and dequeue character from queue


    // if characters are not equal, output the index of the missmatch followed by std::endl


    // recursively empty the stack and queue


    // if both stack and queue are empty, output -1 followed by std::endl

    int main()
    {
      void check_string();
      bool isPalindrome('anna');

      return 0;
    }
