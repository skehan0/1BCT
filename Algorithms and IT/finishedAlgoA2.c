#include <string.h> 
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <math.h>

//void countSort(int arrA[], int size, int maxVal);
void merge(int arrA[], int lb, int mid, int ub);
void mergeSort(int arrA[], int lb, int ub);
//void quickSort(int[], int startval, int endval);
//int partition(int[], int startval, int endval);
//void swap(int* a, int* b);
int swaps = 0;
int comparisons = 0;
int recur = 0;

void main() {
	int arrA[5000];
	int n = 5000;
	FILE* fptr; 
	fopen_s(&fptr, "C:\\Users\\skeha\\OneDrive\\Documents\\5000ints.txt", "r");
	if (fptr == NULL) {
		printf("Error reading file. \nExiting..........");
		return;
	}
		while (!feof(fptr)) {
			printf("Everything works fine\n");
		for (int i = 0; i < 5000; i++) {
			fscanf_s(fptr, "%dzn", &arrA[i]);
		}
	}
	fclose(fptr);

	//countSort(arrA, 5000, 5000);
	mergeSort(arrA, 0, 4999);
	//quickSort(arrA, 0, 4999);

}

/*
void countSort(int arrA[], int size, int maxVal)
{
	clock_t t;
	t = clock();
	double timeTaken;

	int i, value, count;
	int* freq, * arrB;
	int freqSize;

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
		--freq[value];	//decrement freq[]
	} //next value in arrA

	//write back sorted values to arrA[] now that sorting finished
	for (i = 0; i < size; i++) {
		arrA[i] = arrB[i];
	}
	t = clock() - t;
	timeTaken = ((double)t) / CLOCKS_PER_SEC;
	printf("\nCount sort:\nTime taken: %f seconds\n", timeTaken);
	printf("Recursive calls: %d\n", recur);
	printf("swpas: %d\n", swaps);
	printf("Comparisons: %d", comparisons);
}	*/

void mergeSort(int arrA[], int lb, int ub)
{
	clock_t t;
	t = clock();
	double timeTaken;
	int mid;

	if (lb < ub) {
		mid = ((lb + ub) / 2);
		mergeSort(arrA, lb, mid);
		recur++;
		mergeSort(arrA, mid + 1, ub);
		recur++;
		merge(arrA, lb, mid, ub);
		recur++;
	}
	t = clock() - t;
	timeTaken = ((double)t) / CLOCKS_PER_SEC;
	printf("\nMerge sort:\nTime taken: %f seconds\n", timeTaken);
	printf("Recursive calls: %d\n", recur);
	printf("swpas: %d\n", swaps);
	printf("Comparisons: %d\n", comparisons);
}

void merge(int arrA[], int lb, int mid, int ub)
{

	int i, j, k;
	int size = ub - lb + 1;
	int* arrC;
	arrC = (int*)malloc(size * sizeof(int));

	i = lb;
	j = mid + 1;
	k = 0;

	while (i <= mid && j <= ub) {
		comparisons++;
		swaps++;
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
		comparisons++;
		swaps++;
		arrC[k] = arrA[i];
		i++;
		k++;
	}
	// write out anything left in j part
	while (j <= ub) {
		comparisons++;
		swaps++;
		arrC[k] = arrA[j];
		j++;
		k++;
	}


	//write back from arrC to arrA so correct values are in place for next merge
	i = lb;
	k = 0;
	while (i <= ub) {
		comparisons++;
			swaps++;
		arrA[i] = arrC[k];
		i++;
		k++;
	}
}
/*
void quickSort(int arrA[], int startval, int endval)
{
	clock_t t;
	t = clock();
	double timeTaken;

	if ((endval - startval) < 1) {
		return;
	}
	else {
		int k = partition(arrA, startval, endval);
		//now sort the two sub-arrays
		quickSort(arrA, startval, k - 1);  //left partition
		recur++;
		quickSort(arrA, k + 1, endval);   //right partition
		recur++;
	}
	t = clock() - t;
	timeTaken = ((double)t) / CLOCKS_PER_SEC;
	printf("\nQuick sort:\nTime taken: %f seconds\n", timeTaken);
	printf("Recursive calls: %d\n", recur);
	printf("swpas: %d\n", swaps);
	printf("Comparisons: %d\n", comparisons);
}

int partition(int arrA[], int startval, int endval)
{
	int k;
	int pivot = arrA[startval];
	int i = startval;

	for (k = startval + 1; k <= endval; k++) {
		comparisons++;// k keeps incrementing to the end
		if (arrA[k] <= pivot) {
			i++;   // i only increments when there is a new value to add to the <= portion
			if (i != k) {
				swaps++;
				swap(&arrA[i], &arrA[k]);
			}
		}
	}
	swap(&arrA[i], &arrA[startval]);
	swaps++;
	recur++;// put pivot in correct location i
	return(i);
}	
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}*/

