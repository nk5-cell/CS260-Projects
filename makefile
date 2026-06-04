CC = g++
CPPFLAGS = -Wall -g -std=c++11 -m32
LDFLAGS = -m32

all: main

main: main.o table.o
        g++ -m32 -o main main.o table.o

main.o: main.cpp table.h
        g++ -Wall -g -std=c++11 -m32 -c main.cpp

table.o: table.cpp table.h
        g++ -Wall -g -std=c++11 -m32 -c table.cpp

.PHONY: clean
clean:
        rm -f main.o table.o main
