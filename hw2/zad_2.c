/* execute with     gcc zad_2.c && ./a.out<numbers.txt     */

#include <stdio.h>

int main(){
	printf("please type the first number\n");
	int a,b;
	scanf("%d", &a);
	printf("please type the second number\n");
	scanf("%d", &b);
	if((b&&a)||(!b&&!a)){
		printf("0\n");
	}
	else{printf("1\n");}
	return 0;
}
