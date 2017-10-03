//testLL.cpp

#include <iomanip>         // for input/output manipulation
#include <stdlib.h>        // standard general utilities library
#include <assert.h>        // for assert 
#include <iostream>        // for i/o functions
#include <fstream>         // for external file streams
#include <string>          // for string objects
#include "LinkedList.h"

using namespace std;

int main()
{
    
cout << "To begin we initialize a linked list (LL1) and " << endl;
cout << "use orderedInsert() to add a number to it" << endl;

LinkedList <int> LL1;
LL1.orderedInsert(3);
cout << "LL1 is " << LL1;

cout << "\nThen we use the copy contructor to " <<
    "\ninstantiate a new linked list (LL2)";

LinkedList <int> LL2(LL1);
cout << "\nLL1 is still " << LL1 << "\nand LL2 " <<
    "is " << LL2;

cout << "\nThen we instantiate a new linked list " <<
    "\n(LL3) and use orderedInsert() to add a 6 to it";

LinkedList <int> LL3;
LL3.orderedInsert(6);

cout << "\nLL3 is now " << LL3;

cout << "\nThen to test orderedInsert()'s addition to the beginning " <<
    "\nof a linked list, we add a 3 to LL3";
LL3.orderedInsert(3);

cout << "\nLL3 is now " << LL3;

cout << "\nAfter we add 9 to LL3 to test orderedInsert()'s addition " <<
    "\n to the end of the linked list";
LL3.orderedInsert(9);

cout << "\nLL3 is now " << LL3;

cout << "\nAdditionally we test the orderedInsert() with a number added " <<
"to the middle" <<
    "\nwe add 7 to go in between the 6 and the 9";
LL3.orderedInsert(7);

cout << "\nLL3 is now " << LL3;

cout << "\nFinally we check how the orderedInsert() deals with duplicates " <<
"by adding another 7";
LL3.orderedInsert(7);

cout << "\nLL3 is still " << LL3;

cout << "\nNext we test the = operator with LL2 = LL3";
LL2 = LL3;

cout << "\nLL2 is " << LL2;
cout <<"\nand LL3 is still " << LL3;

cout << "\nNext we test Find() by seeing whether there is a 7 in LL3" <<
    "\nand returing true if so";
if (LL3.find(7)){
    cout << "\nThere is a 7 in LL3 and Find() is working";
}
else{
    cout << "\nThere is a 7 in LL3, but Find() is not working";
}

cout << "\nThen we test remove() by removing a 6 from LL2";
LL2.remove(6);

cout << "\nLL2 is now " << LL2;

cout << "\nThen we return to the = operator and test x = y = z";
LL1 = LL2 = LL3;

cout << "LL1 is " << LL1 << "\nLL2 is " << LL2 <<
    "\nand LL3 is " << LL3;


cout << "\nand finally countNodesInList with LL2: \n";

cout << LL2.countNodesInList() << endl;


return (0);
} //end main()
