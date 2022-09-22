/********************************************\
*   allyourbase - Convert a decimal number   *
*                 to any base up to 64       *
*                                            *
*   Authored by: anthero                     *
*                                            *
\********************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void show_help(void);


int main(int argc, char *argv[]) {

	long base, num; 
	long place = 1;
	int  count = 0;
	char base_alphabet[] = {
		'0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'a', 'b', 'c', 'd', 'e', 'f',
		'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
		'o', 'p', 'q', 'r', 's', 't', 'u', 'v' };

	//prevents segfaults, displays help
	if (argc != 3) {
		show_help();
	}
	
	else {

		//declared here to avoid breakage
		base = atol(argv[1]);
		num  = atol(argv[2]);

		//keeps things sane
		if (base < 2 || base > 64) {
			show_help();
		}
		
		//start of actual program
		else {

			//qol stuff for output
			if      (base == 2)
				printf("Binary: 0b");

			else if (base == 8)
				printf("Octal: 0");

			else if (base == 16)
				printf("Hexadecimal: 0x");

			else
				printf("Base%d: ", base);
			
			//think in terms of 1s place, 10s place, 100s place, etc
			while (place <= num / base)
				place = place * base;

			//place gets divided away as the loop iterates
			while (place >= 1) {
				//num gets subtracted away while a count is recorded
				while (num >= place) {
					count++;
					num = num - place;
				}
				//this is where the count comes in handy
				printf("%c", base_alphabet[count]);
				//place gets divided away like we talked about
				place = place / base;
				//count is reset to zero for next run
				count = 0;
			}
			
			//dont forget to bring a newline
			printf("\n");
		}
	}

	return 0;
}

void show_help(void) {
	printf("Usage:\n");
	printf("allyourbase <base> <number>\n");
}
