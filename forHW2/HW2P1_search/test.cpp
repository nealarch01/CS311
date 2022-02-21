#include <iostream>
using namespace std;

//--------------------------------------------
// CS311 HW2P1 Binary Search
// Name: Carlos Andre Hernandez
// Compiler: g++
// --------------------------------------------

// x is what we are looking for in L; first and last are slot numbers 
int binarySearch(int L[], int x, int first, int last) {
    int middle = (first+last)/2;
    
    if (x == L[middle])     // Returns if x is in middle
        return middle;
    else if (first == last) // Returns -1 if not found
        return -1;
    else if (x < L[middle])
        last  = middle - 1; // Searches the first half
    else if (x > L[middle])
        first = middle + 1; // Searches the second half
    
    cout << "comparing against an element in slot " << middle << endl;
    return binarySearch(L, x, first, last); // Recursive Function
}

int main(){
    int A[10];              // Fixed Array
    int e;                  // to look for this
    int first = 0;
    int last = 9;

// fixed elements for A
    A[0] = 1; A[1]= 3; A[2]=5; A[3]= 7; A[4]=9; A[5]=11; A[6]=13;
    A[7] =15; A[8]= 17; A[9]= 19;

    cout << "What do you want to look for? ";
    cin >> e;

// Call binarySearch here to look for e in A
    //  Returns from a recursive call
    int respos = binarySearch(A, e, first, last);

    if (respos == -1) cout << "Element not found" << endl;
    else cout << "Found it in position " << respos+1 << endl;
    
    return 0;
}