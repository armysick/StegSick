#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]){
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
	while((first = fgetc(steg)) != EOF){
		
		counter++;
		if(counter > 50 ){  // MUST BE 50+ for BMP;  TXT has NO HEADER
			// TODO 
		if(DEBUG)
		printf("READ      : <0x%x>\n", first);
		if(curr_to_encryp_bit == 0)
			first &= ~(1 << 0);
		else
			first |= 1 << 0;
		if(DEBUG)
		printf("CHANGED TO: <0x%x>\n\n", first);
		
		}
		fputc(first, target);
	
		
	}
    fclose(steg);
	fclose(target);
	printf("\n%i bytes read!\n", counter);
	
}