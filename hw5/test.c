#include <stdio.h>
#include "dbitmasks.h"
int main(){
	uint32_t a = 7;
	set_bit(&a, 3);
	printf("%d\n", a);
	clear_bit(&a, 3);
	printf("%d\n", a);
	flip_bit(&a, 3);
	printf("%d\n", a);
	printf("%d\n", check_bit(a, 3));
}
