#include <iostream>
#include "huffman.hpp"

using namespace std;

// alphabet size of extended ASCII
int HuffmanTree::R = 256;

int main() {
  while (true) {
     string s;
     HuffmanTree ht;
     cout << endl;
     cout << "Input String: ";
     getline(cin, s);
     if (s == "q") break;
     ht.buildTree(s);
     cout << ht.encode(s) << endl;
     ht.serialize();
  }
  return 0;
} 
