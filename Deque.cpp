/*********************************************************************************************
 Name:              Nidhi Kairon
 Class Number:      CS260 - 20778
 Project Number:    2
 Name of File:      Deque.cpp
 File Description:  This file implements the Deque class, which uses Doubly Linked List to 
 		    perform undo and redo tasks. This file handles dynamic memory allocation 
		    and the task of traveral in the displayAll function. It also managed 
		    pointer arithmetic to link the nodes together.
 **********************************************************************************************/

#include "Deque.h"
#include <iostream>
#include <iomanip>

using namespace std;

//a constructor that initializes an empty list
Deque::Deque() {
    frontPtr = nullptr;
    backPtr = nullptr;
    itemCount = 0;
}

//destructor
Deque::~Deque() {
    //call removeFromFront() until the list is empty
    while (!isEmpty()) {
        removeFromFront();
    }
}

bool Deque::isEmpty() const {
    return itemCount == 0;
}

//add commands to back
bool Deque::addToBack(const Command& command) {
    Node* newNodePtr = new Node(command); //creates new node
    if (isEmpty()) {
        //set front and back pointer to a new node if the list is empty
        frontPtr = newNodePtr;
        backPtr = newNodePtr;
    } else {
        //wires the pointers
        newNodePtr->prev = backPtr;
        backPtr->next = newNodePtr;
        backPtr = newNodePtr;
    }
    itemCount++; //increment
    return true;
}

//add commands to front
bool Deque::addToFront(const Command& command) {
    Node* newNodePtr = new Node(command); //creates new node
    if (isEmpty()) {
        //set front and back pointer to a new node if the list is empty
        frontPtr = newNodePtr;
        backPtr = newNodePtr;
    } else {
        //wires the pointers
        newNodePtr->next = frontPtr;
        frontPtr->prev = newNodePtr;
        frontPtr = newNodePtr;
    }
    itemCount++; //increment
    return true;
}

//remove the command from back
bool Deque::removeFromBack() {
    //checks if the list is empty
    if (isEmpty()) {
        return false;
    }
    //saves the back pointer to the nodeToDelete
    Node* nodeToDelete = backPtr;
    if (itemCount == 1) {
        //set to null pointer
        frontPtr = nullptr;
        backPtr = nullptr;
    } else {
        //undo operation from the back
        backPtr = backPtr->prev;
        backPtr->next = nullptr;
    }
    
    delete nodeToDelete; //free the memory
    itemCount--; //decrement
    return true;
}

//remove the command from the front
bool Deque::removeFromFront() {
    //checks if the list is empty
    if (isEmpty()){
        return false;
    }
    //saves the front pointer to the nodeToDelete
    Node* nodeToDelete = frontPtr;
    if (itemCount == 1) {
        //set to null pointer
        frontPtr = nullptr;
        backPtr = nullptr;
    } else {
        //undo operations from the front
        frontPtr = frontPtr->next;
        frontPtr->prev = nullptr;
    }

    delete nodeToDelete; //free the memory
    itemCount--; //decrement
    return true;
}

//returns the command to the back without removing it
Command Deque::getBack() const {
    if (!isEmpty()) {
        return backPtr->item;
    }
    return Command();
}

//returns the command to the front without removing it
Command Deque::getFront() const {
    if (!isEmpty()) {
        return frontPtr->item;
    }
    return Command();
}

//display the command history 
void Deque::displayAll() const {
    Node* curPtr = frontPtr; 
    while (curPtr != nullptr) {
        cout << setw(6) << curPtr->item.getSequence() << ". " << curPtr->item.getDescription() << endl;
        curPtr = curPtr->next;
    }
}
