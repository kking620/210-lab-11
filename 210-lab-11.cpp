#include <iostream>
using namespace std;

const int NR_ROUNDS = 5, NR_BOWLERS = 5;

struct bowlingScore
{
    string homeTown;
    string localBowlingAlley;
    int  * pinsKnockedDown;
};

void inputBowlingScore(bowlingScore *);
void displayBowlingScore(bowlingScore *);

int main()
{
    bowlingScore *bowlingHistory = new bowlingScore[NR_ROUNDS];

    for (int i = 0; i < NR_BOWLERS; i++)
        inputBowlingScore(&bowlingHistory[i]);

    for (int i = 0; i < NR_BOWLERS; i++)
        displayBowlingScore(&bowlingHistory[i]);

    return 0;
}