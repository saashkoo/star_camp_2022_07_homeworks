#include <stdio.h>
#include <stdint.h>

unsigned onesCount(uint64_t mask){
	unsigned num = 0;
	for(int i  = 0; i < 64; i++){
		if(!!(mask & (1ULL<<i))){num+=1;}
	}
	return num;
}

int main(){
	printf("%d\n", onesCount(7));
	return 0;
}
