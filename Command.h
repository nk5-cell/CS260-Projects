/**********************************************************************************************
 Name:              Nidhi Kairon
 Class Number:      CS260 - 20778
 Project Number:    2
 Name of File:      Command.h
 File Description:  This file defines the structure of the data for the Deque to manupilate 
 		    and store the data, where it acts as a ADT interface for all the commands 
		    entry.
 Structures:        int sequenceNumber and char* description
 Classes:           class Command represents a data container for the commands. It includes
                    memory allocation and deallocation. It acts a iterface for the Deque.
                    This class performs the undo and redo of the commands.
 Prototypes:        There are two constructor: Command() as a default constructor and
                    Command(int seq, const char* desc) as a parameterized constructor.
                    It was one destructor: ~Command. Getters are: getSequence() const, 
                    and getDescription() const.
 **********************************************************************************************/

#ifndef COMMAND_H
#define COMMAND_H

#include <cstring>

using namespace std;

const int MAX_DESC = 100;

class Command {
public:
    //constructors
    Command();
    Command(int seq, const char* desc);
    Command(const Command& other);
    //operration
    Command& operator=(const Command& other);
    //destructor
    ~Command();

    //getters
    int getSequence() const;
    const char* getDescription() const;
private:
    int sequenceNumber;
    char* description;
};

#endif





