// $Dragan Jovic <$dj47@zips.uakron.edu>
//
// palindrome.cpp: main function

#include <iostream>
#include <string>
#include <ctype.h>

#include "stack.hpp"
#include "queue.hpp"

using namespace std;


// fills up stack and queue with input
void fillData(string str, stack<string> &stk, queue<string> &que);

string strip(string s);

// function that checks if string is a palindrome
bool testString(stack<string> &stk, queue<string> &que);


int main()
{
	bool test;
	stack<string> stk;
	queue<string> que;
	string str, _str;
	string quit = "q";
	string fname, line;

  cout << "Enter the string: ";
  while(1)
  {
    std::getline(std::cin, _str);
  cout<<_str<<endl;
    str = strip(_str);
  cout<<str<<endl;
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


string strip(string s)
{
  string ss;
  for(int i=0; i<s.length(); i++)
  {
    if (isalpha(s[i]))
      ss.append(1, s[i]);
  }
  return ss;
}

// using recursion add each character to the stack and queue
void fillData(string str, stack<string> &stk, queue<string> &que)
{
 string letter;

 if(stk.empty() && que.isEmpty())
 {

  int i = 0;
  while(i<str.length())
  {
   letter = str[i];
   stk.push(letter);
   i++;
 }

 int j=0;
 while(j<str.length())
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

bool iequals(const string& a, const string& b)
{
  unsigned int sz = a.size();
  if (b.size() != sz)
    return false;
  for (unsigned int i = 0; i < sz; ++i)
    if (tolower(a[i]) != tolower(b[i]))
      return false;
    return true;
  }


  // using recursion pop from stack and dequeue from queue
  bool testString(stack<string> &stk, queue<string> &que)
  {
    int i=0;
    while(!stk.empty() && !que.isEmpty())
    {
      string s1 = stk.top();
      string s2 = que.front();

      if(iequals(s1,s2))
      {
       stk.pop();
       que.dequeue();
       i++;
     }
     else
     {
      cout<<i<<endl;
      return false;
    }
  }
  return true;
}
