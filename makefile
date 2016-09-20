Juego:arbol.o nodo_avl.o avl_tree.o 
	 g++ arbol.o nodo_avl.o avl_tree.o -o Juego -lncurses
arbol.o: arbol.cpp nodo_avl.h avl_tree.h
	 g++ -c arbol.cpp 
nodo_avl.o:nodo_avl.h nodo_avl.cpp
	 g++ -c nodo_avl.cpp
avl_tree.o:avl_tree.h avl_tree.cpp
	 g++ -c avl_tree.cpp
clean:
	rm *.o;	
