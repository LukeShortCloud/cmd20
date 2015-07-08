#include <stdio.h>
#include <stdlib.h> // required for rand() (random function)
#include <time.h>   // required for rand() time seed
#include <string.h> // required for strcmp (string compare)

void dice(char *argv[], int count) { // dice roller function

        int diceSides = atoi(argv[count]); //atoi() converts chars to ints
        srand(time(NULL)); /* seed the built-in rand() function
                                if you do not then it will NOT be random; 
                                this will also only be random every second*/
        int r = rand() % diceSides + 1; // roll
        printf("Rolling a %d sided die...\n", diceSides);
        printf("You rolled a %d\n", r);
}


int main ( int argc, char *argv[] )
{
        /* argc = the argument count
           argv[] = the actual arguments
           The first command line argument argv[0] is the command itself */
        
        int count;
        int nCount; //used for tracking the "-n" CLI option     

        for (count=1; count < argc; count++) {
                if (strcmp(argv[count], "-n") == 0) {
                // you cannot compare pointer variables since they are memory addresses
                // instead you must use a special function such as "strcmp"     
                        nCount = 1;
                }
                else if (nCount == 1) {
                        dice(argv, count);
                        nCount = 0;
                }
                else {
                        dice(argv, count);
                }        
        }
}
