// CS311 Yoshii Complete all functions with their comments

// ====================================================
// HW#: HW3P1 slist  inheriting from llist
// Your name: Neal Archival
// Complier:  g++
// File type: slist.cpp implementation file
//=====================================================

#include "slist.h"

#include <iostream>
using namespace std;

// ** Make sure llist constructor and destructors have couts in them

// do not change this one
slist::slist() { 
    cout << "slist constructor: " << endl; 
}

// positions always start at 1

// Purpose: Search if an element exists in the list
// Parameter: key: element we want to search for
int slist::search(el_t key) {
    Node *tempPtr = Front; // temporary pointer
    int position = 0; // initialized to 0 so we increment first since position is behind
    // implement our own list iteration. If we use moveTo loop function to iterate list would be dangerous because of exception handling (also less lines than throw catch block)
    while (tempPtr != NULL) {
        position++; // increment first since position is initialized as 0. Purpose is to match the position of the element we are finding
        if (tempPtr->Elem == key) {
          tempPtr = NULL; // set back to NULL because we don't need this pointer anymore
          return position; // return the current position
        }
        tempPtr = tempPtr->Next; // advance to the next node
    }
    return 0; // if we iterate through the entire list and not found our key
}

// don't forget to throw OutOfRange for bad pos
// You should use moveTo to go to the pos
// Purpose: replace an element at certain position
// Parameter: el_t new element, int position we are putting element into
void slist::replace(el_t element, int pos) {
    if (pos < 1 || pos > Count) throw OutOfRange(); // check if a valid position is given, if not then throw OutOfRange exception
    Node *toReplace = Front; // temporary pointer to go the certain position of the node we want to replace
    moveTo(pos, toReplace); // call moveTo to advance to point to the node we are replacing
    toReplace->Elem = element; // change the element
    toReplace = NULL; // since we are no longer using this pointer and we don't need it, set back to NULL
}

// Purpose: Overloaded operator to do a list comparison. Check if both lists have the same size and elements in order.
// Parameters: The other list we want to make comparison (list1 == list2)
bool slist::operator==(const slist &OtherOne) {
    if (this->Count != OtherOne.Count) { // first check the number of elements in the list
        return false; // if they are not the same size, they are not the same
    }
    Node *localPtr = this->Front; // pointer for our left side list (list1 of list1 == list2)
    Node *otherPtr = OtherOne.Front; // pointer for our right side list (list2 of list1 == list2)
    while (localPtr != NULL || otherPtr != NULL) { // while neither of our pointers are not NULL
        if (localPtr->Elem != otherPtr->Elem) { // compare the element contents of each node
            return false; // if they are not the same, return
        }
        localPtr = localPtr->Next; // advance to next node on list1 pointer
        otherPtr = otherPtr->Next; // advance to next node on list2 pointer
    }
    return true; // if we get to the end without any mismatches, the lists are the same
    // if not the same length, return false
    // if the same lengths,
    // check each node to see if the elements are the same
}
