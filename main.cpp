/**********************************************************************************************
 Name:              Nidhi Kairon
 Class Number:      CS260 - 20778
 Project Number:    1
 Name of File:      main.cpp
 File Description:  This is a manu-based user interface that allows user to use/test all the
		    functionalities of the program. It also coordinate interactiosn between
		    the EngineerList ADT and the user. It manages the program's flow and
		    serves as the entry point for the application.
 Inputs:            int choice, char fBuf[100], char lBuf[100], int titleChoice, int assess,
		    int index, int newRating, int levelSearch
 Outputs:           EngineerList masterList, Engineer temp, EngineerList& list
 **********************************************************************************************/
 

#include <iostream>
#include <fstream>
#include "Engineer.h"

using namespace std;

const int DISPLAY = 1;
const int ADD = 2;
const int PROMOTE = 3;
const int EDIT = 4;
const int DISPLAY_LEVEL = 5;
const int REMOVE_POOR = 6;
const int QUIT = 7;

void displayMenu();
void loadFromFile(EngineerList & list);

int main() {
    EngineerList masterList;
    int choice = 0;

    loadFromFile(masterList);

    cout << "Welcome to the Engineer Management System." << endl;

    while (choice != QUIT) {
        displayMenu();
        cin >> choice;
        cin.ignore(100, '\n');

        if (choice == DISPLAY) {
            masterList.displayAll();
        }
        else if (choice == ADD) {
            char fBuf[100], lBuf[100];
            int titleChoice, assess;

            cout << "Enter First Name: ";
            cin.get(fBuf, 100, '\n'); cin.ignore(100, '\n');
            cout << "Enter Last Name: ";
            cin.get(lBuf, 100, '\n'); cin.ignore(100, '\n');
            cout << "Enter Title Level (0 for L1, 7 for L8): ";
            cin >> titleChoice;
            cout << "Enter Assessment (1-5): ";
            cin >> assess;

            Engineer temp;
            if (temp.init(fBuf, lBuf, static_cast<Title>(titleChoice), assess)) {
                masterList.add(temp);
                cout << "Engineer added successfully." << endl;
            }
        }
        else if (choice == PROMOTE) {
            int index;
            masterList.displayAll();
            cout << "Enter the index of the engineer to promote: ";
            cin >> index;
            if (masterList.promoteEngineer(index))
                cout << "Promotion successful." << endl;
            else
                cout << "Invalid index or engineer already at max level." << endl;
        } 
	else if (choice == EDIT) {
            int index, newRating;
            masterList.displayAll();
            cout << "Enter the index of the engineer to edit: ";
            cin >> index;
            cout << "Enter new assessment level (1: Unacceptable - 5: Outstanding): ";
            cin >> newRating;

            if (masterList.editAssessment(index, newRating))
                cout << "Assessment updated successfully." << endl;
            else
                cout << "Invalid index or rating level." << endl;
        }
        else if (choice == DISPLAY_LEVEL) {
            int levelSearch;
            cout << "Enter title level to filter by (0 for L1, 7 for L8): ";
            cin >> levelSearch;
            cout << "\nShowing Engineers at Level " << levelSearch + 1 << ":" << endl;
            masterList.displayByLevel(levelSearch);
        }
        else if (choice == REMOVE_POOR) {
            if (masterList.removePoorPerformers())
                cout << "All engineers with performance rating 1 have been removed." << endl;
            else
                cout << "No engineers found with a rating of 1." << endl;
        }
        else if (choice == QUIT) {
            cout << "GoodBye!!!!!" << endl;
        }
    }

    return 0;
}

void loadFromFile(EngineerList & list) {
    ifstream fin("engineers.txt");
    if (!fin) {
        cout << "No existing data file found. Starting with empty list." << endl;
        return;
    }

    char fBuf[100], lBuf[100];
    int titleInt, assess;

    while (fin >> fBuf >> lBuf >> titleInt >> assess) {
        Engineer temp;
        if (temp.init(fBuf, lBuf, static_cast<Title>(titleInt), assess)) {
            list.add(temp);
        }
    }
    fin.close();
}

void displayMenu() {
    cout << "\n--- Main Menu ---" << endl;
    cout << "1. Display All Engineers" << endl;
    cout << "2. Add New Engineer" << endl;
    cout << "3. Promote Engineer" << endl;
    cout << "4. Edit Assessment Level" << endl;
    cout << "5. Display by Level" << endl;
    cout << "6. Remove Rating 1 Engineers" << endl;
    cout << "7. Quit" << endl;
    cout << "Choice: ";
}
