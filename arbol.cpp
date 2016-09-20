#include<iostream>
#include"nodo_avl.h"
#include"avl_tree.h"
#include "nodo.h"
#include "arbolb.h"
#include<vector>
#include <string>
#include <ncurses.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<cstdlib>
#include<fstream>
#include<sstream>

using namespace std;

using std::vector;
using std::atoi;
using std::cout;
using std::cin;
using std::stringstream;



using std::endl;
int preorden( nodo_avl* , int);
int get_parent(nodo_avl* nodo,int num);
void preorden2( nodo_avl* nodo, int mas);
vector<nodo_avl*> nodes;
int cantidad;
int main(){
	avl_tree*  arbol= new avl_tree(0);
	nodo* prueba= new nodo(1);
	
	arbolb arbolito(prueba,3);

	initscr();
	start_color();
	int bandera = 1;
	init_pair(1,COLOR_WHITE, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	init_pair(2, COLOR_BLACK, COLOR_BLUE);
        init_pair(3, COLOR_RED, COLOR_BLUE);

	char seguir_jugando='1';
       	
	while(seguir_jugando=='1' || seguir_jugando=='2' || seguir_jugando=='3' || seguir_jugando=='4' || seguir_jugando=='5'){

			int contador=0;
			string num=" ";
			 char numero[10];
			attron(COLOR_PAIR(1));
			mvprintw(9,30,"1...... Agregar  ");
			mvprintw(10,30,"2...... eliminar  ");
			mvprintw(11,30,"3...... mostrar  ");	
			mvprintw(12,30,"4.....agregar arbol b ");	
			mvprintw(13,30,"5.....imprimir  arbol b ");
			
				
			seguir_jugando=getch();
			if(seguir_jugando=='1'){
				clear();
		    		refresh();
				mvprintw(9,30,"que valor desea insertar:   ");
				getnstr(numero,sizeof(numero)-1);
				for(int x=0;x<sizeof(numero);x++){
					if(numero[x] != ' '){
						num=num+numero[x];					
					}			
				}
			
				int numero=atoi(num.c_str()); 
				cout<<numero<<endl;	
				arbol->insert(numero);
				cantidad++;						
			}else if(seguir_jugando=='2'){
				clear();
				refresh();
				mvprintw(9,30,"que valor desea eliminar:   ");
				getnstr(numero,sizeof(numero)-1);
				for(int x=0;x<sizeof(numero);x++){
					if(numero[x] != ' '){
						num=num+numero[x];					
					}			
				}
			
				int numero=atoi(num.c_str()); 
				cout<<numero<<endl;	
				arbol->erase(numero,cantidad,0);
				cantidad--;
			
			}else if(seguir_jugando=='3'){
				mvprintw(9,30,"fok entri:   ");
				nodes.clear();
				clear();
				refresh();
				arbol->preorden(arbol->root,0);
				int h=preorden(arbol->root,0);
						
				int z=nodes.size();
				getch();				
				int vab=0;
				int pos=0;
				int centinela=0;
				move(12,0);
				attron(COLOR_PAIR(1));
				//move(tx,ty);
				//char p[2];
				//addch((arbol->root)->valor);
				
				stringstream ss;
				
				for(int x=0;x<=h;x++){
					ss<<"NIVEL "<<x<<"   ";
					for(int y=0;y<z;y++){	
						if(nodes[y]->nivel==x){
							if(x !=0){
								if(nodes[y]->father->right_son == nodes[y]){
									ss<<"[ {"<<nodes[y]->valor<<"};padre :"<<nodes[y]->father->valor<< ";(HD)] ";
								}else{
									ss<<"[ { "<<nodes[y]->valor<<"};padre: "<<nodes[y]->father->valor<< " ;(HI)]  ";							}
							}else{
								ss<<"                             [ valor : "<<nodes[y]->valor<<"; Raiz :   ]";
							}
						}
  		  			}
					ss<<",";
				}
				//ss<<"      tam     "<<h<<"          se   "<<z;
				int ty=0;
				int tx=15;	
				int dimension=ss.str().size();
				char buffer[dimension+1];
				size_t length = ss.str().copy(buffer,dimension);
				for(int pp=0;pp<dimension+1;pp++){
						if(buffer[pp] ==','){
							tx=tx+2;
							ty=0;							
							move(tx,ty);
													
						}else{
							addch(buffer[pp]);
						}					
				}
				getch();

			}else if(seguir_jugando=='4'){
				clear();
		    		refresh();
				mvprintw(9,30,"que valor desea insertar:   ");
				getnstr(numero,sizeof(numero)-1);
				for(int x=0;x<sizeof(numero);x++){
					if(numero[x] != ' '){
						num=num+numero[x];					
					}			
				}
			
				int numero=atoi(num.c_str());
				
				
					arbolito.addNode(arbolito.getRaiz(),numero);
			}else if(seguir_jugando=='5'){
				clear();
		    		refresh();
				vector<nodo*>nodos;
	
				nodo* temp = arbolito.getRaiz();
    				nodos.push_back(temp);
				while(temp->hasRightBrother()){
					temp= temp->get_rightBrother();
					nodos.push_back(temp);
				}
				
				stringstream ss;
				
				ss<<arbolito.imp_arbol(nodos);
				int dimension=ss.str().size();
				char buffer[dimension+1];
				size_t length = ss.str().copy(buffer,dimension);
				for(int pp=0;pp<dimension+1;pp++){
						
					addch(buffer[pp]);
											
				}
				getch();
			}
			clear();
			attroff(COLOR_PAIR(1));
  	 }
		
   			 refresh();
   			 getch();	
  			  endwin();
	return -1;

}


int preorden( nodo_avl* nodo, int mas){
    
     if (nodo ==NULL ){
	  
	  return mas;
    }else{	
	 if(mas<get_parent(nodo,0)){
		mas=get_parent(nodo,0);
	 }
	 nodes.push_back(nodo);
         preorden(nodo->left_son,mas);
         preorden(nodo->right_son,mas);
   }
}
int get_parent(nodo_avl* nodo,int num){
	if(nodo->father != NULL){
		num++;
		get_parent(nodo->father,num);
	}else{
		return num;
 	}
}
