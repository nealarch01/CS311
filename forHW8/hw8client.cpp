// CS311 Yoshii - complete ** for HW8 client
// Note that the client knows about elem.h functions.
// It can create el_t objects.
//-----------------------------------------------

//============================================
// HW#: HW8 hashing client
// Name: **
// File type: client hw8client.cpp (tester)
//===========================================

#include <fstream>
#include <iostream>
#include <string>

#include "htable.h"
using namespace std;

// This tester gets input data interactively but
// for a useful client, input should come from a file.
// Note that el_t X; will create a blank element X using the regular
// constructor. Note that the second constructor of el_t can be used to create
// key+other info to add to the table. e.g. el_t X(30, "mary");
int main() { 
  /**
     fillTable
     making sure some of elements  collide. (function add)
     You can create el_t containing a key using a constructor.
 DisplayTable.

 Loop:
  Interactively look up names using keys. (function find)
    Cout element if found else (blank element was returned i.e. key part is -1)
    an error message.
    */
    htable weatherTable; // table used to store our info
    weatherTable.fillTable(); // get filename and read information
    weatherTable.displayTable(); // display the table
    int lookUpKey; // the key we are looking up (3 digit area code)
    el_t keyData, blankObj; // keyData: el_t object we use to collect the data from the find function
    while(1) { // infinite loop to keep running programming until user exits via ctrl+c
      cout << "Ctrl+C to Exit" << endl;
      cout << "Enter area code: ";
      cin >> lookUpKey;
      keyData = weatherTable.find(lookUpKey); // set keyData to the key that is being found
      cout << "----------------------------" << endl;
      if(keyData == blankObj) { // if the key of collected data and blankObj match, there was no data found
        cout << "Key not found" << endl; // inform user we did not find the key
      } else {
        cout << "Key found" << endl;
        cout << keyData << endl;
      }
      cout << "----------------------------" << endl;
    }
    return 0;
}
