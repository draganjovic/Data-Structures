// $Dragan Jovic <$dj47@zips.uakron.edu>
//
// palindrome.cpp: main function

#include <iostream>
#include <string>
#include <ctype.h>

#include "stack.hpp"
#include "queue.hpp"

using namespace std;


// fills up stack and queue
void fillData(string str, stack<string> &stk, queue<string> &que);

// converts a string to only alphabetic characters (returns str)
string strip(string s);

// checks string to see if it is a palindrome
bool testString(stack<string> &stk, queue<string> &que);


int main()
{
	bool test; // testing purposes (q, -1)
	stack<string> stk; // new stack
	queue<string> que; // new queue
	string str; // str contains the input without the spaces
	string _str; // _str takes in raw input from user
	string quit = "q";

	cout << "Enter the string: ";
  while(1)
  {
    std::getline(std::cin, _str);
    cout << _str << endl;
    str = strip(_str);
    cout << str << endl;
    if(str.compare(quit) == 0)
    {
      break;
    }

    fillData(str, stk, que);

    test = testString(stk, que);

    if(test == true)
      cout << -1 << endl;


    stk.clear();  //clear stack
    que.clear();  //clear queue
  }

  return 0;
}

// converts a string to only alphabetic characters
string strip(string s)
{
  string ss;
  int i = 0;
  while(i < s.length())
  {
    if (isalpha(s[i]))
      ss.append(1, s[i]);
    i++;
  }

  return ss;
}

// using recursion add characters to stack and queue
void fillData(string str, stack<string> &stk, queue<string> &que)
{
 string letter;

 if(stk.empty() && que.isEmpty())
 {
  // fills up stack
  int i = 0;
  while(i < str.length())
  {
   letter = str[i];
   stk.push(letter);
   i++;
 }
 // fills up queue
 int j = 0;
 while(j < str.length())
 {
   letter = str[j];
   que.enqueue(letter);
   j++;
 }

}
else
  cout << "Cannot fill because stack and queue are not empty";

return;
}

// makes sure that upper case and lower case letters are treated the same
bool iequals(const string& a, const string& b)
{
  unsigned int sz = a.size();
  if (b.size() != sz)
    return false;

  int i = 0;
  bool ret;
  while(i < sz){
    if (tolower(a[i]) != tolower(b[i])){
      ret = false;
      break;
    }
    ret = true;
    i++;
  }
  return ret;
  }


// using recursion pop characters from stack and queue
  bool testString(stack<string> &stk, queue<string> &que)
  {
    int i = 0;
    while(!stk.empty() && !que.isEmpty())
    {
      string s1 = stk.top();
      string s2 = que.front();
      // pop and dequeue from stack
      if(iequals(s1,s2))
      {
       stk.pop();
       que.dequeue();
       i++;
     }
     // returns mismatch if there is any
     else
     {
      cout << i << endl;
      return false;
    }
  }
  return true;
}
