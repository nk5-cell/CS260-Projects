/**********************************************************************************************
 Name:              Nidhi Kairon
 Class Number:      CS260 - 20778
 Project Number:    1
 Name of File:      Engineer.h
 File Description:  This file defines the interface for the Engineer Managment System program
 Structures:        sturct Node (contains the instance of the Engineer class)
 Classes:           class Engineer (ADT represening an engineer. It includes dynamic memory
                    allocation for character strings, also includes a copy constructor), class
                    EngineerList (manages engineer objects, its a container class that ises
                    systematic memory deallocation to prevent memory leaks)
 Prototypes:        bool init(...) - dynamically allocates memory, init compare(...) - performs
                    manual characters comparison, void display() - outputs engineer's data,
                    promote() and setAssessment() - mutator functions, getAssessment and
                    getTitle() - accessor functions
 **********************************************************************************************/

#ifndef ENGINEER_H
#define ENGINEER_H

enum Title { L1, L2, L3, L4, L5, L6, L7, L8 };

class Engineer {
    public:
        Engineer();
        ~Engineer();
      
        bool init(const char* fName, const char* lName, Title title, int assessment);
        int compare(const Engineer& other) const;
        void display() const;
        int getAssessment() const { return assessmentLevel; }
        Title getTitle() const { return titleLevel; }
	void promote();
	void setAssessment(int newLevel);
	Engineer(const Engineer& other);

    private:
        char* firstName;
        char* lastName;
        Title titleLevel;
        int assessmentLevel;
};

class EngineerList {
    public:
        EngineerList();
        ~EngineerList();
        
        bool add(const Engineer& newEng);
        void displayAll() const;
        bool removePoorPerformers();
	bool promoteEngineer(int index);
	bool editAssessment(int index, int newRating);
        void displayByLevel(int level) const;

    private:
        struct Node {
            Engineer data;
            Node* next;
            Node(const Engineer& aData) : data(aData), next(nullptr) {}
        };

        Node* head;
        int count;
 
        void destroyRecursive(Node* curr);
	void displayByLevelRecursive(Node* curr, Title level) const;
};

#endif

