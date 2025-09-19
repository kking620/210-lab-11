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
void displayBowlingScore(bowlingScore *, int size);

int main()
{
    bowlingScore *bowlingHistory = new bowlingScore[NR_ROUNDS];
    char answer;
    int size = 0;

    for (int i = 0; i < NR_BOWLERS; i++)
    {
        cout << "Would you like to input bowler information?\n";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            inputBowlingScore(&bowlingHistory[i]);
            size++;
        }
        else if (answer != 'n' || answer != 'N') break;
        else if (answer != 'n' || answer != 'N' || answer != 'y' || answer != 'Y')inputBowlingScore(&bowlingHistory[i]);
    }

    for (int i = 0; i < NR_BOWLERS; i++)
        displayBowlingScore(&bowlingHistory[i], size);

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

void displayBowlingScore(bowlingScore * bptr, int size)
{
    cout << "Bowler summary:\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Name: " << bptr->name << endl;
        cout << "ID: " << bptr->localBowlingAlley << endl;
        for (int i = 0; i < NR_ROUNDS; i++)
            cout << "Round #" << i + 1 << ": " << bptr->pinsKnockedDown[i] << endl;

        cout << endl << endl;
    }
}