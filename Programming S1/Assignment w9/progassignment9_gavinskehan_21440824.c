/*gavin skehan
21440824
23/11/21*/
#include <stdio.h>
#include <math.h>

float timeFunc(); // defining all the functions
float roundTime(float time);
float rtime;
float hour, time, returnTime;
float returnRate(float time);
void timeRate(float time, float rate);

const float dayRate = 23.9; // constants
const float nightRate = 12.6;

void main()
{
	time = timeFunc();
	rtime = roundTime(time); // round time up

	
	timeRate(rtime, returnRate(rtime)); // ensures rate is charged on the rounded
}
float timeFunc()
{
	float hours, mins; // initialise 
	
	printf("Please enter the current hour: "); // allows user to print hours and minutes to the screen
	scanf_s("%f", &hours);

	printf("Please enter the current minute: ");
	scanf_s("%f", &mins);
	
	if (hours > 23) { // hours must be less than 24 
		hours = 23;
	}
	if (mins > 59) { // 60 minutes in an hour
		mins = 59;
	}
	float time = hours + (mins / 60); // converts minutes into appropriate form
	printf("Time = %0.2f\n", time);
	return time;
}
float roundTime(float time)
{
	rtime = ceil(time); // round up function in math.h
	printf("Time %0.2f \n ", rtime);
	return time;
}
float returnRate(float time)
{
	float elecPrice = time < 8 ? nightRate : dayRate; // determine day/night rate
	return elecPrice;
}
void timeRate(float time, float rate)
{
		printf("Electricity price at %0.2f is %.2f c/kWh \n", time, rate); // prints electricity to the screen
}

