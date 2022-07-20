#include<stdio.h>
#include<math.h>
	
int main(){
	float r, h, l;
	printf("h : ");
	scanf("%f", &h);
	printf("r : ");
	scanf("%f", &r);
	printf("l : ");
	scanf("%f", &l);
	/*float res = acos((r-h)/r)*pow(r, 2) - (r-h)*sqrt((2*r*h) - (pow(h, 2)));
	printf("b) = %f\n", res*l);*/
	printf("b) = %f\n", (acos((r-h)/r)*pow(r, 2) - (r-h)*sqrt((2*r*h) - (pow(h, 2))))*l);
	return 0;
}
