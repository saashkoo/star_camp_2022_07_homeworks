#include <stdio.h>
#include <math.h>

int main(){
	float mass, height;
	printf("height : ");
	scanf("%f", &height);
	printf("mass : ");
	scanf("%f", &mass);
	printf("BMI = %f\n", mass/(pow(height,2)));
	printf("BMInew = %f\n", 1.3*(mass/(pow(height, 2.5))));
	
	
	
	return 0;
}
