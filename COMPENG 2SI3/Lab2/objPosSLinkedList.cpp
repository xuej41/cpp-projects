#include "objPosSLinkedList.h"
#include <iostream>
using namespace std;

// Develop the objPos Singly Linked List WITHOUT DUMMY HEADER.  
// Use the Test cases Test.cpp to complete the Test-Driven Development

objPosSLinkedList::objPosSLinkedList()
{
    listHead = new SNode(); //Dummy header

    listHead->next = nullptr;

    persistHead = listHead;
    listSize = 0;
}

objPosSLinkedList::~objPosSLinkedList()
{
    SNode* current = listHead->next; //start at first real node

    while (current != nullptr) {  
        SNode* temp = current;
        current = current->next;
        delete temp;
    }

    delete listHead;
}

int objPosSLinkedList::getSize()
{
    return listSize;
}

bool objPosSLinkedList::isEmpty()
{
   if (listHead->next == nullptr)
        return true;
    else
        return false;
}

void objPosSLinkedList::insertHead(const objPos &thisPos)
{
    SNode* newNode = new SNode();
    newNode->data = thisPos;

    newNode->next = listHead->next;
    listHead->next = newNode;

    listSize++;
}

void objPosSLinkedList::insertTail(const objPos &thisPos)
{
    SNode* newNode = new SNode();    // Create a new node
    newNode->data = thisPos;          // Set the data for the new node
    newNode->next = nullptr;          // New node will be the last one, so its next is null

    if (listHead->next == nullptr)    // If the list is empty
    {
        listHead->next = newNode;    // The head points to the new node
    }
    else
    {
        SNode* readerHead = listHead->next; // Start at the first real node

        while (readerHead->next != nullptr)  // Move to the last node
        {
            readerHead = readerHead->next;
        }

        readerHead->next = newNode;  // Set the last node's next to the new node
    }

    listSize++;  // Increase the list size
}

void objPosSLinkedList::insert(const objPos &thisPos, int index)
{
    SNode* readerHead = listHead->next; //start at first real node

    if (index <= 0)
    {
        insertHead(thisPos);
    }
    else if (index >= listSize-1)
    {
        insertTail(thisPos);
    }
    else
    {
        for (int i = 0; i < index-1; i++) //position readerhead at node right before
            readerHead = readerHead->next;

        SNode* newNode = new SNode();
        newNode->data = thisPos;

        newNode->next = readerHead->next;
        readerHead->next = newNode;

        listSize++;
    }
}

objPos objPosSLinkedList::getHead() const
{
    if (listHead->next != nullptr) //return the data of the first real node
    {
        return listHead->next->data;
    }
    else
    {
        return objPos(-99,0,0,0,0);
    }
}

objPos objPosSLinkedList::getTail() const
{
    if (listHead->next == nullptr) //if list is empty
    {
        return objPos(-99,0,0,0,0);
    }
    else
    {
        SNode* readerHead = listHead->next; //start at first real node

        while (readerHead->next != nullptr) //move to last element
            readerHead = readerHead->next;

        return readerHead->data;
    }
}

objPos objPosSLinkedList::get(int index) const
{
    if (listHead->next == nullptr) //empty list
    {
        return objPos(-99,0,0,0,0);
    }
    else if (index <= 0)
    {
        return getHead();
    }
    else if (index >= listSize-1)
    {
        return getTail();
    }
    else
    {
        SNode* readerHead = listHead->next; //start at first real node

        for (int i = 0; i < index; i++) //position readerhead at node
        {
            readerHead = readerHead->next;
        }

        return readerHead->data;
    }
}

objPos objPosSLinkedList::getNext()
{
    if (persistHead == nullptr) //return the data of the next real node
    {
        persistHead = listHead;
        return objPos(-99,0,0,0,0);
    }
    else
    {
        persistHead = persistHead->next;
        return persistHead->data;
    }
}

void objPosSLinkedList::resetReadPos()
{
    persistHead = listHead;
}

void objPosSLinkedList::set(const objPos &thisPos, int index)
{
    if (listHead->next == nullptr) //empty list
    {
        return;
    }
    else if (index < 0)
    {
        index = 0;
    }
    else if (index > listSize-1)
    {
        index = listSize-1;
    }
    
    SNode* readerHead = listHead->next; //start at first real node

    for (int i = 0; i < index; i++)//position readerhead at node
    {
        readerHead = readerHead->next;
    }

    readerHead->data = thisPos;
}


objPos objPosSLinkedList::removeHead()
{
    if (listHead->next == nullptr) //empty list
    {
        return objPos(-99,0,0,0,0);
    }

    SNode* temp = listHead->next; //first real node
    objPos tempData = temp->data; //copy of the data

    listHead->next = temp->next;

    delete temp;
    listSize--;

    return tempData;
}

objPos objPosSLinkedList::removeTail()
{
    if (listHead->next == nullptr) //empty list
    {
        return objPos(-99,0,0,0,0);
    }

    SNode* readerHead = listHead->next; //start at first real node

    while (readerHead->next->next != nullptr) //move to second to last element
    {
        readerHead = readerHead->next;
    }

    objPos tempData = readerHead->next->data; //copy of the data

    delete readerHead->next;
    readerHead->next = nullptr;
    listSize--;

    return tempData;
}

objPos objPosSLinkedList::remove(int index)
{
    if (listHead->next == nullptr) //empty list
    {
        return objPos(-99,0,0,0,0);
    }
    else if (index <= 0)
    {
        return removeHead();
    }
    else if (index >= listSize-1)
    {
        return removeTail();
    }
    else
    {
        SNode* readerHead = listHead->next; //start at first real node

        for (int i = 0; i < index-1; i++) //position readerhead right before node
            readerHead = readerHead->next;

        SNode* temp = readerHead->next; //node to be removed
        objPos tempData = readerHead->next->data; //copy of the data

        readerHead = readerHead->next->next;

        delete temp;
        listSize--;

        return tempData;
    }
}

void objPosSLinkedList::printList() const
{
    SNode* readerHead = listHead->next; //start at first real node

    while (readerHead != nullptr) {  
        //cout << readerHead->data << endl; placeholder
        readerHead = readerHead->next;
    }
}