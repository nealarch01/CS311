#include <iostream>
using namespace std;
// The Algorithm is in Notes-4A so copy and paste it here!!!!!
// On Empress, control-rightclick will bring up the paste option.

// --------------------------------------------
// CS311 HW2P1 Binary Search
// Name: Neal Archival
// Compiler: g++
// --------------------------------------------

// x is what we are looking for in L; first and last are slot numbers
// This returns the slot number in which x was found or -1 (return the index number)
// Parameters: L[] array of integers, x == key or number we want
// first == left bound; last == right bound
/*
Algorithm: get the middle index of first and last, check if the key exists in the middle index
If not, check if the key is greater than or equal to middle index element
If less than, return the
*/
int binarySearch(int L[], int x, int first, int last) {
    if(first > last) return -1; // base case (if first and last overlaps each other key was not found)
    int middle = (first + last) / 2; // get the middle index of first and last
    cout << "comparing against an element in slot " << middle << endl; // display the index of the item we are searching
    // check if middle index contains key element
    // if not, check if array middle index is less than or greater, then update first and front
    if(L[middle] == x) return middle; // return middle index if key is found
    L[middle] > x ? last = middle - 1 : first = middle + 1; // if x (the number we look for) is less than middle change the last index to middle - 1, otherwise change first to middle + 1
    return binarySearch(L, x, first, last); // call the function again to find
}

int main() {
    int A[10];
    int e;  // to look for this (key)

    // fixed elements for A
    A[0] = 1;
    A[1] = 3;
    A[2] = 5; 
    A[3] = 7;
    A[4] = 9; 
    A[5] = 11;
    A[6] = 13; 
    A[7] = 15;
    A[8] = 17; 
    A[9] = 19;

    for(int i = 0; i < 10; i++) { // display all elements in the array
        cout << A[i] << ' ';
    }
    cout << endl;

    cout << "What do you want to look for? ";
    cin >> e;

    // Call binarySearch here to look for e in A
    int respos = binarySearch(A, e, 0, 10);

    if (respos == -1)
        cout << "Element not found" << endl;
    else
        cout << "Found it in position " << respos + 1 << endl; // add to get the position number not the index
}
