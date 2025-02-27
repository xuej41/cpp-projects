#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr [])
{

    // This is the first programming (scripting) question without any initial setup as hints.

    // This is also the first question requiring you to come up with an algorithm on paper 
    // with mathematical analysis before implementing the code.

    // High Level Hint:
    //  Assume a 3x3 square matrix, look at the SUM of the row and column indices of each element.
    //  You should be able to see a numerical pattern after doing so.
    int index = 0;

    for (int i = 0; i < 2 * N3 - 1; i++) {
        for (int j = 0; j < N3; j++) {
            for (int k = 0; k < N3; k++) {
                if (j + k == i) {
                    arr[index++] = mat[j][k]; // Place element in the array and increment index
                }
            }
        }
    }
}
