#include <stdio.h>

double sum(double a, double b){
	return a+b;
}

double minus(double a, double b){
	return a-b;
}

double umn(double a, double b){
	return a*b;
}

double del(double a, double b){
	return a/b;
}



int main(){
	double a, b;
	char c;
	int res;
	while(1){
		res = scanf("%lf", &a);
		if (res == -1){break;}
		//printf("%lf\n", a);
		res = scanf("%s", &c);
		//printf("%d\n", c);
		if(res == -1){break;}
		while(c != '+' && c != '-' && c != '*' && c != '/'){
			printf("invalid input");
			res = scanf("%s", &c);
			//printf("%d\n", c);
			if(res == -1){break;}
		}
		res = scanf("%lf", &b);
		printf("%lf\n", b);
		if (res == -1){break;}
		if(c == '+'){printf("%lf\n", sum(a, b)); continue;}
		if(c == '-'){printf("%lf\n", minus(a, b)); continue;}
		if(c == '*'){printf("%lf\n", umn(a, b)); continue;}
		if(c == '/'){printf("%lf\n", del(a, b));}
		
		//printf("%d\n", res);
		//reading
	}
	return 0;
}
