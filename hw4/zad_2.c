#include <stdio.h>
#include <stdint.h>


void set_n_bit(uint32_t * m, unsigned int size, unsigned int bit){
	if(size*32 < bit){
	return;
	}
	else{
		int  index  = bit / 32;
		bit = bit %32;
		m[index]|=(1UL<<bit);
		return;
	}
}

void clear_n_bit(uint32_t * m, unsigned int size, unsigned int bit){
	if(size*32 < bit){
	return;
	}
	else{
		int i = bit/32;
		bit = bit %32;
		m[i]&= ~(1UL<<bit);
		return;
	}
}

void printarr(uint32_t *m, unsigned int size){
	for(int i =size-1; i >-1; i--){
		for(int j = 31; j > -1; j--){
			printf("%d", !!(m[i] &(1<<j)));
		}
	}
	printf("\n");
	return;
}

void flip_n_bit(uint32_t * m, unsigned int size, unsigned int bit){
	if(size*32 < bit){
	return;
	}
	else{
		int i = bit/32;
		bit = bit %32;
		m[i]^= (1UL<<bit);
		return;
	}
}

int check_n_bit(uint32_t * m, unsigned int size, unsigned int bit){
	if(size*32 < bit){
	return -1;
	}
	else{
		int i= bit/32;
		bit = bit%32;
		return !(!(m[i]&(1<<bit)));	
	}	
}

int main(){
	uint32_t mask[10] = {0,0,0,0,0,0,0,0,0,0};
	int option;
    int num;
    while (1)
    {
        printf("1. Set attendance\n");
        printf("2. Clear attendance\n");
        printf("3. Attendance info\n");
        printf("4. Change attendance\n");
        printf("5. Exit\n");
        printf("6. Check attendance of number\n");
        scanf("%d", &option);
        if (1 == option)
        {	
        	printf("which num do you want to set\n");
        	scanf("%d", &num);
        	while( num < 1 || num > 320){
        		printf("invalid number, pls try again\n");
        		scanf("%d", &num);
        	}
			set_n_bit(mask, 10, num-1);
        }
        else if (2 == option)
        {
            printf("which num do you want to clear\n");
        	scanf("%d", &num);
        	while( num < 1 || num > 320){
        		printf("invalid number, pls try again\n");
        		scanf("%d", &num);
        	}
			clear_n_bit(mask, 10, num-1);
        }
        else if (3 == option)
        {
           printarr(mask, 10);
        }
        else if (4 == option)
        {
        	printf("which num do you want to reverse\n");
        	scanf("%d", &num);
        	while( num < 1 || num > 320){
        		printf("invalid number, pls try again\n");
        		scanf("%d", &num);
        	}
			flip_n_bit(mask, 10, num-1);
        }
        else if (5 == option)
        {	
        	return 0;
        }
        else if (6 == option)
        {
        	printf("which num do you want to check\n");
        	scanf("%d", &num);
        	while( num < 1 || num > 320){
        		printf("invalid number, pls try again\n");
        		scanf("%d", &num);
        	}
			printf("%d\n",check_n_bit(mask, 10, num-1));
        }
        else
        {
        	printf("invalid option, pls try again\n");
        }
    }
	return 0;
}
