#include "bitmasks.h"

void set_bit(uint32_t*mask, int b){
	*mask |= (1UL<<b);
}
void clear_bit(uint32_t*mask, int b){
	*mask &= ~(1UL<<b);
}
void flip_bit(uint32_t*mask, int b){
	*mask ^= (1UL<<b);
}
int check_bit(uint32_t mask, int b){
	return !!(mask | (1UL<<b));
}


