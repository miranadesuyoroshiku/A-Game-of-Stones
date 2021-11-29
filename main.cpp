#include "StoneGame.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cmath>

using namespace std;

int count = 0;
int chance = 0;

void GameIntro();
void EasyMode(int& stones);
void HardMode(int& stones);
void HumanMove(int& stones, int& count);
void ComputerMove(int& stones);
void UpdateStepCount(int& count);
void NotValidMove(int human_move);
void WinLose(int chance, int count);
void ComputerMoveHard(int& stones);

void GameIntro()
{
    cout << "*************** THE GAME OF NIM ***************" << endl << endl;
    cout << "Rules of the game:" << endl;
    cout << "* Each player can remove 1, 2, or 3 stones from the pile." << endl;
    cout << "* The player who makes the last move loses." << endl << endl;
}

void EasyMode(int& stones)
{
    cout << "Now a roll of the die to determine who plays first..." << endl;
    srand(time(0));
    chance = rand() % 2;
    bool flag = true;

    //computer plays first
    if (chance == 0)
    {
        cout << "The computer plays first." << endl << endl;
        int count = 0;
        while (flag)
        {
            if (stones > 0)
            {
                if (count % 2 == 0)
                {
                    //computer moves
                    ComputerMove(stones);
                    UpdateStepCount(count);
                }
                else
                {
                    //human moves
                    HumanMove(stones, count);
                }
            }
            else
            {
                //determine who wins
                WinLose(chance, count);
                flag = false;
            }
        }

    }

    // human plays first
    else
    {
        cout << "You play first." << endl << endl;
        int count = 0;
        while (true)
        {
            if (stones > 0)
            {
                if (count % 2 == 0)
                {
                    //human moves
                    HumanMove(stones, count);
                }
                else
                {
                    //computer moves
                    ComputerMove(stones);
                    UpdateStepCount(count);
                }
            }
            else //stone == 0 game over
            {
                //determine who wins
                WinLose(chance, count);
                break;
            }
        }
    }

}

void HardMode(int& stones)
{
    cout << "Now a roll of the die to determine who plays first..." << endl;
    srand(time(0));
    chance = rand() % 2;
    bool flag = true;

    //computer plays first
    if (chance == 0)
    {
        cout << "The computer plays first." << endl << endl;
        int count = 0;
        while (flag)
        {
          if (stones > 0)
            {
                if (count % 2 == 0)
                {
                    //computer moves
                    ComputerMoveHard(stones);
                    UpdateStepCount(count);
                }
                else
                {
                    //human moves
                    HumanMove(stones, count);
                }
            }
            else
            {
                //determine who wins
                WinLose(chance, count);
                flag = false;
            }
        }
    }

    //human plays first
    else
    {
        cout << "You play first." << endl << endl;
        int count = 0;
        while (true)
        {
            if (stones > 0)
            {
                if (count % 2 == 0)
                {
                    //human moves
                    HumanMove(stones, count);
                }
                else
                {
                    //computer moves
                    ComputerMoveHard(stones);
                    UpdateStepCount(count);
                }
            }
            else //stone == 0 game over
            {
                //determine who wins
                WinLose(chance, count);
                break;
            }
        }
    }
}

void HumanMove(int& stones, int& count)
{
    cout << "It is your turn. Enter the number of stones you would like to remove: ";
    int human_move = 0;
    cin >> human_move;
    if (human_move == 1)
    {
        cout << "You removed " << human_move << " stone from the pile" << endl;
        stones = stones - human_move;
        UpdateStepCount(count);
        cout << "The pile now has " << stones << " stones left." << endl << endl;
    }
    else if (human_move == 2 || human_move == 3)
    {
        cout << "You removed " << human_move << " stones from the pile" << endl;
        stones = stones - human_move;
        UpdateStepCount(count);
        cout << "The pile now has " << stones << " stones left." << endl << endl;
    }
    else
    {
        NotValidMove(human_move);
    }
}

void ComputerMove(int& stones)
{
    cout << "The computer is choosing a move..." << endl;
    int comp_move = 0;
    srand(time(0));
    comp_move = rand() % 3 + 1;
    usleep(1000000);
    if (comp_move == 1)
    {
        cout << "The computer removed " << comp_move << " stone from the pile" << endl;
    }
    else
    {
        cout << "The computer removed " << comp_move << " stones from the pile" << endl;
    }
    stones = stones - comp_move;
    cout << "The pile now has " << stones << " stones left" << endl << endl;
}

void UpdateStepCount(int& count)
{
    count++;
}

void NotValidMove(int human_move)
{
    cout << human_move << " is not a valid move. Enter either 1, 2, or 3 for the number of stones: ";
}

void WinLose(int chance, int count)
{
    //chance and count odd or even
    if ((chance == 0 && count % 2 == 1) || (chance == 1 && count % 2 == 0))
    {
        cout << "Congratulations, you won! : )" << endl;
    }
    else
    {
        cout << "Sorry, you lost the game : (" << endl;
    }
}

void ComputerMoveHard(int& stones)
{
    cout << "The computer is choosing a move..." << endl;
    int comp_move = 0;
    srand(time(0));
    //computer make decision to win here
    if (stones % 4 > 0 && stones > 4)
    {
        comp_move = 1;
    }
    else
    {
        switch (stones)
        {
        case 4:
            comp_move = 3;
            break;
        case 3:
            comp_move = 2;
            break;
        case 2:
            comp_move = 1;
            break;
        case 1:
            comp_move = 1;
            break;
        default:
            break;
        }

    }
    //computer decision ends here
    usleep(1000000);
    if (comp_move == 1)
    {
        cout << "The computer removed " << comp_move << " stone from the pile" << endl;
    }
    else
    {
        cout << "The computer removed " << comp_move << " stones from the pile" << endl;
    }
    stones = stones - comp_move;
    cout << "The pile now has " << stones << " stones left" << endl << endl;
}

int main()
{
    GameIntro();

    //random the stones
    int stones = 0;
    srand(time(0));
    stones = rand() % 12 + 10;

    // choose mode:
    cout << "Choose mode:" << endl;
    cout << "Easy Mode <e> or Hard Mode <H>: ";
    char mode;
    cin >> mode;
    if (mode == 'e')
    {
        cout << "You have chosen the easy mode." << endl << endl;
        cout << "The initial number of stones is " << stones << endl;
        EasyMode(stones);
    }
    else if (mode == 'H')
    {
        cout << "You have chosen the hard mode." << endl << endl;
        cout << "The initial number of stones is " << stones << endl;
        HardMode(stones);
    }

    return 0;
}
