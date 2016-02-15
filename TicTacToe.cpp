//Tic Tac Toe Game
#include <iostream>

using namespace std;

void board();
void playermove();
bool gameover();

bool draw = false;
char turn;
char board1[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

int main()
{
    cout << "Tic Tac Toe Game!\n";
    cout << "Player 1 is X and Player 2 is O\n";
    turn = 'X';

    while (!gameover())
    {
        board();
        playermove();
        gameover();
    }

    if (turn == 'O' && !draw)
    {
        board();
        cout << endl << endl << "Player 1 [X] Wins! Game Over!\n";
    }
    else if (turn == 'X' && !draw)
    {
        board();
        cout << endl << endl << "Player 2 [O] Wins! Game Over!\n";
    }
    else
    {
        board();
        cout << endl << endl << "It's a draw! Game Over!\n";
    }

    return 0;
}

void board ()
{
    cout << "-------------" << endl;
    cout << "| " << board1[0][0] << " | " << board1[0][1] << " | " << board1[0][2] << " |" << endl;
    cout << "-------------" << endl;
    cout << "| " << board1[1][0] << " | " << board1[1][1] << " | " << board1[1][2] << " |" << endl;
    cout << "-------------" << endl;
    cout << "| " << board1[2][0] << " | " << board1[2][1] << " | " << board1[2][2] << " |" << endl;
    cout << "-------------" << endl;
}

void playermove()
{
    int choice;
    int row = 0, column = 0;

    if (turn == 'X')
    {
        cout << "Player 1's Move [X], Pick between 1-9: " << endl;
    }
    else if (turn == 'O')
    {
        cout << "Player 2's Move [O], Pick between 1-9: " << endl;
    }
    cin >> choice;

    switch (choice)
    {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "You did not enter a number between 1-9! Try again!\n";
            playermove();
    }

    if (turn == 'X' && board1[row][column] != 'X' && board1[row][column] != 'O')
    {
        board1[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board1[row][column] != 'X' && board1[row][column] != 'O')
    {
        board1[row][column] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "The cell you entered is used! Try again!\n";
        playermove();
    }

}

bool gameover()
{
    for (int i = 0; i < 3; i++)//Check for a win
    {
        if ((board1[i][0] == board1[i][1] && board1[i][1] == board1[i][2]) || (board1[0][i] == board1[1][i] && board1[1][i] == board1[2][i]) || (board1[0][0] == board1[1][1] && board1[1][1] == board1[2][2]) || (board1[0][2] == board1[1][1] && board1[1][1] == board1[2][0]))
        {
            return true;
        }
    }

    for (int i = 0; i < 3; i++)//Check for draw
    {
        for (int j = 0; j < 3; j++)
        {
            if (board1[i][j] != 'X' && board1[i][j] != 'O')
            {
                return false;
            }
        }
    }
    draw = true;
    return true;
}
