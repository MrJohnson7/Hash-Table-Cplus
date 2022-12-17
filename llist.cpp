//CS311 Yoshii Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes

//EMACS HINT:
//  You can copy from a Word document to emacs (contrl-right click)
//  cntr-K cuts and cntr-Y pastes
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Nicholas Johnson
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 
//Purpose:This is a constructor to set the data members variables
llist::llist()
{
  // cout << "... in llist constructor..." << endl;
 Front = NULL; //set front to null
 Rear = NULL; // set rear to null
 Count = 0; //set count to zero

}
//Purpose: Deleting the linkedlist by calling the deleteFront function
llist::~llist()
{
  // cout << ".... in llist destructor..." << endl;
 Node *P = Front; //Pointer
 while(P != NULL)
   {
     deleteFront(P->Elem); // call to delete front
       P = P->Next;
   } //end of while start from front and delete every node untill it reaches the end
}

//PURPOSE: Checks to see if the linked list is empty
//PARAMETER:No parameters
bool llist::isEmpty()
 {
   if (Front == NULL && Rear == NULL && Count == 0) //indicates that the list is empty
     {
       return true;
     }
   else
     {
       return false;
     }
 } // be sure to check all 3 data members

//PURPOSE: This function is meant to display the linked list
//By moving the node and using the elem for what is stored
//PARAMETER:No parameters
void llist::displayAll() 
{
  Node *P = Front; //setting a node to the front
  if(isEmpty() == true)
    {
      cout << "[  empty  ]";
    }

  cout << "[ ";
  while (P != NULL)
    {
      cout << P->Elem << " ";
      P = P->Next;
    } 
  cout << "]" << endl;
}  // be sure to display horizontally in [  ] with
// blanks between elements
  
//PURPOSE: The purpose of this function is to add to rear of list
//If there are no elements then we add to list and set the front and rear
//to equal this new node
//PARAMETER: The parameter being passed is NewNum of type int
//will use to put in the Elem part of the node
void llist::addRear(el_t NewNum) 
{
  if(isEmpty() == true) // Special Case: in case the link list is already empty
    {
      Front = new Node;
      Front->Elem = NewNum;
      Rear = Front;
      Rear->Next = NULL; /////////////////////////////////////
      Count++;
    }
  else          // regular case:just adding to the end
    {
      Rear->Next = new Node;
      Rear = Rear->Next;
      Rear->Elem = NewNum;
      Rear->Next = NULL;
      Count++;
    }
} // comment the 2 cases

//PURPOSE: The purpose of this function is to add to the front
//of the list. Or create a list if there isn't ant elements on the list
//PARAMETER: Parameter NewNum is the element we will be adding into the front
void llist::addFront(el_t NewNum) 
{
  if(isEmpty() == true)//Special case,if list is empty we create a new list
    {
      Front = new Node; 
      Front->Elem = NewNum;
      Rear = Front;
      Rear->Next = NULL;
      Count++;
    }
  else                //Regular case, Add a new node at the front
    {
      Node *X = new Node;
      X->Elem = NewNum;
      X->Next = Front;
      
      Front = X;
      Count++;
    }
 
} // comment the 2 cases

//PURPOSE:This function will delete the front node from the list.
//Will also check to see if list is empty, and if it will be empty after 
//the deletion then must update to reflect an empty linked list
//PARAMETER: The prameter OldNum will be used to delte the element
void llist::deleteFront(el_t& OldNum) 
{
  if(isEmpty() == true) //Error Case Throws exception
    {
      throw Underflow();
    } 
  else if(Count == 1)//special case, if count = 1 that means only one element on the list
    {
      OldNum = Front->Elem;
      delete Front;
      Count--;
      Front = NULL;
      Rear = NULL;
    }
  else // Regular case Just deletes the front node,
    {
      OldNum = Front->Elem;
      Node *Second;
      Second = Front->Next;
      delete Front;
      Front = Second;
      Count--;
    }
} // comment the 3 cases

//PURPOSE: This function delete the rear node. If there isn't any node 
//an exception will be thrown. If there is only one element on the list
//it will reset the Front and Rear to Null, And the regular case is when we just
//delete the rear node
//PARAMETER:The parameter OldNum will be used to hold the element to delete.
void llist::deleteRear(el_t& OldNum)
{
  if(isEmpty())//Error Case
    {
      throw Underflow();
    }
  else if(Count == 1)//Special case. If there is only one element left we reset front and rear to null
    {
      OldNum = Rear->Elem;
      delete Rear;
      Rear = NULL;
      Front = NULL;
      Count--;
    }
  else //Regular case we just delete from rear, rear-> next must equal null
    {
      OldNum = Rear->Elem;
      Node *P = Front;
      while(P->Next != Rear)
	{
	  P = P->Next;
	}
      delete Rear;
      Rear = P;
      Rear->Next = NULL;
      Count--;
    }
} // comment the 3 cases


/* harder ones follow */

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp)
{ // moves temp J-1 times to go to the Jth node
  temp = Front;
  for ( int K = 1; K <= J-1; K++ )
    {
      temp = temp->Next;
    }
}

//PURPOSE: The purpose of this function is to delete an element in the linklist
// using a bypass technique with two pointers, the moveTo function will be doing all the work.
// 4 cases one to throw an exception, one to delete front or delete rear if the index matches
// those in that position of the linked list. Regular case we simply delete the node using the moveTo function
//PARAMETER: The parameter int I will be the place in the linked list we want to delete
//oldNum will be a holder for the element that was removed. 
void llist::deleteIth(int I, el_t& OldNum) 
{
  Node *P = Front; //Set Node Pointer to front
  Node *Q = Front; //set Node pointer to front

  int beforeDelete = I - 1;
  int afterDelete = I + 1;

  if(I > Count || I < 1) //Error cases If it is an illegal value throw an exception
    {
      throw OutOfRange();
    }
    else if(I == 1) //Special case if I = the front just call the function deleteFront
    {
   deleteFront(OldNum);
    }
    else  // Regular case
    {
      moveTo(beforeDelete, P); //Moving pointer P to the node before the one we want to delete
      moveTo(afterDelete, Q); //Moving pointer Q to the node after the one we want to delete
      OldNum = P->Next->Elem; //Old num = P.Next.Elem
      delete P->Next; //Deleting P->Next
      P->Next = Q;
      Count--;
    }

} // use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  

//PURPOSE: If I is an illegal value I will throw an exception. Special cases we will addFront or addRear if the int index matches
// those positions in the linked list. Regular case we will add right before theIth node. update count
//PARAMETER: int I will b e the index in the link list we want to add. newNum will hold the value of the number we are adding
void llist::insertIth(int I, el_t newNum) 
{
  Node *P = Front; //Set node pointer to front
  Node *Q = Front; //Set node pointer to front
  int beforeInsert = I - 1;
  int numForIfState = Count + 1;

  if(I > numForIfState || I < 1)// Error case Throws out of range exception
    {
      throw OutOfRange();
    } 
  else if(I == 1) //special case If I = 1, just call addFront
    {
      addFront(newNum);
    }
  else if(I == Count) //special case if I == Count, just call addRear
    {
      addRear(newNum);
    }
  else // regular case just insert to the place off the index
    {
      moveTo(beforeInsert, P);
      moveTo(I, Q);
      P->Next = new Node;
      
      P = P->Next;
      P->Elem = newNum;
      P->Next = Q;
      Count++;

    }
} // use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE: this is an overlooaded constructer that takes in a linked list
//PARAMETER: llist type name original for the linkedlist being passed in
llist::llist(const llist& Original) 
{
  //this->'s data members need to be initialized first
  Front = NULL;
  Rear = NULL;
  Count = 0;
  //this-> object has to be built up by allocating new cells
  //and copying the values from original into each cell as we did with
  // operator = above. To do this

  Node *P;
  P = Original.Front;
  while(P != NULL) // a loop which repeats until you reach the end of Original
    {
      this->addRear(P->Elem); //P's element is added to this->
      P = P->Next;
    }
 
} // use my code

//PURPOSE: Overloading the equals sign to use with linked lists
//PARAMETER: Parameter is of type llist and takes in the other linkedlist needed to be compared
llist& llist::operator=(const llist& OtherOne) 
{
  el_t x;
  //first make sure this-> and OtherOne are not the same object
  // To do this, compare the pointers to the objects
  if(&OtherOne != this) // if not the same
    {
      //this-> object has to be emptied first
      while(!this->isEmpty())
	{
	  this->deleteRear(x);
	}
      //this-> object has to be built up by allocating new cells with otherone elements
      Node *P; //local pointer for other one
      P = OtherOne.Front;
      while(P != NULL) // a loop which repeats until you reach the end of OtherOne
	{
	  this->addRear(P->Elem); //P's element is added to this ->
	  P = P->Next; //Go to the next node in otherone
	}
    } //end of if
  return *this; //return the result unconditionally. Note that result is returned by reference
} // use my code

