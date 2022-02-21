//CS311 Yoshii dgraph.cpp 
// INSTRUCTION:
//  Complete all the functions you listed in dgraph.h
//  Comment the file completely using How to Comment file.
//  Use HW6-help.docx to finish the functions.
//-------------------------------------------------------

//======================================================
// HW#: HW6 dgraph
// Name: Neal Archival
// File Type: dgraph.cpp
//========================================================

#include <iostream>
#include <fstream>
#include <string>
#include "dgraph.h"

using namespace std;

dgraph::dgraph()
 // initialize vertexName (blank) and visit numbers (0) for all slots of the table
 // initialize countUsed to be 0
{
  countUsed = 0; // initialize the number of characters used to none
  for(int i = 0; i < SIZE; i++) { // loop through the entire map of vertices and assign them with default values
    Gtable[i].vertexName = ' '; // initialize as blank spcae
    Gtable[i].visit = 0;
    Gtable[i].outDegree = 0; // number of degrees
  }
}

dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{ // do nothing, we aren't creating any objects in the heat, it's coverered by slist
}

// Purpose: Reads table data from a file and updates the array with graph data
void dgraph::fillTable()  // be sure to read from a specified file
{
  string fname;
  cout << "Enter a file name: ";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in); // declare and open fname
  // the rest is in HW6-help
  int i = 0; // counter for the first loop so we can assign the vertex to the current index
  char temp_adjacentVertex;
  // loop to read while a vertex name is provided
  while(fin >> Gtable[countUsed].vertexName) { // while we are able to read the vertext name
    fin >> Gtable[countUsed].outDegree; // read the degree
    // create a loop and read the number of vertices
    for(int j = 0; j < Gtable[countUsed].outDegree; j++) { //
      fin >> temp_adjacentVertex; 
      Gtable[countUsed].adjacentOnes.addRear(temp_adjacentVertex); // add the adjacent vertex to the bad
    }
    countUsed++; // increment the number of slots that are being used
  }
}

// Purpose: displays the graph, shows the name, number of out degrees, visit number, and the adjacent nodes
void dgraph::displayGraph() // be sure to display
{// in a really nice table format -- all columns but no unused rows and include the total number of edges at the top 
  int numOfEdges = 0;
  // loop through the number of vertices found and increment the total number of edges
  for(int i = 0; i < countUsed; i++) {
    numOfEdges += Gtable[i].outDegree;
  }
  cout << "The number of edges: " << numOfEdges << endl;
  cout << "Name    Out     Visit   Adjacency" << endl;
  cout << "----------------------------------------" << endl;
  for(int i = 0; i < countUsed; i++) {
    cout << Gtable[i].vertexName << "       "; // print the vertex name
    cout << Gtable[i].outDegree << "       "; // print the number of degrees
    cout << Gtable[i].visit << "        "; // print the visit
    Gtable[i].adjacentOnes.displayAll(); // display the elements
  }
  cout << "----------------------------------------" << endl;
}

// Purpose: find the value of the degree.
int dgraph::findOutDegree(char V)/* throws exception */ {
  // does not use a loop - go to a slot using V
  if(!isalpha(V)) throw BadVertex(); // if the character entered is not part of the alphabet
  int index = int(tolower(V) - 'a'); // lower the character, type cast as int and subtract 'a' to get the integer
  // the data is alphabetical so a = 0, b = 1, c = 2, etc
  if(index < 0 || index >= countUsed) throw BadVertex(); // if the index is invalid (less than 0 or it is equal to or great?er than count used)
  return Gtable[index].outDegree;
}

// Purpose: Finds and returns an slist of adjacent nodes
// Parameter: Vertex name character
slist dgraph::findAdjacency(char V)// throws exception
{// does not use a loop - go to a slot using V
  if(!isalpha(V)) throw BadVertex(); // if the character entered is not part of the alphabet
  int index = int(tolower(V) - 'a');
  if(index < 0 || index >= countUsed) throw BadVertex(); // if index is out of range
  return Gtable[index].adjacentOnes; // return the list
}

// Purpose: updates the visit number of a node
// Parameters: int visitNumber current distance traveresed, someVertex is the vertex whose visit number will be changed
void dgraph::visit(int visitNumber, char someVertex) {
  if(!isalpha(someVertex)) throw BadVertex(); // if the character is not part of the alphabet
  int index = int(tolower(someVertex) - 'a'); // get the index position of the vertex passed from client
  if(index < 0 || index >= countUsed) throw BadVertex(); // if the index is out of range
  Gtable[index].visit = visitNumber; // update the visit number
}

// Purpose: check if a node has already been visited. Returns true if visited, false if not
// Parameters: check if a vertex has been marked
bool dgraph::isMarked(char someVertex) {
  // conditionals to check if the vertex given is valid
  if(!isalpha(someVertex)) throw BadVertex(); 
  int index = int(tolower(someVertex) - 'a');
  if(index < 0 || index >= countUsed) throw BadVertex();
  if(Gtable[index].visit == 0) return false; // if the vertex has not been visited, then the visit number would be 0
  return true; // if it is not 0, then it has been visited
}