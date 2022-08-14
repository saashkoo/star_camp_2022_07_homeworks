#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

struct Pixel_Data {
	unsigned int r;
	unsigned int g;
	unsigned int b;
};


struct PPM_Image_Buffer {
	struct Pixel_Data * data;
	int rown;
	int coln;
}typedef  PPM_Image_Buffer;


int read_ppm_color_bitmap_bin(char* filename, PPM_Image_Buffer* buf);
int write_ppm_color_bitmap_bin(char *filename, PPM_Image_Buffer *buf);
void filter_color_component(PPM_Image_Buffer* buf, unsigned int rgb_mask);
void convert_to_grayscale(PPM_Image_Buffer* buf);


int str_contains(char* str, char a){//checks if a string contains a given character, returns 1(true) or 0(false) 
	for(int i = 0; str[i]!='\0'; i++){
		if(str[i]==a){return 1;}
	}
	return 0;
}

int read_ppm_color_bitmap(char* filename, PPM_Image_Buffer* buf){
	FILE* fd = fopen(filename, "rb");
	if(errno > 0){return -1;}
	if(fgetc(fd) == EOF){return -1;}
	if(fgetc(fd) == EOF){return -1;}
	if(fgetc(fd) == EOF){return -1;}//clears P3\n
	if(!fscanf(fd, "%d", &(buf->rown))){return -1;}//on error fscanf returns 0  and !0 == 1
	if(!fscanf(fd, "%d", &(buf->coln))){return -1;}
	int a;
	if(!fscanf(fd, "%d", &a)){return -1;}//used for 255
	a = buf->coln*buf->rown*sizeof(struct Pixel_Data);
	buf->data = malloc(a);
	if(fgetc(fd) == EOF){return -1;}//used for the /n after 255
	for(int i = 0; i < buf->coln*buf->rown;i++){
		fscanf(fd, "%d", &buf->data[i].r);
		if(EOF == buf->data[i].r){return -1;}
		fscanf(fd, "%d", &buf->data[i].g);
		if(EOF == buf->data[i].g){return -1;}
		fscanf(fd, "%d", &buf->data[i].b);
		if(EOF == buf->data[i].b){return -1;}//prevents segmentation fault
	}
	return 0;
}


int write_ppm_color_bitmap(char *filename, PPM_Image_Buffer *buf){
	FILE* fd = fopen(filename, "w+b");
	if(errno > 0){return -1;}
	fprintf(fd, "P3\n%d %d\n%d\n", buf->rown, buf->coln, 255);
	for(int i = 0; i < buf->coln*buf->rown;i++){
		if(1 > fprintf(fd, "%d ", buf->data[i].r)){return -1;}
		if(1 > fprintf(fd, "%d ", buf->data[i].g)){return -2;}
		if(1 > fprintf(fd, "%d ", buf->data[i].b)){return -3;}//fprintf returns the printed amount of chars, excluding the \0
	}
	return 0;
}

int main(int argc, char * argv[]){
	PPM_Image_Buffer a;
	if(!(argc == 4 || argc == 5|| argc == 6)){printf("incorrect argumens\n"); return 0;}
	if(argv[3][1] == 't'){printf("%d\n", read_ppm_color_bitmap_bin(argv[1], &a)); printf("%d\n", write_ppm_color_bitmap(argv[2], &a));}
	if(argv[3][1] == 'b'){printf("%d\n", read_ppm_color_bitmap(argv[1], &a)); printf("%d\n", write_ppm_color_bitmap_bin(argv[2], &a));}
	else{
		printf("%d\n", read_ppm_color_bitmap(argv[1], &a));
		if(argv[3][1] == 'g'){convert_to_grayscale(&a);}//will NOT work if there is only one input/output file
		if(argv[3][1] == 'f'){
			unsigned int b = 0;
			if(str_contains(argv[4], 'r')){b+=1;}
			if(str_contains(argv[4], 'g')){b+=2;}
			if(str_contains(argv[4], 'b')){b+=4;}//it is probably intended to use bitwise operators here
			filter_color_component(&a, b);
		}
		printf("%d\n", write_ppm_color_bitmap(argv[2], &a));
	}
	return 0;
}


int read_ppm_color_bitmap_bin(char* filename, PPM_Image_Buffer* buf){
	FILE* fd = fopen(filename, "rb");
	if(errno > 0){return -1;}
	if(fgetc(fd) == EOF){return -1;}
	if(fgetc(fd) == EOF){return -1;}
	if(fgetc(fd) == EOF){return -1;}//clears P3\n
	if(!fscanf(fd, "%d", &(buf->rown))){return -1;}//on error fscanf returns 0  and !0 == 1
	if(!fscanf(fd, "%d", &(buf->coln))){return -1;}
	int a;
	if(!fscanf(fd, "%d", &a)){return -1;}//used for 255
	a = buf->coln*buf->rown*sizeof(struct Pixel_Data);
	buf->data = malloc(a);
	if(fgetc(fd) == EOF){return -1;}//used for the /n after 255
	for(int i = 0; i < buf->coln*buf->rown;i++){
		buf->data[i].r = fgetc(fd);
		if(EOF == buf->data[i].r){return -1;}
		buf->data[i].g = fgetc(fd);
		if(EOF == buf->data[i].g){return -1;}
		buf->data[i].b = fgetc(fd);
		if(EOF == buf->data[i].b){return -1;}//prevents segmentation fault
	}
	return 0;
}


int write_ppm_color_bitmap_bin(char *filename, PPM_Image_Buffer *buf){
	FILE* fd = fopen(filename, "w+b");
	if(errno > 0){return -1;}
	fprintf(fd, "P6\n%d %d\n%d\n", buf->rown, buf->coln, 255);
	for(int i = 0; i < buf->coln*buf->rown;i++){
		if(1 != fprintf(fd, "%c", buf->data[i].r)){return -1;}
		if(1 != fprintf(fd, "%c", buf->data[i].g)){return -1;}
		if(1 != fprintf(fd, "%c", buf->data[i].b)){return -1;}//fprintf returns the printed amount of chars, excluding the \0
	}
	return 0;
}


void filter_color_component(PPM_Image_Buffer* buf, unsigned int rgb_mask){
	for(int i = 0; i < buf->coln*buf->rown;i++){
		if (!(1&rgb_mask)){buf->data[i].r = 0;}//if the bit is 0 sets the value to 0
		if (!(1&(rgb_mask>>1))){buf->data[i].g = 0;}
		if (!(1&(rgb_mask>>2))){buf->data[i].b = 0;}
	}
}


void convert_to_grayscale(PPM_Image_Buffer* buf){
	for(int i = 0; i < buf->coln*buf->rown;i++){
		int a = (unsigned)(buf->data[i].r*0.3) + (unsigned)(buf->data[i].g*0.59) + (unsigned)(buf->data[i].b*0.11);//uses the given formula
		buf->data[i].r = a;
		buf->data[i].g = a;
		buf->data[i].b = a;
	}
}
