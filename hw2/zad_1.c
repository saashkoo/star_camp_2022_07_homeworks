/* execute with     gcc zad_1.c && ./a.out<numbers.txt     */

#include <stdio.h>

int main(){
	printf("please type the first number\n");
	float a, b, c;
	scanf("%f", &a);
	printf("please type the second number\n");
	scanf("%f", &b);
	printf("please type the third number\n");
	scanf("%f", &c);
	if(a>b){
		if(a>c){printf("%f\n", a);}
		else{printf("%f\n", c);}
	}
	else{
		if(b>c){printf("%f\n", b);}
		else{printf("%f\n", c);}
	}
	return 0;
}
