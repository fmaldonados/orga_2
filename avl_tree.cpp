#include "avl_tree.h"
#include <iostream>
using std::cout;
using std::endl;

avl_tree::avl_tree(){	

}
avl_tree::avl_tree(int val){	
	this -> root = new nodo_avl(val);
}

nodo_avl avl_tree::getroot(){
	return *root;
}
void avl_tree::insert(int value) {
	int bandera=0;
	nodo_avl* nuevo = new nodo_avl(value);        
	nodo_avl* temporal=root;
	while (bandera==0){
		if(root->valor != 0){
			if(root->right_son==NULL && root->left_son==NULL){
		
				if(root->valor <value){
					root->right_son=nuevo;	
					nuevo->father=root;
					
					bool seguir = true;
					bool uno_mas = true;
					int side = 1;
				        Balanceado(root, seguir, uno_mas,side);	
				}else{
					root->left_son=nuevo;							
					nuevo->father=root;			
					bool seguir = true;
					bool uno_mas = true;
					int side = 0;
					Balanceado(root, seguir, uno_mas,side);	
				}
				cout<<"que pepes"<<endl;
				bandera=1;
			
					
			}else{
				cout<<"que pepes"<<endl;
				if(temporal->valor <value){
					if(temporal->right_son !=NULL){
						temporal=temporal->right_son;
									
					}else{
						nuevo->father=temporal;
						temporal->right_son=nuevo;	
						bool seguir = true;
						bool uno_mas = true;
						int side = 1;
						cout<<"tempppppp"<<temporal->valor<<endl;
						Balanceado(temporal, seguir, uno_mas,side);		
						bandera=1;		
					}			
				}else{
					if(temporal->left_son !=NULL){
					
						temporal=temporal->left_son;
									
					}else{
						nuevo->father=temporal;
						temporal->left_son=nuevo;
						bool seguir = true;
						bool uno_mas = true;
						int side = 0;
						cout<<"tempppppp"<<temporal->valor<<endl;
						Balanceado(temporal, seguir, uno_mas,side);	
						bandera=1;					
					}	
							
				}
				cout<<"los"<<endl;
			}
		}else if(root->valor == 0){
			root = new nodo_avl(value);
			bandera=1;
		
		}	
	}	
}
void avl_tree::erase(int eliminar,int todos,int recursivo){
	nodo_avl* eliminado= root;
	int sigue=0;
	int lo_encontro=0;
	if(recursivo==0){
		while(eliminar != eliminado->valor && sigue<todos){
			sigue++;
			if(eliminar>eliminado->valor){
				if(eliminado->right_son !=NULL){
					eliminado=eliminado->right_son;
				}
			}else{
				if(eliminado->left_son !=NULL){
					eliminado=eliminado->left_son;
				}			
			}
		}	
	}else{
		while(sigue <todos  && lo_encontro<2){
			sigue++;
			if(eliminar>=eliminado->valor){
				if(eliminado->valor ==eliminar){
					lo_encontro++;				
				}
				if(eliminado->right_son !=NULL){
					eliminado=eliminado->right_son;
				}
			}else{
				if(eliminado->valor ==eliminar){
					lo_encontro++;				
				}
				if(eliminado->left_son !=NULL){
					eliminado=eliminado->left_son;
				}		
			}
		}		
	}
	bool izquierdo;
	if(eliminado->left_son==NULL){
		izquierdo=false;
	}else{
		izquierdo=true;		
	}
	bool derecho;
	if(eliminado->right_son==NULL){
		derecho=false;
	}else{
		derecho=true;		
	}

	if(izquierdo==false && derecho==false){
		nodo_avl* pad=eliminado->father;
		if(eliminar>pad->valor){
			pad->right_son=NULL;
			eliminado->father=NULL;
			bool seguir = true;
			bool uno_mas = true;
			int side = 1;
			//Balanceado(pad, seguir,uno_mas,side);	
					
		}else{
			pad->left_son=NULL;
			eliminado->father=NULL;
			bool seguir = true;
			bool uno_mas = true;
			int side = 0;
			//Balanceado(pad, seguir,uno_mas,side);	
		}	
	}else if( (izquierdo==true && derecho==false) || (izquierdo==false && derecho==true) ){
		nodo_avl* pad;
		if(eliminado->father !=NULL){
			pad=eliminado->father;		
		}else{
			pad=NULL;
		}
		if((izquierdo==true && derecho==false && pad !=NULL)){
			
			if((pad->left_son)->valor ==eliminar){
				pad->left_son=eliminado->left_son;
				(eliminado->left_son)->father=pad;			
				bool seguir = true;
				bool uno_mas = false;
				int side = 0;
				Balanceado(pad, seguir,uno_mas,side);	
			}else if((pad->right_son)->valor ==eliminar){
				pad->right_son=eliminado->left_son;		
				(eliminado->left_son)->father=pad;	
				bool seguir = true;
				bool uno_mas = false;
				int side = 1;
				Balanceado(pad, seguir,uno_mas,side);
			}
		}else if((izquierdo==false && derecho==true && pad != NULL)){
			
				nodo_avl* pad=eliminado->father;
				if((pad->left_son)->valor ==eliminar){
					(eliminado->right_son)->father=pad;						
					pad->left_son=eliminado->right_son;
					bool seguir = true;
					bool uno_mas = false;
					int side = 0;
					Balanceado(pad, seguir,uno_mas,side);
						
				}else if((pad->right_son)->valor ==eliminar){
					(eliminado->right_son)->father=pad;
					pad->right_son=eliminado->right_son;		
					bool seguir = true;
					bool uno_mas = false;
					int side = 1;
					Balanceado(pad, seguir,uno_mas,side);					
				}

		}else if(eliminado->left_son !=NULL && eliminado->right_son ==NULL && eliminado->father==NULL){
			pad= pad -> left_son;
			pad-> father=NULL;

			bool seguir = true;
			bool uno_mas = false;
			int side = 0;
			Balanceado(pad, seguir,uno_mas,side);
		}else if(eliminado->left_son==NULL && eliminado->right_son != NULL  && eliminado->father==NULL){
			pad= pad -> right_son;
			pad-> father=NULL;
			bool seguir = true;
			bool uno_mas = false;
			int side = 1;
			Balanceado(pad, seguir,uno_mas,side);
		}		
		
	}else if((izquierdo==true && derecho==true)){
		nodo_avl* nuevo=dih(eliminado->right_son);	
		eliminado->valor=nuevo->valor;
		erase(nuevo->valor,todos,1);
	}
}
nodo_avl* avl_tree::dih(nodo_avl* nodo){
	if(nodo->left_son != NULL){
		nodo= nodo->left_son;
		return dih(nodo);
	}else{	
	
	}
	return nodo;
}



void avl_tree::Balanceado(nodo_avl* nodo, bool seguir, bool uno_mas, int side){
	cout<<"auchhhhh"<<endl;
	seguir = true;	
	while(nodo && seguir){
		if (uno_mas == true){
			if (side == 0){
				nodo -> level= nodo->level - 1;
			}else{
				nodo -> level= nodo->level + 1;
			}
		}else{
			if (side == 0){
				nodo -> level= nodo->level +1;
			}else{
				nodo -> level= nodo->level - 1;
			}
		}
		if (nodo->level == 0){
			seguir = false;
		}else if(nodo -> level == -2){
			if ((nodo ->left_son) ->level == 1){
				cout<<"entre en d2"<<endl;
				Dx2(nodo);
			}else{
				D(nodo);
				cout<<"entre en d"<<endl;
			}

			seguir = false;
		}else if(nodo ->level == 2){
			if ((nodo->right_son) -> level == -1){
				cout<<"entre en I2"<<endl;
				Ix2(nodo);
			}else{
				cout<<"entre en I"<<endl;
				I(nodo);
			}

			seguir = false;
		}

		if (nodo -> father){
			if ((nodo ->father) -> right_son == nodo){
				side = 1;
			}else{
				side = 0;
			}
		}

		nodo = nodo ->father;
	}
}
void avl_tree::I(nodo_avl* nodo){
	cout<<"entro aqui i"<<endl;
	nodo_avl* pad = nodo -> father;
	nodo_avl* son = nodo;
	nodo_avl* leftson = son ->right_son;
	nodo_avl* grandson = leftson ->left_son;

	if(pad!= NULL){
		if((pad ->right_son) == son){
			pad ->right_son=(leftson);
		}else{
			pad->left_son=leftson;
			
		}
	}else{
		root=leftson;
	}	

	son ->right_son=grandson;

	leftson->left_son=son;
	son -> father= leftson;
	

	if(grandson){
		grandson -> father= son;
	}
	leftson -> father=pad;
	son ->level=0;
	leftson -> level=0;
}

void avl_tree::D(nodo_avl* nodo){
	cout<<"entro aqui d"<<endl;
	nodo_avl* pad = nodo ->father;
	
	nodo_avl* son = nodo;
	nodo_avl* leftson = son -> left_son;
	nodo_avl* grandson = leftson -> right_son;

	if(pad){
		if((pad ->right_son) == son){
			pad -> right_son=leftson;
		}else{
			pad -> left_son=leftson;
		}
	}else{
		root =leftson;
	}
	son -> left_son=grandson;
	leftson->right_son=son;
	son -> father=leftson;
	if(grandson){
		grandson -> father=son;
	}
	leftson -> father=pad;
	son -> level=0;
	leftson -> level=0;
}

void avl_tree::Dx2(nodo_avl* nodo){
	cout<<"entro aqui D2"<<endl;
	nodo_avl* pad = nodo -> father;
	nodo_avl* son = nodo;
	nodo_avl* leftson =son -> left_son;
	nodo_avl* grandson = leftson -> right_son;
	nodo_avl* left = grandson -> left_son;
	nodo_avl* right = grandson -> right_son; 

	if(pad){
		if(pad ->right_son == nodo){
			pad -> right_son=grandson;
		}else{
			pad -> left_son=grandson;
		}
	}else{
		root = grandson;
	}

	leftson -> right_son=left;
	son->left_son=right;
	grandson -> left_son= leftson;
	grandson -> right_son=son;
	grandson -> father=pad;
	son ->father=leftson;
	leftson -> father=grandson;

	if(left){
		left ->father=left;
	}

	if(right){
		right-> father=son;
	}

	if(grandson -> level == -1){
		leftson -> level=0;
		son -> level=1;
	}else if(grandson -> level == 0){
		leftson -> level=0;
		son -> level=0;
	}else if(grandson -> level == 1){
		leftson -> level=-1;
		son -> level=0;
	}
	cout<<(root)->valor<<endl;
	cout<<(root)->left_son->valor<<endl;
}

void avl_tree::Ix2(nodo_avl* nodo){
	cout<<"entro aqui i2"<<endl;
	nodo_avl* pad = nodo -> father;
	nodo_avl* son = nodo;
	nodo_avl* leftson =son -> right_son;
	nodo_avl* grandson = leftson -> left_son;
	nodo_avl* left = grandson -> left_son;
	nodo_avl* right = grandson -> right_son; 
	
	if(pad){
		if(pad -> right_son == nodo){
			pad -> right_son=grandson;
		}else{
			pad -> left_son=grandson;
		}
	}else{
		root = grandson;
	}


	leftson -> left_son=left;
	son -> right_son=right;
	grandson -> left_son=son;
	grandson -> right_son=leftson;
	
	grandson -> father=pad;
	son ->father=leftson;
	leftson -> father=grandson;

	if(left){
		left -> father=son;
	}

	if(right){
		right -> father=leftson;
	}

	if(grandson -> level == -1){
		leftson -> level=1;
		son -> level=0;
	}else if(grandson -> level == 0){
		leftson -> level=0;
		son -> level=0;
	}else if(grandson -> level == 1){
		leftson -> level=0;
		son -> level=-1;
	}
}



/*

int avl_tree::erase(int   eliminado, nodo_avl* rais){
	int bandera=0;
	nodo_avl* temporal=rais;
	while (bandera==0){
		cout<<"aaaa"<<endl;
		if(temporal->valor==eliminado){
			nodo_avl* pad=temporal->father;
			nodo_avl* pad2= pad->father;
			if(temporal->right_son==NULL && temporal->left_son==NULL){
				
				if(pad->valor<eliminado){
					pad->right_son=NULL;				
				}else{
					pad->left_son=NULL;
				}
				eliminar(0,pad,99999);
				return 8;
			}else if(temporal->right_son==NULL && temporal->left_son !=NULL){
				if(pad->valor<temporal->valor){
					pad->right_son=temporal->left_son;
					nodo_avl* este= temporal->left_son;
					este->father=pad;
					temporal->left_son=NULL;				
				}else{
					
					pad->left_son=temporal->left_son;
					nodo_avl* este= temporal->left_son;
					este->father=pad;
					temporal->left_son=NULL;
				}			
				eliminar(0,pad,99999);
				return 8;
			}else if(temporal->right_son!=NULL && temporal->left_son ==NULL){
				if(pad->valor<temporal->valor){
					
					pad->right_son=temporal->right_son;
					nodo_avl* este= temporal->right_son;
					este->father=pad;
					temporal->right_son=NULL;				
				}else{
					pad->left_son=temporal->right_son;
					nodo_avl* este= temporal->right_son;
					este->father=pad;
					temporal->right_son=NULL;
				}			
				eliminar(0,pad,99999);
				return 8;
			}else if(temporal->right_son!=NULL && temporal->left_son !=NULL){
				if((temporal->right_son)->right_son==NULL && (temporal->right_son)->left_son==NULL &&  (temporal->left_son)->right_son==NULL && (temporal->left_son)->right_son==NULL){
					if(pad->valor<temporal->valor){
						nodo_avl* este= temporal->left_son;
						este->right_son=temporal->right_son;
						pad->right_son=este;
			//			nodo_avl* este2= temporal->left_son;
						este->father=pad;
						temporal->left_son=NULL;				
					}else{
						nodo_avl* este= temporal->left_son;
						este->right_son=temporal->right_son;
						pad->left_son=este;
					//	nodo_avl* este2= temporal->left_son;
						este->father=pad;
						temporal->left_son=NULL;
					}
					eliminar(0,pad,99999);
					return 8;
				}else if((temporal->right_son)->right_son !=NULL && (temporal->right_son)->left_son==NULL){
					if(pad->valor<temporal->valor){
						nodo_avl* este= temporal->right_son;
						este->left_son=temporal->left_son;
						pad->right_son=este;
						//nodo_avl* este2= temporal->left_son;
						este->father=pad;
						temporal->left_son=NULL;				
					}else{
						nodo_avl* este= temporal->right_son;
						este->left_son=temporal->left_son;
						pad->left_son=este;
						nodo_avl* este2= temporal->left_son;
						este->father=pad;
						temporal->left_son=NULL;
					}
					eliminar(0,pad,99999);
					return 8;				
				}else if((temporal->right_son)->left_son !=NULL){
				
				}	
							
			}else{
				
			}
			bandera=1;
		}else{
			if(temporal->valor <eliminado){
				if(temporal->right_son !=NULL){
					temporal=temporal->right_son;				
				}		
			}else{
				if(temporal->left_son ==NULL){
					temporal=temporal->left_son;
				}	
			}
		}
			
	}	
}
void avl_tree::eliminar(int numero, nodo_avl*  passs, int val){
	if(numero==0){
		return; 
	}else{
		erase(numero,pas,val);
	}
}
/*

void avl_tree::ordenar(nodo_avl* comprobar){
	nodo_avl* padre=comprobar->father;
	
	
	nodo_avl* temporal=comprobar->left_son;
	nodo_avl* temporal2=comprobar->right_son;
	nodo_avl* temp=comprobar;
	if((comprobar->right_son != NULL && comprobar->left_son != NULL ) && (temporal->right_son != NULL && temporal->left_son != NULL ) && (temporal2->right_son=NULL && temporal2->left_son==NULL)){

		nodo_avl* izquierdo=temporal->left_son;
		nodo_alv* derecho=temporal->right_son;
		nodo_avl* pad=padre->right_son;
		pad->left_son=izquierdo;
                //aki
		padre->right_son==temporal;
		nodo_avl* nod=padre->right_son;
		nod->right_son=comprobar;
		comprobar->left_son=derecho;
		comprobar->right_son=temporal2;
		nodo_avl* nod3=padre->left_son;
		nod3->right_son=NULL;
		nod3_left_son==NULL;
					
	}	
}
 void rotacion_simple_derecha(){
}	
void rotacion_simple_izquierda(){
}
void rotacion_doble_derecha(){
}
void rotacion_doble_izquierda(){
}

*/
void avl_tree::preorden( nodo_avl* nodo, int num){
    
     if (nodo ==NULL ){
	  cout<<num<<endl;
	  return;
    }else{				
	 nodo->nivel=this->get_parent(nodo,0);
         preorden(nodo->left_son,num+1);
         preorden(nodo->right_son,num+1);
   }
}

int avl_tree::get_parent(nodo_avl* nodo,int num){
	if(nodo->father != NULL){
		num++;
		get_parent(nodo->father,num);
	}else{
		return num;
 	}
}
