#ifndef _NODE_H_
#define _NODE_H_

#include <string>

class BinaryTree; // forward declaration of List

class Node {

  friend class BinaryTree;    // make the main class a friend

 public:
 	Node();
	Node(const string &, const int &);     // constructor
	void setNode(int);
	int getData();
	void setRight(Node *);
	void setLeft(Node *);
	Node * getLeft();
	Node * getRight();
	string getLabel();
	void setLabel(string);
	void setData(int);
	void print();


 private:
  int data;  // data for linked list node
  string label;  
  Node *right; // right child
  Node *left; //left child
};

Node::Node() { //default constructor
	data = 0;
	label = ' ';
	left = NULL;
	right = NULL;
}
// constructor, using member initialization list syntax
Node::Node(const string &l, const int &info) :label(l),data(info),left(NULL),right(NULL) {}

// simple get function for our class (if friendship is not used)
void Node::setNode(int val) {
	if (right->data > left->data) {
		//right larger value
		data = right->data;
		label = right->label;
	} else {
		data = left->data;
		label = left->label;
	}
}
int Node::getData() {
	return data;
}
void Node::setLeft(Node * Left) {
	left = Left;
}
void Node::setRight(Node * Right) {
	right = Right;
}
Node * Node::getRight() {
	return right;
}
Node * Node::getLeft() {
	return left;
}
void Node::setData(int Data) {
	data = Data;
}
string Node::getLabel() {
	return label;
}
void Node::setLabel(string Label) {
	label = Label;
}
void Node::print() {
	cout << "Data: " << data << "; Label: " << label << endl;
}
#endif