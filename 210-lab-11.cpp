//COMSC-210 | Lab 11 | Kristofer King
//IDE Used: VSC
#include <iostream>
#include <string>
using namespace std;

//initializing and declaring the maximum size for both the number of rounds played and the number of bowlers being interviewed
const int NR_ROUNDS = 5, NR_BOWLERS = 100;

//declaring and initializing a structure in which we will be inputting into a dynamic array
struct bowlingScore
{
    string name;
    string localBowlingAlley;
    int nRoundsPlayed;
    int  *pinsKnockedDown;

    //destructor to delete what has been placed into the dynamic array upon completion of its use
    ~bowlingScore()
    {
        if (pinsKnockedDown)
            delete [] pinsKnockedDown;
        
            pinsKnockedDown = nullptr;
    }
};

//prototype functions to record the information from the bowlers participating and displaying their information in an organized list respectively
void inputBowlingScore(bowlingScore *);
void displayBowlingScore(bowlingScore *);

int main()
{
    //declares and initializes a dynamic array of structures
    bowlingScore *bowlingHistory = new bowlingScore[NR_BOWLERS];
    char answer;
    int size = 0;

    //a for loop that asks the user if they want to input more information into the array as long as the number of participants does not exceed the maximum number of bowlers
    for (int i = 0; i < NR_BOWLERS; i++)
    {
        //requests a user input in order to determine if the user wants to input more information
        cout << "Would you like to input bowler information?\n";
        cin >> answer;
        cin.ignore();
        
        //if the user responds with yes then, the prototype function will be called in order to fill the information of the user
        if (answer == 'y' || answer == 'Y')
        {
            inputBowlingScore(&bowlingHistory[i]);
            size++;
        }
        //if the response is no, then the loop breaks and ends the information inputting cycle
        else if (answer != 'n' || answer != 'N') break;
        //if the user inputs a response that is unrecognized, it will display the invalid input message
        else if (answer != 'n' && answer != 'N' && answer != 'y' && answer != 'Y')
            cout << "Invalid input, please try again\n";
    }

    //once information has been inputted, this for loop will display all bowlers' information that was collected
    for (int i = 0; i < size; i++)
        displayBowlingScore(&bowlingHistory[i]);

    return 0;
}
    //void function that is used to input the information of the bowlers
void inputBowlingScore(bowlingScore * bptr)
{
    static int nrBowlers = 1;

    cout << "Input data for bowler #" << nrBowlers << ":\n";

    //requests the input of the name of the bowler whose information is being collected
    cout << "Name: ";
    getline(cin, bptr->name);

    //requests the bowler's local bowling alley that they typically play at
    cout << "Local bowling alley name: ";
    getline(cin, bptr->localBowlingAlley);

    //initializes a dynamic array to input the information of the score of the past rounds played
    bptr -> pinsKnockedDown = new int[NR_ROUNDS];
    
    //requests an input for the amount of rounds played by the bowler
    cout << "How many rounds did they play?\n";
    cin >> bptr->nRoundsPlayed;
    cin.ignore();

    //for loop that continuously requests the number of pins knocked down until the number of rounds they played has been reached
    for (int i = 0; i < bptr->nRoundsPlayed; i++)
    {
        cout << "Pins Knocked Down In Round #" << i + 1 << ": ";
        cin >> bptr->pinsKnockedDown[i];
    }
    cin.ignore();
    cout << endl << endl;

    nrBowlers++;
}

//displays an organized list of the bowlers' information that was inputted by the user
void displayBowlingScore(bowlingScore * bptr)
{
    cout << "Bowler summary:\n";
    cout << "Name: " << bptr->name << endl;
    cout << "Local Bowling Alley: " << bptr->localBowlingAlley << endl;
    for (int i = 0; i < bptr->nRoundsPlayed; i++)
        cout << "Round #" << i + 1 << ": " << bptr->pinsKnockedDown[i] << endl;

    cout << endl << endl;
}