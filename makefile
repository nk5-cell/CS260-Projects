CC = g++
CPPFLAGS = -Wall -g -std=c++11 -m32
LDFLAGS = -m32

all: main

main: main.o Deque.o Command.o
	g++ -m32 -o main main.o Deque.o Command.o

main.o: main.cpp Deque.h Command.h
	g++ -Wall -g -std=c++11 -m32 -c main.cpp

Deque.o: Deque.cpp Deque.h Command.h
	g++ -Wall -g -std=c++11 -m32 -c Deque.cpp

Command.o: Command.cpp Command.h
	g++ -Wall -g -std=c++11 -m32 -c Command.cpp

.PHONY: clean
clean:
	rm -f main.o Deque.o Command.o main


