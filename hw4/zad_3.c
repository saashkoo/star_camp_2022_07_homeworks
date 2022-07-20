#include <stdio.h>
#include <math.h>
#include <string.h>
#define max_figures 10

int convert_letter(char a){
	return a - 'a' + 10;
}

int convert_number(char a){
	return a - '0';
}
char letter_convert(int a){
	return a + 'a' - 10;
}

char number_convert(int a){
	return a + '0';
}

void func(char*number, char*converted,int from,int to){
	long long unsigned int dec = 0;
	for(int i = 0; i < 10; i++){
		if (number[i] >= 'a' ){
			dec = dec + convert_letter(number[i])*pow(from, max_figures - i - 1);
		}
		else{
			dec = dec + convert_number(number[i])*pow(from, max_figures - i - 1);
		}
	}
	printf("in decimal%llu\n", dec);
	int digit = 99;
	while(dec){
		if(dec%to > 9){converted[digit] = letter_convert(dec%to);}
		else{converted[digit] = number_convert(dec%to);}
		digit --;
		dec = dec/to;
	}
	
}

int main(){
	char number[11] = {'0', '0' ,'0', '0', '0', '0', '0', '0', '0', '0', '\0'};
	char converted[100] = {'0', '0' ,'0', '0', '0', '0', '0' ,'0', '0', '0', '0', '0' ,'0', '0', '0', '0', '0' ,'0', '0', '0', '0', '0' ,'0', '0', '0','0', '0' ,'0', '0', '0', '0', '0' ,'0', '0', '0', '0', '0' ,'0', '0', '0', '0', '0' ,'0', '0', '0', '0', '0' ,'0', '0', '0', '0', '0' ,'0', '0', '0', '0', '0' ,'0', '0', '0', '0', '0' ,'0', '0', '0', '0', '0' ,'0', '0', '0', '0', '0' ,'0', '0', '0', '0', '0' ,'0', '0', '0', '0', '0' ,'0', '0', '0', '0', '0' ,'0', '0', '0', '0', '0' ,'0', '0', '0', '0', '0' ,'0', '0', '0'};
	int from, to, flag;
	char a;
	printf("please select a number with up to 10 figures, bit by bit\n");
	for(int i = 0; i < 10; i++){
		scanf("%s", &a);
		number[i] = a;
	}
	printf("please select the system you are converting from\n");
	scanf("%d", &from);
	while(from < 2 || from > 36){
		printf("%d is invalid system, please try again\n", from);
		scanf("%d\n", &from);
	}
	printf("please select the system you are converting to\n");
	scanf("%d", &to);
	while(to < 2 || to > 36){
		printf("%d is invalid system, please try again\n", to);
		scanf("%d\n", &to);
	}
	flag = 0;
	for(int i =0; i < 10; i++){
		if(number[i] >= 'a'){
			if (convert_letter(number[i]) >= from){flag = 1;break;}
		}
		else{
			if(convert_number(number[i]) >= from){flag = 1;break;}
		}
	}
	printf("  entire numbers\n");
	if(1 == flag){printf("invalid input, please try again\n");}
	else{
		func(number, converted, from, to);
		for(int i = 0; i < 100; i++){
			printf("%c", converted[i]);
		}
		printf("\n");
	}

	return 0;
}
