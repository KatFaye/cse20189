//mainTree.cpp
//Author: Kat Herring


#include <vector>
#include <iostream>
#include <string>
using namespace std;

#include "BinaryTree.h"   // include custom linked list library

int main(int argc, char *argv[]) {

	Node *node;

  	BinaryTree tree(10, "tree.txt");  // define templated list

  	cout << endl << "inOrder Traversal: " << endl << endl;
  	tree.inOrder();
  
  	cout << endl << "preOrder Traversal: " << endl << endl;
  	tree.preOrder();

  	cout << endl << "postOrder Traversal: " << endl << endl;
  	tree.postOrder();

  	cout << endl << "Searching for '3'..." << endl << endl;
  	node = tree.Search(3);
  	cout << "Label: " << node->getLabel() << endl;

}

 