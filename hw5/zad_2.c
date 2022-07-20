#include <stdio.h>

int triangle(double a, double b, double c, double* S, double *P);

int validate_input(double a, double b, double c){
	int flag = 1;
	if(a >= b+c){flag = 0;}
	if(b >= a+c){flag = 0;}
	if(c >= b+a){flag = 0;}
	if(0 >= a || 0 >= b || 0 >= c){flag = 0;}
	return flag;
}

int main(){
	double a,b,c;
	double S, P;
	//reading
	while(1){
		res = scanf("%lf", &a);
		if (res == -1){break;}
		res = scanf("%lf", &b);
		if (res == -1){break;}
		res = scanf("%lf", &c);
		if (res == -1){break;}
		if(!validate_input(a,b,c)){printf("Invalid triangle sides\n");}
		else{
			triangle(a,b,c,&S, &P);
			printf("P = %lf  S = %lf", S, P);
		}
	}
	return 0;	
}
