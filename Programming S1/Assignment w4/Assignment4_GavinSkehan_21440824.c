/*
Gavin Skehan
21440824
ASSIGNMENT 4
*/

#include <stdio.h>
void main() 
{

	int age = 1;
	int numChildren = 0;
	int sum = 0;
	float averageAge = 0.0;
	int max= 0;
	int min = 18;

	while (age > 0) 
	{
		printf("Please input age of child:");
		scanf_s("%d", &age);
		
			if (age > 0 && age < 18) 
		{
			numChildren++;
			sum = sum + age; // formulate sum of the ages
			if (age > max) {
				(max = age); // finding the maximum age of all the children
			}
			if (age < min) {
				(min = age); // minimum age of all the children
			}
		}

		if (age >= 18) {
			printf("This is not a child\n"); // 18 doesnt count as a child

		}
	}
	printf("Number of chldren %d\n", numChildren); 

	averageAge = sum / numChildren; // average age of the ages
	printf("The average age is: %0.1f\n", averageAge);
	

	printf("The max is: %d\n", max); // prints the max and min of the children
	printf("The min is: %d\n", min);

}