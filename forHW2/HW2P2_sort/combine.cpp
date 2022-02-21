#include <iostream>
#include <vector>
using namespace std;
// Must use the algorithm that is in the notes!

//--------------------------------------------
// CS311 HW2P2 Combine
// Name: Neal Archival
// Compiler: g++
//--------------------------------------------

// combine two sorted lists A and B into R
// displays comparison every time it is done

void combine(vector<int> A, vector<int> B, vector<int> &R) {
    /*
       ** you can find out the size of A using the
       ** size function. Treat A and B like arrays.
       cout << "comparison" << endl;
       ** // be careful -- R comes in as an empty vector with no slots so you
       have to use push_back
    */
    // box index starting
    int aIndex = 0; 
    int bIndex = 0;
    while(aIndex < A.size() && bIndex < B.size()) { // while a and b index pointers are greater than or less than the index
        cout << "comparison" << endl; 
        if(A[aIndex] < B[bIndex]) { // compare element from A vector and B vector
            R.push_back(A[aIndex++]); // if A[index] element is smaller, push the smaller value into R and increment aIndex
        } else { // if A[index] element is greater than B[index] element
            R.push_back(B[bIndex++]); // push back smallest index and increment bIndex
        }
    }
    // while loop to push back any elements that are leftover
    while(aIndex < A.size()) R.push_back(A[aIndex++]);
    while(bIndex < B.size()) R.push_back(B[bIndex++]);
    return;
}


int main() {
    vector<int> L1;
    vector<int> L2;
    vector<int> L3;
    int N;  // how many elements in each of L1 and L2
    int e;  // for each element

    cout << "How many elements in each list?" << endl;
    cin >> N;

    cout << "List1" << endl;
    for (int i = 1; i <= N; i++) {
        cout << "element :";
        cin >> e;
        L1.push_back(e);
    }

    cout << "List2" << endl;
    for (int i = 1; i <= N; i++) {
        cout << "element :";
        cin >> e;
        L2.push_back(e);
    }

    // call combine here to combine L1 and L2 into L3
    combine(L1, L2, L3);

    cout << "The result is: ";
    for (int i = 0; i < N * 2; i++) {
        cout << L3[i];
    }
    cout << endl;

}  // end of main
