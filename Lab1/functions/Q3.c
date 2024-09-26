#include <stdio.h>

int Q3(int Q3_input, int perfect[]) {
    int counts = 0;
    int sum = 0;

    for (int num = 1; num <= Q3_input; num++) { //start checking nums from 1 to Q3 input

        // Find factors of num
        for (int i = 1; i < num; i++) { // Check all numbers less than num
            if (num % i == 0) { // If i is a factor
                sum += i; // Add factor to sum
            }
        }

        // If sum of factors = num its a perfect number
        if (sum == num) {
            perfect[counts] = num;
            counts++;
        }

        sum = 0; // Reset sum after checking each num
    }

    return counts;
}

int main() {
    int perfect[100];
    int result = Q3(10000, perfect);

    // Print the count of perfect numbers
    printf("Found %d perfect numbers:\n", result);

    // Print the perfect numbers
    for (int i = 0; i < result; i++) {
        printf("%d ", perfect[i]);
    }
    printf("\n");

    return 0;
}
