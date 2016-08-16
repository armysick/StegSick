#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]){
	int DEBUG = 0;
	FILE *steg;
	FILE *target;
	
	steg = fopen(argv[1], "r");
	if(steg == NULL){
		printf("error opening file.");
		return -1;
	}
	
	target = fopen("unstegified", "w");
	if(target == NULL){
		printf("error creating file.");
		return -1;
	}
	
	int first;
	int counter = 0;
	unsigned char byte = 0xF;
	int bit_counter = 0;
	int sent_counter = 0;
	while((first = fgetc(steg)) != EOF){
		
		counter++;
		if(counter > 50 ){  // MUST BE 50+ for BMP;  TXT has NO HEADER
			// TODO 
			if(DEBUG)
			printf("READ      : <0x%x>\n", first);

			if(DEBUG)
				printf(" RESULT: %x\n", (first>>0) & 1);
			if(((first >> 0) & 1) == 1)
				byte |= 1 << bit_counter;
			else
				byte &= ~(1 << bit_counter);
			bit_counter ++;
			sent_counter++;

			if(DEBUG)
			printf("CHANGED TO: <0x%x>\n\n", first);

			if(bit_counter == 8){
				fputc(byte, target);
				bit_counter = 0;
				byte = 0xF;
			}
		
		}
		
	
		
	}
    fclose(steg);
	fclose(target);
	printf("\n%i bytes read!\n", counter);
	printf("\n%i bits received!\n", sent_counter);
	
}