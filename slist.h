// CS311 Yoshii
// HW3P2 Instruction: Inherit everything publicly from llist
// Put only the following in class slist.h 
//    inheriting everything from llist.h
//
// Then create slist.cpp with only the following functions
// Complete all ** parts 
//=================================================
// HW#: HW3P2 slist
// Name: Nicholas Johnson
// File: slist.h Header File
//=================================================

#include"llist.h"  // for includes

class slist : public llist, public Node
{

 public:
  
  slist();   // constructor. cout "in slist constructor".
             // Make it do nothing else.
             // Experiment and see what happens.
             // Taking this out completely would not work.
             // But note that there is no destructor.
             // PLEASE DO NOT delete the couts in slist and llist
             // constructors and destructors for HW6!!!!!
  //Purpose: search through the slist
  //Parameter: parmeter will be the elemnent we are searching for
  int search(el_t);
    // search through the list to see if any node contains the key.
    // If so, return its position (>=1). Otherwise, return 0.
  //Purpose : search the slist, looking for key
  //Parameter: parameter will be used to find and match the key
  el_t search2(el_t);
  //Purpose: to replace an element in the slist
  //Parameter: the parameters are the elementto be replaced and the index of the old elment    
  void replace(el_t,  int);
    // go to the Ith node (if I is between 1 and Count) and 
    // replace the element there with the new element. 
    // If I was an illegal value, throw OutOfRange 
    
  //Purpose: Overload the == operator
  //Parameter: the parameter is an slist which also a linked list
  bool operator==(const slist&);
    // checks to see of the two lists look the same
    

};
