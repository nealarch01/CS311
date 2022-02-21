// CS311 Yoshii
// INSTRUCTION:
// Llist class - header file template
// You must complete the ** parts and then complete llist.cpp
// Don't forget PURPOSE and PARAMETERS

// =======================================================
// HW#: HW3P1 llist
// Your name: Neal Archival
// Compiler:  g++
// File type: headher file  llist.h
//=======================================================

#include "elem.h"

// alias el_t : element type definition


// a list node is defined here as a struct Node for now
struct Node {
    el_t Elem;   // elem is the element stored
    Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist {
   protected: // change access specifier to allow classes to inherit information
    Node *Front;  // pointer to the front node
    Node *Rear;   // pointer to the rear node
    int Count;    // counter for the number of nodes

    // untility function to move to a specified node position
    void moveTo(int, Node *&);

   public:
    // Exception handling classes
    class Underflow {};
    class OutOfRange {};  // thrown when the specified Node is out of range

    llist();   // constructor to create a list object
    ~llist();  // destructor to destroy all nodes

    // Check if there are any nodes in the list
    bool isEmpty();

    // Display all of the elements of list
    void displayAll();

    // Add a new node and point Front pointer to the new node
    void addFront(el_t);

    // Add a new node and point Rear pointer to the new node
    void addRear(el_t);

    // Delete the node front is pointing to and point Front to the second node
    void deleteFront(el_t &);

    //---------------------------------------

    // Delete the node rear is pointing to and point rear to the second to the
    // last node 3 conditionals to check if the list is empty
    void deleteRear(el_t &);

    // Delete a node in certain position
    void deleteIth(int, el_t &);  // calls moveTo

    // Insert a node in certain position
    void insertIth(int, el_t);  // calls moveTo

    // Copy Constructor to allow pass by value and return by value of a llist
    llist(const llist &);

    // Overloading of = (returns a reference to a llist)
    llist &operator=(const llist &);
};
