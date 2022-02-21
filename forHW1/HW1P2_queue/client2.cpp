//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 

//=========================================================
//HW#: HW1P2 queue application (generate all strings)
//Your name: Neal Archival
//Complier:  g++
//File type: client program client2.cpp
//===========================================================

#include <iostream> // cout
#include <stdlib.h> // exit(1) not used
#include <string> // string
#include "queue.h" // queue <string>

using namespace std;

//Purpose of the program: Generate strings of different combinations of A, B, and C strings, display it, 
// and push it into the queue until the queue becomes full
/**********************************************************
How algorihtm works:
1. Remove the front most string of the queue
2. Display the removed string to terminal
3. Concatenate a new string with added characters A, B, and C 
***********************************************************/
int main() { // ** "A", "B", "C" in the queue
  // ** while loop -- indefinitely while(true)
  queue q1; // queue object
  el_t temp; // string to hold the removed item from the queue

  // Initialize the queue with 3 empty strings first
  q1.add("A");
  q1.add("B");
  q1.add("C");

  // loop will run indefinitely
  while(true) { 
    try {
      q1.remove(temp); // remove the front most element
      cout << temp << endl; // display the front most element
      // add popped string and concatenate string with an additional character (A, B, or C)
      q1.add(temp + "A"); 
      q1.add(temp + "B");
      q1.add(temp + "C");

    } catch(queue::QueueOverflow) { // this exception is going to terminate the loop
      cerr << "Cannot add" << endl; // inform that all combinations have been done
      return 1; // return code 1
    } catch (queue::QueueUnderflow) { // in case a queue underflows or wasn't initialized properly we can catch the underflow
      cerr << "Queue is empty" << endl;
      return 1;
    }
  }
}
