#include <stdio.h>
void main()
{
	float sales[1000];
	float totalAverageSales = 0.0;
	float totalSales = 0.0;
	int extraDays;
	int counter = 0;
	int i = 0;

	
		for (i; i < 7; i++) { // for loop to allows input of daily sales
			printf("Enter daily sales in euro for day %d: ", i + 1); 
			scanf_s("%f", &sales[i]);
			counter++; // increment
	
			totalSales = totalSales + sales[i]; // using [] creates an array
		}
		
			printf("Total sales are:%0.2f\n", totalSales); // prints the total sales from the week to two decimal places
			totalAverageSales = totalSales / 7; // formula for average sales
			printf("Average sales are: %0.2f\n", totalAverageSales); // average sales formula,prints to two decimal places

			printf("How many additional days of sales would you like to record:");
			scanf_s("%d", &extraDays); // allows user to input optional extra days
		
		while (counter < 7 + extraDays) {
			
			printf("Enter daily sales in euro for day %d:", counter + 1); // prints out the day number for daily sales
			scanf_s("%f", &sales[counter]); 
			totalSales = totalSales + sales[counter];
			counter++; // increment
			} 
		
			printf("New total sales: %0.2f\n", totalSales); // updates total sales and average sales to incorperate additional days
			totalAverageSales = totalSales / (7 + extraDays); // updated average sales formula
			printf("New average sales: %0.2f\n", totalAverageSales); // indicates new outputs
	
		for (i; i < counter; i++) { // storing daily sales values
			printf("Total daily sales for day %d = %0.2f\n", i + 1, sales[i]);
			scanf_s("%f", &sales[i]);
			counter++;

			}
}
