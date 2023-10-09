/*gavin skehan
21440824
09/02/22*/
#include <stdio.h> // libaries
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void printDoubleArray(double* dp, int len); // functions with pointers
void swapIntegerValues(int* i1, int* i2);
void squareIntArray(int* i1, int len);
void printIntegerArrayBackwards(int* arr, int len);
void randomIntArray(int* arr, int len, int max);

void main() {
	// Question 1
	double array1[] = { 1.50, 2.30, 4.70, 8.90 }; // array double
	printf("Q1: Double array\n"); 
	int* ip = array1; // pointers
	printDoubleArray(array1, 4); // calling function

	// Question 2
	printf("Q2: Integer Swap\n");
	int a = 7; // initialise 
	int b = 6;
	printf("\tBefore swap a = %d B = %d\n", a, b); // before swap
	swapIntegerValues(&a, &b);
	printf("\tAfter swap a = %d b = %d\n", a, b); // after swap

	// Question 3
	int array2[] = { 1,2,4,8,16 }; // array of integers
	printf("Q3: Square Array \n");
	int* iq = array2;
	squareIntArray(array2, 5); // call function

	// Question 4
	printf("\n");
	int array3[] = { 6,7,8,9,10 };
	printf("Q4: Array Backwards \n");
	int* ig = array3;
	printIntegerArrayBackwards(array3, 5);

	// Question 5
	srand(time(NULL));
	printf("\n");
	int array4[5];
	printf("Q5: Random Integers \n");
	int* il = array4;
	randomIntArray(array4, 5, 100); // random number generator with max size 100 and 5 numbers
}


void printDoubleArray(double* dp, int len)
{
	for (int i = 0; i < len; i++) {
		printf("%0.2f\t", *(dp + i)); // prints doubles to the screen
	}
	printf("\n");
}

void swapIntegerValues(int* i1, int* i2)
{
	int temp = *i1; // swapping integer values
	*i1 = *i2;
	*i2 = temp;
	return 0;

}

void squareIntArray(int* i1, int len)
{
	for (int i = 0; i < len; i++) {
		*(i1 + i) = (* (i1 + i) * (*i1 + i)); // formula for squaring
		printf("%d\t", *(i1 + i));
	}
}

void printIntegerArrayBackwards(int* arr, int len)
{
	for (int i = len - 1;i>=0; i--) { // reverse order
		printf("%d \t", arr[i]);
	}
	return 0;
}

void randomIntArray(int* arr, int len, int max)
{
	for (int i = 0; i < len; i++) {
		*(arr + i) = rand() % 100; // modulus function
		printf("%d\t", arr[i]);
	}

}
