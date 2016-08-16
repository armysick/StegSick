#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int DEBUG = 0;
	FILE *fd;
	FILE *target;
    unsigned char c;
	
    
    fd = fopen(argv[1], "r");
	if(fd == NULL){
		printf("error opening file.");
		return -1;
	}
	
	target = fopen("stegified.bmp", "w");
	if(target == NULL){
		printf("error creating file.");
		return -1;
	}
	
	int curr_to_encryp_bit = 1;
	int first;
	int counter = 0;
	while((first = fgetc(fd)) != EOF){
		
		counter++;
		if(counter < 0){
		if(DEBUG)
		printf("READ      : <0x%x>\n", first);
		if(curr_to_encryp_bit == 0){
			first &= ~(1 << 0);
		}
		else{
			first |= 1 << 0;
		}
		if(DEBUG)
		printf("CHANGED TO: <0x%x>\n\n", first);
		
		}
		fputc(first, target);
	
		
	}
    fclose(fd);
	fclose(target);
	printf("\n%i bytes read!\n", counter);
    
    return 0;
}


