#include <stdio.h>

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

void main(){
    int result = Q2_FPN(0,1.234);
    printf("%d", result);
}