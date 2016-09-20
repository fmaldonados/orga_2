#pragma once
#include <string>
using std::string;
#include "Node.h"

class Queue{
	public:
		Node *top;
		Node *head; 
		Queue();
		~Queue();
		Queue(int);
		bool isEmpty();
		void queue(int);
		int dequeue();
		int peek();	
};
