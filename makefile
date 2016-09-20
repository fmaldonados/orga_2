Juego:arbol.o nodo_avl.o nodo.o arbolb.o avl_tree.o 
	 g++ arbol.o nodo_avl.o avl_tree.o nodo.o arbolb.o -o Juego -lncurses
arbol.o: arbol.cpp nodo_avl.h avl_tree.h
	 g++ -c arbol.cpp 
nodo_avl.o:nodo_avl.h nodo_avl.cpp
	 g++ -c nodo_avl.cpp
avl_tree.o:avl_tree.h avl_tree.cpp
	 g++ -c avl_tree.cpp
nodo.o: nodo.h nodo.cpp
	g++ -c nodo.cpp
arbolb.o:	nodo.h arbolb.cpp
	g++ -c arbolb.cpp
clean:
	rm *.o;	
