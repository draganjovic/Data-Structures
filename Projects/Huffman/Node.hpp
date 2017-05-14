#include <iostream>
using namespace std;

#ifndef _NODE__
#define _NODE__
// Huffman node
class Node {
  char ch;
  int freq;
  Node* left;
  Node* right;

public:
  // Parameterized constructor of node, initalizes character and its frequency
  Node(char ch, int freq, Node* left = nullptr, Node* right = nullptr) {
    this->ch    = ch;
    this->freq  = freq;
    this->left  = left;
    this->right = right;
  }

  // Copy constructor
  Node(const Node& node) {
    this->ch    = node.ch;
    this->freq  = node.freq;
    this->left  = node.left;
    this->right = node.right;
  }

  // Getters
  int getFrequency() const {
    return freq;
  }

  Node* getLeft() {
    return left;
  }

  Node* getRight() {
    return right;
  }

  char getChar() const {
    return ch;
  }

  // Method to check if this node is leaf or not
  bool isLeaf() const {
    return left == nullptr && right == nullptr;
  }

  friend ostream& operator << (ostream & out, const Node& node) {
    out << "(" << node.getChar() << ", " << node.getFrequency() << ") ";
    return out;
  }

  int compareTo(const Node& other) {
    if (freq != other.freq) {
      return freq - other.freq;
    }
    return  other.ch - ch;
  }
};

#endif
