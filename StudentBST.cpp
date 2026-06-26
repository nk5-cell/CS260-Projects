/**********************************************************************************************
 Name:              Nidhi Kairon
 Class Number:      CS260 - 20778
 Project Number:    4
 Name of File:      StudentBST.cpp
 File Description:  This file implements the StudentBST class which uses recursive
                    algorithms. It handles heap memory allocation for test
                    and structural memory. It uses divide and conquer appoach
                    from the textbook, and in-order traversal and post-order
                    traversal.
 **********************************************************************************************/

#include <iostream>
#include <cstring>
#include "StudentBST.h"
using namespace std;

//constructor
StudentBST::StudentBST() {
    root = nullptr;
}

//destructor
StudentBST::~StudentBST() {
    destroyTree(root);
}

//a function that cleans up the memory
//deletes every node and recursively traverses the tree
void StudentBST::destroyTree(Node*& curr) {
    if (curr != nullptr) {
        destroyTree(curr->left);
        destroyTree(curr->right);
        destroyStudent(curr->data);
        delete curr;
        curr = nullptr;
    }
}

//a function that performs deep copy
//allocates new dynamic memory
void StudentBST::copyStudent(Student& dest, const Student& source) const {
    dest.programName = new char[strlen(source.programName) + 1];
    strcpy(dest.programName, source.programName);
    
    dest.gNumber = new char[strlen(source.gNumber) + 1];
    strcpy(dest.gNumber, source.gNumber);
    
    dest.studentName = new char[strlen(source.studentName) + 1];
    strcpy(dest.studentName, source.studentName);
    
    dest.academicStanding = source.academicStanding;
}

//a function that freed dynamically allocatted memory
void StudentBST::destroyStudent(Student& s) const {
    delete[] s.programName;
    delete[] s.gNumber;
    delete[] s.studentName;
    s.programName = nullptr;
    s.gNumber = nullptr;
    s.studentName = nullptr;
}

//a function that insert a new student based on G#
int StudentBST::insert(const Student& toAdd) {
    return insert(root, toAdd);
}

//a function that uses divide and conquer approach
int StudentBST::insert(Node*& curr, const Student& toAdd) {
    if (curr == nullptr) {
        curr = new Node;
        copyStudent(curr->data, toAdd);
        curr->left = nullptr;
        curr->right = nullptr;
        return 1;
    }
    if (strcmp(toAdd.gNumber, curr->data.gNumber) < 0) {
        return insert(curr->left, toAdd);
    } else {
        return insert(curr->right, toAdd);
    }
}

//a function that retrieve the information about a particular student based on G#
bool StudentBST::retrieve(const char* gNumber, Student& foundStudent) const {
    return retrieve(root, gNumber, foundStudent);
}

//a function that depends on a divide and conquer approach
bool StudentBST::retrieve(Node* curr, const char* gNumber, Student& foundStudent) const {
    if (curr == nullptr) {
        return false;
    }
    
    int cmp = strcmp(gNumber, curr->data.gNumber);
    if (cmp == 0) {
        copyStudent(foundStudent, curr->data);
        return true;
    } else if (cmp < 0) {
        return retrieve(curr->left, gNumber, foundStudent);
    } else {
        return retrieve(curr->right, gNumber, foundStudent);
    }
}

//a function that find the inorder successor
Node* StudentBST::getLeftmostNode(Node* curr) {
    while (curr != nullptr && curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;
}

//a function that remove a particular student based on G#
int StudentBST::removeByGNumber(const char* gNumber) {
    return removeByGNumber(root, gNumber);
}

//a function that recurively search and remove a student by G#
int StudentBST::removeByGNumber(Node*& curr, const char* gNumber) {
    if (curr == nullptr) {
        return 0;
    }

    int cmp = strcmp(gNumber, curr->data.gNumber);
    if (cmp < 0) {
        return removeByGNumber(curr->left, gNumber);
    } else if (cmp > 0) {
        return removeByGNumber(curr->right, gNumber);
    } else {
        return deleteNode(curr);
    }
}

//a function that delete a node
int StudentBST::deleteNode(Node*& curr) {
    Node* temp = nullptr;
    if (curr->left == nullptr) {
        temp = curr->right;
        destroyStudent(curr->data);
        delete curr;
        curr = temp;
        return 1;
    } else if (curr->right == nullptr) {
        temp = curr->left;
        destroyStudent(curr->data);
        delete curr;
        curr = temp;
        return 1;
    } else {
        Node* successor = getLeftmostNode(curr->right);
        destroyStudent(curr->data);
        copyStudent(curr->data, successor->data);
        return removeByGNumber(curr->right, successor->data.gNumber);
    }
}

//a funcion that remove all students in a program
int StudentBST::removeByProgram(const char* programName) {
    return removeByProgram(root, programName);
}

//a function that uses post-order traversal strategy
int StudentBST::removeByProgram(Node*& curr, const char* programName) {
    if (curr == nullptr) {
        return 0;
    }

    int count = removeByProgram(curr->left, programName) + removeByProgram(curr->right, programName);

    if (strcmp(curr->data.programName, programName) == 0) {
        deleteNode(curr);
        count++;
    }
    return count;
}

//a function that display all students
void StudentBST::displayAll() const {
    displayAll(root);
}

//a function that traverse left first and then right
void StudentBST::displayAll(Node* curr) const {
    if (curr != nullptr) {
        displayAll(curr->left);
        
        const char* standingText = "Unknown";
        switch(curr->data.academicStanding) {
            case 1: standingText = "Unacceptable"; break;
            case 2: standingText = "Needs Improvement"; break;
            case 3: standingText = "Meets Expectations"; break;
            case 4: standingText = "Exceeds Expectations"; break;
            case 5: standingText = "Outstanding"; break;
        }
        
        cout << "G#: " << curr->data.gNumber
        << " | Name: " << curr->data.studentName
        << " | Program: " << curr->data.programName
        << " | Standing: " << standingText << endl;
        
        displayAll(curr->right);
    }
}

//a function that calculates the height of the BST
int StudentBST::getHeight(Node* curr) const {
    if (curr == nullptr) {
        return 0;
    }
    int leftHeight = getHeight(curr->left);
    int rightHeight = getHeight(curr->right);
    if (leftHeight > rightHeight) {
        return 1 + leftHeight;
    } else {
        return 1 + rightHeight;
    }
}

//a function that calculates the number of nodes
int StudentBST::countNodes(Node* curr) const {
    if (curr == nullptr) {
        return 0;
    }
    return 1 + countNodes(curr->left) + countNodes(curr->right);
}

//a function that monitor the height of the tree
void StudentBST::monitor() const {
    int totalItems = countNodes(root);
    int treeHeight = getHeight(root);
    cout << "\nMonioring the performance of BST..." << endl;
    cout << "Total Number of Student Nodes Stored are " << totalItems << endl;
    cout << "Tree Height is: " << treeHeight << endl;
    if (totalItems == 0) {
        cout << "Currently, the tree is empty!" << endl;
        return;
    }
    int idealBalancedHeight = 0;
    int maxNodesAtHeight = 0;
    int powerOfTwo = 1;
        
    while (maxNodesAtHeight < totalItems) {
        idealBalancedHeight = idealBalancedHeight + 1;
        powerOfTwo = powerOfTwo * 2;
        maxNodesAtHeight = powerOfTwo - 1;
    }
    if (treeHeight == idealBalancedHeight) {
        cout << "The tree is perfectly balancedn and operating at O(log N) efficiency." << endl;
    }
    else if (treeHeight <= idealBalancedHeight * 2 && treeHeight < totalItems) {
        cout << "The tree is balanced and efficient." << endl;
    }
    else {
        cout << "The tree is NOT balanced due to the " << totalItems << " items and a height of " << treeHeight << "." << endl;
    }
    
}
