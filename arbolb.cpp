#include "arbolb.h"
#include "nodo.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;

arbolb::arbolb(){
}
arbolb::arbolb(nodo* raiz,int node_size){
	this->raiz = raiz;
	this->node_size=node_size;
}
arbolb::~arbolb(){
}

//------------------------------------------------------------------------------------------------------------
int arbolb::getHeight(){
	return height;
}
void arbolb::setHeight(int h){
	this-> height= height;
}
int arbolb::getNodeSize(){
	return node_size;
}
void arbolb::setNodeSize(int size){
	this->node_size = node_size;
}
nodo* arbolb::getRaiz(){
	raiz = this-> getLefter(raiz);
	/*if (raiz->hasRightParent()){
		return getLefter(raiz->get_rightParent());
	}else{

		if(raiz->hasLeftParent()){
			return getLefter(raiz->get_leftParent());
		}else{
			return raiz;
		}
	}
	*/
	return raiz;
}
nodo* arbolb::getRaiz_d(nodo* n){
	nodo* temp = this-> getLefter(n);
	if (temp->hasRightParent()){
		temp = getLefter(temp->get_rightParent());
		getRaiz_d(temp);
	}else{
		if(temp->hasLeftParent()){
			temp = getLefter(temp->get_leftParent());
			getRaiz_d(temp);
		}
	}

	return raiz;
}
void arbolb::setRaiz(nodo* raiz){
	this->raiz = raiz;
}


//--------------------------------------------------------------------------------------------------------------
bool arbolb::levelFull(nodo* nodito){
	if (this->nodeCount(this->getLefter(nodito))==node_size){
		return true;
	}else{
		return false;
	}
}
int arbolb::nodeCount(nodo* nodito){
	int cont=0;
	if (nodito==NULL){
		return cont;
	}else{
		while(nodito->hasRightBrother()){
			cont++;
			nodito = nodito->get_rightBrother();
		}
		cont++;
		return cont;
	}
}
nodo* arbolb::getLefter(nodo* nodito){
	nodo* temp = nodito;
	if (!nodito->hasLeftBrother()){
		return nodito;
	}else{
		while(temp->hasLeftBrother()){
				temp = temp->get_leftBrother();
		}
		return temp;
	}
}
nodo* arbolb::getRighter(nodo* nodito){
	nodo* temp = nodito;
	if (!nodito->hasRightBrother()){
		return nodito;
	}else{
		while(temp->hasRightBrother()){
				temp = temp->get_rightBrother();
		}
		return temp;
	}
}
void arbolb::addFinal(int valor,nodo* temp){
	temp= this->getLefter(temp);
	nodo* pd =temp->get_rightParent();
	nodo* pi =temp->get_leftBrother();
	if(this->getRaiz()){
		if (temp->getValue()>valor){
			temp->set_leftBrother(new nodo(valor));
			nodo* temp2 = temp->get_leftBrother();
			temp2->set_RightBrother(temp);
			
		}else{
			if (temp->hasRightBrother()){
				while(temp->hasRightBrother()){
					if (temp->get_rightBrother()->getValue()<valor){
						temp= temp->get_rightBrother();
					}else{
						break;
					}
				
				}
				nodo*temp2 = temp->get_rightBrother();
				nodo*temp3 = temp;
				temp->set_RightBrother(new nodo(valor));
				temp = temp->get_rightBrother();
				temp->set_RightBrother(temp2);
				temp->set_leftBrother(temp3);
				
			}else{
				while(temp->hasRightBrother()){
					temp= temp->get_rightBrother();
				}
				temp->set_RightBrother(new nodo(valor));
				nodo* temp2 = temp->get_rightBrother();
				temp2->set_leftBrother(temp);
				
			}
		}
	}else{
		this->setRaiz(new nodo(valor));
	}

}
void arbolb::addNode(nodo* h_lista, int insertado){
	if (this->levelFull(h_lista) && !h_lista->hasLeftSon()){
		this->addFinal(insertado,h_lista);
		nodo*temp=this->getLefter(h_lista);
		if ((node_size)%2==0){
			for (int i = 0; i <(node_size)/2; ++i){		
				temp= temp->get_rightBrother();
			}
		}else{
			for (int i = 0; i <= (node_size)/2 ; ++i){
				temp= temp->get_rightBrother();
			}
		}
		overflow(temp,h_lista);
		
	}else{
		if (h_lista->hasLeftSon()){
			nodo*temp= h_lista;
			while(temp->getValue()<insertado && temp->hasRightBrother()){
				temp = temp->get_rightBrother(); 
			}

			if (temp->getValue()>insertado){
				this->addNode(temp->get_leftSon(),insertado);
			}else{
				this->addNode(temp->get_rightSon(),insertado);
			}
		}else{
				this->addFinal(insertado,h_lista);
		}
	}
}

void arbolb::imprimirNivel(nodo* nodito){
	nodo*temp = this->getLefter(nodito);
	cout<< "|" <<temp->getValue()<<"|";
	while(temp->hasRightBrother()){
		temp=temp->get_rightBrother();
		cout<<temp->getValue()<<"|";
	}
}
nodo* arbolb::getpi(nodo* nodito){
	nodito = this->getLefter(nodito);
	while(!nodito->hasLeftParent()){
		nodito= nodito->get_rightBrother();
	}
	return nodito->get_leftParent();
}
nodo* arbolb::getpd(nodo* nodito){
	nodito = this->getLefter(nodito);
	while(!nodito->hasRightParent()){
		nodito= nodito->get_rightBrother();
	}
	return nodito->get_rightParent();
}
void arbolb::overflow(nodo* temp,nodo* h_lista){
			if (h_lista->hasLeftParent()){
				if (h_lista->hasRightParent()){
					if (this->levelFull(this->getpi(temp))){
						
						nodo*izquierdo = temp->get_leftBrother();
						nodo*derecho = temp->get_rightBrother();
						
						nodo* padre_i= this->getpi(temp);
						nodo* padre_d= this->getpd(temp);
						
						temp->set_leftSon(this->getLefter(temp));
						temp->set_RightSon(temp->get_rightBrother());
						temp->set_RightBrother(padre_d);
						temp->set_leftBrother(padre_i);
						temp->set_leftParent(NULL);
						temp->set_RightParent(NULL);

						this->getLefter(temp->get_leftSon())->set_leftParent(padre_i);
						izquierdo->set_RightBrother(NULL);
						izquierdo->set_RightParent(temp);

						derecho->set_leftParent(temp);
						derecho->set_leftBrother(NULL);
						derecho->set_RightParent(padre_d);
						
						padre_i->set_RightBrother(temp);
						padre_i->set_RightSon(izquierdo);

						padre_d->set_leftBrother(temp);
						padre_d->set_leftSon(derecho);
						
						nodo*temp2=raiz;
						
						
						if ((node_size)%2==0){
							for (int i = 0; i < (node_size)/2; ++i){		
								temp2= temp2->get_rightBrother();
							}
						}else{
							for (int i = 0; i <= (node_size)/2 ; ++i){
								temp2= temp2->get_rightBrother();
							}
						}
						
						overflow(temp2,temp);
						
						
					}else{
						nodo*izquierdo = temp->get_leftBrother();
						cout<<izquierdo->getValue();
						
						nodo*derecho = temp->get_rightBrother();
						
						nodo* padre_i= this->getpi(temp);
						nodo* padre_d= this->getpd(temp);
						
						temp->set_leftSon(this->getLefter(temp));
						temp->set_RightSon(temp->get_rightBrother());
						temp->set_RightBrother(padre_d);
						temp->set_leftBrother(padre_i);
						

						this->getLefter(temp->get_leftSon())->set_leftParent(padre_i);
						izquierdo->set_RightBrother(NULL);
						izquierdo->set_RightParent(temp);

						derecho->set_leftParent(temp);
						derecho->set_leftBrother(NULL);
						derecho->set_RightParent(padre_d);
						
						padre_i->set_RightBrother(temp);
						padre_i->set_RightSon(izquierdo);

						padre_d->set_leftBrother(temp);
						padre_d->set_leftSon(derecho);
						

						this->setRaiz(this->getLefter(temp));
					}
				}else{
					
					if (this->levelFull(this->getpi(temp))){
						nodo*izquierdo = temp->get_leftBrother();
						
						nodo*derecho = temp->get_rightBrother();
						nodo* padre_i= this->getpi(temp);
						
						temp->set_leftSon(this->getLefter(temp));
						temp->set_RightSon(temp->get_rightBrother());
						temp->set_RightBrother(NULL);
						temp->set_leftBrother(padre_i);
						temp->set_leftParent(NULL);

						this->getLefter(temp->get_leftSon())->set_leftParent(padre_i);
						izquierdo->set_RightBrother(NULL);
						izquierdo->set_RightParent(temp);

						derecho->set_leftParent(temp);
						derecho->set_leftBrother(NULL);
						derecho->set_RightParent(NULL);
						
						padre_i->set_RightBrother(temp);
						padre_i->set_RightSon(izquierdo);
						
						nodo*temp2=raiz;
						
						
						if ((node_size)%2==0){
							for (int i = 0; i < (node_size)/2; ++i){		
								temp2= temp2->get_rightBrother();
							}
						}else{
							for (int i = 0; i <= (node_size)/2 ; ++i){
								temp2= temp2->get_rightBrother();
							}
						}
						
						overflow(temp2,temp);
						
						
					}else{
						nodo*izquierdo = temp->get_leftBrother();
						
						nodo*derecho = temp->get_rightBrother();
						nodo* padre_i= this->getpi(temp);
						
						temp->set_leftSon(this->getLefter(temp));
						temp->set_RightSon(temp->get_rightBrother());
						temp->set_RightBrother(NULL);
						temp->set_leftBrother(padre_i);
						

						this->getLefter(temp->get_leftSon())->set_leftParent(padre_i);
						izquierdo->set_RightBrother(NULL);
						izquierdo->set_RightParent(temp);

						derecho->set_leftParent(temp);
						derecho->set_leftBrother(NULL);
						derecho->set_RightParent(NULL);
						
						padre_i->set_RightBrother(temp);
						padre_i->set_RightSon(izquierdo);
						
						this->setRaiz(this->getLefter(temp));
						
					}
					
					
				}
			}else{
				if (h_lista->hasRightParent()){
					
					if (this->levelFull(this->getpd(temp))){
						nodo*izquierdo = temp->get_leftBrother();
						
						nodo*derecho = temp->get_rightBrother();
						
						nodo* padre_d= this->getpd(temp);
						
						
						temp->set_leftSon(this->getLefter(temp));
						temp->set_RightSon(temp->get_rightBrother());
						temp->set_leftBrother(NULL);
						temp->set_RightBrother(padre_d);
						temp->set_RightParent(NULL);

						this->getLefter(temp->get_leftSon())->set_RightParent(temp);
						izquierdo->set_RightBrother(NULL);
						izquierdo->set_leftParent(NULL);

						derecho->set_leftParent(temp);
						derecho->set_leftBrother(NULL);
						derecho->set_RightParent(padre_d);

						padre_d->set_leftBrother(temp);
						padre_d->set_leftSon(derecho);
						
						nodo*temp2=this->getLefter(padre_d);
						
						if ((node_size)%2==0){
							for (int i = 0; i < (node_size)/2; ++i){		
								temp2= temp2->get_rightBrother();
							}
						}else{
							for (int i = 0; i <= (node_size)/2 ; ++i){
								temp2= temp2->get_rightBrother();
							}
						}

						overflow(temp2,temp);
						
					}else{
						nodo*izquierdo = temp->get_leftBrother();
						
						nodo*derecho = temp->get_rightBrother();
						
						nodo* padre_d= this->getpd(temp);
						
						
						temp->set_leftSon(this->getLefter(temp));
						temp->set_RightSon(temp->get_rightBrother());
						temp->set_leftBrother(NULL);
						temp->set_RightBrother(padre_d);
						temp->set_RightParent(NULL);

						this->getLefter(temp->get_leftSon())->set_RightParent(temp);
						izquierdo->set_RightBrother(NULL);
						izquierdo->set_leftParent(NULL);

						derecho->set_leftParent(temp);
						derecho->set_leftBrother(NULL);
						derecho->set_RightParent(padre_d);

						padre_d->set_leftBrother(temp);
						padre_d->set_leftSon(derecho);
						
						this->setRaiz(getLefter(temp));
					}
					
					
				}else{
					nodo*izquierdo = temp->get_leftBrother();
					nodo*derecho = temp->get_rightBrother();

					temp->set_leftSon(this->getLefter(temp));
					temp->set_RightSon(temp->get_rightBrother());
					temp->set_leftBrother(NULL);
					temp->set_RightBrother(NULL);

					getLefter(temp->get_leftSon())->set_RightParent(temp);
					izquierdo->set_RightBrother(NULL);
					izquierdo->set_leftParent(NULL);

					derecho->set_leftParent(temp);
					derecho->set_leftBrother(NULL);
					derecho->set_RightParent(NULL);

					this->setRaiz(getLefter(temp));
				}
			}
		//end overflow
}
nodo* arbolb::getNodo(nodo* nivel, int valor){
	nodo*temp= nivel;
	
	
	while(temp->getValue()<valor && temp->hasRightBrother()){
		temp = temp->get_rightBrother();
	}
	cout<< temp->getValue();
	
	if (temp->getValue() == valor){
		
		return temp;
	}else{
		if (temp->hasLeftSon()){
			if (temp->getValue()>valor){
				
				getNodo(temp->get_leftSon(),valor);
			}else{
				getNodo(temp->get_rightSon(),valor);
			}
			
		}else{
			return NULL;
		}
	}
}

string arbolb::imp_arbol(vector<nodo*> nodos){
	stringstream ss;
	for (int i = 0; i < nodos.size(); ++i){
		ss<<"|"<<nodos[i]->getValue()<<"|";
		//ss<< s_Nivel(nodos[i]);
	}
	if (nodos[0]->hasLeftSon()){
		vector<nodo*> nodos2;
		for (int i = 0; i < nodos.size(); ++i){
			nodos2.push_back(nodos[i]->get_leftSon());
			nodos2.push_back(nodos[i]->get_rightSon());
		}
		ss<<"\n" << imp_arbol(nodos2);
		return ss.str();
	}else{
		return ss.str() ;
	}
}

string arbolb::s_Nivel(nodo* nodito){
	stringstream ss;
	nodo*temp = this->getLefter(nodito);
	ss<< "|" <<temp->getValue()<<"|";
	while(temp->hasRightBrother()){
		temp=temp->get_rightBrother();
		ss<<temp->getValue()<<"|";
	}
	return ss.str();
}