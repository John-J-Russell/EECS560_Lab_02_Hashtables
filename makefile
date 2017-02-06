lab2: main.o Node.o DoubleLinkedList.o OpenHashtable.o
	g++ -g -Wall -std=c++11 main.o Node.o DoubleLinkedList.o OpenHashtable.o -o lab2

main.o: main.cpp OpenHashtable.h
	g++ -g -Wall -std=c++11 -c main.cpp

Node.o: Node.cpp
	g++ -g -Wall -std=c++11 -c Node.cpp

DoubleLinkedList.o: DoubleLinkedList.cpp Node.h
	g++ -g -Wall -std=c++11 -c DoubleLinkedList.cpp

OpenHashtable.o: OpenHashtable.cpp DoubleLinkedList.h
	g++ -g -Wall -std=c++11 -c OpenHashtable.cpp

clean:
	rm *.o lab2
