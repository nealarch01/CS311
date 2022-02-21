// CS311 Quick Sort - plug in your partition and it should work
----------------------------------------------------------------

#include<iostream>
using namespace std;

// partitions the array a into smaller than pivot and others.
int partition(int a[], int f, int r)
{
cout << ".. Partition called with " << "front " << f << " and rear " << r << endl;
// ** your partition here but it needs to
// ** set the pivot to a[0] at the start

}


// sorting a's section starting at f and ending at r
void quicksort(int a[], int f, int r)
{
  if (f >= r) return;

  cout << "QuickSort front is " << f << " and rear is " << r << endl;

  int beg = partition(a, f, r);

  quicksort(a, f, beg-1);  // sort the small section in place
  quicksort(a, beg, r);    // sort the large section in place
}


int main()
{
  int x;
  int nums[10];
  cout << "How many elements? (must be less than 10) "; 
  cin >> x;
  cout << "Enter elements one per line.." << endl;
  for (int i = 0; i < x; i++)
    { cin >> nums[i]; }

  quicksort(nums, 0, x-1);

  cout << "FINAL RESULT:" << endl;
  for (int i = 0; i < x; i++) // up to the partition
      {cout << nums[i]; }
  cout << endl;
}
