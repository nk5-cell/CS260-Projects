/**********************************************************************************************
 Name:              Nidhi Kairon
 Class Number:      CS260 - 20778
 Project Number:    3
 Name of File:      main.cpp
 File Description:  This driver program is for the PCC Academic Standing System.
                    It first load the student.txt file at the beginning of the
                    program. The user interface allow the user to add new
                    student, retrieve students based on the subject, edit
                    academic standings, monitor the performance of
                    hashing function, and lastly allows the user to exit the
                    program.
 Inputs:            student.txt file, int choice, char buffer[], char gNumBuffer[], int
                    newStanding
 Outputs:           int removed, results[i].studentName, results[i].gNumber,
                    getStandingText(results[i].academicStanding),
                    getStandingText(newStanding)
 Sources:           Module 5 Lectures, Textbook: Data Abstraction & Problem Solving
                    with Walls And Mirrors  by Frank M. Carrano and Timothy M. henry
 **********************************************************************************************/
#include <iostream>
#include <cstring>
#include <fstream>
#include "table.h"

using namespace std;

const char* getStandingText(int level);
void pressEnterToContinue();

int main() {
    Table studentSystem(41);
    int choice = 0;
    char buffer[128];
    ifstream infile("student.txt");

    //get data from the student.txt file
    if (!infile) {
            cout << "Error occured. Could not open the data file!" << endl;
    }
    else {
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
            infile.ignore(100, '\n'); // Clear the newline after the integer
            //insert
            studentSystem.insert(s);
            //delete memory
            delete[] s.programName;
            delete[] s.gNumber;
            delete[] s.studentName;
        }
            //closes the file
            infile.close();
        }

    cout << "---------------PCC-Academic-Standing-System---------------" << endl;
    do {
        cout << "\nEnter your choice based on the following menu:\n";
        cout << "1. Add New Student\n";
        cout << "2. Retrieve Students based on the Program\n";
        cout << "3. Edit Academic Standing for a particular program and student match\n";
        cout << "4. Remove Unacceptable Standings\n";
        cout << "5. Monitor the Performance of Hashing Function\n";
        cout << "6. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore(128, '\n');

        //add new student
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

            delete[] s.programName; delete[] s.gNumber; delete[] s.studentName;
            pressEnterToContinue();
        }
        //Retrieve Students based on the Program
        else if (choice == 2) {
            cout << "Enter Program Name to Retrieve: ";
            cin.get(buffer, 128); cin.ignore(1000, '\n');
            Student results[100];
            int found = 0;
            if (studentSystem.retrieve(buffer, results, found)) {
                for (int i = 0; i < found; ++i) {
                    cout << "Name: " << results[i].studentName << " | G#: " << results[i].gNumber
                         << " | Standing: " << getStandingText(results[i].academicStanding) << endl;
                    delete[] results[i].programName;
                    delete[] results[i].gNumber;
                    delete[] results[i].studentName;
                }
            } else cout << "No students found in that program." << endl;
            pressEnterToContinue();
        }
        //Edit Academic Standing for a particular progrm and student match
        else if (choice == 3) {
            char gNumBuffer[128];
            int newStanding = 0;

            cout << "Enter Program Name: ";
            cin.get(buffer, 128);
            cin.ignore(1000, '\n');

            cout << "Enter Student G#: ";
            cin.get(gNumBuffer, 128);
            cin.ignore(1000, '\n');

            cout << "Enter New Academic Standing (1-5): ";
            cin >> newStanding;
            cin.ignore(1000, '\n');

            if (studentSystem.edit(buffer, gNumBuffer, newStanding)) {
                cout << "Academic standing is updating to " << getStandingText(newStanding) << "." << endl;
            } else {
                cout << "Student record not found." << endl;
            }

            pressEnterToContinue();
        }
        //Remove Unacceptable Standings
        else if (choice == 4) {
            int removed = studentSystem.removeUnacceptableStanding();
            cout << "Removed: " << removed << endl;
            pressEnterToContinue();
        }
        //Monitor the Performance of Hashing Function
        else if (choice == 5) {
            studentSystem.monitor();
            pressEnterToContinue();
        }
        //Exit
        else if (choice == 6) {
            cout << "Thank you for using PCC Academic System!!!!!" << endl;
        }
        //error message
        else {
            cout << "Invalid choice!" << endl;
            pressEnterToContinue();
        }
    } while (choice != 6);

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
