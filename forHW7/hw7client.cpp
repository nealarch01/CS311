 //==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: Neal Archival
// File type: client hw7client.cpp
//==========================================

#include <iostream>

#include "stack.h"
#include "dgraph.h"

using namespace std;

// ** Be sure to include both dgraph  and stack

// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main() {
    // ** copy here the algorithm (read carefully) in the HW7
    // assignment sheet and use that has the comments.
  dgraph graph; // graph we will use
  stack vertexStack; // stack we will use for DFS
  graph.fillTable(); // fill the table with data

  // display the graph
  graph.displayGraph();
  // push character 'A' into the stack
  vertexStack.push('A');
  // list to store vertex adjacency vertices
  slist adjacenctVertices;
  // char variable used to store the adjacent vertex removed from the slist
  int currentVisit = 0; // the current visit number
  char removedVertex; // the elem we are going to pass into the stack pop function to get the vertex in the stack
  char adjacentVertex; // the elem we are going to pass into the slist of adjacent vertices to get one vertex from the adjacency list
  // while the stack is not empty
  while(!vertexStack.isEmpty()) {
    vertexStack.pop(removedVertex); // pop the vertex
    // Inform the user we removed a vertex from the stack
    cout << "Removed vertex: '" << removedVertex << "' from stack" << endl;
    try {
      if(!graph.isMarked(removedVertex)) {
        currentVisit++; // increment the number of visits
        graph.visit(currentVisit, removedVertex); // update the removed vertex, mark as visited
        // Inform the user we are visiting this vertex
        cout << "Visiting '" << removedVertex << "' as: " << currentVisit << endl; 
        if(graph.findOutDegree(removedVertex) == 0) { // check if the vertex is a deadend
          // inform user we have reached a deadend
          cout << "Deadend reached - backup" << endl;
        } else { // if there are at least 1 adjacent vertices
          adjacenctVertices = graph.findAdjacency(removedVertex);
          // loop to push all the adjacent vertices into the stack
          while(!adjacenctVertices.isEmpty()) {
            adjacenctVertices.deleteRear(adjacentVertex); // delete the rear element of the adjacentVertices list
            // inform the user we are pushing an adjacent vertex from the slist into the stack
            cout << "Pushing adjacent vertex: '" << adjacentVertex << "' into stack" << endl; // inform the user we are pushing an adjacent vertex into the stack
            vertexStack.push(adjacentVertex); // push into the stack
          }
        }
      } else {
        cout << "The vertex: " << removedVertex << " already has been visited" << endl;
      }
    } catch(dgraph::BadVertex) {
      cerr << "Vertex: " << removedVertex << " is a bad vertex" << endl;
    } // end of try-catch block
    vertexStack.displayAll();
  } // end of while loop
  graph.displayGraph();
  return 0;
}
