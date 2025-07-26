#include <iostream>
#include "objPosHashTable.h"

// Provided Code for Model Code Integration
////////////////////////////////////////////////

// uncomment this line when integrating with model code
// #include "./Lab5-Model/inc/MacUILib.h"

using namespace std;

objPosHashTable::objPosHashTable()
{
    // create the hash table with default size (TABLE_SIZE)
    tableSize = TABLE_SIZE;
    myHashTable = new objPos[tableSize];
    // By default, all elements in the table should be initialized to:
    //  x = 0, y = 0, prefix = '\0' (0), number = 0, symbol = '\0' (0)
}

objPosHashTable::objPosHashTable(int size)
{
    // create the hash table with the custom size (size)
    tableSize = size;
    myHashTable = new objPos[tableSize];
    // By default, all elements in the table should be initialized to:
    //  x = 0, y = 0, prefix = '\0' (0), number = 0, symbol = '\0' (0)
}

objPosHashTable::~objPosHashTable()
{
    // remove the hash table
    delete[] myHashTable;
}

int objPosHashTable::calculateHashing(int prefix, int number) const
{
    // calculate the hash index using the prefix and number.
    int index = 0;
    while (prefix > 0) {
        index += prefix % 10;
        prefix /= 10;
    }

    while (number > 0) {
        index += number % 10;
        number /= 10;
    }
    
    return index;

    // Formula: Add all digits of the number and the integer value of the ASCII prefix.

    // Ex. prefix = 'A'(65), number = 37
    //     return value = 6 + 5 + 3 + 7 = 21
}

double objPosHashTable::getLambda() const
{
    // calculate the load factor of the hash table
    double occupied = 0.0;

    for (int i = 0; i < tableSize; i++) {
        if (myHashTable[i].getSym() == 'v')
            occupied++;
    }

    double load = occupied / tableSize;

    return load;
}

void objPosHashTable::printMe() const
{
    // Provided for verbose mode in Test.cpp
    // comment the entire for-loop out when integrating with the model code.
    // for(int i = 0; i < tableSize; i++)
    // {
    //     cout << "[" << i << "]  " << myHashTable[i].getPF() << myHashTable[i].getNum() << " " << myHashTable[i].getSym() << endl;     
    // }



    // Provided Code for Model Code Integration
    ////////////////////////////////////////////////

    // uncomment the following lines when integrating with model code

    // MacUILib_printf("[ ");
    // for(int i = 0; i < TABLE_SIZE; i++)
    // {
    //     if(myHashTable[i].getSym() != 0)
    //         MacUILib_printf("%c%d ", myHashTable[i].getPF(), myHashTable[i].getNum());     
    // }
    // MacUILib_printf("] L=%.2f", getLambda());

    // You will also need to #include "MacUILib.h" when integrating with the model code.
}