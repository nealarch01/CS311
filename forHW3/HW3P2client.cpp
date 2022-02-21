// CS311 Yoshii
// INSTRUCTION:
// Read the whole file first.
// Look for ** to complete all of them.
// The output should match my assingment sheet. Check!!!
// DO not forget to Tab on each line

//=========================================================
// HW#: HW3P2 slist
// Your name: Neal Archival
// Complier:  g++
// File type: client program (tester) HW3P2client.cpp
//===========================================================

#include <stdlib.h>

#include <iostream>

#include "slist.h"

using namespace std;

// PURPOSE: Testing search and replace functions
void testOne() {
    slist L;          // the list
    int foundPos;     // to hold the found position from Search
    int counter = 1;  // used to display test line number
    try {
        //  1)add to front once (element 4)
        cout << "Step " << counter << " addFront" << endl;
        counter++;
        L.addFront(4); 

        //  2)add to rear 3 times (elements 6,7,8)
        cout << "Step " << counter << " addRear" << endl;
        counter++;
        for (int i = 6; i < 9; i++) L.addRear(i);

        //  3)displayAll    - 4 6 7 8
        cout << "Step " << counter << endl;
        counter++;
        L.displayAll();

        //  4)search for 6, report the result  - found in pos 2
        cout << "Step " << counter << endl;
        counter++;
        foundPos = L.search(6); // reassign foundPos to the position of the newly found item
        cout << "Found 6 in location " << foundPos << endl;

        //  5)replace the 6 with 0 using the search result (foundPos)
        cout << "Step " << counter << " replace 6" << endl;
        counter++;
        L.replace(0, foundPos);

        // 6)displayAll - 4 0 7 8
        cout << "Step " << counter << endl;
        counter++;
        L.displayAll(); 

        // 7)search for 8 and report the result - found in pos 4
        cout << "Step " << counter << endl;
        counter++;
        foundPos = L.search(8); // search if 8 exists in the list
        cout << "Found 8 in location " << foundPos << endl; 

        // 8)replace the 8 with 2 using the search result (foundPos)
        cout << "Step " << counter << " replace 8" << endl;
        counter++;
        foundPos = L.search(8); // first find the position where 8 lives
        L.replace(2, foundPos); // pass the new number we are replacing and the position where we found 8

        // 9)displayAll                       - 4 0 7 2
        cout << "Step " << counter << endl;
        counter++;
        L.displayAll();

        // 10)search for 5 and report the result   - not found
        cout << "Step " << counter << endl;
        counter++;
        foundPos = L.search(5); // reassign foundPos to find the position in which 5 exists
        // conditionals: if foundPos returns 0, the element is not found, otherwise print the location if 5 was found
        if(foundPos == 0) cout << "Element not found" << endl; // since 5 does not exist in the list, this should be printed
        else cout << "Found 5 in location " << foundPos << endl; 

        // 11) replace postion 7 with 10
        // attempt to replace an element using an invalid position
        cout << "Step " << counter << " replace 7" << endl;
        counter++;
        L.replace(7, 10); 


    }  // end of try
    catch (llist::OutOfRange) {
        cerr << "ERROR: Bad position was given" << endl;
    }   
    // additional edge cases for OutOfRange exception
    cout << "----------- Edge Cases (replacing at Count - 1 and 0 when list is empty --------------" << endl;
    // try replacing at Count + 1 (currently list has 4 items so Greatest Position == 4)
    cout << "Replacing at Position 5" << endl;
    try {
        L.replace(5, 10); // replace position 5
    } catch(llist::OutOfRange) {
        cerr << "Error: Bad position was given" << endl;
    }
    slist L3;
    cout << "Replacing at Position 0 with empty list" << endl;
    try {
        L3.replace(10, 0);
    } catch(llist::OutOfRange) {
        cerr << "Error: Bad position was given" << endl;
    }
    cout << "Replacing at Position -1" << endl;
    try {
        L3.replace(10, -1);
    } catch(llist::OutOfRange) {
        cerr << "Error: Bad position was given" << endl;
    }
    cout << "Replacing position 1 with empty list" << endl;
    try {
        L3.replace(10, 1);
    } catch(llist::OutOfRange) {
        cerr << "Error: Bad position was given" << endl;
    }
}  // end of testOne

// PURPOSE: Testing overloading of ==
void testTwo() {
    slist L1, L2;

    // 1. L1 is empty and L2 is empty
    if (L1 == L2)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    // 2. L1 is empty and L2 with 4, 5
    L2.addRear(4);
    L2.addRear(5);
    if (L1 == L2)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    // 3.  The opposite
    if (L2 == L1)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    // 4. L1 with 1,2,3 and L2 with  1,2,3
    L1.addRear(1); 
    L1.addRear(2);
    L1.addRear(3);
    int x;
    L2.deleteFront(x);
    L2.deleteFront(x);
    L2.addRear(1);
    L2.addRear(2);
    L2.addRear(3);
    if (L1 == L2)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    // 5. L1 with 1,2,3 and L2 with  1,2
    L2.deleteRear(x);
    if (L1 == L2)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    // 6. L1 has 1,2,3 and L2 has 1,2,3,4
    L2.addRear(3);
    L2.addRear(4);
    if (L1 == L2)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    // 7. L1 has 1,2,3 and L2 has 1,2,4
    L2.deleteRear(x);
    L2.deleteRear(x);
    L2.addRear(4);
    if (L1 == L2)
        cout << "true" << endl;
    else
        cout << "false" << endl;

}  // end of testTwo

// PURPOSE: to test slist thoroughly
int main() {
    testOne();  // for search and replace

    cout << "---- First Part testing done ----- " << endl;

    testTwo();  // for testing ==

}  // end of program
