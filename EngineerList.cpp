/*********************************************************************************************
 Name:              Nidhi Kairon
 Class Number:      CS260 - 20778
 Project Number:    1
 Name of File:      EngineerList.cpp
 File Description:  This file implements the EngineerList class, which uses Singly Linked List
		    as its underling data structure for managing the collection of engineers. 
		    This file handles systematic deletion, dynamic node insertion, and
		    recursive traveral.
 **********************************************************************************************/

#include <iostream>
#include "Engineer.h"
using namespace std;

EngineerList::EngineerList() : head(nullptr), count(0) {}

void EngineerList::destroyRecursive(Node* curr) {
    if (!curr) return;
    destroyRecursive(curr->next);
    delete curr;
}

EngineerList::~EngineerList() {
    destroyRecursive(head);
}

bool EngineerList::add(const Engineer& newEng) {
    Node* newNode = new Node(newEng);
    
    if (!head || newNode->data.compare(head->data) < 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* curr = head;
        while (curr->next && newNode->data.compare(curr->next->data) > 0) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    count++;
    return true;
}
bool EngineerList::promoteEngineer(int index) {
    if (!head || index < 1 || index > count) return false;

    Node* curr = head;

    for (int i = 1; i < index; ++i) {
        curr = curr->next;
    }

    curr->data.promote();
    return true;
}

void EngineerList::displayAll() const {
    if (!head) {
        std::cout << "The list is currently empty." << std::endl;
        return;
    }

    int index = 1;
    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        std::cout << index << ". ";
        curr->data.display();
        index++;
    }
}

bool EngineerList::removePoorPerformers() {
    if (!head) return false;

    bool removedAny = false;
    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr) {
        if (curr->data.getAssessment() == 1) {
            Node* temp = curr;

            if (prev == nullptr) {
                head = curr->next;
                curr = head;
            } else {
                prev->next = curr->next;
                curr = prev->next;
            }

            delete temp;
            count--;
            removedAny = true;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return removedAny;
}

bool EngineerList::editAssessment(int index, int newRating) {
    if (!head || index < 1 || index > count) return false;
    Node* curr = head;
    for (int i = 1; i < index; ++i) {
        curr = curr->next;
    }
    curr->data.setAssessment(newRating);
    return true;
}

void EngineerList::displayByLevel(int level) const {
    displayByLevelRecursive(head, static_cast<Title>(level));
}

void EngineerList::displayByLevelRecursive(Node* curr, Title level) const {
    if (!curr) return;

    if (curr->data.getTitle() == level) {
        curr->data.display();
    }

    displayByLevelRecursive(curr->next, level);
}
