// intlist.cpp
// Implements class IntList
// Dingfan Zheng, 7/21/2021

#include "intlist.h"

#include <iostream>

using std::cout;

// copy constructor
IntList::IntList(const IntList &source) {
    first = nullptr;
    Node *prev = nullptr;
    for (Node *sourceNode = source.first; sourceNode != nullptr; sourceNode = sourceNode->next) {

        Node *copy = new Node;
        copy->info = sourceNode->info;
        copy->next = nullptr;

        if (first == nullptr) {
            first = copy;
        }
        if (prev != nullptr) {
            prev->next = copy;
        }

        prev = copy;
    }

    //IMPLEMENT THIS
}

// destructor deletes all nodes
IntList::~IntList() {
    Node *node = first;
    while (node != nullptr) {
        Node *temp = node;
        node = node->next;
        delete temp;
    }
    // IMPLEMENT THIS
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;

    Node *node = first;
    while (node != nullptr) {
        sum += node->info;
        node = node->next;
    }

    return sum; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node *node = first;
    while (node != nullptr) {
        if (node->info == value)
            return true;
        node = node->next;
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (first == nullptr)
        return 0;
    int max = first->info;
    Node *node = first->next;
    while (node != nullptr) {
        if (node->info > max) {
            max = node->info;
        }

        node = node->next;
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (first == nullptr)
        return 0;
    return (double) sum() / count();
    // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node *newFirst = new Node;
    newFirst->info = value;
    newFirst->next = first;
    first = newFirst;
    // IMPLEMENT
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList &IntList::operator=(const IntList &source) {
    Node *node = first;
    while (node != nullptr) {
        Node *temp = node;
        node = node->next;
        delete temp;
    }


    first = nullptr;
    Node *prev = nullptr;
    for (Node *sourceNode = source.first; sourceNode != nullptr; sourceNode = sourceNode->next) {

        Node *copy = new Node;
        copy->info = sourceNode->info;
        copy->next = nullptr;

        if (first == nullptr) {
            first = copy;
        }
        if (prev != nullptr) {
            prev->next = copy;
        }
        prev = copy;
    }

    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) {}


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    } else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
