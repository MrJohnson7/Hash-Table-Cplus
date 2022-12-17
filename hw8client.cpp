// CS311 Yoshii - complete ** for HW8 client
// Note that the client knows about elem.h functions.
// It can create el_t objects.
//-----------------------------------------------

//============================================
// HW#: HW8 hashing client
// Name: Nicholas Johnson
// File type: client hw8client.cpp (tester)
//===========================================

using namespace std;
#include "htable.h"

// This tester gets input data interactively but
// for a useful client, input should come from a file.
// Note that el_t X; will create a blank element X using the regular constructor.  
// Note that the second constructor of el_t can be used to
// create key+name to add to the table. e.g. el_t X(30, "mary");
int main()
{
  // Loop:  
  // Interactively add about 20 keys and names to the table,
  // making sure some of them  collide. (function add)
  // You can create el_t containing a key and name using a constructor.
    
  int threeDigitKey;
  int keyForName;
  string name;
  htable h;
  int index;

  for(int i = 0; i < 20; i++)
    {
      cout << "Please enter 3 digit key to add to table: " << endl;
      cin >> threeDigitKey;
      cout << "Please enter name to be associated with this key: " << endl;
      cin >> name;
      el_t objectCreate(threeDigitKey, name);
      index = h.add(objectCreate);
      cout << "-----------------------------------------------" << endl;
      cout << "KEY AND NAME ADDED TO TABLE. Slot " << index << endl;
      cout << "-----------------------------------------------" << endl;

    }
  // DisplayTable.
  h.displayTable();

  // Loop:
  // Interactively look up names using keys. (function find)
  // Cout the key + name if found else (blank element was returned i.e. key part is -1)
  // an error message.
  cout << "Look for? ";
  cin >> keyForName;
  while(keyForName != -1)
    {
     el_t returnedObject = h.find(keyForName);
     if(returnedObject.getkey() != -1)
       {
	 cout << returnedObject << endl;
       }
     else
       {
	 cout << keyForName << " not found" << endl;
       }
     cout << "Look for? ";
     cin >> keyForName;
       } // end while
  cout << "Done. " << endl;
 }
