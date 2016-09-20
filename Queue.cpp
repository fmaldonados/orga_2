#include "Node.h"
#include "Queue.h"
#include <string>
using std::stringstream;
#include <sstream>
using std::string;

Queue::Queue(){
}

Queue::~Queue(){
}

Queue::Queue(int value){
	Node* nodo = new Node(value);
	head = nodo;
}

void Queue::queue(int value){
	Node* nodo = new Node(value);
	if (head != NULL && top != NULL){
		top->setNext(nodo);
		top = top->getNext();	
	}else{
		head = nodo;
		top = nodo;
	}
}

int Queue::dequeue(){
	int value = head->getValue();
	head = head->getNext();
	return value;
}

int Queue::peek(){
	return head->getValue();
}
