#include <iostream>
#include <string>
using namespace std;

const int NR_ROUNDS = 5, NR_BOWLERS = 100;

struct bowlingScore
{
    string name;
    string localBowlingAlley;
    int  * pinsKnockedDown;

    ~bowlingScore()
    {
        if (pinsKnockedDown)
            delete [] pinsKnockedDown;
        
            pinsKnockedDown = nullptr;
    }
};

void inputBowlingScore(bowlingScore *);
void displayBowlingScore(bowlingScore *);

int main()
{
    bowlingScore *bowlingHistory = new bowlingScore[NR_ROUNDS];

    char answer;

    for (int i = 0; i < NR_BOWLERS; i++)
    {
        inputBowlingScore(&bowlingHistory[i]);
    }

    for (int i = 0; i < NR_BOWLERS; i++)
    {
        displayBowlingScore(&bowlingHistory[i]);
    }

    return 0;
}

void inputBowlingScore(bowlingScore * bptr)
{
    static int nrBowlers = 1;

    cout << "Input data for bowler #" << nrBowlers << ":\n";

    cout << "Name: ";
    getline(cin, bptr->name);

    cout << "Local bowling alley name: ";
    getline(cin, bptr->localBowlingAlley);

    bptr -> pinsKnockedDown = new int[NR_ROUNDS];
    for (int i = 0; i < NR_ROUNDS; i++)
    {
        cout << "Pins Knocked Down In Round #" << i + 1 << ": ";
        cin >> bptr->pinsKnockedDown[i];
    }
    cin.ignore();
    cout << endl << endl;

    nrBowlers++;
}

void displayBowlingScore(bowlingScore * bptr)
{
    cout << "Bowler summary:\n";
    cout << "Name: " << bptr->name << endl;
    cout << "ID: " << bptr->localBowlingAlley << endl;
    for (int i = 0; i < NR_ROUNDS; i++)
        cout << "Round #" << i + 1 << ": " << bptr->pinsKnockedDown[i] << endl;

    cout << endl << endl;
}