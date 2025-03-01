#include "objPosDLinkedList.h"
#include <iostream>
using namespace std;

// Develop the objPos Doubly Linked List WITH DUMMY HEADER here.  
// Use the Test cases Test.cpp to complete the Test-Driven Development

objPosDLinkedList::objPosDLinkedList()
{
    listHead = new DNode(); // Dummy header
    listTail = new DNode(); // Dummy tail
    
    // what they point to initially
    listHead->prev = nullptr;
    listTail->next = nullptr;

    listHead->next = listTail;
    listTail->prev = listHead;
    
    persistHead = listHead; // Persistent head
    listSize = 0;           // Empty list
}

objPosDLinkedList::~objPosDLinkedList()
{
    DNode* current = listHead->next; //start at first real node
    
    // Delete all nodes except the dummy tail
    while (current != listTail) {  
        DNode* temp = current;
        current = current->next;
        delete temp;
    }

    delete listHead; // Finally delete the dummy header
}

int objPosDLinkedList::getSize()
{
    return listSize;
}

bool objPosDLinkedList::isEmpty()
{
    if (listHead->next == listTail)
        return true;
    else
        return false;
}

void objPosDLinkedList::insertHead(const objPos &thisPos)
{
    DNode* newNode = new DNode();
    newNode->data = thisPos;

    newNode->next = listHead->next;
    newNode->prev = listHead;

    listHead->next = newNode;
    newNode->next->prev = newNode;

    listSize++;
}

void objPosDLinkedList::insertTail(const objPos &thisPos)
{
    DNode* newNode = new DNode();
    newNode->data = thisPos;

    newNode->next = listTail;
    newNode->prev = listTail->prev;

    listTail->prev = newNode;
    newNode->prev->next = newNode;

    listSize++;
}

void objPosDLinkedList::insert(const objPos &thisPos, int index)
{
    DNode* readerHead = listHead->next; //start at first real node

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

        DNode* newNode = new DNode();
        newNode->data = thisPos;

        newNode->next = readerHead->next;
        newNode->prev = readerHead;

        readerHead->next = newNode;
        newNode->next->prev = newNode;
        listSize++;
    }
}

objPos objPosDLinkedList::getHead() const
{
    if (listHead->next != listTail) //return the data of the first real node
    {
        return listHead->next->data;
    }
    else
    {
        return objPos(-99,0,0,0,0);
    }
}

objPos objPosDLinkedList::getTail() const
{
    if (listHead->next != listTail) //return the data of the last real node
    {
        return listTail->prev->data;
    }
    else
    {
        return objPos(-99,0,0,0,0);
    }
}

objPos objPosDLinkedList::get(int index) const
{
    if (listHead->next == listTail) //empty list
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
        DNode* readerHead = listHead->next; //start at first real node

        for (int i = 0; i < index; i++) //position readerhead at node
        {
            readerHead = readerHead->next;
        }

        return readerHead->data;
    }
}

objPos objPosDLinkedList::getNext()
{
    if (persistHead == listTail) //return the data of the next real node
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

void objPosDLinkedList::resetReadPos()
{
    persistHead = listHead;
}

void objPosDLinkedList::set(const objPos &thisPos, int index)
{
    if (listHead->next == listTail) //empty list
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

    DNode* readerHead = listHead->next; //start at first real node

    for (int i = 0; i < index; i++)//position readerhead at node
    {
        readerHead = readerHead->next;
    }

    readerHead->data = thisPos;
}


objPos objPosDLinkedList::removeHead()
{
    if (listHead->next == listTail) //empty list
    {
        return objPos(-99,0,0,0,0);
    }

    DNode* temp = listHead->next; //first real node
    objPos tempData = temp->data; //copy of the data

    listHead->next = temp->next;
    temp->next->prev = listHead;

    delete temp;
    listSize--;

    return tempData;
}

objPos objPosDLinkedList::removeTail()
{
    if (listHead->next == listTail) //empty list
    {
        return objPos(-99,0,0,0,0);
    }

    DNode* temp = listTail->prev; //last real node
    objPos tempData = temp->data; //copy of the data

    listTail->prev = temp->prev;
    temp->prev->next = listTail;

    delete temp;
    listSize--;

    return tempData;
}

objPos objPosDLinkedList::remove(int index)
{
    if (listHead->next == listTail) //empty list
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
        DNode* readerHead = listHead->next; //start at first real node

        for (int i = 0; i < index; i++) //position readerhead at node
        {
            readerHead = readerHead->next;
        }

        objPos tempData = readerHead->data; //copy of the data

        readerHead->prev->next = readerHead->next;
        readerHead->next->prev = readerHead->prev;

        delete readerHead;
        listSize--;

        return tempData;
    }
}


void objPosDLinkedList::printList() const
{
    DNode* readerHead = listHead->next; //start at first real node

    while (readerHead != listTail) {  
        //cout << readerHead->data << endl; placeholder
        readerHead = readerHead->next;
    }
}


