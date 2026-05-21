/**********************************************************************************************
 Name:              Nidhi Kairon
 Class Number:      CS260 - 20778
 Project Number:    2
 Name of File:      main.cpp
 File Description:  This program first load the commands.txt file at the beginning of
                    the program. The user interface allow the user to show
                    the entire command history, undo a certain number of
                    commands, redo a certain number of commands.
 Inputs:            commands.txt file, int choice, int numCmdsUndo, int numCmdsRedo
 Outputs:           display command history
 Sources:           Module 3 & 4 Lectures, Textbook: Data Abstraction & Problem Solving 
 		    with Walls And Mirrors  by Frank M. Carrano and Timothy M. henry
 **********************************************************************************************/
#include <iostream>
#include <fstream>
#include "Deque.h"

using namespace std;

//function prototype
bool loadData(Deque& history, const char* fileName);

//main
int main() {
	int choice = 0;
    	Deque historyList;
    	Deque redoList;

    	cout << "***** Welcome to the Undo-Redo System *****" << endl;
    
    	//loads data from commands.txt if found
    	if (!loadData(historyList, "commands.txt")) {
            	cout << "commands.txt is not found" << endl;
    		return 1;
    	}

    	//performs the functions based on the user choice
    	while (choice != 4) {
		cout << "\n1. Show entire command history" << endl;
        	cout << "2. Undo commands" << endl;
        	cout << "3. Redo commands" << endl;
        	cout << "4. Exit" << endl;
        	cout << "Enter Your Choice: ";
        	cin >> choice;

        	if (choice == 1) {
            		if (historyList.isEmpty()) {
				cout << "Command History is Empty!" << endl;
			}
			else {
				historyList.displayAll();
			}
        	}
        	else if (choice == 2) {
			if (historyList.isEmpty()) {
				cout << "Command History is Empty!" << endl;
			}
			else {
            			int trackUndo = 0;
                		int numCmdsUndo = 0;
				cout << "Enter number of commands to undo? ";
            			cin >> numCmdsUndo;
	   			while (trackUndo < numCmdsUndo && !historyList.isEmpty()) {
        				Command cmd = historyList.getBack();
        				historyList.removeFromBack();
        				redoList.addToFront(cmd);
					trackUndo++;
    				}
    				if (trackUndo < numCmdsUndo) {
        				cout << "[Only " << trackUndo << " commands were available to undo.]" << endl;
    				}

    				cout << "\nAfter undo " << trackUndo << " commands, the command history:" << endl;
    				redoList.displayAll(); 
    				cout << endl;
    				historyList.displayAll();
			}
		}
        	else if (choice == 3) {
			if (redoList.isEmpty()) {
				cout << "Redo List is Empty!" << endl;
			}
			else {
				int trackRedo = 0;
        			int numCmdsRedo = 0;
            			cout << "Enter number of commands to redo? ";
            			cin >> numCmdsRedo;

	    			while (trackRedo < numCmdsRedo && !redoList.isEmpty()) {
        				Command cmd = redoList.getFront();
        				redoList.removeFromFront();
					historyList.addToBack(cmd);
        				trackRedo++;
    				}
   	 			if (trackRedo < numCmdsRedo) {
        				cout << "[Only " << trackRedo << " commands were available to redo.]" << endl;
    				}

    				cout << "\nAfter redo " << trackRedo << " commands, the command history:" << endl;
    				redoList.displayAll();
    				cout << endl;
    				historyList.displayAll();
			}
		}
	}
    return 0;
}


//function that loads the data
bool loadData(Deque& history, const char* fileName) {
    	ifstream inputFile(fileName);
    	int sequence;
    	//file input validation
    	if (!inputFile) {
        	return false;
    	}
    	//uses dynamic memory allocation
    	while (inputFile >> sequence) {
        	inputFile.ignore();//skips the space
        	//initializes the size of the buffer
        	int capacity = 10;
        	int len = 0;
        	//memory allocation on the heap
        	char* dynamicDesc = new char[capacity];
        	//variable to use for reading the line by each character
        	char character;
        	//while loop to read until the end of the line
        	while (inputFile.get(character) && character != '\n') {
            		if (len + 1 >= capacity) {
                		//resize
                		capacity *= 2; //doubles the capacity
                		char* newTemp = new char[capacity]; //new memory with more capacity
                		strncpy(newTemp, dynamicDesc, len);
                		delete[] dynamicDesc; //prevent leaks
                		dynamicDesc = newTemp; //updates the pointer
            		}
            		dynamicDesc[len++] = character;
        	}
        	dynamicDesc[len] = '\0';
        	//adds to the history
        	history.addToBack(Command(sequence, dynamicDesc));
        	delete[] dynamicDesc; //free the memory
    	}
    	inputFile.close();
    	return true;
}

