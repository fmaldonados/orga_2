#ifndef NODO_AVL_H
#define NODO_AVL_H
#include<vector>
class nodo_avl
{
public:
	int valor;
	int level;
	nodo_avl* right_son;
	nodo_avl* left_son;
	nodo_avl* father;
	int nivel;
	

	nodo_avl();
	nodo_avl(int);
	int  getvalue();
	nodo_avl getParent();
	void setParent(nodo_avl*);
	void setRight_son(nodo_avl*);
	void setLeft_son(nodo_avl*);
	nodo_avl getRight_son();
	nodo_avl getLeft_son();
	bool Right_son();
	bool Left_son();
};

	
#endif		
