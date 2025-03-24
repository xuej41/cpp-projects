#include "objPosArrayList.h"
#include <iostream>
using namespace std;

objPosArrayList::objPosArrayList()
{
    listSize = 0;
    currentPos = 0;
    arrayCapacity = DEFAULT_ARRAY_LIST_SIZE;

    list = new objPos[DEFAULT_ARRAY_LIST_SIZE]; 
}

objPosArrayList::~objPosArrayList()
{
    delete[] list;
}


int objPosArrayList::getSize()
{
    return listSize;
}

bool objPosArrayList::isEmpty()
{
    return (listSize == 0);
}


void objPosArrayList::insertHead(const objPos &thisPos)
{
    if(listSize == arrayCapacity) return;

    for(int i = listSize; i > 0; i--)
    {
        list[i] = list[i-1];  // can do this because of copy constructor
    }
    
    list[0].setX(thisPos.getX());
    list[0].setY(thisPos.getY());
    list[0].setNum(thisPos.getNum());
    list[0].setPF(thisPos.getPF());
    list[0].setSym(thisPos.getSym());    

    //list[0].printObjPos();

    listSize++;
}

void objPosArrayList::insertTail(const objPos &thisPos)
{
    if(listSize == arrayCapacity) return;

    list[listSize].setX(thisPos.getX());
    list[listSize].setY(thisPos.getY());
    list[listSize].setNum(thisPos.getNum());
    list[listSize].setPF(thisPos.getPF());
    list[listSize].setSym(thisPos.getSym());

    //list[listSize].printObjPos();

    listSize++;
}

void objPosArrayList::insert(const objPos &thisPos, int index)
{
    if(listSize == arrayCapacity) return;
    if(index > listSize) index = listSize;
    if(index < 0) index = 0;

    for(int i = listSize; i > index; i--)
    {
        list[i] = list[i-1];
    }

    list[index].setX(thisPos.getX());
    list[index].setY(thisPos.getY());
    list[index].setNum(thisPos.getNum());
    list[index].setPF(thisPos.getPF());
    list[index].setSym(thisPos.getSym());

    //list[index].printObjPos();

    listSize++;
}


objPos objPosArrayList::getHead() const
{
    return list[0];  // thanks to copy constructor
}

objPos objPosArrayList::getTail() const
{
    return list[listSize-1];
}

objPos objPosArrayList::get(int index) const
{
    if(index < 0) index = 0;
    if(index > listSize - 1) index = listSize - 1;

    return list[index];
}

objPos objPosArrayList::getNext()
{
    //cout << "current head position: " << currentPos << endl;
    
    if(currentPos == listSize)
    {
        cerr << "reader head reaching the END!" << endl;
        currentPos = 0;
        return objPos(-99,0,0,0,0); // indicating end of list
    }
 
    return list[currentPos++];
}

void objPosArrayList::resetReadPos()
{
    currentPos = 0;
}

void objPosArrayList::set(const objPos &thisPos, int index)
{
    if(index < 0) index = 0;
    if(index > listSize - 1) index = listSize - 1;

    list[index].setX(thisPos.getX());
    list[index].setY(thisPos.getY());
    list[index].setNum(thisPos.getNum());
    list[index].setPF(thisPos.getPF());
    list[index].setSym(thisPos.getSym());
}


objPos objPosArrayList::removeHead()
{
    if(listSize <= 0) 
        return objPos(-99,0,0,0,0); // indicating invalid element
    
    objPos temp = list[0];

    for(int i = 0; i < listSize - 1; i++)
    {
        list[i] = list[i+1];
    }

    listSize--;

    return temp;
}

objPos objPosArrayList::removeTail()
{
    if(listSize <= 0) 
        return objPos(-99,0,0,0,0); // indicating invalid element

    listSize--;  // lazy delete

    return list[listSize];  // return the lazy-deleted element
 }

objPos objPosArrayList::remove(int index)
{
    objPos temp;  // call default constructor
    if(listSize <= 0) 
        return objPos(-99,0,0,0,0); // indicating invalid element
    
    if(index > listSize) index = listSize - 1;
    if(index < 0) index = 0;

    temp = list[index];

    for(int i = index; i < listSize - 1; i++)
    {
        list[i] = list[i+1];
    }

    listSize--;

    return temp;
}


void objPosArrayList::printList() const
{
    cout << "List Contains:" << endl;
    
    for(int i = 0; i < listSize; i++)
    {
        cout << "[" << i << "] ";
        list[i].printObjPos();
    }

    cout << "END OF LIST" << endl;
}

