#include <stdio.h>
#include <stdlib.h> // required for rand() (random function)
#include <time.h>   // required for rand() time seed
#include <string.h> // required for strcmp (string compare)

static int r;
static int resultsArray[2];

int dice(char *argv[], int count) { // dice roller function

        int diceSides = atoi(argv[count]); //atoi() converts chars to ints
        srand(time(NULL)); /* seed the built-in rand() function
                                if you do not then it will NOT be random; 
                                this will also only be random every second*/
        int r = rand() % diceSides + 1; // roll
	resultsArray[0] = r;
	resultsArray[1] = diceSides;
	return *resultsArray; // this must be returned as a pointer;
			      // you can only return one variable so
			      // an array or struct needs to be used
}

void verboseDice(int resultsArray[]) {
        printf("Rolling a %d sided die...\n", resultsArray[1]);
        printf("You rolled a %d\n", resultsArray[0]);
}

int main ( int argc, char *argv[] )
{
        /* argc = the argument count
           argv[] = the actual arguments
           The first command line argument argv[0] is the command itself */
        
        int count;
	int diceSides;
        int nCount = 0; //used for tracking the "-n" CLI option     
	int qCount = 0; //used for tracking the "-q" CLI option

        for (count=1; count < argc; count++) {
                if (strcmp(argv[count], "-n") == 0) {
                // you cannot compare pointer variables since they are memory addresses
                // instead you must use a special function such as "strcmp"     
                        nCount = 1;
                }
		else if (strcmp(argv[count], "-q") == 0) {
			qCount = 1;
		}
                else if (strcmp(argv[count], "-h") == 0) {
                        printf("Options:\n");
			printf("\t-n number\tgenerates a random number between 1 and the specified number\n");
			printf("\t-q\tquiet mode only outputs the end result\n");
			printf("\t-v\t\tshows the current version of cmd20\n");
			printf("\t-h\t\tshows the available command line arguments\n");
                }
		else if (strcmp(argv[count], "-v") == 0) {
			printf("cmd20 version: 0.1 (build 2)\n");
		}
                else if (nCount == 1) {
                        if (qCount == 1) {
				dice(argv, count);
				printf("%d\n", resultsArray[0]);	
				qCount = 0;		
			}
			else {
				dice(argv, count);
				verboseDice(resultsArray);
			}
                        nCount = 0;
		}
		else {
                        dice(argv, count);
			printf("resultsArray[0] is %d\n", resultsArray[0]);
                }        
        }
}
