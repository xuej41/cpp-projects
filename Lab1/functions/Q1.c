#include <stdio.h>

int Q1_for(int num){
	int sum;
    sum = 0;
	
	// calculate your sum below..this has to use for loop
	for (int i = num; i <= 1000; i+=num)
	{
        sum += i;
	}

    return sum;
}

void main(){
    int result = Q1_for(99);
    printf("the result is %d", result);
}