/**********************************************************************************************
 Name:              Nidhi Kairon
 Class Number:      CS260 - 20778
 Project Number:    4
 Name of File:      main.cpp
 File Description:  This driver program is for the PCC Academic Standing System.
                    It first load the student.txt file at the beginning of the
                    program. The user interface allow the user to add new
                    student, retrieve students based on the G#, remove all
                    students in a particular program, rmove a particular
                    student based on G#, display all student sorted by G#,
                    and lastly monitor the height of the tree.
 Inputs:            student.txt file, int choice, char buffer[], Student s, s.programName,
                    s.gNumber, s.studentName, s.academicStanding, Student
                    matchedResult, StudentBST studentSystem
 Outputs:           choice, buffer, s.programName, s.gNumber, s.studentName,
                    s.academicStanding, matchedResult.studentName,
                    matchedResult.gNumber, matchedResult.programName,
                    getStandingText(matchedResult.academicStanding), dropped,
                    studentSystem.displayAll(), studentSystem.monitor()
 Sources:           Module 8 Lectures, Textbook: Data Abstraction & Problem Solving
                    with Walls And Mirrors  by Frank M. Carrano and Timothy M. henry
 **********************************************************************************************/

#include <iostream>
#include <cstring>
#include <fstream>
#include "StudentBST.h"

using namespace std;

const char* getStandingText(int level);
void pressEnterToContinue();

int main() {
    StudentBST studentSystem;
    int choice = 0;
    char buffer[128];
    ifstream infile("student.txt");
    //get data from the student.txt file
    if (!infile) {
        cout << "Error occured. Could not open the data file!" << endl;
    } else {
        while (infile.getline(buffer, 128)) {
            Student s;
            //from data file
            //get the program name
            s.programName = new char[strlen(buffer) + 1];
            strcpy(s.programName, buffer);
            //get G-number
            infile.getline(buffer, 128);
            s.gNumber = new char[strlen(buffer) + 1];
            strcpy(s.gNumber, buffer);
            //get student name
            infile.getline(buffer, 128);
            s.studentName = new char[strlen(buffer) + 1];
            strcpy(s.studentName, buffer);
            //get acamdemic standing
            infile >> s.academicStanding;
            infile.ignore(100, '\n');
            //insert
            studentSystem.insert(s);
            //delete memory
            delete[] s.programName;
            delete[] s.gNumber;
            delete[] s.studentName;
        }
        infile.close();
    }

    cout << "---------------PCC-Academic-Standing-System---------------" << endl;
    do {
        cout << "\nEnter your choice based on the following menu:\n";
        cout << "1. Insert a new student based on G#\n";
        cout << "2. Retrieve the information about a particular student based on G#\n";
        cout << "3. Remove a particular student based on G#\n";
        cout << "4. Remove all students in a program\n";
        cout << "5. Display all students (sorted by G#)\n";
        cout << "6. Monitor the height of the tree\n";
        cout << "7. Exit the Program\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore(128, '\n');
        //Insert a new student based on G#
        if (choice == 1) {
            Student s;
            cout << "Enter Program Name (e.g. Computer Science): ";
            cin.get(buffer, 128);
            cin.ignore(1000, '\n');
            s.programName = new char[strlen(buffer) + 1];
            strcpy(s.programName, buffer);

            cout << "Enter Student G#: ";
            cin.get(buffer, 128);
            cin.ignore(1000, '\n');
            s.gNumber = new char[strlen(buffer) + 1];
            strcpy(s.gNumber, buffer);

            cout << "Enter Student Name: ";
            cin.get(buffer, 128);
            cin.ignore(1000, '\n');
            s.studentName = new char[strlen(buffer) + 1];
            strcpy(s.studentName, buffer);

            cout << "Enter Academic Standing (1-5 have the following meanings respectively: unacceptable, needs improvement, meets expectations, exceeds expectations, outstanding): ";
            cin >> s.academicStanding;
            cin.ignore(1000, '\n');

            studentSystem.insert(s);
            
            delete[] s.programName;
            delete[] s.gNumber;
            delete[] s.studentName;
            
            pressEnterToContinue();
        }
        //Retrieve the information about a particular student based on G#
        else if (choice == 2) {
            cout << "Enter Student G#: ";
            cin.get(buffer, 128);
            cin.ignore(1000, '\n');
            
            Student matchedResult;
            if (studentSystem.retrieve(buffer, matchedResult)) {
                cout << "\nName: " << matchedResult.studentName << endl;
                cout << "G#: " << matchedResult.gNumber << endl;
                cout << "Program: " << matchedResult.programName << endl;
                cout << "Academic Performance: " << getStandingText(matchedResult.academicStanding) << endl;
               
                delete[] matchedResult.programName;
                delete[] matchedResult.gNumber;
                delete[] matchedResult.studentName;
            } else {
                cout << "No student found with the G# provided!" << endl;
            }
            pressEnterToContinue();
        }
        //Remove a particular student based on G#
        else if (choice == 3) {
            cout << "Enter Student G#: ";
            cin.get(buffer, 128); cin.ignore(1000, '\n');
            if (studentSystem.removeByGNumber(buffer)) {
                cout << "Removed: " << buffer << endl;
            } else {
                cout << "Unable to find the provided G#" << endl;
            }
            pressEnterToContinue();
        }
        //Remove all students in a program
        else if (choice == 4) {
            cout << "Enter Program Name: ";
            cin.get(buffer, 128); cin.ignore(1000, '\n');
            int dropped = studentSystem.removeByProgram(buffer);
            cout << dropped << " records removed from " << buffer << endl;
            pressEnterToContinue();
        }
        //Display all students (sorted by G#)
        else if (choice == 5) {
            studentSystem.displayAll();
            pressEnterToContinue();
        }
        //Monitor the height of the tree.
        else if (choice == 6) {
            studentSystem.monitor();
            pressEnterToContinue();
        }
        //Exit
        else if (choice == 7) {
            cout << "Thank you for using PCC Academic Systsem!!!!!" << endl;
        }
        //Error message
        else {
            cout << "Invalid choice!" << endl;
            pressEnterToContinue();
        }
    } while (choice != 7);

    return 0;
}

const char* getStandingText(int level) {
    switch(level) {
        case 1:
            return "Unacceptable";
        case 2:
            return "Needs Improvement";
        case 3:
            return "Meets Expectations";
        case 4:
            return "Exceeds Expectations";
        case 5:
            return "Outstanding";
        default:
            return "Unknown";
    }
}

void pressEnterToContinue() {
    cout << "\nPress Enter to continue...";
    cin.get();
}




void myCopyLeaf(node * root, node *& newRoot) {
    if (root == nullptr) {
        newRoot = nullptr;
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        newRoot = new node;
        newRoot->data = root->data;
        newRoot->left = nullptr;
        newRoot->right = nullptr;
        return;
    }

    node * leftCopy = nullptr;
    node * rightCopy = nullptr;

    myCopyLeaf(root->left, leftCopy);
    myCopyLeaf(root->right, rightCopy);

    if (leftCopy != nullptr && rightCopy != nullptr) {
        newRoot = leftCopy;
        node * curr = leftCopy;
        while (curr->right != nullptr) {
            curr = curr->right;
        }
        curr->right = rightCopy;
    }
    else if (leftCopy != nullptr) {
        newRoot = leftCopy;
    }
    else {
        newRoot = rightCopy;
    }
}

