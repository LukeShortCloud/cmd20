#include <iostream> // used for C++ cout and cin

// S = Success, A = Advantage, R = tRiumph, + = array is a positive die
// F = Failure, T = Threat,    D = Despair, - = array is a negative die

std::string abilityDiceValues[] = { "+", "", "S", "S", "SS", "A", "A", "SA", "AA" };
std::string difficultyDiceValues[] = { "-", "", "F", "FF", "T", "T", "T", "TT", "FT"};
std::string boostDiceValues[] = { "+","", "", "S", "SA", "AA", "A" };
std::string setbackDiceValues[] = { "-" "", "", "F", "F", "T", "T" };
 
int S_count = 0;
int F_count = 0;
int A_count = 0;
int T_count = 0;
int R_count = 0;
int D_count = 0;


std::string rollSWDice(std::string DiceValues[], int rollCount) {	

	printf("rollSWDice-debug: rollCount = %d", rollCount);

	return "Stub";	

}

