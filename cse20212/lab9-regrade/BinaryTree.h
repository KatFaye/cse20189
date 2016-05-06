#ifndef _BinaryTree_H_
#define _BinaryTree_H_

#include "Node.h"     // contains the node information
#include <iostream>   // for using cout
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;

class BinaryTree {
 public:
  BinaryTree(int, string);    // constructor
  ~BinaryTree();   // deconstructor
  void loadData();
  void ClearTree(Node *);
  bool Insert(Node *);
  bool Insert(string, int);

  Node * Search(int);
  void inOrder();
  void inOrder(Node *);
  void preOrder();
  void preOrder(Node *);
  void postOrder();
  void postOrder(Node *);

 private:
  int numLevels;
  string file;
  Node *root;                // first element in the list
  Node *newNode();   // helper function; creates a new node
};

//to figure number of levels; int(ceil(log2(n)))
// constructor (empty body)
BinaryTree::BinaryTree(int n, string f) { 
  file = f;
  numLevels = int(ceil(log2(n)));
  root = NULL;
  loadData();
}

// destructor
BinaryTree::~BinaryTree() {
  ClearTree(root);
  
}
void BinaryTree::loadData() {
  ifstream f(file.c_str());

  string line, label;
  int data;
  Node * newNode;

  while(f.good()) {
    if(f.is_open()) {
      getline(f, line);
      istringstream is(line);
      is >> label >> data;
      //cout << label << " " << data << endl;

      //newNode = new Node(label, data);

      Insert(label, data); //adds data to 
    }
  }
  f.close();

//makeTree(0, root);

}
void BinaryTree::ClearTree(Node *node) {
  if (node==NULL)
    return; //tree empty
  else if(node->getLeft() != NULL)
    ClearTree(node->getLeft());
  if(node->getRight() != NULL) 
    ClearTree(node->getRight());
  delete node;
  return;
}
bool BinaryTree::Insert(Node *newNode) {
  Node *temp;
  Node *back;

  temp = root;
  back = NULL;

  while(temp != NULL) {
    back = temp;
    if(newNode->getData() < temp->getData()) {
      temp = temp->getLeft();
    } else {
      temp = temp->getRight();
    }
  }
  //add new node
  if(back == NULL) {
    root = newNode;
  } else {
    if(newNode->getData() < back->getData()) {
      back->setLeft(newNode);
    } else {
      back->setRight(newNode);
    }
  }
  return true;
}
bool BinaryTree::Insert(string label, int data) {
  Node *newNode;

  //create new node
  newNode = new Node();
  newNode->setData(data);
  newNode->setLabel(label);

  return(Insert(newNode)); //add node to tree
}
Node * BinaryTree::Search(int data) {
  bool foundValue = false;
  Node * temp;

  temp = root;
  while((temp!=NULL)&&(temp->getData()!=data)) {
    if(data < temp->getData()) {
      temp = temp->getLeft();
    } else {
      temp = temp->getRight();
    }
  }
  return temp;
}
void BinaryTree::inOrder() {
  inOrder(root);
}
void BinaryTree::inOrder(Node *node) {
  if(node != NULL) {
    inOrder(node->getLeft());
    node->print();
    inOrder(node->getRight());
  }
}
void BinaryTree::preOrder() {
  preOrder(root);
}
void BinaryTree::preOrder(Node *node) {
  if(node) {
    node->print();
    preOrder(node->getLeft());
    preOrder(node->getRight());
  }
}
void BinaryTree::postOrder() {
  postOrder(root);
}
void BinaryTree::postOrder(Node *node) {
  if(node) {
    preOrder(node->getLeft());
    preOrder(node->getRight());
    node->print();
  }
}
#endif