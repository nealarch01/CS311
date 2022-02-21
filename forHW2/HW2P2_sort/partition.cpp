#include <iostream>
using namespace std;

// You may not change my code in any manner.  0 pts if you do!!!!!!
// Simply add your code for **

//----------------------------------------
// CS311 HW2P2 Partition
// Name: Neal Archival
// Compiler: g++
//-----------------------------------------

// partitions the array a into smaller than pivot and others.
// f is the beginning of the section to be partitioned
// r is the end of the section to be partitioned
// return the first slot of the Large section
int partition(int a[], int f, int r) {
    int pivot = a[f];  // pivot is the first element a[0]
    int small = f;     // pointer from the left
    int large = r;     // pointer from the right

    while (small <= large) {
      if(a[small] < pivot) { // if small pointer number is not large, then move small pointer
        small++;
        continue; // continue looping
      }
      if(a[large] > pivot) { // if large number if not large, then move large pointer
        large--;
        continue; // continue to loop after increment
      }
      // if mismatch exists, then do a swap and move both pointers
      int temp = a[small];
      a[small] = a[large];
      a[large] = temp; // do swap
      small++;
      large--; // change both pointers
    }
    return small;
    // ** there is a special cases and a regular case
}

int main() {
    int x;  // number of elements
    int nums[10];
    cout << "How many elements? (must be less than 10) ";
    cin >> x;
    cout << "Enter elements one per line.." << endl;
    for (int i = 0; i < x; i++) {
        cin >> nums[i];
    }

    // the pivot is always the first element
    cout << "Ok the pivot is " << nums[0] << endl;

    int part = partition(nums, 0, x - 1);

    cout << "Results..." << endl;
    // display up to the partition without endl
    for (int i = 0; i < part; i++) cout << nums[i];

    cout << "|";
    // display from the partition on.. without endl
    for (int i = part; i < x; i++) cout << nums[i];

    cout << endl;
}
