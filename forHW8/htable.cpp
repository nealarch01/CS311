// CS311 Yoshii - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//-----------------------------------------------------

// ============================================
// HW#: HW8 Hash Table
// Name: Neal Archival
// File Type: implementation htable.cpp
// =============================================


#include "htable.h"
#include <iostream>
#include <fstream> // ifstream

using namespace std;

htable::htable() {}

htable::~htable() {}

// a simple hash function that uses % TSIZE simply
int htable::hash(int key) { 
  return key % TSIZE;
}

// adds the element to the table and returns slot#
int htable::add(el_t element) {
    int slot = hash(element.getkey());  // hash with the key part
    // ** Note that this means adding the element to a slist in the slot
    // (addRear)
    table[slot].addRear(element);
    return slot;
}

// finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
el_t htable::find(int skey) {
    int slot = hash(skey);  // hash with skey
    if(slot < 0 || slot >= TSIZE) { // if the slot index num is out of range
        el_t blankObj; // instantiate a blank object
        return blankObj; // return the blank object
    }
    el_t selement;          // this is the element to look for in slist
    /**                      // initialize selement with just the skey
     **   // call slist's search2 with selement which returns the found element
      **/  // return the found element from here (it could be blank)
    
    // call slistsearch2
    selement.setkey(skey); // initialize the search element with setkey
    el_t item = table[slot].search2(selement); // set the item e
    return item;
}

// fills the table using the specified input file
void htable::fillTable() {
    // ** model this after HW6 to get data from the file user specifies
    string filename; // the name of the file
    ifstream fin; // ifstream object
    cout << "Enter filename: "; 
    cin >> filename;
    fin.open(filename.c_str()); // convert to c-string to open file (c-str arg required for .open() function)
    string city, state; // two el_t string members, hold city and state name reading from fin
    int areacode; // will serve as our key
    int temperatureF; // temperature in fahrenheit 
    int index; // the index of the hash table we are putting out info into
    // while loop to read all the data
    while(fin >> areacode) {
        fin >> state; //read state
        fin >> city; // read city
        fin >> temperatureF; // read temperature
        el_t weatherData(areacode, state, city, temperatureF); // instantiate el_t object with data read from file
        index = hash(areacode);
        if(index < 0 || index >= TSIZE) continue; // an invalid area code that goes out of bounds has been read, so continue loop iteration to avoid segmentation fault
        table[hash(areacode)].addRear(weatherData); // add the el_t object into a hashed slot
    }
}

// displays the entire table with slot#s too    
void htable::displayTable() {
    // iterate through the entire list
    for (int i = 0; i < TSIZE; i++) {
        cout << i << ":";
        table[i].displayAll();
      //  **  // call slist's displayAll
    }
}
