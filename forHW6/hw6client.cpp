// CS311 Yoshii
// HW6 Client file 
//INSTRUCTION: Complete this file and comment using How to Comment file.
//---------------------------------------------

#include <iostream> // cout, cerr, cin
#include "dgraph.h" // only need to include graph because other headers are included in thish eader file
// ================================================
// HW#: HW6 dgraph client 
// Name: Neal Archival
// File type:  hw6client.cpp  (tester)
// ================================================

//**
int main()
{ /**
  0.Declare dgraph object
  1.fillTable()
  2.displayGraph()
  while (the user does not want to stop)
    a.the user will specify which vertex     
    b.findOutDegree of the vertex and display the result
    b.findAdjacency of the vertex and display the result (see Hint)
    c.catch exception to display error mesg but do not exit
  */
  dgraph graph;
  char key; // search key, search for a character
  slist adjacentVertices; // the list of adjacent vertices a vertex has
  int numOfDegrees; // the number of degrees for us to display
  graph.fillTable(); // fill the table (read from file)
  graph.displayGraph(); // display all the vertices
  while(1) {
    cout << "Enter a vertex name: "; 
    cin >> key;
    try {
      numOfDegrees = graph.findOutDegree(key); //
      adjacentVertices = graph.findAdjacency(key); 
      cout << "Number of degrees: " << numOfDegrees << " " << endl;
      adjacentVertices.displayAll();
    } catch (dgraph::BadVertex) {
      cerr << "Bad vertex given" << endl;
    }
  }
  return 0;
}

/*
Hint:
  slist l1;
  l1 = G.findAdjacency('a');
  // how do you display l1?  Hint: it is an slist from HW3.

*/
