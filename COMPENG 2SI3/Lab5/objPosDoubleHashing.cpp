#include "objPosDoubleHashing.h"
//#include "MacUILib.h"

#include <iostream>
using namespace std;

objPosDoubleHashing::objPosDoubleHashing()
{
    // do you need anything here? no already done in objPosHashTable
}

objPosDoubleHashing::objPosDoubleHashing(int size) : objPosHashTable(size)
{
    // do you need to modify anything here? no
}

objPosDoubleHashing::~objPosDoubleHashing()
{
    // do you need anything here? no
}

int objPosDoubleHashing::calculateSecondaryHashing(int input) const
{
    // Secondary Hashing Function
    int sum = 0;
    while (input > 0) {
        sum += input % 10;
        input /= 10;
    }
    return (5 - (sum % 5));

    // Formula : sum of all digits of the first hashing index mod 5.

    // Ex. Hashing Index = 36, then Secondary Hashing Index = (3 + 6) % 5 = 4
}

bool objPosDoubleHashing::insert(const objPos &thisPos)
{
    // Insert thisPos into the Hash Table (if not already inserted) using Double Hashing
    if (isInTable(thisPos)) {
        return false;
    }

    // Insert thisPos into the Hash Table (if not already inserted) using Quadratic Probing same implementation as in Linear Probing but with i*doubleHash instead
    int hashVal = calculateHashing(thisPos.getPF(), thisPos.getNum());
    int doubleHash = calculateSecondaryHashing(hashVal);
    int i = 0;

    while (myHashTable[hashVal].getSym() == 'v') {
        i++;
        hashVal = (calculateHashing(thisPos.getPF(), thisPos.getNum()) + i*doubleHash) % tableSize;

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

bool objPosDoubleHashing::remove(const objPos &thisPos)
{
    // Remove thisPos from the Hash Table using Double Hashing, same implementation as Linear Probing but with i*doubleHash instead
    if (!isInTable(thisPos)) {
        return false;
    }

    int hashVal = calculateHashing(thisPos.getPF(), thisPos.getNum());
    int doubleHash = calculateSecondaryHashing(hashVal);
    int i = 0;

    while (true) {
        if (myHashTable[hashVal].getSym() != '\0' && myHashTable[hashVal].getPF() == thisPos.getPF() && myHashTable[hashVal].getNum() == thisPos.getNum()) {
            break;
        }

        i++;
        hashVal = (calculateHashing(thisPos.getPF(), thisPos.getNum()) + i*doubleHash) % tableSize;

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

bool objPosDoubleHashing::isInTable(const objPos &thisPos) const // same implementation as Linear Probing but with i^doubleHash instead
{
    // Check if thisPos is in the Hash Table using Double Hashing Probing
    int hashVal = calculateHashing(thisPos.getPF(), thisPos.getNum());
    int doubleHash = calculateSecondaryHashing(hashVal);
    int i = 0;
    bool found_object = false;

    while (true) {
        if (myHashTable[hashVal].getSym() != '\0' && myHashTable[hashVal].getPF() == thisPos.getPF() && myHashTable[hashVal].getNum() == thisPos.getNum()) {
            found_object = true;
            break;
        }

        i++;
        hashVal = (calculateHashing(thisPos.getPF(), thisPos.getNum()) + i*doubleHash) % tableSize;

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