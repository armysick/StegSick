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
	
	target = fopen("unstegified", "w");
	if(target == NULL){
		printf("error creating file.");
		return -1;
	}
	
	int curr_to_encryp_bit = 0;
	int first;
	int counter = 0;
	int sent_counter = 0;
	while((first = fgetc(fd)) != EOF){
		
		counter++;
		if(counter > 50 ){  // MUST BE 50+ for BMP;  TXT has NO HEADER
		if(DEBUG)
		printf("READ      : <0x%x>\n", first);
		if(curr_to_encryp_bit == 0)
			first &= ~(1 << 0);
		else
			first |= 1 << 0;
		if(DEBUG)
		printf("CHANGED TO: <0x%x>\n\n", first);
		sent_counter ++;
		}
		fputc(first, target);
	
		
	}
    fclose(fd);
	fclose(target);
	printf("\n%i bytes read!\n", counter);
	printf("\n%i bits sent!\n", sent_counter);
    
    return 0;
}


