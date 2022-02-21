#include <fstream> // std::ifstream
#include <iostream> // std::cout
#include <vector> // std::vector
using namespace std;

//--------------------------------------
// CS311 File mat.cpp for HW1P3 Matrix
// Compiler: g++
// Your name: Neal Archival
//--------------------------------------

// the following can be changed and the rest of the code should work
int const R = 3;   // number of rows
int const C = 4;   // number of columns
int const VL = 3;  // table entry vector length

vector<char> T[R][C];  // 3 rows and 4 columns table for now

// ------------------ Functions --------------------------------

// Purpose: Convert the column character into an integer so we can access column in our matrix
// Parameter: any single character to be converted into integer
int convert(char x) {
    //  ** do a formula to convert a to 0, b to 1, c to 2 etc.
    // check if x is in between or equal to 'a' and 'z' characters
    if(x >= 'a' && x <= 'z') return x - 'a'; // subtract by 'a' ascii to return the integer value
    return x; // if the character is not a lowercase alphabet key return the same character
}

// Purpose: this reads the input file into the matrix table
void readTable() { 
    int row, col;
    char col_c;
    ifstream fin("lines.txt", ios::in);
    // Read in the file into vector matrix
    while (fin >> row) {  // per row
        vector<char> V;
        fin >> col_c; // read the column
        col = convert(col_c);  // to a slot number
        char c;                // one char from the file
        // ** Fill vector V with chars from the file (a for loop)
        for(int i = 0; i < VL; i++) { // get the VL characters and push it into the new vector
          fin >> c; // read the character
          V.push_back(c); // push back into vector
        }
        // ** Put the vector in T[row][col]
        T[row][col] = V;
    }  // end of while
    
}

// Purpose display the vector nicely to the outstream
// Parameters: vector (vector of characters from matrix) and output stream (cout or fout)
void showVector(vector<char> v, ostream& ost) {
    if (v.size() == 0)  // empty ent ry will be dashes
        for (int i = 1; i <= VL; i++) ost << "- ";
    else {  // ** show the content of v separated by blanks if size > 0
      for(int i = 0; i < v.size(); i++) ost << v[i] << " ";
    }
}

// Purpose: display the table used for the matrix
void displayTable() {
    // display T nicely labeled with row numbers
    //    by calling showVector with cout
    //    for each column
    for (int r = 0; r < R; r++) {
        cout << r << ":";
        for (int c = 0; c < C; c++) {
            showVector(T[r][c], cout);
            cout << "|";
        }
        cout << endl;
    }
}

// Purpose: Save the output to it's own file
void saveTable() {
    ofstream fout("table.txt", ios::out);
    // use the same algorihtm to display the table but instead use fout to display the table
      for (int r = 0; r < R; r++) {
        fout << r << ":";
        for (int c = 0; c < C; c++) {
            showVector(T[r][c], fout); // pass fout since we want to print to another file
            fout << "|";
        }
        fout << endl;
    }
    // ** output T nicely labeled with row numbers
    //    by calling showVector with fout
    //    for each column
}

//
int main() {
    cout << "reading from lines.txt" << endl;
    readTable(); // read information into single vector
    displayTable(); // display the table with matrix information
    cout << "saving the table in table.txt" << endl;
    saveTable(); // save the output into another file
    return 0;
}  