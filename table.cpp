/*********************************************************************************************
 Name:              Nidhi Kairon
 Class Number:      CS260 - 20778
 Project Number:    3
 Name of File:      table.cpp
 File Description:  This file implements the Table class, which uses vertically linkes lists 
                    that is attached to a flat array grid. This file handles dynamic memory
                    allocation, explicit deep-copy routine, and contains text to index
                    mathematical hash function. It defines class interface while
                    handling algorithm heavy lifting. It shields collison handling and
                    low-level pointer manipulation.
 **********************************************************************************************/
#include <iostream>
#include <cstring>
#include "table.h"
using namespace std;

//constructor
//dynamically allocates the array
Table::Table(int size) : tableSize(size) {
    hashTable = new Node*[tableSize];
    for (int i = 0; i < tableSize; ++i) {
        hashTable[i] = nullptr;
    }
}

//destructor
Table::~Table() {
    clearTable();
    delete[] hashTable;
}

//a function to clear up linked list nodes
//iterated through the bucket in teh array
//traverse linked list
//track current node
void Table::clearTable() {
    for (int i = 0; i < tableSize; ++i) {
        Node* current = hashTable[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            destroyStudent(temp->data);
            delete temp;
        }
        hashTable[i] = nullptr;
    }
}

//a function that converts the c-stirng to the int array index
int Table::hashFunction(const char* key) const {
    int value = 0;
    int len = strlen(key);
    //loops through the char
    for (int i = 0; i < len; ++i) {
        value += key[i];
    }
    //this makes sure that the index is between 0 and tableSize-1
    return value % tableSize;
}

//a function to manage deep copies
//dynamically allocates array and copies the text
void Table::copyStudent(Student& dest, const Student& source) const {
    dest.programName = new char[strlen(source.programName) + 1];
    strcpy(dest.programName, source.programName);
    dest.gNumber = new char[strlen(source.gNumber) + 1];
    strcpy(dest.gNumber, source.gNumber);
    dest.studentName = new char[strlen(source.studentName) + 1];
    strcpy(dest.studentName, source.studentName);
    dest.academicStanding = source.academicStanding;
}

//a function to free the memory
void Table::destroyStudent(Student& s) const {
    delete[] s.programName;
    delete[] s.gNumber;
    delete[] s.studentName;
}

//a function that takes O(1) constant time
//hashes the program name
int Table::insert(const Student& toAdd) {
    int index = hashFunction(toAdd.programName);
    Node* newNode = new Node;
    copyStudent(newNode->data, toAdd);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
    return 1;
}

//a function that search through the data
bool Table::retrieve(const char* program, Student allMatches[], int& numFound) const {
    int index = hashFunction(program);
    Node* current = hashTable[index];
    numFound = 0;

    while (current) {
        //uses strcmp to scan linked list
        if (strcmp(current->data.programName, program) == 0) {
            //puts deep copies un allMatches array
            copyStudent(allMatches[numFound], current->data);
            numFound++;
        }
        current = current->next;
    }
    return numFound > 0;
}

//a function that finds bukchet and searches linked list 
int Table::edit(const char* program, const char* gNumber, int newStanding) {
    int index = hashFunction(program);
    Node* current = hashTable[index];
    if (!current) return 0;
    while (current) {
        if (strcmp(current->data.gNumber, gNumber) == 0) {
            current->data.academicStanding = newStanding;
            return 1;
        }
        current = current->next;
    }
    return 0;
}

//a function that remove unacceptable standing
//remove nodes from a linnked list
//track the node behind current
int Table::removeUnacceptableStanding() {
    int count = 0;
    for (int i = 0; i < tableSize; ++i) {
        Node* current = hashTable[i];
        Node* prev = nullptr;
        while (current) {
            if (current->data.academicStanding == 1) { // 1 = Unacceptable
                Node* toDelete = current;
                if (!prev) hashTable[i] = current->next;
                else prev->next = current->next;
                current = current->next;
                destroyStudent(toDelete->data);
                delete toDelete; //frees memory
                count++;
            } else {
                prev = current;
                current = current->next;
            }
        }
    }
    return count;
}

//a function that prints chain length of each bucket
//counts num of codes in each bucket chain
void Table::monitor() const {
    for (int i = 0; i < tableSize; ++i) {
        int chainLen = 0;
        Node* curr = hashTable[i];
        while (curr) {
            chainLen++;
            curr = curr->next;
        }
        cout << "Chain Length of [" << i <<"] is: " << chainLen << endl;
    }
}

