/*********************************************************************************************
 Name:              Nidhi Kairon
 Class Number:      CS260 - 20778
 Project Number:    1
 Name of File:      Engineer.cpp
 File Description:  This file implements the Engineer class from Engineer.h file. This file
		    focuses on the Engineer object data.
 *********************************************************************************************/

#include <iostream>
#include "Engineer.h"
using namespace std;

Engineer::Engineer() : firstName(nullptr), lastName(nullptr) {}

Engineer::~Engineer() {
    delete [] firstName;
    delete [] lastName;
}

bool Engineer::init(const char* fName, const char* lName, Title title, int assessment) {
    if (!fName || !lName) return false;

    int fLen = 0;
    while (fName[fLen] != '\0') fLen++;

    firstName = new char[fLen + 1];
    for (int i = 0; i < fLen; i++) {
        firstName[i] = fName[i];
    }
    firstName[fLen] = '\0';

    int lLen = 0;
    while (lName[lLen] != '\0') lLen++;

    lastName = new char[lLen + 1];
    for (int i = 0; i < lLen; i++) {
        lastName[i] = lName[i];
    }
    lastName[lLen] = '\0';

    titleLevel = title;
    assessmentLevel = assessment;
    return true;
}

Engineer::Engineer(const Engineer& other) {
    firstName = nullptr;
    lastName = nullptr;
    init(other.firstName, other.lastName, other.titleLevel, other.assessmentLevel);
}

int Engineer::compare(const Engineer& other) const {
   
    int i = 0;
    while (lastName[i] != '\0' && other.lastName[i] != '\0') {
        if (lastName[i] != other.lastName[i]) return lastName[i] - other.lastName[i];
        i++;
    }
    if (lastName[i] != other.lastName[i]) return lastName[i] - other.lastName[i];

    i = 0;
    while (firstName[i] != '\0' && other.firstName[i] != '\0') {
        if (firstName[i] != other.firstName[i]) return firstName[i] - other.firstName[i];
        i++;
    }
    return firstName[i] - other.firstName[i];
}

void Engineer::promote() {
    if (titleLevel < L8) {
        int currentLevel = static_cast<int>(titleLevel);
        titleLevel = static_cast<Title>(currentLevel + 1);
    }
}

void Engineer::display() const {
    if (lastName && firstName) {
        cout << lastName << ", " << firstName;
    } else {
        cout << "[No name provided]]";
    }
    cout << " | Title Level: " << static_cast<int>(titleLevel) + 1
         << " | Assessment: " << assessmentLevel << endl;
}

void Engineer::setAssessment(int newRating) {
    if (newRating >= 1 && newRating <= 5) {
        assessmentLevel = newRating;
    }
}
