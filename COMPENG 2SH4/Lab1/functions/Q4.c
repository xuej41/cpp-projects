#include <stdio.h>
#include <stdbool.h>

int Q4_Bubble(int array[], int size){

	int passes = 0;
	bool swap = true;

	while (swap)
	{
        swap = false;

        //perform one pass
		for (int i = 0; i < size-1; i++)
		{
			if (array[i] > array[i+1])
			{
				int temp = array[i]; //swap the two numbers
				array[i] = array[i+1];
				array[i+1] = temp;

				swap = true; //swap occured, continue
			}
		}

        passes++; //increment passes after a pass of the for loop
	}

	return passes;
}

int main(){
    int array[] = {-100, 100, -90, 90, -80, 80, -70, 70, -60, 60};
    int result = Q4_Bubble(array,10);
    printf("%d passes\n", result);

    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;

}