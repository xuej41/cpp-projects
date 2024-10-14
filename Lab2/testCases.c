#include <stdlib.h>
#include <stdio.h>

#include "Questions.h"
    
int successCount;
int passCount;

int totalTestCases, totalAssertions;

int assert_equal_int(int, int);
int assert_equal_char(char, char);
int assert_equal_double(double, double, double);
void tearDown(int result);
    
    
//=========Question 1==================================
void TestQ1_add() {

    printf("\n=== TestQ1_add() ===\n");
	int result = 1; // true;
	
	int i;
	int n = 5;
	double input1[5] = {3.60, 4.78, 6.00, 10.00, 0.01};
	double input2[5] = {1.50, 2.00, 3.30, 9.90, 1.00};
	double actual[5];
	double expected [5] = {5.10, 6.78, 9.30, 19.90, 1.01};

	add_vectors(input1,input2,actual,n);
	
	for (i=0; i<n; i++)
		result &= assert_equal_double(expected[i], actual[i],0.009);

    tearDown(result);		
}
    
void TestQ1_scalar_prod() {

    printf("\n=== TestQ1_scalar_prod() ===\n");
	int result = 1; // true;

	int n = 5;
	double input1[5] = {3.60, 4.78, 6.00, 10.00, 0.01};
	double input2[5] = {1.50, 2.00, 3.30, 9.90, 1.00};
	double expected=133.770 ;
	double actual = scalar_prod(input1,input2,n);

	result &= assert_equal_double(expected, actual,0.009);

	tearDown(result);
}

void TestQ1_norm() {

    printf("\n=== TestQ1_norm() ===\n");
	int result = 1; // true;

	int n = 5;
	double input1[5] = {3.60, 4.78, 6.00, 10.00, 0.01};
	double expected=13.108 ;
    double actual = norm2(input1,n);

	result &= assert_equal_double(expected, actual,0.009);

	tearDown(result);
}

void TestQ1_add_Custom1() {

    printf("\n=== TestQ1_add_Custom1() ===\n");
	int result = 1; // true;
	
	int i;
	int n = 10;
	double input1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	double input2[10] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10}; //edge case: result array should be empty
	double actual[10];
	double expected [10] = {}; //empty array

	add_vectors(input1,input2,actual,n);
	
	for (i=0; i<n; i++)
		result &= assert_equal_double(expected[i], actual[i],0.009);

    tearDown(result);		
}
void TestQ1_add_Custom2() {

    printf("\n=== TestQ1_add_Custom2() ===\n");
	int result = 1; // true;
	
	int i;
	int n = 1;
	double input1[1] = {0};
	double input2[1] = {0};
	double actual[1];
	double expected [1] = {}; //edge case: result should be an empty array

	add_vectors(input1,input2,actual,n);
	
	for (i=0; i<n; i++)
		result &= assert_equal_double(expected[i], actual[i],0.009);		
	
	tearDown(result);
}
void TestQ1_add_Custom3() {

    printf("\n=== TestQ1_add_Custom3() ===\n");
	int result = 1; // true;
	
	int i;
	int n = 8;
	double input1[8] = {-1, -2, -3, -4, -5, -6, -7, -8};
	double input2[8] = {-1, -2, -3, -4, -5, -6, -7, -8};
	double actual[8];
	double expected [8] = {-2, -4, -6, -8, -10, -12, -14, -16};

	add_vectors(input1,input2,actual,n);
	
	for (i=0; i<n; i++)
		result &= assert_equal_double(expected[i], actual[i],0.009);		
	
	tearDown(result);
}
    
void TestQ1_scalar_prod_Custom1() {

    printf("\n=== TestQ1_scalar_prod_Custom1() ===\n");
	int result = 1; // true;

	int n = 10;
	double input1[10] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
	double input2[10] = {1, -1, 2, -2, 3, -3, 4, -4, 5, -5}; //edge case: everything should cancel out
	double expected = 0;
	double actual = scalar_prod(input1,input2,n);

	result &= assert_equal_double(expected, actual,0.009);

    tearDown(result);
}
void TestQ1_scalar_prod_Custom2() {

    printf("\n=== TestQ1_scalar_prod_Custom2() ===\n");
	int result = 1; // true;

	int n = 1;
	double input1[1] = {0};
	double input2[1] = {0};
	double expected = 0;
	double actual = scalar_prod(input1,input2,n);

	result &= assert_equal_double(expected, actual,0.009);

    tearDown(result);
}
void TestQ1_scalar_prod_Custom3() {

    printf("\n=== TestQ1_scalar_prod_Custom3() ===\n");
	int result = 1; // true;

	int n = 8;
	double input1[8] = {1.5, 1.2, 2.5, 2.2, 3.5, 3.2, 4.5, 4.2};
	double input2[8] = {1.2, 1.5, 2.2, 2.5, 3.2, 3.5, 4.2, 4.5};
	double expected = 74.8;
	double actual = scalar_prod(input1,input2,n);

	result &= assert_equal_double(expected, actual,0.009);

    tearDown(result);
}

void TestQ1_norm_Custom1() {

    printf("\n=== TestQ1_norm_Custom1() ===\n");
	int result = 1; // true;

	int n = 10;
	double input1[10] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10}; //edge case: negative numbers should not matter
	double expected = 19.62141687;
    double actual = norm2(input1,n);

	result &= assert_equal_double(expected, actual,0.009);

    tearDown(result);
}
void TestQ1_norm_Custom2() {

    printf("\n=== TestQ1_norm_Custom2() ===\n");
	int result = 1; // true;

	int n = 1;
	double input1[1] = {-10}; //edge case: negative number, only one element in the array
	double expected = 10;
    double actual = norm2(input1,n);

	result &= assert_equal_double(expected, actual,0.009);

    tearDown(result);
}
void TestQ1_norm_Custom3() {

    printf("\n=== TestQ1_norm_Custom3() ===\n");
	int result = 1; // true;

	int n = 8;
	double input1[8] = {0, 0, 0, 0, 0, 0, 0, 0}; //edge case: zeroes
	double expected = 0;
    double actual = norm2(input1,n);

	result &= assert_equal_double(expected, actual,0.009);

    tearDown(result);
}

//===========================================================
//=================Question 2================================  

void TestQ2() {

    printf("\n=== TestQ2() ===\n");
	int result = 1; // true;

	int n = 3;
	int input[3][3] = {{1, 2, 3},{ 5, 8, 9},{ 0, 3, 5}};
	int expected[9]= {1, 2, 5, 3, 8, 0, 9, 3, 5};
	int actual[9];
	diag_scan(input,actual);

	int i;
	for (i=0; i<n*n; i++)
        result &= assert_equal_int(expected[i], actual[i]);

	tearDown(result);
}

void TestQ2_Custom1() {

    printf("\n=== TestQ2_Custom1() ===\n");
	int result = 1; // true;

	int n = 3;
	int input[3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
	int expected[9]= {1, 2, 4, 3, 5, 7, 6, 8, 9};
	int actual[9];
	diag_scan(input,actual);

	int i;
	for (i=0; i<n*n; i++)
        result &= assert_equal_int(expected[i], actual[i]);

	tearDown(result);
}
void TestQ2_Custom2() {

    printf("\n=== TestQ2_Custom2() ===\n");
	int result = 1; // true;

	int n = 3;
	int input[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};
	int expected[9]= {}; //edge case: empty 3x3 matrix
	int actual[9];
	diag_scan(input,actual);

	int i;
	for (i=0; i<n*n; i++)
        result &= assert_equal_int(expected[i], actual[i]);

	tearDown(result);
}
void TestQ2_Custom3() {

    printf("\n=== TestQ2_Custom3() ===\n");
	int result = 1; // true;

	int n = 3;
	int input[3][3] = {{-1, 10, 77},{2, -99, -98},{100, 3, -2.5}};
	int expected[9]= {-1, 10, 2, 77, -99, 100, -98, 3, -2.5}; // edge case: negative numbers
	int actual[9];
	diag_scan(input,actual);

	int i;
	for (i=0; i<n*n; i++)
        result &= assert_equal_int(expected[i], actual[i]);

	tearDown(result);
}


    
//===========================================================
//=================Question 3================================   
void TestQ3_1() {

    printf("\n=== TestQ3_1() ===\n");
	int result = 1; // true;

	int n=8;
	int input[]={0,0,23,0,-7,0,0,48};
	struct Q3Struct actual[8] = {0};
	struct Q3Struct expected[8] = {{23, 2}, {-7, 4}, {48, 7}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
        result &= assert_equal_int(expected[i].val, actual[i].val);
		result &= assert_equal_int(expected[i].pos, actual[i].pos);
	}

	tearDown(result);
}

void TestQ3_zeros() {

    printf("\n=== TestQ3_zeros() ===\n");
	int result = 1; // true;

	int n=8;
	int input[]={0,0,0,0,0,0,0,0};
	struct Q3Struct actual[8] = {0};
	struct Q3Struct expected[8] = {0};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		result &= assert_equal_int(expected[i].val, actual[i].val);
		result &= assert_equal_int(expected[i].pos, actual[i].pos);
	}

	tearDown(result);
}

void TestQ3_combined() {

    printf("\n=== TestQ3_combined() ===\n");
	int result = 1; // true;

	int n=8;
	int input[]={0,0,23,0,-7,0,0,48};
	struct Q3Struct int_result[8] = {0};
	int expected[8] = {0,0,23,0,-7,0,0,48};
	int actual[8] = {0};
	efficient(input,int_result,n);
	reconstruct(actual, 8, int_result, 3);

	int i;
	for (i=0; i<n; i++){
		result &= assert_equal_int(expected[i], actual[i]);
	}

	tearDown(result);
}

void TestQ3_combined_Custom1() {

    printf("\n=== TestQ3_combined_Custom1() ===\n");
	int result = 1; // true;

	int n=4;
	int input[]={1,0,-2,0};
	struct Q3Struct int_result[4] = {0};
	int expected[4] = {1,0,-2,0};
	int actual[4] = {0};
	efficient(input,int_result,n);
	reconstruct(actual, 4, int_result, 2);

	int i;
	for (i=0; i<n; i++){
		result &= assert_equal_int(expected[i], actual[i]);
	}

	tearDown(result);
}
void TestQ3_combined_Custom2() {

    printf("\n=== TestQ3_combined_Custom2() ===\n");
	int result = 1; // true;

	int n=10;
	int input[]={0,0,0,0,-999,0,0,2000,-100,1};
	struct Q3Struct int_result[10] = {0};
	int expected[10] = {0,0,0,0,-999,0,0,2000,-100,1};
	int actual[10] = {0};
	efficient(input,int_result,n);
	reconstruct(actual, 10, int_result, 4);

	int i;
	for (i=0; i<n; i++){
		result &= assert_equal_int(expected[i], actual[i]);
	}

	tearDown(result);
}
    


//===========================================================
//=================Question 4================================   
void TestQ4_BubbleSort_1() 
{
    printf("\n=== TestQ4_BubbleSort_1() ===\n");
	int result = 1; // true;

	int n=6;
	struct Q4Struct input[]={{10, 'c'}, {2, 'B'}, {-5, 'k'}, {12, 'z'}, {77, 'a'}, {-42, '?'}};	
	struct Q4Struct expected[]={{-42, '?'}, {-5, 'k'}, {2, 'B'}, {10, 'c'}, {12, 'z'}, {77, 'a'}};		
	
	sortDatabyBubble(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		result &= assert_equal_int(expected[i].intData, input[i].intData);
		result &= assert_equal_char(expected[i].charData, input[i].charData);
	}

	tearDown(result);
}

void TestQ4_BubbleSort_2() 
{
    printf("\n=== TestQ4_BubbleSort_2() ===\n");
	int result = 1; // true;

	int n=8;
	struct Q4Struct input[]={{-23, '='}, {78, ' '}, {11, 'Y'}, {-2, '0'}, {41, '+'}, {0, 'm'}, {55, 'T'}, {-9, 'o'}};	
	struct Q4Struct expected[]={{-23, '='}, {-9, 'o'}, {-2, '0'}, {0, 'm'}, {11, 'Y'}, {41, '+'}, {55, 'T'}, {78, ' '}};		
	
	sortDatabyBubble(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		result &= assert_equal_int(expected[i].intData, input[i].intData);
		result &= assert_equal_char(expected[i].charData, input[i].charData);
	}

	tearDown(result);
}

void TestQ4_BubbleSort_Custom() 
{
    printf("\n=== TestQ4_BubbleSort_Custom() ===\n");
	int result = 1; // true;

	int n=3;
	struct Q4Struct input[]={{1000, 't'}, {-999, 'Z'}, {-3, 'k'}};	
	struct Q4Struct expected[]={{-999, 'Z'}, {-3, 'k'}, {1000, 't'}};	
	
	sortDatabyBubble(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		result &= assert_equal_int(expected[i].intData, input[i].intData);
		result &= assert_equal_char(expected[i].charData, input[i].charData);
	}

	tearDown(result);
}

void TestQ4_SelectionSort_1() 
{
    printf("\n=== TestQ4_SelectionSort_1() ===\n");
	int result = 1; // true;

	int n=6;
	struct Q4Struct input[]={{10, 'c'}, {2, 'B'}, {-5, 'k'}, {12, 'z'}, {77, 'a'}, {-42, '?'}};	
	struct Q4Struct expected[]={{-42, '?'}, {-5, 'k'}, {2, 'B'}, {10, 'c'}, {12, 'z'}, {77, 'a'}};		
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		result &= assert_equal_int(expected[i].intData, input[i].intData);
		result &= assert_equal_char(expected[i].charData, input[i].charData);
	}

	tearDown(result);
}

void TestQ4_SelectionSort_2() 
{
	printf("\n=== TestQ4_SelectionSort_2() ===\n");
	int result = 1; // true;
	
	int n=8;
	struct Q4Struct input[]={{-23, '='}, {78, ' '}, {11, 'Y'}, {-2, '0'}, {41, '+'}, {0, 'm'}, {55, 'T'}, {-9, 'o'}};	
	struct Q4Struct expected[]={{-23, '='}, {-9, 'o'}, {-2, '0'}, {0, 'm'}, {11, 'Y'}, {41, '+'}, {55, 'T'}, {78, ' '}};			
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		result &= assert_equal_int(expected[i].intData, input[i].intData);
		result &= assert_equal_char(expected[i].charData, input[i].charData);
	}

	tearDown(result);
}

void TestQ4_SelectionSort_Custom() 
{
    printf("\n=== TestQ4_SelectionSort_Custom() ===\n");
	int result = 1; // true;
	
	int n=5;
	struct Q4Struct input[]={{100, '?'}, {2, '#'}, {-99, 'Y'}, {9999, '0'}, {-1234, '+'}};	
	struct Q4Struct expected[]={{-1234, '+'}, {-99, 'Y'}, {2, '#'},{100, '?'}, {9999, '0'}};			
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		result &= assert_equal_int(expected[i].intData, input[i].intData);
		result &= assert_equal_char(expected[i].charData, input[i].charData);
	}

	tearDown(result);
}


//===========================================================
	int runAllTests(int argc, char const *argv[]) {
		
		TestQ1_add();
		TestQ1_scalar_prod();
		TestQ1_norm();

		TestQ1_add_Custom1();
		TestQ1_add_Custom2();
		TestQ1_add_Custom3();
		TestQ1_scalar_prod_Custom1();
		TestQ1_scalar_prod_Custom2();
		TestQ1_scalar_prod_Custom3();
		TestQ1_norm_Custom1();
		TestQ1_norm_Custom2();
		TestQ1_norm_Custom3();

		TestQ2();
		TestQ2_Custom1();
		TestQ2_Custom2();
		TestQ2_Custom3();

		TestQ3_1();
		TestQ3_zeros();
		TestQ3_combined();
		TestQ3_combined_Custom1();
		TestQ3_combined_Custom2();

		TestQ4_BubbleSort_1();
		TestQ4_BubbleSort_2();
		TestQ4_BubbleSort_Custom();
		TestQ4_SelectionSort_1();
		TestQ4_SelectionSort_2();
		TestQ4_SelectionSort_Custom();

		return (successCount == totalAssertions);
	}

int main(int argc, char const *argv[]) {
  		
	successCount = 0;
	passCount = 0;
    totalAssertions = 0;
    totalTestCases = 0;
    
	int successCode = runAllTests(argc, argv);

    printf("\n=== Lab Test Report ===");
	if(successCode)	printf("\nPassed All Tests\n"); 
	else			printf("\nFailed Tests, Check Failure\n");

	printf("Test Case Score (Graded): %d / %d\n", passCount, totalTestCases);
    printf("Total Assertion Score (For Reference): %d / %d\n\n", successCount, totalAssertions);

	return successCode? EXIT_SUCCESS : EXIT_FAILURE;
}
    
int assert_equal_int(int a, int b)
{
	int result = (a == b);
	if(result)	
		successCount++;
	else
	{
		printf("\t\t[ASSERTION] Expected: %d, but Actual: %d \n", a, b);	
	}

    totalAssertions++;
	return result;
}

int assert_equal_char(char a, char b)
{
	int result = (a == b);
	if(result)	
		successCount++;
	else
	{
		printf("\t\t[ASSERTION] Expected: %c, but Actual: %c \n", a, b);	
	}

    totalAssertions++;
	return result;
}


int assert_equal_double(double a, double b, double tolRange)
{
	int result = ((a <= (b + tolRange)) && (a >= (b - tolRange)));
	if(result)	
		successCount++;
	else
	{
		printf("\t\t[ASSERTION] Expected: %f, but Actual: %f \n", a, b);	
	}

    totalAssertions++;
	return result;
}

void tearDown(int result)
{
    totalTestCases++;
    
    if(result) 
    {
        passCount++;
        printf("Passed\n");
    }
    else
    {
        printf("!!! FAILED !!!\n");
    }
} 
    
