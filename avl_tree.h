#ifndef AVL_TREE_H
#define AVL_TREE_H
#include "nodo_avl.h"

class avl_tree
{
public:
	nodo_avl* root;
       
        
	avl_tree();
	avl_tree(int);
	nodo_avl getroot();
	void insert(int);
	void erase(int,int,int);
	nodo_avl* dih(nodo_avl* nodo);
	void Ix2(nodo_avl* nodo);
	void Dx2(nodo_avl* nodo);
	void I(nodo_avl* nodo);
	void D(nodo_avl* nodo);
	void Balanceado(nodo_avl* , bool, bool , int );
	void preorden( nodo_avl*, int);
	int get_parent(nodo_avl*,int );

};

	
#endif		
