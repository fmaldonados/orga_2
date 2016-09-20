#pragma once

#include <string>
#include <sstream>

using namespace std;
using std::stringstream;
using std::string;

class nodo{
	public:
		int value;
		nodo* leftBrother;
		nodo* rightBrother;
		nodo* leftSon;
		nodo* rightSon;
		nodo* leftParent;
		nodo* rightParent;
	
		nodo();
		nodo(int valor);
		nodo(int valor, nodo* pd, nodo* pi);
		~nodo();
		nodo* get_leftBrother();
		nodo* get_rightBrother();
		void set_leftBrother(nodo* leftBrother);
		void set_RightBrother(nodo* RightBrother);
		bool hasLeftBrother();
		bool hasRightBrother();

		nodo* get_leftSon();
		nodo* get_rightSon();
		void set_leftSon(nodo* leftSon);
		void set_RightSon(nodo* Rightson);
		bool hasLeftSon();
		bool hasRightSon();

		nodo* get_leftParent();
		nodo* get_rightParent();
		void set_leftParent(nodo* leftParent);
		void set_RightParent(nodo* RightParent);
		bool hasLeftParent();
		bool hasRightParent();

		int getValue();
		void setValue(int value);
		
};

