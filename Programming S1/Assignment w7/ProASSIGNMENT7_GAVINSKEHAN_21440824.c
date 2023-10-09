/*Gavin skehan
21440824
9/11/21*/
#include <stdio.h>
#include "string.h"
void main()
{
	// initialize variables
	char choice[50] = "a";	
	float height; // dimensions of the shapes must be initialised
	float width;
	float baseWidth;
	float radius;
	const float PI = 3.14; // PI is a constant
	float area1;
	float area2;
	float area3;
	float area4;
	int done = 0;

	while (done != 1) // use a while loop to allow multiple choices 
	{
	
	puts("Are Calculator - Shape Choices are: "); // these texts must be inputed after each choice is finished
	puts("______________________________________________________ ");
	puts("Triangle, Rectangle, Circle, Trapezium. 'Done' to end ");
	puts("______________________________________________________ ");
		puts("Choice: "); // used instead of printf. also prints on a new line
		gets(choice); // used instead of scanf_s for strings
 
			if(strcmp(choice, "triangle") == 0) { //strcmp compares the strings
				printf("Enter the height: "); 
				scanf_s("%f", &height); // scans the users input for heigth and uses it for the area
				printf("Enter the base width: ");
				scanf_s("%f", &baseWidth);
				area1 = (baseWidth / 2) * height; // we define the area to create the formuala
				printf("Area of the triangle = %0.2f \n", area1);
			}
			else if(strcmp(choice, "rectangle") == 0) { // if the user types rectangle the process for its area is executed
				printf("Enter the height: ");
				scanf_s("%f", &height);
				printf("Enter the width: ");
				scanf_s("%f", &width);
				area2 = height * width;
				printf("Area of the rectangle = %0.2f \n", area2);
			}
			else if (strcmp(choice, "circle") == 0) {
				printf("Enter the radius: ");
				scanf_s("%f", &radius);
				area3 = PI * radius * radius;
				printf("Area of the Cirlce = %0.2f \n", area3);
			}
			else if (strcmp(choice, "trapezium") == 0) {
				printf("Enter the height: ");
				scanf_s("%f", &height);
				printf("Enter the width: ");
				scanf_s("%f", &width);
				printf("Enter the base width: ");
				scanf_s("%f", &baseWidth);
				area4 = ((width + baseWidth) / 2) * height;
				printf("Area of the Trapezium = %0.2f \n", area4);
			}
			else if(strcmp(choice, "done") == 0) {
				done++; // increment done to make it 1 therefore stops the program

			}
			
	
	}


}