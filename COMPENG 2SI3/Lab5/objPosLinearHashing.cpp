#include "objPosLinearHashing.h"

#include <iostream>
using namespace std;

objPosLinearHashing::objPosLinearHashing()
{
    // do you need anything here? no already done in objPosHashTable 
}

objPosLinearHashing::objPosLinearHashing(int size) : objPosHashTable(size)
{
    // do you need to modify anything here? no
}

objPosLinearHashing::~objPosLinearHashing()
{
    // do you need anything here? no
}

bool objPosLinearHashing::insert(const objPos &thisPos)
{
    if (isInTable(thisPos)) { // if already in table return false
        return false;
    }

    // Insert thisPos into the Hash Table (if not already inserted) using Linear Probing
    int hashVal = calculateHashing(thisPos.getPF(), thisPos.getNum()) % tableSize; // h(x) mod M
    int i = 0;
    while (myHashTable[hashVal].getSym() == 'v') { // while occupied
        i++;
        hashVal = (calculateHashing(thisPos.getPF(), thisPos.getNum()) + i) % tableSize; // (h(x) + i) mod M

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

bool objPosLinearHashing::remove(const objPos &thisPos)
{
    if (!isInTable(thisPos)) {  // if already in table return false
        return false;
    }

    int hashVal = calculateHashing(thisPos.getPF(), thisPos.getNum());
    int i = 0;

    while (true) {
        // If objPos is found break out of the loop and set Symbol = 0 (FREE)
        if (myHashTable[hashVal].getSym() != '\0' && myHashTable[hashVal].getPF() == thisPos.getPF() && myHashTable[hashVal].getNum() == thisPos.getNum()) {
            break;
        }
        i++;
        // else keep recalculating hashVal with i increasing until 1000 and then return false
        hashVal = (calculateHashing(thisPos.getPF(), thisPos.getNum()) + i) % tableSize;

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

bool objPosLinearHashing::isInTable(const objPos &thisPos) const
{
    // Check if thisPos is in the Hash Table using Linear Probing
    int hashVal = calculateHashing(thisPos.getPF(), thisPos.getNum());
    int i = 0;
    bool found_object = false;
    while (true) {
        // if objPos is found break out of the loop and set found_object = true
        if (myHashTable[hashVal].getSym() != '\0' && myHashTable[hashVal].getPF() == thisPos.getPF() && myHashTable[hashVal].getNum() == thisPos.getNum()) {
            found_object = true;
            break;
        }
        // else keep recalculating hashVal with i increasing until 1000 and then return false
        i++;
        hashVal = (calculateHashing(thisPos.getPF(), thisPos.getNum()) + i) % tableSize;

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