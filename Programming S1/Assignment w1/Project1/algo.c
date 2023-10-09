#include <string.h> 
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

int arrA[8] = { 12,26,37,41,52,67,77,88 };
int size = 8;
int lb = 0;
int ub = 7;
int count;
int comparisons = 0;
int swaps = 0;

void mergeSort(int arrA[], int lb, int ub);
void merge(int arrA[], int lb, int mid, int ub);


void main() {
	void mergeSort();
	void merge(swaps, comparisons);
	printf("Number of swaps: %d\nNumber of comparisons: %d", swaps, comparisons);
}

void mergeSort(int arrA[], int lb, int ub)
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
	int* arrC;
	int size = ub - lb + 1;
	arrC = (int*)malloc(size * sizeof(int));
	for (i = lb, j = mid + 1, k = 0; i <= mid && j <= ub; k++) {
		if (arrA[i] <= arrA[j])
			arrC[k] = arrA[i++];
		else
			arrC[k] = arrA[j++];
	}
	while (i <= mid)
		arrC[k++] = arrA[i++];
	while (j <= ub)
		arrC[k++] = arrA[j++];
	for (i = lb, k = 0; i <= ub; i++, k++)
		arrA[i] = arrC[k];
}