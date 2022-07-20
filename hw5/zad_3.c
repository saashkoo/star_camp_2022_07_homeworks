#include <stdio.h>

int rectangle(double a, double b, double* S, double *P);

int validate_input(double a, double b){
	int flag = 1;
	if(0 >= a || 0 >= b){flag = 0;}
	return flag;
}

int main(){
	double a,b;
	double S, P;
	//reading
	while(1){
		res = scanf("%lf", &a);
		if (res == -1){break;}
		res = scanf("%lf", &b);
		if (res == -1){break;}
		if(!validate_input(a,b)){printf("Invalid triangle sides\n");}
		else{
			rectangle(a,b,&S, &P);
			printf("P = %lf  S = %lf", S, P);
		}
	}
}
