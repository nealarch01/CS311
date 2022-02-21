// CS311 Yoshii - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
// Edit ** parts
//----------------------------------------------------

#include "elem.h"

// blank element
el_t::el_t() {
    key = -1;  // cannot be 0 because 0 is a valid key
    name = ""; // initialize as empty string
    city = ""; // not initialized
    temperature = 0; // although this temperature is valid we will know it is invalid if city is an empty string
    //** initialize other parts to be blanks
}

// initializing constructor to create an el_t object
el_t::el_t(int aKey, string sName, string nCity, int tempF) {
    key = aKey; // set the key of the 
    name = sName;
    city = nCity;
    temperature = tempF;
    // ** initialize other parts to be the arguments
}

// ONLY the key part should be available to the user of this class
int el_t::getkey() { 
    return key; 
}

// ONLY the key part should be available to the user of this class
void el_t::setkey(int akey) { 
    key = akey;
}

// overload == for search based on the key part only
bool el_t::operator==(el_t OtherOne) {
    // list out all the false parts
    // find function only compares int key so other info is ignored in comparison
    if(this->key != OtherOne.key) return false;
    return true;
}

// Overloaded operator function that will check if el_t items are not equal to each other
// Parameters: other el_t object we want to compare
bool el_t::operator!=(el_t OtherOne) {
    // first check if they are equal to each other
    // if keys are equal, return false, otherwise, return true
    // our find function only checks for the key and city name and no other information
    if(this->key == OtherOne.key) return false;
    return true;
}

// overload cout
// Purpose: display the element object nicely
ostream& operator<<(ostream& os, const el_t& E) {
    os << "{" << E.key << ": "; // prints key
    if(E.key == -1) { // if the key is -1, the members are blank, do not display anything
        os << "No Data" << endl; // inform user no data to be shown
    } else { // if key is valid
        os << E.city << ", " << E.name; // display the city and state
        os << " " << E.temperature << "° Degrees Fahrenheit} "; // display the temperature
    }
    // os << E.key << " " << E.name << endl;  // *** display other parts of E in a nice way
    return os;
}