#pragma once
#include "nodo.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class arbolb{
	public:
		int height;
		int node_size;
		nodo* raiz;
	
		arbolb();
		arbolb(nodo* raiz, int node_size);
		~arbolb();
		int getHeight();
		void setHeight(int h);
		int getNodeSize();
		nodo* getRaiz();

		void setRaiz(nodo* raiz);

		void setNodeSize(int size);
		bool levelFull(nodo* nodito);
		void addNode(nodo* h_lista, int insertado);
		int nodeCount(nodo* nodito);
		void addFinal(int valor, nodo* head);
		nodo* getLefter(nodo* nodito);
		nodo* getRighter(nodo* nodito);
		void imprimirNivel(nodo* nodito);
		nodo* getpi(nodo* nodito);
		nodo* getpd(nodo* nodito);
		void overflow(nodo* temp, nodo* h_lista);
		nodo* getNodo(nodo* nivel, int valor);
		string imp_arbol(vector<nodo*> nodos);
		string s_Nivel(nodo* nodito);
		nodo* getRaiz_d(nodo* n);
};
