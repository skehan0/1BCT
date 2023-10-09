#include <string.h> 
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
//void bubbleSort(int arrA[], int size);
void selectionSort(int arrA[], int size);
//void insertionSort(int arrA[], int size);

void main() {
	int arrA[5000];
	int n = 5000;
	int i;
	FILE* fptr;
	char myfilePath[] = "C:\\Users\\skeha\\OneDrive\\Documents\\sortedints.txt";
	fopen_s(&fptr, myfilePath, "r+");
	if (NULL == fptr) {
		fprintf(stderr, "Error opening file\n");
		return;
	}
	else {
		for (i = 0; fscanf_s(fptr, "%d", &arrA[i]) == 1 && i < 5000; i++);
	}
	fclose(fptr);

	selectionSort(arrA, n);
	//insertionSort(arrA, n);
	//bubbleSort(arrA, n);

	printf("\n 5000 sorted ints: ");
	for (int i = 0; i < n; i++)
		printf("\n %d", arrA[i]);
}

/*
void bubbleSort(int arrA[], int size) {
	int i, k, temp;
	int numSwaps = 0;
	int numCmprs = 0;
	double timeTaken;

	clock_t time;
	time = clock();

	for (k = 0; k < size; k++) {
		for (i = 0; i < size - 1 - k; i++) {
			if (arrA[i] > arrA[i + 1]) {
				++numSwaps;
				temp = arrA[i];
				arrA[i] = arrA[i + 1];
			}
			++numCmprs;
		}
	}
	time = clock() - time;
	timeTaken = ((double)time) / CLOCKS_PER_SEC;
	printf("\n Bubble sort:\n time taken: %f; \n number of swaps is %d;\n number of comparisons is %d", timeTaken, numSwaps, numCmprs);
}
*/

void selectionSort(int arrA[], int size)
{
	int i, j, temp, min;
	int numSwaps = 0;
	int numCmprs = 0;


	clock_t t;
	t = clock();

	for (i = 0; i < size - 1; i++) {
		min = i;
		for (j = min + 1; i < size - 1; i++) {
			if (arrA[min] > arrA[j]) {

				min = j;
			}
			++numCmprs;
		}
		if (i != min) {
			++numSwaps;
			temp = arrA[i];
			arrA[i] = arrA[min];
			arrA[min] = temp;
		}

	}
	t = clock() - t;
	double time_Taken = ((double)t) / CLOCKS_PER_SEC;
	printf("\n Selection sort:\n time taken: %f; \n number of swaps is %d;\n number of comparisons is %d", time_Taken, numSwaps, numCmprs);
}
/*
void insertionSort(int arrA[], int size)
{
	int i, j, curr;
	int numMoves = 0;
	int numCmprs = 0;


	clock_t t;
	t = clock();

	for (i = 1; i < size; i++)
	{
		curr = arrA[i];

		for (j = i - 1; j >= 0 && curr < arrA[j]; j--) {
			++numCmprs;
			arrA[j + 1] = arrA[j];
			++numMoves;
		}
		++numCmprs;

		if (i != j + 1) {
			arrA[j + 1] = curr;
			++numMoves;
		}
	}
	t = clock() - t;
	double time_Taken = ((double)t) / CLOCKS_PER_SEC;
	printf("\n Insertion sort:\n time taken: %f; \n number of swaps is %d;\n number of comparisons is %d", time_Taken, numMoves, numCmprs);
}
*/