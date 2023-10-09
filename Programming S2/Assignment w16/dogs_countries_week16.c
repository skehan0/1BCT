/*gavin skehan
21440824
01/02/22*/
#include <stdio.h> // libraries
#include <stdlib.h>
#include <string.h>

void main() {
	FILE* fptr; // create file pointer

	fopen_s(&fptr, "C:\\Users\\skeha\\OneDrive\\Documents\\dogs.txt", "r+"); // open the file

	if (fptr != NULL) {
		fseek(fptr, -4, SEEK_END);
		int len = ftell(fptr);
		printf("Size of dogs.txt: %d bytes. \n", len); // prints the byte size of the file
		fclose(fptr); // close the file
	}

	fopen_s(&fptr, "C:\\Users\\skeha\\OneDrive\\Documents\\dogs.txt", "r+"); // read and append
	if (fptr != NULL) {
		fseek(fptr, -4, SEEK_END); // replaces bottom line with boxer
		fputs("Boxer", fptr);
		fclose(fptr);
	}
	char line[1000]; // array size
	char countries[1000];
	int population;
	fopen_s(&fptr, "C:\\Users\\skeha\\OneDrive\\Documents\\countries.txt", "r"); // read to file
	if (fptr != NULL) {
		int j = 0;
		while (!feof(fptr)) {
			char c = fgetc(fptr);
			while (c != '\t') {
				countries[j] = c;
				j++; // increment
				c = fgetc(fptr);
			}
			countries[j] = '\0';
			fscanf_s(fptr, "%d\n", &population); // scan in population
			printf("Country: %s\nPopulation: %d\n", countries, population); // print to screen
			j = 0;
		}
		fclose(fptr); // close file
	}
	fopen_s(&fptr, "C:\\Users\\skeha\\OneDrive\\Documents\\countries.txt", "a"); // append the file
	if (fptr != NULL) {
		fseek(fptr, 7, SEEK_END); // end of file
		fputs("Ghana \t  31000000", fptr); // new country
		fclose(fptr); // close file
	}
}
