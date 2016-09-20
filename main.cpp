#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "nodo.h"
#include "arbolb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::stringstream;
using std::string;

int main(int argc, char const *argv[]){
	nodo* prueba= new nodo(1);
	
	arbolb arbolito(prueba,2);

	
	
	//arbolito.addNode(arbolito.getRaiz(),1);
	/*arbolito.addNode(arbolito.getRaiz(),90);
	arbolito.addNode(arbolito.getRaiz(),16);
	arbolito.addNode(arbolito.getRaiz(),4);
	arbolito.addNode(arbolito.getRaiz(),7);
	//arbolito.addNode(arbolito.getRaiz(),91);
	//arbolito.addNode(arbolito.getRaiz(),22);
	//arbolito.addNode(arbolito.getRaiz(),11);
	//arbolito.addNode(arbolito.getRaiz(),92);
	//arbolito.addNode(arbolito.getRaiz(),94);
	*/
	for (int i = 2; i <= 10; ++i){
		arbolito.addNode(arbolito.getRaiz(),i);
	}
	//cout<<arbolito.getRaiz()->get_leftParent()->getValue();
	//arbolito.getNodo(arbolito.getRaiz(),11);
	//cout<<arbolito.getRaiz()->get_leftSon()->get_leftBrother()->getValue();
	//cout<<"numero de nodos:"<<arbolito.nodeCount(arbolito.getRaiz())<<endl;
	
	
	//cout<<"\t"<<"\t"<<"\t";
	arbolito.imprimirNivel(arbolito.getRaiz());
	cout<<endl;
	//arbolito.imprimirNivel(arbolito.getRaiz()->get_rightSon()->get_leftSon());
	//arbolito.imprimirNivel(arbolito.getRaiz()->get_leftSon());
	//cout<<"\t"<<"\t"<<"\t";
	//arbolito.imprimirNivel(arbolito.getRaiz()->get_rightSon());
	//cout<<endl;
	//cout<<endl;
	//cout<<"\t"<<"\t"<<"\t";
	//arbolito.imprimirNivel(arbolito.getRaiz()->get_rightBrother()->get_rightSon());
	//arbolito.imprimirNivel(arbolito.getRaiz()->get_leftSon()->get_rightSon());
	//cout<< endl;
	//arbolito.imprimirNivel(arbolito.getRaiz()->get_rightBrother()->get_rightBrother()->get_rightSon());
	//cout<<arbolito.getRaiz()->get_leftBrother()->get_rightSon()->getValue();
	//arbolito.getRaiz()->getValue();
	//vector<nodo*>nodos;
	
	/*nodo* temp = arbolito.getRaiz();
    nodos.push_back(temp);
	while(temp->hasRightBrother()){
		temp= temp->get_rightBrother();
		nodos.push_back(temp);
	}
	
	//cout<<arbolito.imp_arbol(nodos);
	*/
	cout<<endl;
	return 0;
}