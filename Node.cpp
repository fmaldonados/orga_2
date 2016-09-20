#include "Node.h"
#include <string>
using std::stringstream;
#include <sstream>
using std::string;

Node::Node(){
}

Node::~Node(){
}

Node::Node(int value):value(value),next(NULL){
}

bool Node::hasNext(){
	return next != NULL;
}

int Node::getValue(){
	return value;
}

void Node::setValue(int value){
	this->value = value;
}	

Node* Node::getNext(){
	return this->next;
}

void Node::setNext(Node* nodo){
	this->next = nodo;
}

string Node::toString()const{
	stringstream ss;
	ss<<value;
	return ss.str();
}
