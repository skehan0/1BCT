#include <string.h> 
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <math.h>

void countSort(int[], int, int);
//void merge(int[], int, int, int);
//void mergeSort(int[], int, int);
//void quickSort(int[], int, int);
//int partition(int[], int, int);

void main() {
	int arrA[5000];
	int n = 5000;
	FILE* fptr;
	char myfilePath[] = "C:\\Users\\skeha\\OneDrive\\Documents\\5000ints.txt";
	fopen_s(&fptr, myfilePath, "r+");
	if (NULL == fptr) {
		fprintf(stderr, "Error opening file\n");
		return;
	}
	else {
		printf("Everything works fine.\n");
		for (int i = 0; fscanf_s(fptr, "%d", &arrA[i]) == 1 && i < 5000; i++) {
			fprintf(fptr, "Line %d of text.\n", (i + 1));
		}
	}
	fclose(fptr);
	
	void countSort(arrA, n);
	//void merge(arrA, n));
	//void mergeSort(arrA, n));
	//void quickSort(arrA, n));
	//int partition(arrA, n));

	printf("\n 5000 sorted ints: ");
	for (int i = 0; i < n; i++)
		printf("\n %d", arrA[i]);
}



void countSort(int[], int, int)	
{
	int i, value, count;
	int* freq, * arrB;
	int freqSize;
	int swaps = 0;
	int comparisons = 0;
	int recur = 0;

	freqSize = maxVal + 1;

	freq = (int*)malloc(freqSize * sizeof(int));   //create freq[]
	arrB = (int*)malloc(size * sizeof(int));       //create arrB[] same size as arrA[]

	// initialise freq[]
	for (i = 0; i < freqSize; i++) {
		freq[i] = 0;
	}

	// count
	for (i = 0; i < size; i++) {
		++freq[arrA[i]];
	}

	// get <= in freq[]
	for (i = 1; i < freqSize; i++) {
		freq[i] = freq[i] + freq[i - 1];
	}

	// place values from arrA into arrB; update freq[]
	for (i = 0; i < size; i++) {
		value = arrA[i];			//value to sort
		count = freq[value];		//<= freq of value
		arrB[count - 1] = value; //place value in arrB
		--freq[value];				//decrement freq[]
	} //next value in arrA

	//write back sorted values to arrA[] now that sorting finished
	for (i = 0; i < size; i++) {
		arrA[i] = arrB[i];
	}
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
	printf("\n\nCount Sort:\nTime taken to sort is %f seconds\nNumber of Swaps: %d\n Number of comparisons: %d\nRecursive calls: %d", time_taken, swaps, comparisons, recur);
}


/*
void quickSort(int arrA[], int startval, int endval) 
{

	if ((endval - startval) < 1) {
		return;
	}
	else {
		int k = partition2(arrA, startval, endval);
		//now sort the two sub-arrays
		quickSort(arrA, startval, k - 1);  //left partition
		quickSort(arrA, k + 1, endval);   //right partition
	}
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
	printf("\nQuick Sort:\nTime taken to sort: %f seconds\nNumber of Swaps: %d\n Number of comparisons: %d\nRecursive calls: %d", time_taken, swaps, comparisons, recur);
	
}
*/

/*void mergeSort(int arrA[], int lb, int ub) 
{

	int mid;

	if (lb < ub) {
		mid = ((lb + ub) / 2);
		mergeSort(arrA, lb, mid);
		mergeSort(arrA, mid + 1, ub);
		merge(arrA, lb, mid, ub);
	}
}

void merge(int arrA[], int lb, int mid, int ub) 
{

	int i, j, k;
	int size = ub - lb + 1;
	int* arrC;
	arrC = (int*)malloc(size * sizeof(int));
	int swaps = 0;
	int comparisons = 0;
	int comparisons = 0;

	i = lb;
	j = mid + 1;
	k = 0;

	while (i <= mid && j <= ub) {
		if (arrA[i] <= arrA[j]) {
			arrC[k] = arrA[i];
			i++;
		}
		else {
			arrC[k] = arrA[j];
			j++;
		}
		k++;
	} //end while

	// write out anything left in i part
	while (i <= mid) {
		arrC[k] = arrA[i];
		i++;
		k++;
	}
	// write out anything left in j part
	while (j <= ub) {
		arrC[k] = arrA[j];
		j++;
		k++;
	}

	//write back from arrC to arrA so correct values are in place for next merge
	i = lb;
	k = 0;
	while (i <= ub) {
		arrA[i] = arrC[k];
		i++;
		k++;
	}
	clock_t start = clock();
	clock_t end = clock();
	double timeTaken = ((double)(end)-(double)(start)) / CLOCKS_PER_SEC;
	printf("\nMerge Sort:\nTime taken to sort: %f seconds\nNumber of Swaps: %d\n Number of comparisons: %d\nRecursive calls: %d", timeTaken, swaps, comparisons, recur);
}
void swap(int* a, int* b) 
{

	int temp = *a;
	*a = *b;
	*b = temp;
}


int partition(int arrA[], int startval, int endval)
{
	int i = startval + 1;
	int k = endval;
	int pivot = arrA[startval];
	int swaps = 0;
	int comparisons = 0;
	int recur = 0;

	while (k >= i) {
		while (arrA[i] <= pivot && i <= k) {
			i++;
		}
		while (arrA[k] > pivot && k >= i) {
			k--;
		}
		if (k > i) { //swap values at k and i
			swap(&arrA[i], &arrA[k]);
			
		}
	}
	//out of this loop when k >= i not true
	swap(&arrA[startval], &arrA[k]);
	return(k);
} 

void quickSort(int arrA[], int startval, int endval) 
{

int numSwaps = 0;
	int numCmprs = 0;
	if ((endval - startval) < 1) {
		return;
	}
	else {
		int k = partition2(arrA, startval, endval);
		//now sort the two sub-arrays
		quickSort(arrA, startval, k - 1);  //left partition
		quickSort(arrA, k + 1, endval);   //right partition
	}
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
	printf("\nQuick Sort:\nTime taken to sort: %f seconds\nNumber of Swaps: %d\n Number of comparisons: %d\nRecursive calls: %d", time_taken, swaps, comparisons, recur);
}	*/

