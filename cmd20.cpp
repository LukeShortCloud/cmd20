#include <iostream>
#include <stdio.h>
#include <stdlib.h> // required for rand() (random function) and exit()
#include <string.h> // required for strcmp (string compare)
#include <time.h>	// required for rand() time seed
#include "includes/swrpg.h" // Star Wars Fantasy Flight Games RPG plugin


//static int r;
static int resultsArray[2];


class Dice {

	public:
		int diceSides;
		//int diceValues[diceSides];

};


int dice(char *argv[], int argsCount) { // dice roller function

	Dice Dice1;

	Dice1.diceSides = atoi(argv[argsCount]); //atoi() converts chars to ints
	srand(time(NULL)); /* seed the built-in rand() function
							if you do not then it will NOT be random; 
							this will also only be random every second*/
	int r = rand() % Dice1.diceSides + 1; // roll
	resultsArray[0] = r;
	resultsArray[1] = Dice1.diceSides;
	return *resultsArray; // this must be returned as a pointer;
				  // you can only return one variable so
				  // an array or struct needs to be used
}


void verboseDice(int resultsArray[]) {

	printf("Rolling a %d sided die...\n", resultsArray[1]);
	printf("You rolled a %d\n", resultsArray[0]);
}

void checkArgvCount(int argsCount, int argc) {
 
	// if the current count is greater than the 
	// amount of command line arguments, return
	// False and error out
	if (argsCount >= argc) {
		printf("Error. Missing command line arguments.\n");
		exit(1);
	} else {
		printf("argsCount is not bigger than argc\n");
	}
 
}


int main ( int argc, char *argv[] ) {
	
	/* argc = the argument count
	   argv[] = the actual arguments
	   The first command line argument argv[0] is the command itself */
		
	int argsCount;
	int nCount = 0; // used for tracking the "-n" CLI option	 
	int qCount = 0; // used for tracking the "-q" CLI option
	//int swCount = 0; // ... "-sw" CLI options

		for (argsCount=1; argsCount < argc; argsCount++) {
	
			// you cannot compare pointer variables since they are memory addresses
			// instead you must use a special function such as "strcmp"		
			if (strcmp(argv[argsCount], "-n") == 0) {
				nCount = 1;
				argsCount = argsCount + 1;
			}
			else if (strcmp(argv[argsCount], "-q") == 0) {
				qCount = 1;
				argsCount = argsCount + 1;
			}
			else if (strcmp(argv[argsCount], "-h") == 0) {
				printf("Options:\n");
				printf("\t-n number\tgenerates a random number between 1 \
					   and the specified number\n");
				printf("\t-q\t\tquiet mode; output only the results\n");
				printf("\t-sw\t\tStar Wars(R) Fantasy Flight Games(TM) mode\n");
				printf("\t-a number\t\troll ability dice\n");
				printf("\t-d number\t\troll difficulty dice\n");
				printf("\t-v\t\tshows the current version of cmd20\n");
				printf("\t-h\t\tshows the available command line arguments\n");
				argsCount = argsCount + 1;
			}
			else if (strcmp(argv[argsCount], "-sw") == 0) {
				
				argsCount = argsCount + 1;
				checkArgvCount(argsCount, argc);
				
				// we add 1 because argsCount starts from 0 and argsCount
				// starts counting at 1
				while ( argsCount + 1 <= argc ) {

					argsCount = argsCount + 1;
					checkArgvCount(argsCount, argc);
					
					// "Ability" dice
					if ( strcmp(argv[argsCount - 1], "-a" ) == 0 ) { 
						printf("-a activated\n");
						// "atoi()" is used to convert our string to an int
						rollSWDice(abilityDiceValues, atoi(argv[argsCount])); 
					}
					// "Difficulty" dice
					else if ( strcmp(argv[argsCount - 1], "-d" ) == 0 ) { 
						rollSWDice(difficultyDiceValues, atoi(argv[argsCount])); 
					}
					// "Boost" dice
					else if ( strcmp(argv[argsCount - 1], "-b" ) == 0 ) { 
						rollSWDice(boostDiceValues, atoi(argv[argsCount])); 
					}
					// "Setback" dice
					else if ( strcmp(argv[argsCount - 1], "-s" ) == 0 ) { 
						rollSWDice(setbackDiceValues, atoi(argv[argsCount])); 
					}  

					argsCount = argsCount + 1;
				} 
				exit(0);

			}
			else if (strcmp(argv[argsCount], "-v") == 0) {
				printf("cmd20 version: 0.3.0\n");
			}
			else if (nCount == 1) {
				
				if (qCount == 1) {
					dice(argv, argsCount);
					printf("%d\n", resultsArray[0]);	
					qCount = 0;		
				}
				else {
					dice(argv, argsCount);
					verboseDice(resultsArray);
				}
				
				nCount = 0;
			}
		else {
			dice(argv, argsCount);
			verboseDice(resultsArray);
		}		 
	}
}
