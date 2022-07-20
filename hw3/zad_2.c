// needs to be compiled with  -lm

#include <stdio.h>
#include <math.h>

long double mymethod_ld(long double a, double b){
	long double diff = (long double)b;
	while(1){
		if(fabs(a-b) < diff){diff = diff/10;}
		else{
		diff = diff * 10;
		break;
		}
	}
	return diff;
}

long double mymethod_df( double a, float b){
	long double diff = (long double)b;
	while(1){
		if(fabs(a-b) < diff){diff = diff/10;}
		else{
		diff = diff * 10;
		break;
		}
	}
	return diff;
}

long double mymethod_fl(float a, long double b){
	long double diff = (long double)a;
	while(1){
		if(fabs(a-b) < diff){diff = diff/10;}
		else{
		diff = diff * 10;
		break;
		}
	}
	return diff;
}

int main(){
	float a = 444444444.67f;
	double as = 444444444.67;
	long double asd = 444444444.67L;
	printf("%.19f  - float\n", a);
	printf("%.35lf  - double\n", as);
	printf("%.35Lf  - long double\n", asd);
	printf("difference between long double and double is less than %.35Lf\n", mymethod_ld(asd, as));
	printf("difference between double and float is less than %.35Lf\n", mymethod_df(as, a));
	printf("difference between float and long double is less than %.35Lf\n", mymethod_fl(a, asd));

}
