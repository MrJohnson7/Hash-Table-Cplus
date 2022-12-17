//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Nicholas Johnson
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
#include "elem.h"

//a list node is defined here as a struct Node for now

struct Node
{
el_t Elem;   // elem is the element stored
Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
  void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //**purpose: return true if front and rear are both pointing to null
  // and count is 0
  bool isEmpty();
    
  //**display each element of the list starting from Front
  void displayAll();

  //**purpose add to the front if it is empty
  //or adds a new node to the front
  // parameter is of type node el_t
  void addFront(el_t);
    
  //purpose : add to rear of linkedlist but if stack is empty
  //parameter: el_t will be element we are adding to the rear
  void addRear(el_t);

  //purpose: delete the front of the linked list
  //parameter: el_t will be the parameter passed by reference
  void deleteFront(el_t&);
    
  //purpose: deletes the rear of the linked list
  //parameter: el_t will be the parameter passed by reference
  void deleteRear(el_t&);
    
  //purpose:This will delete a specific element in the array list
  //parameter: int and el_t will be used to locate the element to be removed
  void deleteIth(int, el_t&);  // calls moveTo

  //will insert an element into a specific location in the linked list
  // int and el_t will be used to locate the location for the new element to be placed
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};
