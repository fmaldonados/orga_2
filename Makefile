btree:	nodo.o arbolb.o main.o
	g++ nodo.o arbolb.o main.o -o btree

main.o:	main.cpp nodo.h arbolb.h
	g++ -c main.cpp 

nodo.o:	nodo.cpp nodo.h
	g++ -c nodo.cpp  

arbolb.o:	arbolb.cpp arbolb.h nodo.h
	g++ -c arbolb.cpp  