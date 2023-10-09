#include <stdio.h>
void main() {
    float averageSales = 0.0;
    float day1;
    float day2;
    float day3;
    float day4;
    int dailyCustomers = 500; // average amount of customers
    float averageSpend = 0.0;

    printf("Enter total daily sales for day1");
    scanf_s("%f", &day1);

    printf("Enter total daily sales for day2");
    scanf_s("%f", &day2);

    printf("Enter total daily sales for day3");
    scanf_s("%f", &day3);

    printf("Enter total daily sales for day4");
    scanf_s("%f", &day4);

    averageSales = (day1 + day2 + day3 + day4) / 4; // formula for average sales

    printf("The averageSales is %0.2f \n", averageSales);

    if (averageSales < 10000) {
        printf("Sales are low\n"); // sales are less than 10000
    }
    else if (averageSales < 15000) {
        printf("Sales are normal\n"); // sales are less than 15000 but more than or equal to 10000
    }
    else {
        printf("Sales are high\n"); // sales are 15000 or greater
    }
    averageSpend = averageSales / dailyCustomers; // formula for average spend per customer over the 4 days
      printf("Average spend per customer is %0.2f \n", averageSpend);
}

Screenshots:

 
 
 



