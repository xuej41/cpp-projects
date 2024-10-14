#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


// this is the very first question without hints in the comments.  read the manual to develop your own algorithm

// Read Questions.h to understand the definition of Q3Struct

void efficient(const int source[], struct Q3Struct effVector[], int size)
{   
    int nonZeroes = 0;

    for (int i = 0; i < size; i++)
    {
        if (source[i] != 0)
        {
            effVector[nonZeroes].val = source[i];
            effVector[nonZeroes].pos = i;
            nonZeroes++;
        }
        
    }
}

void reconstruct(int source[], int m, const struct Q3Struct effVector[], int n)
{
    for (int i = 0; i < n; i++) // Loop through the elements of effVector
    {
        if (effVector[i].pos >= 0 && effVector[i].pos < m) // Make sure position is within bounds
        {
            source[effVector[i].pos] = effVector[i].val;  // Replace 0 in source vector with appropriate value in effVector
        }
    }
}
