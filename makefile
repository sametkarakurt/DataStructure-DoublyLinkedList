hepsi: derle calistir 

derle:
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp 
	g++ -I ./include/ -o ./lib/DoublyLinkedList.o -c ./src/DoublyLinkedList.cpp 
	g++ -I ./include/ -o ./bin/main ./lib/Node.o ./lib/DoublyLinkedList.o ./src/main.cpp
	
bagla:
	g++ ./lib/main.o -o ./bin/main
calistir:
	./bin/main