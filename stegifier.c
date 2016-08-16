#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int DEBUG = 1;
	FILE *fd;
    unsigned char c;
	
    
    fd = fopen("test.txt", "r");
	if(fd == NULL){
		printf("error opening file.");
		return -1;
	}
	int curr_to_encryp_bit = 1;
	int first;
	while((first = fgetc(fd)) != EOF){
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
    fclose(fd);

    
    return 0;
}


