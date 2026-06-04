/**********************************************************************************************
 Name:              Nidhi Kairon
 Class Number:      CS260 - 20778
 Project Number:    3
 Name of File:      table.h
 File Description:  This file implements the linked list and array by defining the interface for
                    the ADT for the Hash Table. This file estabilishes interaction of the
                    program by establishing insert, retreive, editing, removing
                    unacceptable standings, and as well as display and monitor. 
 Structures:        There's a stuct student and strcut node. A struct student has a dynamic pointer
                    programName that acts as a hash key, it also has a gNumber pointer
                    that holds student ID, and a studentName also is a pointer that holds
                    student name and it has one more pointer of academic standing that
                    speaks about the performance of a student. This struct holds all the
                    student information. Struct node is the one that builds linked lists.
                    It holds student record and also a has a pointer to the next node.
                    Its inked lists that it build is the one that builds inside the hash table
                    buckets. Both of these group relate variables.
 Classes:           class Table makes the system that functions the hash table. It centrelized the
                    entire data structure. It manages memory, collisions, and hashing.
                    It has a private data members that has an array of Node pointers,
                    and tableSize that tracks the capacity of the array. This class
                    allocates these arrays on the system heap. It also makes sure that
                    the program doesn't crash. It uses private data members to handle
                    student record. This class dynamically builds chains of students. This
                    Table class acts as a saffety manager for the entire program.
 Prototypes:        Constructor: Table(int size = 101). Destructor: ~Table(). Boolean Prototypes:
                    bool retrieve(const char* program, Student allMatches[], int& numFound)
                    const. Mutators: int insert(const Student& toAdd), int edit(const char*
                    program, const char* gNumber, int newStanding),
                    int removeUnacceptableStanding(), void clearTable(). Accessors: bool
                    retrieve(const char* program, Student allMatches[], int& numFound) const,
                    void displayAll() const, void monitor() const, int hashFunction(const char*
                    key) const.
 **********************************************************************************************/

#ifndef TABLE_H
#define TABLE_H

//holds student information
struct Student {
    char* programName;
    char* gNumber;
    char* studentName;
    int academicStanding;
};

//this is a singly linked list
struct Node {
    Student data; //holds student record
    Node* next; //pointer to the next node
};

class Table {
public:
    //constructor
    Table(int size = 101);
    //destructor
    ~Table();

    //operations 
    int insert(const Student& toAdd);
    bool retrieve(const char* program, Student allMatches[], int& numFound) const;
    int edit(const char* program, const char* gNumber, int newStanding);
    int removeUnacceptableStanding();
    void displayAll() const;
    void monitor() const;

private:
    Node** hashTable; //array
    int tableSize; //num of byckets in hash table that are available

    //helper functions
    int hashFunction(const char* key) const; //takes the c-string key and then converts to the index
    void clearTable(); //delete the nodes
    void copyStudent(Student& dest, const Student& source) const; //handle deep copying
    void destroyStudent(Student& s) const; //delete
};

#endif
