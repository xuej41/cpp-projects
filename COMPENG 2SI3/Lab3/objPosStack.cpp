#include "objPosStack.h"
#include "objPosSHLinkedList.h"

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

// Available Data Members from objPosStack.h (Must Review)
//
//      objPosList* myList
//      
//  This is the polymorphic list pointer to the underlying List data structure to
//   support all Stack functionalities
//
//  You should use the provided objPosSHLinkedList as your main design param (Singly with Header)


objPosStack::objPosStack()
{
    myList = new objPosSHLinkedList(); // Initialize the linked list
}


objPosStack::~objPosStack()
{
    delete myList;  // Deallocate the linked list

}


void objPosStack::populateRandomElements(int size)
{
    // This function generates the number of randomly generated objPos instances with uninitialized
    //  x-y coordinate on the Stack, then sort them in ascending order using the digit of 10
    //  of the **number** field in objPos instances.

    // Implementation done.  You'd have to implement the following two private helper functions above.
    srand(time(NULL));
    generateObjects(size);
    sortByTenScoreBS();   // bubble sort
}




// private helper function
void objPosStack::generateObjects(int count)
{
    // Generate and pushes individual objPos isntances with randomly generated Prefix, Number, and Symbol.
    // The total number of generated instances is capped by input variable **count**.
    
    // 1. Generate Prefix A-Z and a-z.  Alphabetic characters only.
    // 2. Generate Number [0, 99]
    // 3. Leave Symbol as *
    // Push every randomly generately objPos into the Stack.
    for (int i = 0; i < count; i++) {
        char prefix = (rand() % 2 == 0) ? ('A' + rand() % 26) : ('a' + rand() % 26);
        int number = rand() % 100;
        char symbol = '*';
        objPos newObj(0, 0, prefix, number, symbol);
        push(newObj);
    }
}


// private helper function
void objPosStack::sortByTenScoreBS()
{
    // Use BUBBLE or SELECTION SORT to sort all the objPos instances in the Stack in ascending order using the doigit of 10
    //  of the **number** field of objPos.

    // You can use the relevant insertion, removal, getter, and setter methods from the objPosSHLinkedList interface
    //  to complete the sorting operations.
    int n = myList->getSize();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            objPos first = myList->get(j);
            objPos second = myList->get(j + 1);
            if ((first.getNum() / 10) > (second.getNum() / 10)) {
                //myList->swap(j, j + 1); // Swap elements if needed
                objPos temp = myList->get(j);
                myList->set(myList->get(j + 1), j);
                myList->set(temp, j + 1);
            }
        }
    }
}




void objPosStack::push(const objPos &thisPos) const
{
    // Push thisPos on to the Stack.
    myList->insertHead(thisPos);
}

objPos objPosStack::pop()
{
    // Pop the top element of the Stack.
    //  If the Stack is empty, return objPos(-99, 0, 0, 0, 0)
    if (myList->isEmpty()) {
        return objPos(-99, 0, 0, 0, 0);
    }
    objPos topElement = myList->getHead();
    myList->removeHead();
    return topElement;
}

objPos objPosStack::top()
{
    // Return the top element of the Stack without removing it
    //  If the Stack is empty, return objPos(-99, 0, 0, 0, 0)
    if (myList->isEmpty()) {
        return objPos(-99, 0, 0, 0, 0);
    }
    return myList->getHead();
}

int objPosStack::size()
{
    // Return the size of the Stack 
    //  Think about which objPosSHLinkedList method can realize this operation.
    return myList->getSize();
}

void objPosStack::printMe()
{
    // NOT GRADED
    //  Print the contents of the Stack

    // IMPORTANT: USE THIS METHOD FOR DEBUGGING!!!
    myList->printList();
}