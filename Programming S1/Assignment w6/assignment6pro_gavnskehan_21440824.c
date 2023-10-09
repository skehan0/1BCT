#include <stdio.h>
void main()
{
	int movieRating[21];
	float averageRating = 0.0;
	int ratingFrequency[5] = { 0,0,0,0,0 };
	int count = 0;
	float sum = 0;
	float ratingPercent[] = { 0,0,0,0,0 };

	for (int i = 0; i < 21; i++) // initialise i, for i<21 and increment 
	{
		printf("Enter rating for movie number %d on a scale of 1-5: ", i + 1); // 
		scanf_s("%d", &movieRating[i]); // input the rating for movie rating
		sum = sum + movieRating[i]; // 
		ratingFrequency[movieRating[i] - 1]++; // this ensures rating frequency incorporates 0th place
	}

	averageRating = sum / 21; // formula for average
	printf("The average rating is %0.1f \n", averageRating); // to 1 decimal place
	printf("Rating Frequency\n"); 
	printf("-----------------------\n");

	for (count = 0; count < 5; count++) // initialise, for loop, increment
	{
		printf("%d star: ", count + 1); // displays & adds 1 to count
		for (int j = 0; j < ratingFrequency[count]; j++) 
			printf("*");
		printf("\t %d\n", ratingFrequency[count]); 
	}

	printf("-------------------\n");
	printf("Rating percentage\n");
	printf("-------------------\n");
	

	for (count = 0; count < 5; count++) // for loop displaying stars and percentage rating
	{
		ratingPercent[count] = 100*((float)ratingFrequency[count] / 21); // formula for rating frequency
		printf("%d star: \t", count + 1); 

		for (int j = 0; j < ratingPercent[count]; j++)
		{
			printf("*"); 
		}
		printf("\t %0.1f% \n", ratingPercent[count]); // rating percentage to one decimal place
	}

}


