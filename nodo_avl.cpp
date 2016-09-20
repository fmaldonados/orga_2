#include "nodo_avl.h"
#include <iostream>
#include <vector>


nodo_avl::nodo_avl(){	

}
nodo_avl::nodo_avl(int numero){	
	this->valor= numero;
	this->right_son= NULL;
	this->left_son= NULL;
	this->father=NULL;
	this->level=0;
	this->nivel=0;
	
	
}
int nodo_avl::getvalue(){
	return valor;		
}

nodo_avl nodo_avl::getParent(){
	return *father;
}
void nodo_avl::setParent(nodo_avl* padre){
	 father=padre;
}
void nodo_avl::setRight_son(nodo_avl* derecho){
	right_son=derecho;		
}
void nodo_avl::setLeft_son(nodo_avl* izquierdo){
	left_son=izquierdo;		
}

nodo_avl nodo_avl::getRight_son(){
	return *right_son;
}

nodo_avl nodo_avl::getLeft_son(){
	return *left_son;
}
bool nodo_avl::Right_son(){
	if(right_son==NULL){
		return false;			
	}else{
		return true;
	}
}
bool nodo_avl::Left_son(){
	if(left_son==NULL){
		return false;			
	}else{
		return true;
	}
}
