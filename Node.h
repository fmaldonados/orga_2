#pragma once
#include <string>
using std::string;

class Node{
	public:
		int value;
		Node *next;
		Node();
		~Node();
		Node(int);
		bool hasNext();
		int getValue();
		void setValue(int);
		Node* getNext();
		void setNext(Node* next);
		virtual string toString()const;
};
