CC = g++
CPPFLAGS = -Wall -g -std=c++11

proj1: main.o Engineer.o EngineerList.o
	$(CC) $(CPPFLAGS) main.o Engineer.o EngineerList.o -o proj1

main.o: Engineer.h

Engineer.o: Engineer.h

EngineerList.o: Engineer.h

.PHONY: clean
clean:
	$(info -- cleaning the directory --)
	rm -f *.o
	rm -f proj1

