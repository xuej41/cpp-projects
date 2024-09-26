
#include "Questions.h"
//#include <stdbool.h> didnt need


int Q1_for(int num){
	int sum;
    sum = 0;
	
	for (int i = num; i <= 1000; i+=num){
        sum += i;
	}

    return sum;
}

int Q1_while(int num){
	int sum;
	sum = 0;
	int i = num;

	while (i <= 1000){
		sum += i;
		i += num;
	}

	return sum;
}

int Q1_dowhile(int num){
	int sum;
	sum = 0;
	int i = num;

	do{
		sum += i;
		i += num;
	} while (i <= 1000);

	return sum;
}
//===============================================================================================
int Q2_FPN(float Q2_input, float Q2_threshold){
	
	int result;

	if (Q2_input >= -2*Q2_threshold && Q2_input < -1*Q2_threshold)
	{
		result = 0;
	}
	else if (Q2_input >= -1*Q2_threshold && Q2_input < 0)
	{
		result = 1;
	}
	else if (Q2_input >= 0 && Q2_input < Q2_threshold)
	{
		result = 2;
	}
	else if (Q2_input >= Q2_threshold && Q2_input <= 2*Q2_threshold)
	{
		result = 3;
	}
	else
	{
		result = -999;
	}

	return result;
}
//===============================================================================================
int Q3(int Q3_input, int perfect[]){
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
//===============================================================================================
int Q4_Bubble(int array[], int size){
	
	int passes = 0;
	int swap = 1; //swap = true

	while (swap)
	{
        swap = 0; //set swap to false at each pass

        //perform one pass
		for (int i = 0; i < size-1; i++)
		{
			if (array[i] > array[i+1])
			{
				int temp = array[i]; //swap the two numbers
				array[i] = array[i+1];
				array[i+1] = temp;

				swap = 1; //swap occured, continue
			}
		}

        passes++; //increment passes after a pass of the for loop
	}

	return passes;
}