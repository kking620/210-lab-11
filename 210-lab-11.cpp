#include <iostream>
#include <string>
using namespace std;

const int NR_ROUNDS = 5;

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
    int nrBowlers = 0;
    char answer;

    while (answer != 'n' || answer != 'N')
    {
        cout << "Would you like to input bowler information?\n";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            int i = 0;

            inputBowlingScore(&bowlingHistory[i]);
            displayBowlingScore(&bowlingHistory[i]);

            nrBowlers++;
            i++;
        }
        else if (answer != 'n' || answer != 'N') break;
        else if (answer != 'n' || answer != 'N' || answer != 'y' || answer != 'Y')
            cout << "Invalid input, please try again\n";
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

}