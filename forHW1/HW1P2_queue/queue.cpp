//INSTRUCTION:
//Look for ** using control-S
//Then, fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P2 queue
//Your name: Neal Archival
//Complier:  g++
//File type: **  queue.cpp
//===========================================================

#include <iostream>
#include "queue.h"  
using namespace std;

// constructor 
queue::queue()  {  /* initialize data members as in the notes */ 
  count = 0;
  rear = -1;
  front = 0;
}

//destructor 
queue::~queue() { /* nothing */ }

// PURPOSE: returns true if queue is empty, otherwise false - checks count
bool queue::isEmpty() { if(count <= 0) return true; return false; }

// PURPOSE: returns true if queue is full, otherwise false - checks count
bool queue::isFull() { if(count == MAX_SIZE) return true; return false; }

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem) { 
  if(isFull()) throw QueueOverflow();
  ++rear %= MAX_SIZE; // increment using algorithm to get the next index
  el[rear] = newElem; // access the new index and set it to the new element
  count++; // increment the total number of elements in the queue
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem) {
  if(isEmpty()) throw QueueUnderflow();
  removedElem = el[front]; // access the front element
  ++front %= MAX_SIZE; // we want our front to be after the removed element so we do it AFTER
  count--;
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem) { theElem = el[front]; }

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize() { return count; }

// PURPOSE: display everything in the queue horizontally
// from front to rear enclosed in [   ]
// if empty, displays [ empty ]
void queue::displayAll() {  
  if (isEmpty()) cout << "[ empty ]" << endl;
  else {
      int j = front;
      cout << "[";
      for (int i = 1; i <= count; i++) { 
        cout << el[j]; // print the element
        ++j %= MAX_SIZE; // increment j and get the modulo of max size to wrap around back to index 0
      }
      cout << "]" << endl;   
    }
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//calling remove followed by add.
void queue::goToBack() {           // ** comment a local variable
  if(isEmpty()) throw QueueUnderflow();
  if(count == 1) return; // return back to client
  el_t temp; // temporarily hold the value we are swapping
  remove(temp); // remove the front element
  add(temp); // move the front element into the last slow of the array
}