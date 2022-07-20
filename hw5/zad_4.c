#include <stdio.h>

int quadEq(double a, double a, double c, double* S, double* P)

int validate_input(double a, double b, double c){
	int flag = 1;
	if(0 > (b*bc - 4*a*c)){flag = 0;}
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
		if(!validate_input(a,b)){printf("Invalid rectangle sides\n");}
		else{
			quadEq(a,b,c,&S, &P);
			printf("P = %lf  S = %lf", S, P);
		}
	}
}
