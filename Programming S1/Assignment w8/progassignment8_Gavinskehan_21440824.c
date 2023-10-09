/*gavin skehan
21440824
16/11/21 */
#include <stdio.h>
#include <string.h>

	float volume(int length, int width, int height) // declaring functions that can be reused
 {
	 return(0.0f);
 }
 float mass(volume); // mass is calculated using volume
 float numBarrels(volume); // number of barrels calculated using volume
 
 void main()
{
	float numBarrel; // initialise varibales
	float mass;
	float volume;
	int length = 8; // last 3 digits of student ID
	int width = 2;
	int height = 4;
	volume = length * width * height; // formula for volume
	printf("Volume: %0.2f\n", volume);
	mass = volume * 1000; // formula for mass
	printf("Mass of the water:  %0.2f \n", mass);
	numBarrel = volume / 0.48; // formula for calculates number of barrels
	printf("Numer of barrels %0.0f \n", numBarrel); // rounds down to amount of full barrels
}










