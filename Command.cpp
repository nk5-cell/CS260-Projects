/*********************************************************************************************
 Name:              Nidhi Kairon
 Class Number:      CS260 - 20778
 Project Number:    2
 Name of File:      Command.cpp
 File Description:  This file implements the Command class, which uses constructors and getters
                    for managing commands data. It handles c-style strings securely, where
                    the descriptions gets copied correctly.
 **********************************************************************************************/

#include "Command.h"

//this constructor created empty command
Command::Command() {
    sequenceNumber = 0;
    description = new char[1];
    description[0] = '\0'; //places null terminator at the first index
}

//this is a parameterized constructor
Command::Command(int seq, const char* desc) {
    sequenceNumber = seq; //asigns the sequence number
    
    if (desc != nullptr) {
        description = new char[strlen(desc) + 1];
        strcpy(description, desc); //copy the characters from desc
    } else {
        description = new char[1];
        description[0] = '\0';
    }
}

//constructor
Command::Command(const Command& other) {
    this->sequenceNumber = other.sequenceNumber;
    this->description = new char[strlen(other.description) + 1];
    strcpy(this->description, other.description);
}

//operator
Command& Command::operator=(const Command& other) {
    if (this != &other) {
        delete[] this->description;
        this->sequenceNumber = other.sequenceNumber;
        this->description = new char[strlen(other.description) + 1];
        strcpy(this->description, other.description);
    }
    return *this;
}

//destructor
Command::~Command() {
    if (description != nullptr) {
        delete [] description;
        description = nullptr;
    }
}

//getter 
int Command::getSequence() const {
    return sequenceNumber;
}

//getter
const char* Command::getDescription() const {
    return description;
}
