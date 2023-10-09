/*gavin skehan
21440824
18/01/2022*/

#include <stdio.h> // librays
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define rows 10 // delare grid size
#define columns 10

int shipX, shipY; // delcaring variables and functions
int targetShipX, targetShipY;
void randomSearch(int grid);
int grid = 10;
int numLocations = 0;
void gridSearch(int grid, int numLocations);
int n = 1;
int iD = 4; // new grid size


void main() {
	
	srand(time(NULL)); // random function
	int gridSize[rows][columns];
	shipX = rand() % 10; // ensures boundaries for the grid
	shipY = rand() % 10; // modulus 
	printf("---------Random Search--------- \n");
	
	randomSearch(grid); // random search function
	printf("Ship co-ordinates - x : %d, y : %d \n", shipX, shipY); // shows the co-ordinates of the ship
	
	printf("-----Grid Search------ \n");
	
	gridSearch(grid, 0); // function using recursion
	printf("Ship co-ordinates - x : %d, y : %d \n", shipX, shipY);

	printf("======New grid========= \n"); // student id grid
	printf("---------Random Search--------- \n");
	shipX = rand() % iD;
	shipY = rand() % iD;
	randomSearch(4); // change grid size
	printf("Ship co-ordinates - x : %d, y : %d \n", shipX, shipY);
	
	printf("-----Grid Search------ \n");
	gridSearch(4, 0);
	printf("Ship co-ordinates - x : %d, y : %d \n", shipX, shipY);

	return 0; 
}


void randomSearch(int grid) { // function
	
	while (shipX != targetShipX || shipY != targetShipY) { // increment searches when co-ordinates are wrong
		targetShipX = rand() % 10;
		targetShipY = rand() % 10;
		numLocations++; // increment
	}
			if (shipX == targetShipX && shipY == targetShipY) {
				printf("Ship found after %d locations! \n", numLocations); // print number of attempts when found
			}

}

void gridSearch(int grid, int numLocations) { // recursion method
	
		int targetX = numLocations % grid; // grid = 10
		int targetY = numLocations / grid;
		if (targetX == shipX && targetY == shipY) {
			printf("Ship found after % d locations!\n", numLocations);
		}
		else {
			gridSearch(grid, numLocations + 1); // function delares itself
		}
	
}
