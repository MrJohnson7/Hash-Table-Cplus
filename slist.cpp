// CS311 Yoshii Complete all functions with their comments

// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Nicholas Johnson
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 

// ** Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist()
{              }


// positions always start at 1
//Purpose: This function will search through the slist
//Parameter: the key parameter will be the element we are lloking for in the slist
int slist::search(el_t key)
{
  Node *P = Front; //Set node pointer to front
  int ElemPosition = 1;
  while(P != NULL) //While loop to run through whole list
    {
      if(key == P->Elem)// comparing the Element in p to key being sent in
	{
	  return ElemPosition; //Returns the elements position, breaks out of function
	}
      else
	{
	  P = P->Next; //Moves to next position in list
	  ElemPosition++; //this is the counter for the next position
	}
    }//End of while loop
  return 0; //If while loop ends, return 0. Element not found

}
el_t slist::search2(el_t X)
{
  el_t M; //blank
  Node *P = Front; //NODE P points to front which is type  el_t
  int threeDigit = X.getkey(); // Getting the integer part of the object
  int elemKey; //  this will hold the intger part of object from the slist
  while(P != NULL) // While slist has elements
    {
      elemKey = (P->Elem).getkey(); //Storing the integer part of the slist node
      if(threeDigit == elemKey) // comparing integers
	{
	  return P->Elem; // return the whole element
	}
      else
	{
	  P = P->Next; // move to next element
	}

    }//end of while
  return M; //went to end of llist not found
}
//Purpose: This function will be used to determine
// if index is out of range, then if not will replace
//index 
//Parameter: the element will be what we want to replace in the
// slist, the pos is the index where we will replace in the slist
// don't forget to throw OutOfRange for bad pos 
void slist::replace(el_t element, int pos)
{
  Node *P = Front;
  Node *Q = Front;
  int beforeReplace = pos - 1;
  int afterReplace = pos + 1;

  if(pos > Count || pos < 1)
    {
      throw OutOfRange();
    }// end if
  else if(beforeReplace == 0)
    {
      P->Elem = element;
    }
  else
    {
      moveTo(beforeReplace, P); //P will be before the node to replace
      moveTo(afterReplace, Q); //q will be after the node to replace
      P->Next->Elem = element;
      // delete P->Next; //delete the node we want to replace
      // P->Next = new Node; //give a new node to the deleted node
      // P = P->Next; //moving P to the new node
      // P->Elem = element;//setting the new elememt, "Replaced deleted  node"

      // P->Next = Q; // bypass, now the new node's next equals Q, relink after delete
    
    }// end of else
}
//Purpose: this function overloads the == operator 
//so we can compare linked lists
//parameter: otherone will be the slist we are passing into compare
bool slist::operator==(const slist& OtherOne)
{
  Node *P;
  Node *Q;

  P = OtherOne.Front;
  Q = this->Front;

  int countForLoop = this->Count;
  if(this->Count != OtherOne.Count)
    {
      return false;
    } // if not the same length, return false
  else
    {
      for(int i = 0; i < countForLoop; i++)
	{
	  if(Q->Elem != P->Elem)
	    {
	      return false;
	    }
	  else
	    {
	      Q = Q->Next; ///////////////////////////////////////////
	      P = P->Next;
	    }
	}//end of for loop
     
    }// end of else
  // if the same lengths,
  // check each node to see if the elements are the same
  return true; // return true if loop continues to the end
}
