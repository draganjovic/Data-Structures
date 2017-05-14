
#include <iostream>
#include <string>
#include "priorityQueue.hpp"
using namespace std;

#ifndef __HUFFMAN__
#define __HUFFMAN__


class HuffmanTree {

    // alphabet size of ASCII
static int R;
    vector<Node*> treeNodes;
    Node* root;
    vector<string> codes;

    // Creates a table from symbols and their encodings
    void buildCode( Node* x, string& s) {
        if (!x->isLeaf()) {
            s.push_back('0');
            buildCode(x->getLeft(),  s);
            s.pop_back();
            s.push_back('1');
            buildCode(x->getRight(), s);
            s.pop_back();
        }
        else {
            codes[x->getChar()] = s;
        }
    }

    void serializeHelper(Node* root) {
        if (root != nullptr) {
            if (root->getChar() == '*') {
                cout << '*';
            }
            else cout << root->getChar() << "//";

            serializeHelper (root->getLeft());
            serializeHelper (root->getRight());
        }
    }
public:

    // Default constructor
    HuffmanTree () : root(nullptr) {}

    // Free tree nodes in destructor
    ~HuffmanTree() {
        for (int i = 0; i < treeNodes.size(); ++i) {
            delete treeNodes[i];
        }
    }

    /**
     * Given a string this method compresses it using huffman code
     */
    string encode(const string& s) {
        string ans;
        for (int i = 0; i < s.size(); ++i) {
            ans += codes[s[i]];
            if (codes[s[i]] == "") {
                cerr << "String contains characters which is not present in the original message. ";
                return "";
            }
        }

        return ans;
    }

    // build the Huffman tree with given string
    void buildTree(const string& s) {
        // Calculate frequencies of each character
        int freq[R];
        for (int i = 0; i < R; ++i) {
            freq[i] = 0;
        }

        for (int i = 0; i < s.length(); ++i) {
            freq[s[i]]++;
        }

        // initialze priority queue with singleton trees
        PriorityQueue pq;
        for (int i = 0; i < R; i++) {
            if (freq[i]) {
                Node* node = new Node(i, freq[i]);
                treeNodes.push_back(node);
                pq.push(node);
            }
        }
        // merge two smallest trees
        while (pq.size() > 1) {
            Node* left  = pq.top();
            pq.pop();
            Node* right = pq.top();
            pq.pop();
            //if (left->getChar() == '*') swap(right, left);
            Node* parent = new Node('*', left->getFrequency() + right->getFrequency(), left, right);
            pq.push(parent);
            treeNodes.push_back(parent);
        }
        root = pq.top();
        pq.pop();
        codes.resize(R, string(""));
        string str;
        buildCode(root, str);
    }


    void serialize() {
        serializeHelper(root);
    }

};



#endif