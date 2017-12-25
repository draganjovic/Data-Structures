### Objective

In this assignment I will implement a palindrome class. This class will detect if a given string is a
palindrome or not (it reads the same in reverse).

### Files 

• `CMakeLists.txt` - The build system for your project. Read this file carefully.

• `palindrome.cpp` - This is where you write your main function.

• `stack.cpp` - This is where you provide the implementation of Stack.

• `stack.hpp` - This is where you provide the definition of Stack.

• `queue.cpp` - This is where you provide the implementation of Queue.

• `queue.hpp` - This is where you provide the definition of Queue.

• `input1.txt` - The text file given for testing.

• `output1.txt` - The expected output from using the input1.txt file.

### Class requirements

Your task will be to determine if an input string is has the same letters when read forwards as it does
backwards. For example: The word ‘anna’ has the same letters regardless of which end you start from. A
palindrome For the purpose of this project we will ignore any non-alphanumeric characters (space, punctuation,
non-printable characters).

### General Program Flow

• while a string is entered on standard input and is not "q"

• store the string

• using recursion, add each alphanumeric character to both a stack and a queue

• using recursion, pop a character from the stack and dequeue a character from the queue

• if the characters are not equal

• output the index of the missmatch followed by std::endl

• recursively empty the stack and queue

• if both the stack and queue are empty

• output -1 followed by std::endl

### Tools used
 
1. MacBook Pro (Retina, 13-inch, Early 2015)
2. Dual Monitor Setup
3. Terminal
4. Emacs
5. Atom
6. Xcode

