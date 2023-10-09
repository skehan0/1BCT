/*gavin skehan
2140824
25/01/22*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int month, day, year; // declare variables
	char region[50], name[50], item[50];
	int units;
	float unitCost, total;
} supplies;

void readSupplies(FILE* fptr); // function

void main() {
	FILE* fptr;
	fopen_s(&fptr, "C:\\Users\\skeha\\OneDrive\\Documents\\programming\\SampleData.txt", "r"); // file 

	if (fptr == NULL) {
		puts("Error Openeing File \n Exiting......."); // if the file isnt read 
		return;
	}
	else {
		printf("Everything works fine. \n");
		char c = fgetc(fptr);
		while (c != EOF) {
			printf("%c", c);
			c = fgetc(fptr);
		}

	}
	fclose(fptr); // closes file
	fopen_s(&fptr, "‪C:\\User\\SampleData.txt", "r"); // re open file
	
	readSupplies(fptr);
	}


	void readSupplies(FILE * fptr) // function
	{
		supplies c;
		float totalSum = 0;
		int i = 0;
		while (!feof(fptr)) {
			fscanf_s(fptr, "%d%*[-/]%d%*[-/]%d", &c.month, &c.day, &c.year);
			fscanf_s(fptr, "%s\t", c.region, 50);
			fscanf_s(fptr, "%s\t", c.name, 50);
			fscanf_s(fptr, "%s\t", c.item, 50);
			fscanf_s(fptr, "%d\t", &c.units);
			fscanf_s(fptr, "%f\t", &c.unitCost);
			fscanf_s(fptr, "%f\t", &c.total);
			fprintf(fptr, "%d/%d/%d %s\t%s\t%s\t%d\t%.2f\t%.2f\n", c.month, c.day, c.year, c.region, c.name, c.item, c.units, c.unitCost, c.total);

			printf("Month is: %d\t", c.month);
			printf("Day is: %d\t", c.day);
			printf("Year is: %d\t", c.year);
			printf("Region is: %s\t", c.region);
			printf("Name is: %s\t", c.name);
			printf("Item name is: %s\t", c.item);
			printf("Number of units is: %d\t", c.units);
			printf("Unit cost is: %f\t", c.unitCost);
			printf("Total cost is: %f\n", c.total);
			float totalSum = c.total; // calculation formula
			i++;

			float average = c.total / i; // average
		}
		float average = totalSum / i;
		supplies c = {1,25,22,"Galway","Skehan","Pen", 24, 19.99, 479.76}; // part 3
		printf("Total income from all of the orders: %f\n", totalSum);
		printf("Average order value: %f\n", average);
		fclose(fptr);
		
	}

