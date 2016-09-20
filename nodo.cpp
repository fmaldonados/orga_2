#include <iostream>
#include "nodo.h"
using std::cin;
using std::cout;
using std::endl;
nodo::nodo(){
}
nodo::nodo(int value){
	this->value = value;
}
nodo::nodo(int valor, nodo* pd, nodo* pi){
	this->value = valor;
	this->rightParent = pd;
	this->leftParent = pi;
}
nodo::~nodo(){
}

nodo* nodo::get_leftBrother(){
	return leftBrother;
}
nodo* nodo::get_rightBrother(){
	return rightBrother;
}
void nodo::set_leftBrother(nodo* leftBrother){
	this->leftBrother= leftBrother;
}
void nodo::set_RightBrother(nodo* RightBrother){
	this->rightBrother=RightBrother;
}
bool nodo::hasLeftBrother(){
	if (leftBrother==NULL){
		return false;
	}else{
		return true;
	}
}
bool nodo::hasRightBrother(){
	if (rightBrother==NULL){
		return false;
	}else{
		return true;
	}
}

nodo* nodo::get_leftSon(){
	return leftSon;
}
nodo* nodo::get_rightSon(){
	return rightSon;
}
void nodo::set_leftSon(nodo* leftSon){

	this->leftSon= leftSon;
}
void nodo::set_RightSon(nodo* RightSon){
	this->rightSon=RightSon;
}
bool nodo::hasLeftSon(){
	if (leftSon==NULL){
		return false;
	}else{
		return true;
	}
}
bool nodo::hasRightSon(){
	if (rightSon==NULL){
		return false;
	}else{
		return true;
	}
}

nodo* nodo::get_leftParent(){
	return leftParent;
}
nodo* nodo::get_rightParent(){
	return rightParent;
}
void nodo::set_leftParent(nodo* leftParent){
	this->leftParent= leftParent;
}
void nodo::set_RightParent(nodo* RightParent){
	this->rightParent=RightParent;
}
bool nodo::hasLeftParent(){
	if (leftParent==NULL){
		return false;
	}else{
		return true;
	}
}
bool nodo::hasRightParent(){
	if (rightParent==NULL){
		return false;
	}else{
		return true;
	}
}

int nodo::getValue(){
	return value;
}
void nodo::setValue(int value){
	this->value = value;
}

