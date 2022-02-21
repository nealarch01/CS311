// CS311 Merge Sort - plug in your combine and it should work
--------------------------------------------------------

using namespace std;
#include <iostream>
#include <vector>

void display(vector<int> X)
{ cout << "[ ";
  for (int i = 0; i < X.size(); i++)
    cout << X[i] << " ";
  cout << "]" << endl;
}

void Combine( vector<int> A, vector<int> B, vector<int> &R )
{
  // your combine here  
}


// sort N into R
void MergeSort(vector<int> N, vector<int>& R)
{ vector<int> L1, L2, L1R, L2R;

  // only one element, so done
  if (N.size() == 1) {R.push_back(N[0]); return;}

  cout << "Merge sort called on: "; display(N);

  // divide N into L1 and L2
  for (int i = 0; i < N.size()/2; i++)
    L1.push_back(N[i]);
  for (int i = N.size()/2; i < N.size(); i++)
    L2.push_back(N[i]);

  cout << "1st half:" << endl;
  display(L1);
  cout << "2nd half:" << endl; 
  display(L2);

  // sort the first half and produce L1R
  MergeSort(L1, L1R); 
  // sort the second half and produce L2R
  MergeSort(L2, L2R); 

  // combine the sorted halves into sorted R
  Combine(L1R, L2R, R); 
}

int main()
{
  vector<int> Mine, Mine2;
  int a;
  cout << "Enter elements or -1 to stop" << endl;
  cout << "Element:"; cin >> a;
  while (a != -1)
    {
      Mine.push_back(a);
      cout << "Element:"; cin >> a;
    }
  MergeSort(Mine, Mine2);  // produce Mine2

  cout << "FINAL RESULT:" << endl;
  display(Mine2);
}
