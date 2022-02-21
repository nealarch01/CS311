// CS311 Yoshii - HW5 Priority Queue Implementation File
// Complete all ** parts and give good comments
// ** Do not delete my comments.

// =================================================
// HW5 Priority Printer Queue
// YOUR NAME: Neal Archival
// File Type: implementation pqueue.cpp
// =================================================

#include "pqueue.h"

// constructor
pqueue::pqueue() {
    count = 0;  // no jobs yet
}

// destructor does nothing
pqueue::~pqueue() {}

// Purpose: to add a job to a right place in the Pqueue
// Argument: j is the job priority number
// Remember that the current last job is in slot count-1.
void pqueue::insertjob(int j) {
    cout << "Adding: " << j << endl;
    if (count == MAX) {
        cout << "Error: Queue is full" << endl;   // prompt the user there is an error
        return; // return from the function
    }
    // ** add the job j at the rear (and update count)
    // **   if possible else display error message.
    Q[count] = j;
    count++;      // increment the total number of elements in the queue
    trickleup();  // moves the job to the right place
}

// Purpose: to print a job and reheapify the Pqueue
void pqueue::printjob() {
    cout << "Printing: " << Q[0] << endl;
    reheapify();
    count--; // decrement
}

// Purpose: to display all jobs
void pqueue::displayAll() {
    cout << "Jobs: ";
    cout << "[";
    // display the contents of the array
    for(int i = 0; i < count; i++) {
        cout << Q[i] << " ";
    }
    cout << "]" << endl;
    // ** loop to display jobs from slot 0 to slot count-1 horizontally. No need
    // to show a tree format.
}

// Utility functions follow: ------------------

void pqueue::swap(int loc1, int loc2) {
    // ** simply swap the values in these locations in Q
    int tempElem = Q[loc1]; // temporary element to hold the element of Q[loc1]
    Q[loc1] = Q[loc2];
    Q[loc2] = tempElem;
}

// Purpose: to make the very last job trickle up to the right location. Never do
// X--.
void pqueue::trickleup() {
    int x = count - 1;  // the very last job's location
    // ** While x is > 0
    //    compare Q[x] with the parent (*)
    //    and if the parent is bigger call swap & update x
    //    to be the parent . Otherwise stop the loop.
    // (*) Call getParent to get the location of the parent
    //            based on the child's location.
    int parentIndex;  // parent of x
    // while child is less than the index, we will keep swapping
    while (x > 0) {
        parentIndex = getParent(x); // get the parent of x first
        if(Q[x] < Q[parentIndex]) { // if the child is less than parent
            swap(x, parentIndex);  // swap the two numbers
            x = parentIndex;      // set x to the index of the old parent
        } else { // if(Q[x] < Q[parentIndex])
            return; // exit out the loop and function if greater than
        }
    }
}

// Purpose: find the location of the parent
// The child location is given.  Need to call even.
int pqueue::getParent(int childloc) {  // ** return the parent location based on the child loc
    // check if childloc is even, if even, then reverse findChild formula (Index
    // - 2) * 2, if odd, reverse formula (Index - 1) / 2 and return the value
    if(even(childloc)) return (childloc - 2) / 2; // if even, return the reversed formula to find right child
    return (childloc - 1) / 2;  // if odd, return the reversed formula to find left child
}

// Purpose: is location i even? Important in finding its parent location
bool pqueue::even(int i) {
    if ((i % 2) == 0)
        return true;
    else
        return false;
}

// Purpose: to reheapify the Pqueue after printing
//  This trickles down.  Never do X++.
void pqueue::reheapify() {
    int X = 0;            // the current location
    Q[0] = Q[count - 1];  // move the last job to the front
    // ** Start X at 0 (the root)
    //    while X is within the array:
    //       Find the location of the smaller child
    //       (if the location of both children are off the tree, stop the loop).
    //       If the smaller child is smaller than the parent,
    //          call swap and X becomes the smaller child's location.
    //       else no swaps so stop to loop.
    int childIndex;
    while(getSmallerchild(X) < count) {  // while the child of X is within the loop (less than count)
        childIndex = getSmallerchild(X);
        if(Q[X] > Q[childIndex]) {
            swap(X, childIndex); // swap the two numbers.
            X = childIndex; // update X
        } else { // if Q[X] < Q[childIndex]
            return;
        }
    }
}

// Purpose: to find the location of the smaller child
// where children are at locations 2*i+1 and 2*i+2
int pqueue::getSmallerchild(int i) {
    int LC, RC;  // locations of children
                 // ** set LC and RC first.
    // ** return the location of the smaller child
    //    Be careful because one or both of them may be
    //    beyond count-1.  Check boundaries before you
    //    compare Q contents!!!!
    //    If both are beyond count-1, you want to return a special value.
    RC = i * 2 + 2; // formula to find the right child
    LC = i * 2 + 1; // formula to find the left child
    
    if(LC > count - 1) { // RC is always going to be +1 greater than LC. If LC is out of range, then RC is out of range.
        return count; // we will return the size of the array, this will make it so that reheapify function can end it's loop
    } else if(RC > count - 1 && LC <= count - 1) { // if only the right child is out of range and left child is still in range
        return LC; // return the left child
    }
    // if neither are out of range, do regular comparison
    if (Q[RC] < Q[LC]) return RC;  // check which child is the least and return the least number's position
    return LC; // if Q[LC] is less than right child
}

// NEVER GO TO UNUSED PART OF THE ARRAY
