#include "objPosQuadHashing.h"

#include <iostream>
using namespace std;

objPosQuadHashing::objPosQuadHashing()
{
    // do you need anything here? no already done in objPosHashTable
}

objPosQuadHashing::objPosQuadHashing(int size) : objPosHashTable(size)
{
    // do you need to modify anything here? no
}

objPosQuadHashing::~objPosQuadHashing()
{
    // do you need anything here? no
}

bool objPosQuadHashing::insert(const objPos &thisPos)
{
    if (isInTable(thisPos)) { // if already in table return false
        return false;
    }

    // Insert thisPos into the Hash Table (if not already inserted) using Quadratic Probing same implementation as in Linear Probing but with i^2 instead
    int hashVal = calculateHashing(thisPos.getPF(), thisPos.getNum());
    int i = 0;

    while (myHashTable[hashVal].getSym() == 'v') {
        i++;
        hashVal = (calculateHashing(thisPos.getPF(), thisPos.getNum()) + i*i) % tableSize;

        if (i > MAX_PROBING_COUNT) {
            return false;
        }
    }

    myHashTable[hashVal] = thisPos;
    myHashTable[hashVal].setSym('v');
    
    return true;

    // When inserting, using Symbol as a way to check if the table entry is occupied or free
    //    Symbol = 0 (FREE),   Symbol = 'v' (Occupied)
}

bool objPosQuadHashing::remove(const objPos &thisPos)  // lazy delete, same implementation as Linear Probing but with i^2 instead
{
    if (!isInTable(thisPos)) {
        return false;
    }

    int hashVal = calculateHashing(thisPos.getPF(), thisPos.getNum());
    int i = 0;

    while (true) {
        if (myHashTable[hashVal].getSym() != '\0' && myHashTable[hashVal].getPF() == thisPos.getPF() && myHashTable[hashVal].getNum() == thisPos.getNum()) {
            break;
        }

        i++;
        hashVal = (calculateHashing(thisPos.getPF(), thisPos.getNum()) + i*i) % tableSize;

        if (i > MAX_PROBING_COUNT) {
            return false;
        }
    }

    myHashTable[hashVal].setSym('\0');

    return true;

    // If found in the table, apply lazy deletion by setting Symbol = 0 (free), and return true
    // If not found in the table, return false

    // You need to think carefully about what conditions will end the probing
    // During debugging, you may use MAX_PROBING_COUNT defined in objPosHash.h as a hard limit to the number of probes 
    // to be carried out.  This hard limit is not to fix the bug, but only to help you debugger more easily.
}

bool objPosQuadHashing::isInTable(const objPos &thisPos) const // same implementation as Linear Probing but with i^2 instead
{
    // Check if thisPos is in the Hash Table using Quadratic Probing
    int hashVal = calculateHashing(thisPos.getPF(), thisPos.getNum());
    int i = 0;
    bool found_object = false;

    while (true) {
        if (myHashTable[hashVal].getSym() != '\0' && myHashTable[hashVal].getPF() == thisPos.getPF() && myHashTable[hashVal].getNum() == thisPos.getNum()) {
            found_object = true;
            break;
        }
        
        i++;
        hashVal = (calculateHashing(thisPos.getPF(), thisPos.getNum()) + i*i) % tableSize;

        if (i > MAX_PROBING_COUNT) {
            return false;
        }
    }
    return found_object;

    // If found in the table, return true
        // Remember, finding the match is not enough.  The entry has to be VALID (symbol = 'v').
    // If not found in the table, return false

    // You need to think carefully about what conditions will end the probing
    // During debugging, you may use MAX_PROBING_COUNT defined in objPosHash.h as a hard limit to the number of probes 
    // to be carried out.  This hard limit is not to fix the bug, but only to help you debugger more easily. 
}