#include <stdio.h>
#include <stdlib.h> // required for rand() (random function) and exit()
#include <time.h>   // required for rand() time seed
#include <string.h> // required for strcmp (string compare)
#include <iostream>
#include "modules/swrpg.h" // Star Wars Fantasy Flight Games RPG plugin

static int r;
static int resultsArray[2];


class Dice
{
    public:
        int diceSides;
	//int diceValues[diceSides];
};


int dice(char *argv[], int count) { // dice roller function

    Dice Dice1;

    Dice1.diceSides = atoi(argv[count]); //atoi() converts chars to ints
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


int main ( int argc, char *argv[] )
{
	
	/* argc = the argument count
       argv[] = the actual arguments
       The first command line argument argv[0] is the command itself */
        
    int count;
    int nCount = 0; // used for tracking the "-n" CLI option     
    int qCount = 0; // used for tracking the "-q" CLI option
    int swCount = 0; // ... "-sw" CLI options

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
                printf("\t-q\t\tquiet mode only; outputs the end result\n");
                printf("\t-sw\t\tStar War's Fantasy Flight Games mode\n");
                printf("\t\t-a number\t\troll ability dice\n");
                printf("\t\t-d number\t\troll difficulty dice\n");
                printf("\t-v\t\tshows the current version of cmd20\n");
                printf("\t-h\t\tshows the available command line arguments\n");
            }
            else if (strcmp(argv[count], "-sw") == 0) {
                
                while ( count < argc - 1 ) {
    
                    if ( count <= argc ) {
                        count = count + 1;
                    }

                    //count = count + 1;
                    printf("-sw option triggered\n");
                    printf("argv count: %s", argv[count]);
                    if ( strcmp(argv[count], "-a" ) == 0 ) { // Ability dice
                        printf("-a");
                        count = count + 1;
                        rollSWDice(abilityDiceValues, atoi(argv[count])); // convert string to int

/*std::string abilityDiceValues[] = { "+", " ", "S", "S", "SS", "A", "A", "SA", "AA" };
std::string difficultyDiceValues[] = { "-", "", "F", "FF", "T", "T", "T", "TT", "FT"};
std::string boostDiceValues[] = { "+","", "", "S", "SA", "AA", "A" };
std::string setbackDiceValues[] = { "-" "", "", "F", "F", "T", "T" };
*/
                    }
                    else if ( strcmp(argv[count], "-d" ) == 0 ) { // Difficulty dice
                        count = count + 1;
                        rollSWDice(difficultyDiceValues, atoi(argv[count])); // convert string to int

                    }
                    else if ( strcmp(argv[count], "-b" ) == 0 ) { // Boost dice
                        count = count + 1;
                        rollSWDice(boostDiceValues, atoi(argv[count])); // convert string to int
                    }
                    else if ( strcmp(argv[count], "-s" ) == 0 ) { // Setback dice
                        count = count + 1;
                        rollSWDice(setbackDiceValues, atoi(argv[count])); // convert string to int

                    }  
                } 
                exit(0);

            }
            else if (strcmp(argv[count], "-v") == 0) {
                printf("cmd20 version: 0.2.0\n");
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
            verboseDice(resultsArray);
        }        
    }
}
