//CS311 Yoshii Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//  You can copy from a Word document to emacs (contrl-right click)
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes

//EMACS HINT:
//  cntr-K cuts and cntr-Y pastes. 
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Neal Archival
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

#include<iostream>
#include"llist.h" 
using namespace std;

llist::llist() { 
  // cout << "... in llist constructor..." << endl; 
  Count = 0; // set count to 0 
  Front = Rear = NULL; // front and rear will point to NULL
}

llist::~llist() { 
  // cout << ".... in llist destructor..." << endl; 
  el_t tempItem; // temporarily store the element of nodes we are removing from the list
  while(!isEmpty()) { // while our linked list contains elements
    deleteRear(tempItem);  // delete the rear node 
  }
}

//PURPOSE: Check if the linked list is empty
//PARAMETER: None
// Returns true if there are nodes in list, false if there are none
bool llist::isEmpty() { 
  if(Count == 0 && Front == NULL && Rear == NULL) return true; // if Count is 0 and both Front and Rear are pointing to NULL, list is empty
  return false; // otherwise return false (there are elements in the list)
} // be sure to check all 3 data members

//PURPOSE: Display all the elements in the linked list
//PARAMETER: None
void llist::displayAll() { 
  Node *P = Front; // set to Front
  cout << '[';
  while(P != NULL) { 
    cout << P->Elem << " " ;
    P = P->Next;
  }
  cout << ']';
  cout << endl;
}  // be sure to display horizontally in [  ] with
// blanks between elements e.g. [ 1 2 3 4]
// You MUST use while (P != NULL) loop or you will not get the credit!
  
//PURPOSE: Add a node to the back of the list
//PARAMETER: element we want to add to the list
void llist::addRear(el_t NewNum) {
  Node *nNode = new Node; 
  nNode->Elem = NewNum;
  nNode->Next = NULL; // rear->next is always going to be NULL because this node is at the end of the list
  if(isEmpty()) { // check if empty
    Front = nNode; // point front to the only node in the list
  } else { // if not empty then update the rear pointer 
    Rear->Next = nNode; // update rear to point to the new rear
  }
  Rear = nNode; // for all cases, the newest node is going to be pointer to rear
  Count++;
} // comment the 2 cases

//PURPOSE: Add a node to the front of the list and update front pointer node
//PARAMETER: element we want to add to the list
void llist::addFront(el_t NewNum) { 
  Node *nNode = new Node;
  nNode->Elem = NewNum; // initialize node element to the element we want to add
  if(isEmpty()) { // check if the list is empty
    Rear = nNode; // point rear node to the only node
    nNode->Next = NULL; // there is only one node in the list so Next will point to NULL
  } else { // if list empty
    nNode->Next = Front; // make the new node point to the current front
  }
  Front = nNode; // update the front pointer to point to our newly created node
  Count++; 
} // comment the 2 cases

//PURPOSE: delete the node at the front of the 
//PARAMETER: OldNum will be the element of the node we are deleting
void llist::deleteFront(el_t& OldNum) { 
  if(isEmpty()) throw Underflow();
  Count--;
  OldNum = Front->Elem; // el_t item of the Front element we are deleting
  if(Count == 0) { // check if the list is going to be empty
    delete Front; // delete old front
    Front = Rear = NULL; // set both front and rear pointers to NULL to signify the list is empty
  } else { // if not empty
    Node *oldFront = Front; // pointer to front node we are deleting
    Front = Front->Next; // update front pointer by making front point to second node in list
    delete oldFront; // delete our old front
  }
} // comment the 3 cases

//PURPOSE: Delete the rear node of the list and make the 2nd to last node rear
//PARAMETER: el_t number that we are removing from the list
void llist::deleteRear(el_t& OldNum){
  if(isEmpty()) throw Underflow(); // return if there are no elements then we return back to client
  OldNum = Rear->Elem; // set OldNum to the rear element 
  Count--; // reduce the number of elements for conditionals
  if(Count == 0) { // if the count is 0, we have to update both front and rear pointers
    delete Rear;
    Front = Rear = NULL; // make both front and rear point to NULL to signify list is empty
  } else { // if not empty
    Node *p = Front; // temporary pointer to traverse to second to last node
    while(p->Next != Rear) p = p->Next; // traverse to second to last node
    delete Rear; // delete the rear node
    Rear = p; // point Rear to the second to last node
    Rear->Next = NULL; // new rear needs to point to NULL
  }
  return;
} // comment the 3 cases


/* --- harder ones follow -- */
// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp) { 
  temp = Front; // initialize the local pointer to point to front first
  for(int i = 1; i < J; i++) {
    temp = temp->Next;
  }
}

//PURPOSE: delete node in position i
//PARAMETER: I (Position Number) and OldNum the element we are removing
void llist::deleteIth(int I, el_t& OldNum) {
  if(I > Count || I < 1) throw OutOfRange(); // if position is greater than the number of elements or is less than 1
  if(I == 1) { // if we are removing position 1
    deleteFront(OldNum); // delete the front node
    return;
  } else if(I == Count) { // else if we are deleting the last position
    deleteRear(OldNum); // delete the rear
    return;
  } // return both if statements
  Node *prevNode; // node previous to node we are deleting to reassign next-> pointer
  Node *currNode; // we are going to delete this node
  moveTo(I - 1, prevNode); // move to previous node of the node we are deleting
  moveTo (I, currNode); // move to the node we are going to delete
  OldNum = currNode->Elem; 
  prevNode->Next = currNode->Next; // update previous node next pointer to the node after 
  delete currNode; // delete the node
  prevNode = currNode = NULL; // change currNode to NULL and avoid dangling pointer
  Count--; // decrement
} // use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  

//PURPOSE: Insert a node in a certain position
//PARAMETER:
void llist::insertIth(int I, el_t newNum) { 
  if(I > Count + 1 || I < 1) { // if I is greater than the size + 1 and less than 0
    throw OutOfRange(); // instantiate the object to be thrown that I is out of range
  }
  if(I == 1) { // if we are inserting into the position one (first node of the list)
    addFront(newNum); // add new node to the front
    return;
  } else if(I == Count + 1) { // if we are inserting into the rear of the list
    addRear(newNum); // call addRear
    return;
  }
  Node *tempNode; // node left of the Insertion position
  moveTo(I - 1, tempNode);  // move to the node previous to insertion position
  Node* nNode = new Node; 
  nNode->Elem = newNum; 
  nNode->Next = tempNode->Next; // point the new node's next to the node occupying current position
  tempNode->Next = nNode; // change our node to our new node
  tempNode = NULL; // we don't need this pointer anymore so set to NULL
  Count++; // since we added one new element
} // use move to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE: copy constructor
//PARAMETER: the original list object we want to copy
llist::llist(const llist &Original) { 
  this->Front = this->Rear = NULL;
  this->Count = 0;
  Node *tempPtr = Original.Front;
  while(tempPtr != NULL) {
    this->addRear(tempPtr->Elem);
    tempPtr = tempPtr->Next;
  }
} // use my code

//PURPOSE: overloaded operator to assign 
//PARAMETER: list we want to make a reference of
llist &llist::operator=(const llist &OtherOne) { 
  if(this->Front == OtherOne.Front) return *this; // if we are setting the linked list to itself, nothing should chamge
  // we will comprae fronts because the other list we are passing is not const and we're passing a const reference of the same list
  if(!this->isEmpty()) { // if the list has any current nodes, we clear it to avoid garbage cells
    el_t temp;
    while(!this->isEmpty()) {
      this->deleteRear(temp);
    }
  }
  Node *tempPtr = OtherOne.Front;
  while(tempPtr != NULL) {
    this->addRear(tempPtr->Elem);
    tempPtr = tempPtr->Next;
  }
  return *this; // return the current list
} // use my code

