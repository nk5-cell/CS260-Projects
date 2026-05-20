/**********************************************************************************************
 Name:              Nidhi Kairon
 Class Number:      CS260 - 20778
 Project Number:    2
 Name of File:      Deque.h
 File Description:  This file implements the doubly linked list by defining the interface for 
 		    the ADT for the Deque. This file estabilishes interaction of the program
                    by establishing adding, removing, and viewing the commands.
 Structures:        Theres a struct Node in the private of the class Deque. It contains a
                    Command item and two pointers that makes a double linked list,
                    which allows the program to perform both the undo and redo
                    functions.
 Classes:           class Deque organizes the commans into specific structure. It maanges the
                    Nodes and Pointers by managing the front and back of the list of
                    the commands. It ensures that undo and redo gets done correctly.
                    
 Prototypes:        Constructor: Deque(). Destructor: virtual ~Deque(). bool isEmpty() const is 
 		    a boolean function prototype . Mutators: bool addToFront(const Command& 
		    command), bool addToBack(const Command& command), bool removeFromFront(), 
		    bool removeFromBack(). Accessors: Command getFront() const, Command 
		    getBack() const. Lastly, oid displayAll() const as a utility prototype.
 **********************************************************************************************/

#ifndef DEQUE_H
#define DEQUE_H

#include "Command.h"

class Deque {
public:
    //constructor
    Deque();
    //destructor
    virtual ~Deque();

    //check the status of the doubly linked list
    bool isEmpty() const;
    //adds commands
    bool addToFront(const Command& command);
    bool addToBack(const Command& command);
    //remove commands
    bool removeFromFront();
    bool removeFromBack();

    //return commands without removing them
    Command getFront() const;
    Command getBack() const;
    
    //display the command history
    void displayAll() const;
    
private:
    //container for the linked list
    struct Node {
        Command item;
        Node* next;
        Node* prev;
        //constructor for this struct
        Node(const Command& anItem) : item(anItem), next(nullptr), prev(nullptr) {}
    };

    Node* frontPtr; //points to redo end
    Node* backPtr; //points to the recent command end
    int itemCount; //tracks the num of commands
};

#endif

