/**********************************************************************************************
 Name:              Nidhi Kairon
 Class Number:      CS260 - 20778
 Project Number:    4
 Name of File:      StudentBST.h
 File Description:  This file defines the interface for the Binary Search Tree ADT. It manages
                    and store student records by g-number using the left and the
                    right pointer which acts as a left child and right child of the tree.
                    It recursively does insertion, retrieval, removal, display, and
                    monitoring.
 Structures:        There's a struct student and struct node. Student struct that holds all the
                    student information. It has a pointer for program Name, a pointer
                    for the g-number, a pointer for the student name, and this allows
                    to manually allocate memory and free memory for the student
                    information. Node Struct has a node for student data, and a left
                    pointer node and a right pointer node that acts as a building block
                    within a tree.
 Classes:              class StudentBST makes the system that fuctions the binary search tree.  It
                    centrelized the entire data structure and manages memory. It does
                    ADT operations of insert, retreive, remove, display and monitor. It
                    also has a student constructor and destructor. This also has a private
                    helper functions to help perform actions of public ADT operations.
 Prototypes:         Constructor: StudentBST(). Destructor: ~StudentBST(). Boolean Accessors:
                    retrieve(...). Standard Accessors: displayAll(), monitor(), getHeight(...),
                    countNodes(...). Mutators: insert(...), removeByProgram(...),
                    removeByGNumber(...). Memory Management Mutators:
                    destroyStudent(...), destroyTree(...), copyStudent(...). Pointer Traversal
                    Helpers: getLeftmostNode(...), deleteNode(...)
 **********************************************************************************************/

#ifndef STUDENTBST_H
#define STUDENTBST_H

//holds student information
struct Student {
    char* programName;
    char* gNumber; 
    char* studentName;
    int academicStanding;
};

struct Node {
    Student data; //holds student data
    Node* left; //left child tree pointer
    Node* right; //right  child tree pointer
};

class StudentBST {
public:
    //constructor
    StudentBST();
    //destructor
    ~StudentBST();
    //operations
    int insert(const Student& toAdd);
    bool retrieve(const char* gNumber, Student& foundStudent) const;
    int removeByProgram(const char* programName);
    int removeByGNumber(const char* gNumber);
    void displayAll() const;
    void monitor() const;

private:
    Node* root;
    //helper functions
    void destroyTree(Node*& curr);
    int insert(Node*& curr, const Student& toAdd);
    bool retrieve(Node* curr, const char* gNumber, Student& foundStudent) const;
    int removeByProgram(Node*& curr, const char* programName);
    int removeByGNumber(Node*& curr, const char* gNumber);
    void displayAll(Node* curr) const;
    int getHeight(Node* curr) const;
    int countNodes(Node* curr) const;
    void copyStudent(Student& dest, const Student& source) const;
    void destroyStudent(Student& s) const;
    Node* getLeftmostNode(Node* curr);
    int deleteNode(Node*& curr);
};

#endif
